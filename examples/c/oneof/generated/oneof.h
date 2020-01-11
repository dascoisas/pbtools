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

#ifndef ONEOF_H
#define ONEOF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pbtools.h"

/**
 * Enum oneof.Foo.bar.
 */
enum oneof_foo_bar_choice_e {
    oneof_foo_bar_choice_none_e = 0,
    oneof_foo_bar_choice_fie_e = 1,
    oneof_foo_bar_choice_fum_e = 2
};

/**
 * Oneof oneof.Foo.bar.
 */
struct oneof_foo_bar_oneof_t {
    enum oneof_foo_bar_choice_e choice;
    union {
        int32_t fie;
        bool fum;
    } value;
};

/**
 * Message oneof.Foo.
 */
struct oneof_foo_repeated_t {
    int length;
    struct oneof_foo_t *items_p;
};

struct oneof_foo_t {
    struct pbtools_message_base_t base;
    struct oneof_foo_bar_oneof_t bar;
};

void oneof_foo_bar_fie_init(
    struct oneof_foo_t *self_p);

void oneof_foo_bar_fum_init(
    struct oneof_foo_t *self_p);

/**
 * Encoding and decoding of oneof.Foo.
 */
struct oneof_foo_t *
oneof_foo_new(
    void *workspace_p,
    size_t size);

int oneof_foo_encode(
    struct oneof_foo_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int oneof_foo_decode(
    struct oneof_foo_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

/* Internal functions. Do not use! */

void oneof_foo_init(
    struct oneof_foo_t *self_p,
    struct pbtools_heap_t *heap_p);

void oneof_foo_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct oneof_foo_t *self_p);

void oneof_foo_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct oneof_foo_t *self_p);

void oneof_foo_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct oneof_foo_repeated_t *repeated_p);

void oneof_foo_decode_repeated_inner(
    struct pbtools_repeated_info_t *repeated_info_p,
    struct pbtools_decoder_t *decoder_p,
    struct oneof_foo_repeated_t *repeated_p);

#ifdef __cplusplus
}
#endif

#endif
