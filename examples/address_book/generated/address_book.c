/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * This file was generated by pbtools version 0.1.0 Thu Jan 24 08:14:06 2019.
 */

#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "address_book.h"

struct encoder_t {
    uint8_t *buf_p;
    int size;
    int pos;
};

struct decoder_t {
    const uint8_t *buf_p;
    int size;
    int pos;
    struct address_book_heap_t *heap_p;
};

static struct address_book_heap_t *heap_init(void *buf_p, size_t size)
{
    struct address_book_heap_t *heap_p;

    if (size >= sizeof(*heap_p)) {
        heap_p = (struct address_book_heap_t *)buf_p;
        heap_p->buf_p = buf_p;
        heap_p->size = size;
        heap_p->pos = sizeof(*heap_p);
    } else {
        heap_p = NULL;
    }

    return (heap_p);
}

static void *heap_alloc(struct address_book_heap_t *self_p, size_t size)
{
    void *buf_p;
    int left;

    left = (self_p->size - self_p->pos);

    if (size <= left) {
        buf_p = &self_p->buf_p[self_p->pos];
        self_p->pos += size;
    } else {
        buf_p = NULL;
    }

    return (buf_p);
}

static void encoder_init(struct encoder_t *self_p,
                         uint8_t *buf_p,
                         size_t size)
{
    self_p->buf_p = buf_p;
    self_p->size = size;
    self_p->pos = (size - 1);
}

static size_t encoder_pos(struct encoder_t *self_p)
{
    return (self_p->pos);
}

static int encoder_get_result(struct encoder_t *self_p)
{
    /* int i; */

    /* fprintf(stderr, "pos: %d, size: %d\n", (int)self_p->pos, (int)self_p->size); */

    /* for (i = self_p->pos + 1; i < self_p->size; i++) { */
    /*     fprintf(stderr, "\\x%02x", self_p->buf_p[i]); */
    /* } */

    /* fprintf(stderr, "\n"); */

    return (self_p->size - self_p->pos - 1);
}

static void encoder_prepend_byte(struct encoder_t *self_p,
                                 uint8_t value)
{
    if (self_p->pos < 0) {
        fprintf(stderr, "encoder_prepend_byte: %d\n", self_p->pos);
        exit(1);
    }

    self_p->buf_p[self_p->pos] = value;
    self_p->pos--;
}

static void encoder_prepend_bytes(struct encoder_t *self_p,
                                  const uint8_t *buf_p,
                                  size_t size)
{
    int i;

    for (i = (int)size - 1; i >= 0; i--) {
        encoder_prepend_byte(self_p, buf_p[i]);
    }
}

static void encoder_prepend_tag(struct encoder_t *self_p,
                                int tag,
                                int wire_type)
{
    encoder_prepend_byte(self_p, (tag << 3) | wire_type);
}

static void encoder_prepend_varint_value(struct encoder_t *self_p,
                                         uint64_t value)
{
    if (value > 127) {
        fprintf(stderr, "encoder_prepend_varint_value: %llu\n", (unsigned long long)value);
        exit(1);
    }

    encoder_prepend_byte(self_p, value);
}

static void encoder_prepend_varint(struct encoder_t *self_p,
                                   int tag,
                                   uint64_t value)
{
    encoder_prepend_varint_value(self_p, value);
    encoder_prepend_tag(self_p, tag, 0);
}

static void encoder_prepend_length_delimited(struct encoder_t *self_p,
                                             int tag,
                                             uint64_t length)
{
    encoder_prepend_varint_value(self_p, length);
    encoder_prepend_tag(self_p, tag, 2);
}

static void encoder_prepend_string(struct encoder_t *self_p,
                                   int tag,
                                   const char *value_p)
{
    int length;

    length = strlen(value_p);
    encoder_prepend_bytes(self_p, (uint8_t *)value_p, length);
    encoder_prepend_length_delimited(self_p, tag, length);
}

static void decoder_init(struct decoder_t *self_p,
                         const uint8_t *buf_p,
                         size_t size,
                         struct address_book_heap_t *heap_p)
{
    self_p->buf_p = buf_p;
    self_p->size = size;
    self_p->pos = 0;
    self_p->heap_p = heap_p;
}

static void decoder_init_slice(struct decoder_t *self_p,
                               struct decoder_t *parent_p,
                               int size)
{
    //fprintf(stderr, "slice size: %d\n", size);
    self_p->buf_p = &parent_p->buf_p[parent_p->pos];
    self_p->size = size;
    self_p->pos = 0;
    self_p->heap_p = parent_p->heap_p;
}

static void decoder_seek(struct decoder_t *self_p,
                         int offset)
{
    if (offset < 0) {
        exit(1);
    }

    self_p->pos += offset;
}

static bool decoder_available(struct decoder_t *self_p)
{
    return (self_p->pos < self_p->size);
}

static int decoder_get_result(struct decoder_t *self_p)
{
    int res;

    if (self_p->pos == self_p->size) {
        res = self_p->pos;
    } else {
        res = -1;
    }

    //fprintf(stderr, "result: %d\n", res);

    return (res);
}

