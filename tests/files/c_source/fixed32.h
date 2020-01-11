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

#ifndef FIXED32_H
#define FIXED32_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pbtools.h"

/**
 * Message fixed32.Message.
 */
struct fixed32_message_repeated_t {
    int length;
    struct fixed32_message_t *items_p;
};

struct fixed32_message_t {
    struct pbtools_message_base_t base;
    uint32_t value;
};

/**
 * Encoding and decoding of fixed32.Message.
 */
struct fixed32_message_t *
fixed32_message_new(
    void *workspace_p,
    size_t size);

int fixed32_message_encode(
    struct fixed32_message_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int fixed32_message_decode(
    struct fixed32_message_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

/* Internal functions. Do not use! */

void fixed32_message_init(
    struct fixed32_message_t *self_p,
    struct pbtools_heap_t *heap_p);

void fixed32_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct fixed32_message_t *self_p);

void fixed32_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct fixed32_message_t *self_p);

void fixed32_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct fixed32_message_repeated_t *repeated_p);

void fixed32_message_decode_repeated_inner(
    struct pbtools_repeated_info_t *repeated_info_p,
    struct pbtools_decoder_t *decoder_p,
    struct fixed32_message_repeated_t *repeated_p);

#ifdef __cplusplus
}
#endif

#endif
