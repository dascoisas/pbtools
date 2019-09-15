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

#ifndef IMPORTED2_H
#define IMPORTED2_H

#include "pbtools.h"
#include "imported3.h"
#include "imported1.h"
#include "imported_duplicated_package.h"

/**
 * Enum imported2.foo.bar.Imported2Enum.
 */
enum imported2_foo_bar_imported2_enum_e {
    imported2_foo_bar_imported2_enum_a_e = 0,
    imported2_foo_bar_imported2_enum_b_e = 1
};

/**
 * Message imported2.foo.bar.Imported2Message.
 */
struct imported2_foo_bar_imported2_message_repeated_t {
    int length;
    struct imported2_foo_bar_imported2_message_t **items_pp;
    struct imported2_foo_bar_imported2_message_t *head_p;
    struct imported2_foo_bar_imported2_message_t *tail_p;
};

struct imported2_foo_bar_imported2_message_t {
    struct pbtools_message_base_t base;
    struct imported_imported_duplicated_package_message_t v1;
};

/**
 * Message imported2.foo.bar.Imported3Message.Imported2Message.
 */
struct imported2_foo_bar_imported3_message_imported2_message_repeated_t {
    int length;
    struct imported2_foo_bar_imported3_message_imported2_message_t **items_pp;
    struct imported2_foo_bar_imported3_message_imported2_message_t *head_p;
    struct imported2_foo_bar_imported3_message_imported2_message_t *tail_p;
};

struct imported2_foo_bar_imported3_message_imported2_message_t {
    struct pbtools_message_base_t base;
    struct imported_imported_duplicated_package_message_t v1;
};

/**
 * Message imported2.foo.bar.Imported3Message.
 */
struct imported2_foo_bar_imported3_message_repeated_t {
    int length;
    struct imported2_foo_bar_imported3_message_t **items_pp;
    struct imported2_foo_bar_imported3_message_t *head_p;
    struct imported2_foo_bar_imported3_message_t *tail_p;
};

struct imported2_foo_bar_imported3_message_t {
    struct pbtools_message_base_t base;
    struct imported_imported_duplicated_package_message_t v1;
    struct imported2_foo_bar_imported3_message_imported2_message_t v2;
    struct bar_imported2_message_t v3;
    struct foo_bar_imported2_message_t v4;
    struct imported2_foo_bar_imported2_message_t v5;
    struct imported_imported2_message_t v6;
    struct bar_imported3_message_repeated_t v7;
    struct foo_bar_imported3_message_repeated_t v9;
    struct bar_imported3_message_repeated_t v8;
    struct foo_bar_imported3_message_repeated_t v10;
};

struct imported2_foo_bar_imported2_message_t *
imported2_foo_bar_imported2_message_new(
    void *workspace_p,
    size_t size);

int imported2_foo_bar_imported2_message_encode(
    struct imported2_foo_bar_imported2_message_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int imported2_foo_bar_imported2_message_decode(
    struct imported2_foo_bar_imported2_message_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

int imported2_foo_bar_imported3_message_v7_alloc(
    struct imported2_foo_bar_imported3_message_t *self_p,
    int length);

int imported2_foo_bar_imported3_message_v9_alloc(
    struct imported2_foo_bar_imported3_message_t *self_p,
    int length);

int imported2_foo_bar_imported3_message_v8_alloc(
    struct imported2_foo_bar_imported3_message_t *self_p,
    int length);

int imported2_foo_bar_imported3_message_v10_alloc(
    struct imported2_foo_bar_imported3_message_t *self_p,
    int length);

struct imported2_foo_bar_imported3_message_t *
imported2_foo_bar_imported3_message_new(
    void *workspace_p,
    size_t size);

int imported2_foo_bar_imported3_message_encode(
    struct imported2_foo_bar_imported3_message_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int imported2_foo_bar_imported3_message_decode(
    struct imported2_foo_bar_imported3_message_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

/* Internal functions. Do not use! */

void imported2_foo_bar_imported2_message_init(
    struct imported2_foo_bar_imported2_message_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct imported2_foo_bar_imported2_message_t *next_p);

void imported2_foo_bar_imported2_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct imported2_foo_bar_imported2_message_t *self_p);

void imported2_foo_bar_imported2_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct imported2_foo_bar_imported2_message_t *self_p);

void imported2_foo_bar_imported2_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct imported2_foo_bar_imported2_message_repeated_t *repeated_p);

void imported2_foo_bar_imported2_message_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct imported2_foo_bar_imported2_message_repeated_t *repeated_p);

void imported2_foo_bar_imported2_message_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct imported2_foo_bar_imported2_message_repeated_t *repeated_p);

void imported2_foo_bar_imported3_message_init(
    struct imported2_foo_bar_imported3_message_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct imported2_foo_bar_imported3_message_t *next_p);

void imported2_foo_bar_imported3_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct imported2_foo_bar_imported3_message_t *self_p);

void imported2_foo_bar_imported3_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct imported2_foo_bar_imported3_message_t *self_p);

void imported2_foo_bar_imported3_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct imported2_foo_bar_imported3_message_repeated_t *repeated_p);

void imported2_foo_bar_imported3_message_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct imported2_foo_bar_imported3_message_repeated_t *repeated_p);

void imported2_foo_bar_imported3_message_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct imported2_foo_bar_imported3_message_repeated_t *repeated_p);

void imported2_foo_bar_imported3_message_imported2_message_init(
    struct imported2_foo_bar_imported3_message_imported2_message_t *self_p,
    struct pbtools_heap_t *heap_p,
    struct imported2_foo_bar_imported3_message_imported2_message_t *next_p);

void imported2_foo_bar_imported3_message_imported2_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct imported2_foo_bar_imported3_message_imported2_message_t *self_p);

void imported2_foo_bar_imported3_message_imported2_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct imported2_foo_bar_imported3_message_imported2_message_t *self_p);

void imported2_foo_bar_imported3_message_imported2_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct imported2_foo_bar_imported3_message_imported2_message_repeated_t *repeated_p);

void imported2_foo_bar_imported3_message_imported2_message_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct imported2_foo_bar_imported3_message_imported2_message_repeated_t *repeated_p);

void imported2_foo_bar_imported3_message_imported2_message_finalize_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct imported2_foo_bar_imported3_message_imported2_message_repeated_t *repeated_p);

#endif
