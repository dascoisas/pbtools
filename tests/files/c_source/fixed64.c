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
 * This file was generated by pbtools version 0.1.0 Sun Aug 25 22:38:57 2019.
 */

#include <string.h>

#include "fixed64.h"

struct encoder_t {
    uint8_t *buf_p;
    int size;
    int pos;
};

struct decoder_t {
    const uint8_t *buf_p;
    int size;
    int pos;
    struct fixed64_heap_t *heap_p;
};

static struct fixed64_heap_t *heap_new(void *buf_p, size_t size)
{
    struct fixed64_heap_t *heap_p;

    if (size >= sizeof(*heap_p)) {
        heap_p = (struct fixed64_heap_t *)buf_p;
        heap_p->buf_p = buf_p;
        heap_p->size = size;
        heap_p->pos = sizeof(*heap_p);
    } else {
        heap_p = NULL;
    }

    return (heap_p);
}

static void *heap_alloc(struct fixed64_heap_t *self_p, size_t size)
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

static int encoder_get_result(struct encoder_t *self_p)
{
    int length;

    if (self_p->pos >= 0) {
        length = (self_p->size - self_p->pos - 1);
        memmove(self_p->buf_p,
                &self_p->buf_p[self_p->pos + 1],
                length);
    } else {
        length = self_p->pos;
    }

    return (length);
}

static void encoder_abort(struct encoder_t *self_p,
                          int error)
{
    if (self_p->size >= 0) {
        self_p->size = -error;
        self_p->pos = -error;
    }
}

static void encoder_put(struct encoder_t *self_p,
                        uint8_t value)
{
    if (self_p->pos >= 0) {
        self_p->buf_p[self_p->pos] = value;
        self_p->pos--;
    } else {
        encoder_abort(self_p, FIXED64_ENCODE_BUFFER_FULL);
    }
}

static void encoder_write(struct encoder_t *self_p,
                          uint8_t *buf_p,
                          int size)
{
    int i;

    for (i = size - 1; i >= 0; i--) {
        encoder_put(self_p, buf_p[i]);
    }
}

static void encoder_write_tag(struct encoder_t *self_p,
                              int field_number,
                              int wire_type)
{
    uint8_t buf[5];
    int pos;
    uint32_t value;

    value = ((field_number << 3) | wire_type);
    pos = 0;

    while (value > 0) {
        buf[pos++] = (value | 0x80);
        value >>= 7;
    }

    buf[pos - 1] &= 0x7f;
    encoder_write(self_p, &buf[0], pos);
}

static void encoder_write_fixed64(struct encoder_t *self_p,
                                  int field_number,
                                  uint64_t value)
{
    uint8_t buf[8];

    if (value > 0) {
        buf[0] = (value & 0xff);
        buf[1] = ((value >> 8) & 0xff);
        buf[2] = ((value >> 16) & 0xff);
        buf[3] = ((value >> 24) & 0xff);
        buf[4] = ((value >> 32) & 0xff);
        buf[5] = ((value >> 40) & 0xff);
        buf[6] = ((value >> 48) & 0xff);
        buf[7] = ((value >> 56) & 0xff);
        encoder_write(self_p, &buf[0], 8);
        encoder_write_tag(self_p, field_number, 1);
    }
}

static void decoder_init(struct decoder_t *self_p,
                         const uint8_t *buf_p,
                         size_t size,
                         struct fixed64_heap_t *heap_p)
{
    self_p->buf_p = buf_p;
    self_p->size = size;
    self_p->pos = 0;
    self_p->heap_p = heap_p;
}

static int decoder_get_result(struct decoder_t *self_p)
{
    int res;

    if (self_p->pos == self_p->size) {
        res = self_p->pos;
    } else {
        res = -1;
    }

    return (res);
}

static void decoder_abort(struct decoder_t *self_p,
                          int error)
{
    if (self_p->size >= 0) {
        self_p->size = -error;
        self_p->pos = -error;
    }
}

static bool decoder_available(struct decoder_t *self_p)
{
    return (self_p->pos < self_p->size);
}

static uint8_t decoder_get(struct decoder_t *self_p)
{
    uint8_t value;

    if (decoder_available(self_p)) {
        value = self_p->buf_p[self_p->pos];
        self_p->pos++;
    } else {
        decoder_abort(self_p, FIXED64_OUT_OF_DATA);
        value = 0;
    }

    return (value);
}

static uint64_t decoder_read_varint(struct decoder_t *self_p,
                                    int wire_type)
{
    uint64_t value;
    uint8_t byte;
    int offset;

    if (wire_type != 0) {
        decoder_abort(self_p, FIXED64_BAD_WIRE_TYPE);

        return (0);
    }

    value = 0;
    offset = 0;

    do {
        byte = decoder_get(self_p);
        value |= (((uint64_t)byte & 0x7f) << offset);
        offset += 7;
    } while (byte & 0x80);

    return (value);
}

static int decoder_read_tag(struct decoder_t *self_p,
                            int *wire_type_p)
{
    uint32_t value;

    value = decoder_read_varint(self_p, 0);
    *wire_type_p = (value & 0x7);

    return (value >> 3);
}

static uint64_t decoder_read_fixed64(struct decoder_t *self_p,
                                     int wire_type)
{
    uint64_t value;

    value = decoder_get(self_p);
    value |= ((uint64_t)decoder_get(self_p) << 8);
    value |= ((uint64_t)decoder_get(self_p) << 16);
    value |= ((uint64_t)decoder_get(self_p) << 24);
    value |= ((uint64_t)decoder_get(self_p) << 32);
    value |= ((uint64_t)decoder_get(self_p) << 40);
    value |= ((uint64_t)decoder_get(self_p) << 48);
    value |= ((uint64_t)decoder_get(self_p) << 56);

    return (value);
}

static void fixed64_message_encode_inner(
    struct fixed64_message_t *self_p,
    struct encoder_t *encoder_p)
{
    encoder_write_fixed64(encoder_p, 1, self_p->value);
}

static void fixed64_message_decode_inner(
    struct fixed64_message_t *self_p,
    struct decoder_t *decoder_p)
{
    int wire_type;

    while (decoder_available(decoder_p)) {
        switch (decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            self_p->value = decoder_read_fixed64(decoder_p, wire_type);
            break;

        default:
            break;
        }
    }
}

struct fixed64_message_t *fixed64_message_new(
    void *workspace_p,
    size_t size)
{
    struct fixed64_message_t *self_p;
    struct fixed64_heap_t *heap_p;

    heap_p = heap_new(workspace_p, size);

    if (heap_p == NULL) {
        return (NULL);
    }

    self_p = heap_alloc(heap_p, sizeof(*self_p));

    if (self_p != NULL) {
        self_p->heap_p = heap_p;
        self_p->value = 0;
    }

    return (self_p);
}

int fixed64_message_encode(
    struct fixed64_message_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    struct encoder_t encoder;

    encoder_init(&encoder, encoded_p, size);
    fixed64_message_encode_inner(self_p, &encoder);

    return (encoder_get_result(&encoder));
}

int fixed64_message_decode(
    struct fixed64_message_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    struct decoder_t decoder;

    decoder_init(&decoder, encoded_p, size, self_p->heap_p);
    fixed64_message_decode_inner(self_p, &decoder);

    return (decoder_get_result(&decoder));
}
