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
 * This file was generated by pbtools.
 */

#include "repeated.h"

static void repeated_message_init(
    struct repeated_message_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct repeated_message_t *next_p);

static void repeated_message_encode_inner(
    struct repeated_message_t *self_p,
    struct pbtools_encoder_t *encoder_p);

static void repeated_message_decode_inner(
    struct repeated_message_t *self_p,
    struct pbtools_decoder_t *decoder_p);

static void repeated_message_init(
    struct repeated_message_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct repeated_message_t *next_p)
{
    self_p->heap_p = heap_p;
    self_p->next_p = next_p;
    self_p->int32s.length = 0;
    self_p->messages.length = 0;
    self_p->strings.length = 0;
    self_p->bytes.length = 0;
}

int repeated_message_int32s_alloc(struct repeated_message_t *self_p,
                                  int length)
{
    return (pbtools_alloc_repeated_int32(&self_p->int32s,
                                         self_p->heap_p,
                                         length));
}

int repeated_message_messages_alloc(
    struct repeated_message_t *self_p,
    int length)
{
    int res;
    int i;
    struct repeated_message_t *items_p;

    res = -1;
    self_p->messages.items_pp = pbtools_heap_alloc(
        self_p->heap_p,
        sizeof(items_p) * length);

    if (self_p->messages.items_pp != NULL) {
        items_p = pbtools_heap_alloc(self_p->heap_p, sizeof(*items_p) * length);

        if (items_p != NULL) {
            for (i = 0; i < length; i++) {
                repeated_message_init(&items_p[i],
                                      self_p->heap_p,
                                      &items_p[i + 1]);
                self_p->messages.items_pp[i] = &items_p[i];
            }

            items_p[length - 1].next_p = NULL;
            self_p->messages.length = length;
            self_p->messages.head_p = &items_p[0];
            self_p->messages.tail_p = &items_p[length - 1];
            res = 0;
        }
    }

    return (res);
}

int repeated_message_strings_alloc(struct repeated_message_t *self_p,
                                   int length)
{
    return (pbtools_alloc_repeated_string(&self_p->strings,
                                          self_p->heap_p,
                                          length));
}

int repeated_message_bytes_alloc(struct repeated_message_t *self_p,
                                 int length)
{
    return (pbtools_alloc_repeated_bytes(&self_p->bytes,
                                         self_p->heap_p,
                                         length));
}

static void repeated_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct repeated_message_repeated_t *repeated_p)
{
    int i;
    int pos;

    for (i = repeated_p->length - 1; i >= 0; i--) {
        pos = encoder_p->pos;
        repeated_message_encode_inner(repeated_p->items_pp[i], encoder_p);
        pbtools_encoder_write_length_delimited(encoder_p,
                                               field_number,
                                               pos - encoder_p->pos);
    }
}

static void repeated_message_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct repeated_message_repeated_t *repeated_p)
{
    size_t size;
    struct pbtools_decoder_t decoder;
    struct repeated_message_t *item_p;

    if (wire_type != PBTOOLS_WIRE_TYPE_LENGTH_DELIMITED) {
        pbtools_decoder_abort(decoder_p, PBTOOLS_BAD_WIRE_TYPE);

        return;
    }

    item_p = pbtools_decoder_heap_alloc(decoder_p, sizeof(*item_p));

    if (item_p == NULL) {
        return;
    }

    size = pbtools_decoder_read_varint(decoder_p);
    repeated_message_init(item_p, decoder_p->heap_p, NULL);
    pbtools_decoder_init_slice(&decoder, decoder_p, size);
    repeated_message_decode_inner(item_p, &decoder);
    pbtools_decoder_seek(decoder_p, pbtools_decoder_get_result(&decoder));
    item_p->next_p = NULL;

    if (repeated_p->length == 0) {
        repeated_p->head_p = item_p;
    } else {
        repeated_p->tail_p->next_p = item_p;
    }

    repeated_p->tail_p = item_p;
    repeated_p->length++;
}

static void repeated_message_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct repeated_message_repeated_t *repeated_p)
{
    int i;
    struct repeated_message_t *item_p;

    if (repeated_p->length == 0) {
        return;
    }

    repeated_p->items_pp = pbtools_decoder_heap_alloc(
        decoder_p,
        sizeof(item_p) * repeated_p->length);

    if (repeated_p->items_pp == NULL) {
        return;
    }

    item_p = repeated_p->head_p;

    for (i = 0; i < repeated_p->length; i++) {
        repeated_p->items_pp[i] = item_p;
        item_p = item_p->next_p;
    }
}

static void repeated_message_encode_inner(
    struct repeated_message_t *self_p,
    struct pbtools_encoder_t *encoder_p)
{
    pbtools_encoder_write_repeated_bytes(encoder_p, 4, &self_p->bytes);
    pbtools_encoder_write_repeated_string(encoder_p, 3, &self_p->strings);
    repeated_message_encode_repeated_inner(encoder_p,
                                           2,
                                           &self_p->messages);
    pbtools_encoder_write_repeated_int32(encoder_p, 1, &self_p->int32s);
}

static void repeated_message_decode_inner(
    struct repeated_message_t *self_p,
    struct pbtools_decoder_t *decoder_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            pbtools_decoder_read_repeated_int32(
                decoder_p,
                wire_type,
                &self_p->int32s);
            break;

        case 2:
            repeated_message_decode_repeated_inner(
                decoder_p,
                wire_type,
                &self_p->messages);
            break;

        case 3:
            pbtools_decoder_read_repeated_string(
                decoder_p,
                wire_type,
                &self_p->strings);
            break;

        case 4:
            pbtools_decoder_read_repeated_bytes(
                decoder_p,
                wire_type,
                &self_p->bytes);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }

    pbtools_decoder_finalize_repeated_int32(decoder_p,
                                            &self_p->int32s);
    repeated_message_finalize_repeated_inner(
        decoder_p,
        &self_p->messages);
    pbtools_decoder_finalize_repeated_string(decoder_p,
                                             &self_p->strings);
    pbtools_decoder_finalize_repeated_bytes(decoder_p,
                                            &self_p->bytes);
}

struct repeated_message_t *repeated_message_new(
    void *workspace_p,
    size_t size)
{
    struct repeated_message_t *self_p;
    struct pbtools_heap_t *heap_p;

    heap_p = pbtools_heap_new(workspace_p, size);

    if (heap_p == NULL) {
        return (NULL);
    }

    self_p = pbtools_heap_alloc(heap_p, sizeof(*self_p));

    if (self_p != NULL) {
        repeated_message_init(self_p, heap_p, NULL);
    }

    return (self_p);
}

int repeated_message_encode(
    struct repeated_message_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    struct pbtools_encoder_t encoder;

    pbtools_encoder_init(&encoder, encoded_p, size);
    repeated_message_encode_inner(self_p, &encoder);

    return (pbtools_encoder_get_result(&encoder));
}

int repeated_message_decode(
    struct repeated_message_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    struct pbtools_decoder_t decoder;

    pbtools_decoder_init(&decoder, encoded_p, size, self_p->heap_p);
    repeated_message_decode_inner(self_p, &decoder);

    return (pbtools_decoder_get_result(&decoder));
}