static uint8_t decoder_read_byte(struct decoder_t *self_p)
{
    uint8_t value;

    if (self_p->pos >= self_p->size) {
        fprintf(stderr, "decoder_read_byte: %d %d\n", self_p->pos, self_p->size);
        exit(1);
    }

    value = self_p->buf_p[self_p->pos];
    self_p->pos++;

    //fprintf(stderr, "r: %02x\n", value);

    return (value);
}

static void decoder_read_bytes(struct decoder_t *self_p,
                               uint8_t *buf_p,
                               size_t size)
{
    int i;

    for (i = 0; i < size; i++) {
        buf_p[i] = decoder_read_byte(self_p);
    }
}

static void decoder_read_tag(struct decoder_t *self_p,
                             int tag,
                             int wire_type)
{
    uint8_t value;

    value = decoder_read_byte(self_p);

    if (value != ((tag << 3) | wire_type)) {
        fprintf(stderr, "decoder_read_tag: %02x %02x\n", value, (tag << 3) | wire_type);
        exit(1);
    }
}

static bool decoder_peek_tag(struct decoder_t *self_p,
                             int tag)
{
    return (decoder_available(self_p)
            && ((self_p->buf_p[self_p->pos] >> 3) == tag));
}

static int decoder_peek_tag_2(struct decoder_t *self_p)
{
    return (self_p->buf_p[self_p->pos] >> 3);
}

static uint64_t decoder_read_varint_value(struct decoder_t *self_p)
{
    return (decoder_read_byte(self_p));
}

static uint64_t decoder_read_varint(struct decoder_t *self_p,
                                    int tag)
{
    decoder_read_tag(self_p, tag, 0);

    return (decoder_read_varint_value(self_p));
}

static uint64_t decoder_read_length_delimited(struct decoder_t *self_p,
                                              int tag)
{
    decoder_read_tag(self_p, tag, 2);

    return (decoder_read_varint_value(self_p));
}

static int decoder_peek_repeated_length(struct decoder_t *self_p,
                                        int tag)
{
    int length;
    int item_length;
    struct decoder_t decoder;

    decoder = *self_p;
    length = 0;

    while (decoder_peek_tag(&decoder, tag)) {
        item_length = decoder_read_length_delimited(&decoder, tag);
        decoder_seek(&decoder, item_length);
        length++;
    }

    //fprintf(stderr, "repeated length peek: %d\n", length);

    return (length);
}

static void decoder_read_string(struct decoder_t *self_p,
                                int tag,
                                char **value_pp)
{
    uint64_t length;
    char *value_p;

    length = decoder_read_length_delimited(self_p, tag);
    //fprintf(stderr, "length: %llu\n", (unsigned long long)length);
    value_p = heap_alloc(self_p->heap_p, length + 1);
    *value_pp = value_p;

    if (value_p != NULL) {
        decoder_read_bytes(self_p, (uint8_t *)value_p, length);
        value_p[length] = '\0';
    }
}

void address_book_person_free(struct address_book_person_t *person_p)
{
    free(person_p);
}

int address_book_person_phones_alloc(
    struct address_book_person_t *person_p,
    int length)
{
    int res;
    int i;
    struct address_book_person_phone_number_t *items_p;

    items_p = heap_alloc(person_p->heap_p, sizeof(*items_p) * length);

    if (items_p != NULL) {
        for (i = 0; i < length; i++) {
            items_p[i].number_p = "";
            items_p[i].type = address_book_person_phone_type_mobile_e;
        }

        person_p->phones.length = length;
        person_p->phones.items_p = items_p;
        res = 0;
    } else {
        res = -1;
    }

    return (res);
}

struct address_book_address_book_t *address_book_address_book_init(
    void *workspace_p,
    size_t size)
{
    struct address_book_address_book_t *address_book_p;
    struct address_book_heap_t *heap_p;

    heap_p = heap_init(workspace_p, size);

    if (heap_p == NULL) {
        return (NULL);
    }

    address_book_p = heap_alloc(heap_p, sizeof(*address_book_p));

    if (address_book_p != NULL) {
        address_book_p->heap_p = heap_p;
        address_book_p->people.length = 0;
    }

    return (address_book_p);
}

int address_book_address_book_people_alloc(
    struct address_book_address_book_t *address_book_p,
    int length)
{
    int res;
    int i;
    struct address_book_person_t *items_p;

    items_p = heap_alloc(address_book_p->heap_p, sizeof(*items_p) * length);

    if (items_p != NULL) {
        for (i = 0; i < length; i++) {
            items_p[i].heap_p = address_book_p->heap_p;
            items_p[i].name_p = "";
            items_p[i].id = 0;
            items_p[i].email_p = "";
        }

        address_book_p->people.length = length;
        address_book_p->people.items_p = items_p;
        res = 0;
    } else {
        res = -1;
    }

    return (res);
}

void address_book_person_phone_number_encode_inner(
    struct encoder_t *encoder_p,
    struct address_book_person_phone_number_t *phone_number_p)
{
    encoder_prepend_varint(encoder_p, 2, phone_number_p->type);
    encoder_prepend_string(encoder_p, 1, phone_number_p->number_p);
}

