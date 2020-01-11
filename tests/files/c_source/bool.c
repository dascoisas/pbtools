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

#include <limits.h>
#include "bool.h"

#if CHAR_BIT != 8
#    error "Number of bits in a char must be 8."
#endif

void bool_message_init(
    struct bool_message_t *self_p,
    struct pbtools_heap_t *heap_p)
{
    self_p->base.heap_p = heap_p;
    self_p->value = 0;
}

void bool_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct bool_message_t *self_p)
{
    pbtools_encoder_write_bool(encoder_p, 1, self_p->value);
}

void bool_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct bool_message_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            self_p->value = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

void bool_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct bool_message_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct bool_message_t),
        (pbtools_message_encode_inner_t)bool_message_encode_inner);
}

void bool_message_decode_repeated_inner(
    struct pbtools_repeated_info_t *repeated_info_p,
    struct pbtools_decoder_t *decoder_p,
    struct bool_message_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        repeated_info_p,
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct bool_message_t),
        (pbtools_message_init_t)bool_message_init,
        (pbtools_message_decode_inner_t)bool_message_decode_inner);
}

struct bool_message_t *
bool_message_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct bool_message_t),
                (pbtools_message_init_t)bool_message_init));
}

int bool_message_encode(
    struct bool_message_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)bool_message_encode_inner));
}

int bool_message_decode(
    struct bool_message_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)bool_message_decode_inner));
}
