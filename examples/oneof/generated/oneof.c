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
#include "oneof.h"

#if CHAR_BIT != 8
#    error "Number of bits in a char must be 8."
#endif

void oneof_foo_bar_fie_init(
    struct oneof_foo_t *self_p)
{
    self_p->bar.choice = oneof_foo_bar_choice_fie_e;
    self_p->bar.value.fie = 0;
}

void oneof_foo_bar_fum_init(
    struct oneof_foo_t *self_p)
{
    self_p->bar.choice = oneof_foo_bar_choice_fum_e;
    self_p->bar.value.fum = 0;
}

void oneof_foo_bar_encode(
    struct pbtools_encoder_t *encoder_p,
    struct oneof_foo_bar_oneof_t *self_p)
{
    switch (self_p->choice) {

    case oneof_foo_bar_choice_fie_e:
        pbtools_encoder_write_int32(
            encoder_p,
            1,
            self_p->value.fie);
        break;

    case oneof_foo_bar_choice_fum_e:
        pbtools_encoder_write_bool(
            encoder_p,
            2,
            self_p->value.fum);
        break;

    default:
        break;
    }
}

static void oneof_foo_bar_fie_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_foo_t *self_p)
{
    oneof_foo_bar_fie_init(self_p);
    self_p->bar.value.fie = pbtools_decoder_read_int32(
        decoder_p,
        wire_type);
}

static void oneof_foo_bar_fum_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_foo_t *self_p)
{
    oneof_foo_bar_fum_init(self_p);
    self_p->bar.value.fum = pbtools_decoder_read_bool(
        decoder_p,
        wire_type);
}

void oneof_foo_init(
    struct oneof_foo_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct oneof_foo_t *next_p)
{
    self_p->base.heap_p = heap_p;
    self_p->base.next_p = &next_p->base;
    self_p->bar.choice = 0;
}

void oneof_foo_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct oneof_foo_t *self_p)
{
    oneof_foo_bar_encode(encoder_p, &self_p->bar);
}

void oneof_foo_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct oneof_foo_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            oneof_foo_bar_fie_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        case 2:
            oneof_foo_bar_fum_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

void oneof_foo_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct oneof_foo_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        (pbtools_message_encode_inner_t)oneof_foo_encode_inner);
}

void oneof_foo_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct oneof_foo_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        wire_type,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct oneof_foo_t),
        (pbtools_message_init_t)oneof_foo_init,
        (pbtools_message_decode_inner_t)oneof_foo_decode_inner);
}

void oneof_foo_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct oneof_foo_repeated_t *repeated_p)
{
    pbtools_finalize_repeated_inner(
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p);
}

struct oneof_foo_t *
oneof_foo_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct oneof_foo_t),
                (pbtools_message_init_t)oneof_foo_init));
}

int oneof_foo_encode(
    struct oneof_foo_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)oneof_foo_encode_inner));
}

int oneof_foo_decode(
    struct oneof_foo_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)oneof_foo_decode_inner));
}