void address_book_person_phone_number_decode_inner(
    struct decoder_t *decoder_p,
    struct address_book_person_phone_number_t *phone_number_p)
{
    while (decoder_available(decoder_p)) {
        switch (decoder_peek_tag_2(decoder_p)) {

        case 1:
            decoder_read_string(decoder_p, 1, &phone_number_p->number_p);
            break;

        case 2:
            phone_number_p->type = decoder_read_varint(decoder_p, 2);
            break;

        default:
            fprintf(stderr, "address_book_person_phone_number_decode_inner\n");
            exit(1);
            return;
        }
    }
}

void address_book_person_encode_inner(
    struct encoder_t *encoder_p,
    struct address_book_person_t *person_p)
{
    int i;
    int pos;

    for (i = person_p->phones.length - 1; i >= 0; i--) {
        pos = encoder_pos(encoder_p);
        address_book_person_phone_number_encode_inner(
            encoder_p,
            &person_p->phones.items_p[i]);
        encoder_prepend_length_delimited(encoder_p,
                                         4,
                                         pos - encoder_pos(encoder_p));
    }

    encoder_prepend_string(encoder_p, 3, person_p->email_p);
    encoder_prepend_varint(encoder_p, 2, person_p->id);
    encoder_prepend_string(encoder_p, 1, person_p->name_p);
}

void address_book_person_decode_inner(
    struct decoder_t *decoder_p,
    struct address_book_person_t *person_p)
{
    struct address_book_person_phone_number_t *phone_number_p;
    uint64_t length;
    struct decoder_t decoder;
    int i;

    while (decoder_available(decoder_p)) {
        switch (decoder_peek_tag_2(decoder_p)) {

        case 1:
            decoder_read_string(decoder_p, 1, &person_p->name_p);
            break;

        case 2:
            person_p->id = decoder_read_varint(decoder_p, 2);
            break;

        case 3:
            decoder_read_string(decoder_p, 3, &person_p->email_p);
            break;

        case 4:
            person_p->phones.length = decoder_peek_repeated_length(decoder_p, 4);
            person_p->phones.items_p = heap_alloc(
                decoder_p->heap_p,
                sizeof(*phone_number_p) * person_p->phones.length);

            for (i = 0; i < person_p->phones.length; i++) {
                length = decoder_read_length_delimited(decoder_p, 4);
                //fprintf(stderr, "repeated length: %llu\n", (unsigned long long)length);
                decoder_init_slice(&decoder, decoder_p, length);
                address_book_person_phone_number_decode_inner(&decoder,
                                                              &person_p->phones.items_p[i]);
                decoder_seek(decoder_p, decoder_get_result(&decoder));
            }
            break;

        default:
            fprintf(stderr, "address_book_person_decode_inner\n");
            exit(1);
            return;
        }
    }
}

void address_book_address_book_encode_inner(
    struct encoder_t *encoder_p,
    struct address_book_address_book_t *address_book_p)
{
    int i;
    int pos;

    for (i = address_book_p->people.length - 1; i >= 0; i--) {
        pos = encoder_pos(encoder_p);
        address_book_person_encode_inner(encoder_p,
                                         &address_book_p->people.items_p[i]);
        encoder_prepend_length_delimited(encoder_p,
                                         1,
                                         pos - encoder_pos(encoder_p));
    }
}

void address_book_address_book_decode_inner(
    struct decoder_t *decoder_p,
    struct address_book_address_book_t *address_book_p)
{
    struct address_book_person_t *person_p;
    uint64_t length;
    struct decoder_t decoder;
    int i;

    address_book_p->people.length = decoder_peek_repeated_length(decoder_p, 1);
    address_book_p->people.items_p = heap_alloc(
        decoder_p->heap_p,
        sizeof(*person_p) * address_book_p->people.length);

    for (i = 0; i < address_book_p->people.length; i++) {
        length = decoder_read_length_delimited(decoder_p, 1);
        //fprintf(stderr, "repeated length: %llu\n", (unsigned long long)length);
        decoder_init_slice(&decoder, decoder_p, length);
        address_book_person_decode_inner(&decoder,
                                         &address_book_p->people.items_p[i]);
        decoder_seek(decoder_p, decoder_get_result(&decoder));
    }
}

int address_book_address_book_encode(
    struct address_book_address_book_t *address_book_p,
    uint8_t *encoded_p,
    size_t size)
{
    struct encoder_t encoder;

    encoder_init(&encoder, encoded_p, size);
    address_book_address_book_encode_inner(&encoder, address_book_p);

    return (encoder_get_result(&encoder));
}

int address_book_address_book_decode(
    struct address_book_address_book_t *address_book_p,
    const uint8_t *encoded_p,
    size_t size)
{
    struct decoder_t decoder;

    decoder_init(&decoder, encoded_p, size, address_book_p->heap_p);
    address_book_address_book_decode_inner(&decoder, address_book_p);

    return (decoder_get_result(&decoder));
}
