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

#ifndef MESSAGE_H
#define MESSAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pbtools.h"

/**
 * Message message.Foo.
 */
struct message_foo_repeated_t {
    int length;
    struct message_foo_t *items_p;
};

struct message_foo_t {
    struct pbtools_message_base_t base;
};

/**
 * Message message.Bar.
 */
struct message_bar_repeated_t {
    int length;
    struct message_bar_t *items_p;
};

struct message_bar_t {
    struct pbtools_message_base_t base;
    int32_t fie;
};

/**
 * Enum message.Message.Foo.
 */
enum message_message_foo_e {
    message_message_foo_a_e = 0,
    message_message_foo_b_e = 1
};

/**
 * Message message.Message.Fie.Foo.
 */
struct message_message_fie_foo_repeated_t {
    int length;
    struct message_message_fie_foo_t *items_p;
};

struct message_message_fie_foo_t {
    struct pbtools_message_base_t base;
    bool value;
    struct message_bar_t bar;
};

/**
 * Message message.Message.Fie.
 */
struct message_message_fie_repeated_t {
    int length;
    struct message_message_fie_t *items_p;
};

struct message_message_fie_t {
    struct pbtools_message_base_t base;
    struct message_message_fie_foo_t foo;
};

/**
 * Message message.Message.
 */
struct message_message_repeated_t {
    int length;
    struct message_message_t *items_p;
};

struct message_message_t {
    struct pbtools_message_base_t base;
    enum message_message_foo_e foo;
    struct message_bar_t bar;
    struct message_message_fie_t fie;
};

/**
 * Enum message.UnusedInnerTypes.UnusedEnum.
 */
enum message_unused_inner_types_unused_enum_e {
    message_unused_inner_types_unused_enum_a_e = 0
};

/**
 * Message message.UnusedInnerTypes.UnusedMessage.
 */
struct message_unused_inner_types_unused_message_repeated_t {
    int length;
    struct message_unused_inner_types_unused_message_t *items_p;
};

struct message_unused_inner_types_unused_message_t {
    struct pbtools_message_base_t base;
    bool v1;
};

/**
 * Message message.UnusedInnerTypes.
 */
struct message_unused_inner_types_repeated_t {
    int length;
    struct message_unused_inner_types_t *items_p;
};

struct message_unused_inner_types_t {
    struct pbtools_message_base_t base;
    bool v2;
};

/**
 * Encoding and decoding of message.Foo.
 */
struct message_foo_t *
message_foo_new(
    void *workspace_p,
    size_t size);

int message_foo_encode(
    struct message_foo_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int message_foo_decode(
    struct message_foo_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

/**
 * Encoding and decoding of message.Bar.
 */
struct message_bar_t *
message_bar_new(
    void *workspace_p,
    size_t size);

int message_bar_encode(
    struct message_bar_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int message_bar_decode(
    struct message_bar_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

/**
 * Encoding and decoding of message.Message.
 */
struct message_message_t *
message_message_new(
    void *workspace_p,
    size_t size);

int message_message_encode(
    struct message_message_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int message_message_decode(
    struct message_message_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

/**
 * Encoding and decoding of message.UnusedInnerTypes.
 */
struct message_unused_inner_types_t *
message_unused_inner_types_new(
    void *workspace_p,
    size_t size);

int message_unused_inner_types_encode(
    struct message_unused_inner_types_t *self_p,
    uint8_t *encoded_p,
    size_t size);

int message_unused_inner_types_decode(
    struct message_unused_inner_types_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

/* Internal functions. Do not use! */

void message_foo_init(
    struct message_foo_t *self_p,
    struct pbtools_heap_t *heap_p);

void message_foo_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct message_foo_t *self_p);

void message_foo_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct message_foo_t *self_p);

void message_foo_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct message_foo_repeated_t *repeated_p);

void message_foo_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct pbtools_repeated_info_t *repeated_info_p,
    struct message_foo_repeated_t *repeated_p);

void message_bar_init(
    struct message_bar_t *self_p,
    struct pbtools_heap_t *heap_p);

void message_bar_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct message_bar_t *self_p);

void message_bar_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct message_bar_t *self_p);

void message_bar_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct message_bar_repeated_t *repeated_p);

void message_bar_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct pbtools_repeated_info_t *repeated_info_p,
    struct message_bar_repeated_t *repeated_p);

void message_message_init(
    struct message_message_t *self_p,
    struct pbtools_heap_t *heap_p);

void message_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct message_message_t *self_p);

void message_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct message_message_t *self_p);

void message_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct message_message_repeated_t *repeated_p);

void message_message_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct pbtools_repeated_info_t *repeated_info_p,
    struct message_message_repeated_t *repeated_p);

void message_message_fie_init(
    struct message_message_fie_t *self_p,
    struct pbtools_heap_t *heap_p);

void message_message_fie_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct message_message_fie_t *self_p);

void message_message_fie_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct message_message_fie_t *self_p);

void message_message_fie_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct message_message_fie_repeated_t *repeated_p);

void message_message_fie_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct pbtools_repeated_info_t *repeated_info_p,
    struct message_message_fie_repeated_t *repeated_p);

void message_message_fie_foo_init(
    struct message_message_fie_foo_t *self_p,
    struct pbtools_heap_t *heap_p);

void message_message_fie_foo_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct message_message_fie_foo_t *self_p);

void message_message_fie_foo_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct message_message_fie_foo_t *self_p);

void message_message_fie_foo_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct message_message_fie_foo_repeated_t *repeated_p);

void message_message_fie_foo_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct pbtools_repeated_info_t *repeated_info_p,
    struct message_message_fie_foo_repeated_t *repeated_p);

void message_unused_inner_types_init(
    struct message_unused_inner_types_t *self_p,
    struct pbtools_heap_t *heap_p);

void message_unused_inner_types_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct message_unused_inner_types_t *self_p);

void message_unused_inner_types_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct message_unused_inner_types_t *self_p);

void message_unused_inner_types_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct message_unused_inner_types_repeated_t *repeated_p);

void message_unused_inner_types_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct pbtools_repeated_info_t *repeated_info_p,
    struct message_unused_inner_types_repeated_t *repeated_p);

void message_unused_inner_types_unused_message_init(
    struct message_unused_inner_types_unused_message_t *self_p,
    struct pbtools_heap_t *heap_p);

void message_unused_inner_types_unused_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct message_unused_inner_types_unused_message_t *self_p);

void message_unused_inner_types_unused_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct message_unused_inner_types_unused_message_t *self_p);

void message_unused_inner_types_unused_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct message_unused_inner_types_unused_message_repeated_t *repeated_p);

void message_unused_inner_types_unused_message_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct pbtools_repeated_info_t *repeated_info_p,
    struct message_unused_inner_types_unused_message_repeated_t *repeated_p);

#ifdef __cplusplus
}
#endif

#endif
