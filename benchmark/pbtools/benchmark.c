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
#include "benchmark.h"

#if CHAR_BIT != 8
#    error "Number of bits in a char must be 8."
#endif

void benchmark_sub_message_init(
    struct benchmark_sub_message_t *self_p,
    struct pbtools_heap_t *heap_p)
{
    self_p->base.heap_p = heap_p;
    self_p->field1 = 0;
    self_p->field2 = 0;
    self_p->field3 = 0;
    self_p->field15_p = "";
    pbtools_bytes_init(&self_p->field12);
    self_p->field13 = 0;
    self_p->field14 = 0;
    self_p->field21 = 0;
    self_p->field22 = 0;
    self_p->field206 = 0;
    self_p->field203 = 0;
    self_p->field204 = 0;
    self_p->field205_p = "";
    self_p->field207 = 0;
    self_p->field300 = 0;
}

void benchmark_sub_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct benchmark_sub_message_t *self_p)
{
    pbtools_encoder_write_enum(encoder_p, 300, self_p->field300);
    pbtools_encoder_write_uint64(encoder_p, 207, self_p->field207);
    pbtools_encoder_write_string(encoder_p, 205, self_p->field205_p);
    pbtools_encoder_write_int32(encoder_p, 204, self_p->field204);
    pbtools_encoder_write_fixed32(encoder_p, 203, self_p->field203);
    pbtools_encoder_write_bool(encoder_p, 206, self_p->field206);
    pbtools_encoder_write_int32(encoder_p, 22, self_p->field22);
    pbtools_encoder_write_fixed64(encoder_p, 21, self_p->field21);
    pbtools_encoder_write_int64(encoder_p, 14, self_p->field14);
    pbtools_encoder_write_int64(encoder_p, 13, self_p->field13);
    pbtools_encoder_write_bytes(encoder_p, 12, &self_p->field12);
    pbtools_encoder_write_string(encoder_p, 15, self_p->field15_p);
    pbtools_encoder_write_int32(encoder_p, 3, self_p->field3);
    pbtools_encoder_write_uint32(encoder_p, 2, self_p->field2);
    pbtools_encoder_write_uint32(encoder_p, 1, self_p->field1);
}

void benchmark_sub_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_sub_message_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            self_p->field1 = pbtools_decoder_read_uint32(decoder_p, wire_type);
            break;

        case 2:
            self_p->field2 = pbtools_decoder_read_uint32(decoder_p, wire_type);
            break;

        case 3:
            self_p->field3 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 15:
            pbtools_decoder_read_string(decoder_p, wire_type, &self_p->field15_p);
            break;

        case 12:
            pbtools_decoder_read_bytes(decoder_p, wire_type, &self_p->field12);
            break;

        case 13:
            self_p->field13 = pbtools_decoder_read_int64(decoder_p, wire_type);
            break;

        case 14:
            self_p->field14 = pbtools_decoder_read_int64(decoder_p, wire_type);
            break;

        case 21:
            self_p->field21 = pbtools_decoder_read_fixed64(decoder_p, wire_type);
            break;

        case 22:
            self_p->field22 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 206:
            self_p->field206 = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        case 203:
            self_p->field203 = pbtools_decoder_read_fixed32(decoder_p, wire_type);
            break;

        case 204:
            self_p->field204 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 205:
            pbtools_decoder_read_string(decoder_p, wire_type, &self_p->field205_p);
            break;

        case 207:
            self_p->field207 = pbtools_decoder_read_uint64(decoder_p, wire_type);
            break;

        case 300:
            self_p->field300 = pbtools_decoder_read_enum(decoder_p, wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

void benchmark_sub_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct benchmark_sub_message_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct benchmark_sub_message_t),
        (pbtools_message_encode_inner_t)benchmark_sub_message_encode_inner);
}

void benchmark_sub_message_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct pbtools_repeated_info_t *repeated_info_p,
    struct benchmark_sub_message_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        repeated_info_p,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct benchmark_sub_message_t),
        (pbtools_message_init_t)benchmark_sub_message_init,
        (pbtools_message_decode_inner_t)benchmark_sub_message_decode_inner);
}

struct benchmark_sub_message_t *
benchmark_sub_message_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct benchmark_sub_message_t),
                (pbtools_message_init_t)benchmark_sub_message_init));
}

int benchmark_sub_message_encode(
    struct benchmark_sub_message_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)benchmark_sub_message_encode_inner));
}

int benchmark_sub_message_decode(
    struct benchmark_sub_message_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)benchmark_sub_message_decode_inner));
}

void benchmark_message1_init(
    struct benchmark_message1_t *self_p,
    struct pbtools_heap_t *heap_p)
{
    self_p->base.heap_p = heap_p;
    self_p->field80 = 0;
    self_p->field81 = 0;
    self_p->field2 = 0;
    self_p->field3 = 0;
    self_p->field280 = 0;
    self_p->field6 = 0;
    self_p->field22 = 0;
    self_p->field4.length = 0;
    self_p->field59 = 0;
    self_p->field16 = 0;
    self_p->field150 = 0;
    self_p->field23 = 0;
    self_p->field24 = 0;
    self_p->field25 = 0;
    benchmark_sub_message_init(&self_p->field15, heap_p);
    self_p->field78 = 0;
    self_p->field67 = 0;
    self_p->field68 = 0;
    self_p->field128 = 0;
    self_p->field129_p = "";
    self_p->field131 = 0;
}

void benchmark_message1_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct benchmark_message1_t *self_p)
{
    pbtools_encoder_write_int32(encoder_p, 131, self_p->field131);
    pbtools_encoder_write_string(encoder_p, 129, self_p->field129_p);
    pbtools_encoder_write_int32(encoder_p, 128, self_p->field128);
    pbtools_encoder_write_int32(encoder_p, 68, self_p->field68);
    pbtools_encoder_write_int32(encoder_p, 67, self_p->field67);
    pbtools_encoder_write_bool(encoder_p, 78, self_p->field78);
    pbtools_encoder_sub_message_encode(
        encoder_p,
        15,
        &self_p->field15.base,
        (pbtools_message_encode_inner_t)benchmark_sub_message_encode_inner);
    pbtools_encoder_write_int32(encoder_p, 25, self_p->field25);
    pbtools_encoder_write_bool(encoder_p, 24, self_p->field24);
    pbtools_encoder_write_int32(encoder_p, 23, self_p->field23);
    pbtools_encoder_write_int32(encoder_p, 150, self_p->field150);
    pbtools_encoder_write_int32(encoder_p, 16, self_p->field16);
    pbtools_encoder_write_bool(encoder_p, 59, self_p->field59);
    pbtools_encoder_write_repeated_string(encoder_p, 4, &self_p->field4);
    pbtools_encoder_write_int64(encoder_p, 22, self_p->field22);
    pbtools_encoder_write_int32(encoder_p, 6, self_p->field6);
    pbtools_encoder_write_int32(encoder_p, 280, self_p->field280);
    pbtools_encoder_write_int32(encoder_p, 3, self_p->field3);
    pbtools_encoder_write_int32(encoder_p, 2, self_p->field2);
    pbtools_encoder_write_bool(encoder_p, 81, self_p->field81);
    pbtools_encoder_write_bool(encoder_p, 80, self_p->field80);
}

void benchmark_message1_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_message1_t *self_p)
{
    int wire_type;
    struct pbtools_repeated_info_t repeated_info_field4;

    pbtools_repeated_info_init(&repeated_info_field4, 4);

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 80:
            self_p->field80 = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        case 81:
            self_p->field81 = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        case 2:
            self_p->field2 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 3:
            self_p->field3 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 280:
            self_p->field280 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 6:
            self_p->field6 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 22:
            self_p->field22 = pbtools_decoder_read_int64(decoder_p, wire_type);
            break;

        case 4:
            pbtools_repeated_info_decode_string(
                &repeated_info_field4,
                decoder_p,
                wire_type);
            break;

        case 59:
            self_p->field59 = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        case 16:
            self_p->field16 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 150:
            self_p->field150 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 23:
            self_p->field23 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 24:
            self_p->field24 = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        case 25:
            self_p->field25 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 15:
            pbtools_decoder_sub_message_decode(
                decoder_p,
                wire_type,
                &self_p->field15.base,
                (pbtools_message_decode_inner_t)benchmark_sub_message_decode_inner);
            break;

        case 78:
            self_p->field78 = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        case 67:
            self_p->field67 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 68:
            self_p->field68 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 128:
            self_p->field128 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 129:
            pbtools_decoder_read_string(decoder_p, wire_type, &self_p->field129_p);
            break;

        case 131:
            self_p->field131 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }

    pbtools_decoder_decode_repeated_string(
        decoder_p,
        &repeated_info_field4,
        &self_p->field4);
}

int benchmark_message1_field4_alloc(
    struct benchmark_message1_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated_string(
                &self_p->base,
                length,
                &self_p->field4));
}

void benchmark_message1_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct benchmark_message1_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct benchmark_message1_t),
        (pbtools_message_encode_inner_t)benchmark_message1_encode_inner);
}

void benchmark_message1_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct pbtools_repeated_info_t *repeated_info_p,
    struct benchmark_message1_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        repeated_info_p,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct benchmark_message1_t),
        (pbtools_message_init_t)benchmark_message1_init,
        (pbtools_message_decode_inner_t)benchmark_message1_decode_inner);
}

struct benchmark_message1_t *
benchmark_message1_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct benchmark_message1_t),
                (pbtools_message_init_t)benchmark_message1_init));
}

int benchmark_message1_encode(
    struct benchmark_message1_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)benchmark_message1_encode_inner));
}

int benchmark_message1_decode(
    struct benchmark_message1_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)benchmark_message1_decode_inner));
}

void benchmark_message2_init(
    struct benchmark_message2_t *self_p,
    struct pbtools_heap_t *heap_p)
{
    self_p->base.heap_p = heap_p;
    self_p->field1 = 0;
    self_p->field2 = 0;
    self_p->field3 = 0;
    self_p->field4_p = "";
    self_p->field5 = 0;
    self_p->field6 = 0;
}

void benchmark_message2_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct benchmark_message2_t *self_p)
{
    pbtools_encoder_write_bool(encoder_p, 6, self_p->field6);
    pbtools_encoder_write_int32(encoder_p, 5, self_p->field5);
    pbtools_encoder_write_string(encoder_p, 4, self_p->field4_p);
    pbtools_encoder_write_sint32(encoder_p, 3, self_p->field3);
    pbtools_encoder_write_uint64(encoder_p, 2, self_p->field2);
    pbtools_encoder_write_enum(encoder_p, 1, self_p->field1);
}

void benchmark_message2_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_message2_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            self_p->field1 = pbtools_decoder_read_enum(decoder_p, wire_type);
            break;

        case 2:
            self_p->field2 = pbtools_decoder_read_uint64(decoder_p, wire_type);
            break;

        case 3:
            self_p->field3 = pbtools_decoder_read_sint32(decoder_p, wire_type);
            break;

        case 4:
            pbtools_decoder_read_string(decoder_p, wire_type, &self_p->field4_p);
            break;

        case 5:
            self_p->field5 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 6:
            self_p->field6 = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

void benchmark_message2_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct benchmark_message2_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct benchmark_message2_t),
        (pbtools_message_encode_inner_t)benchmark_message2_encode_inner);
}

void benchmark_message2_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct pbtools_repeated_info_t *repeated_info_p,
    struct benchmark_message2_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        repeated_info_p,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct benchmark_message2_t),
        (pbtools_message_init_t)benchmark_message2_init,
        (pbtools_message_decode_inner_t)benchmark_message2_decode_inner);
}

struct benchmark_message2_t *
benchmark_message2_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct benchmark_message2_t),
                (pbtools_message_init_t)benchmark_message2_init));
}

int benchmark_message2_encode(
    struct benchmark_message2_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)benchmark_message2_encode_inner));
}

int benchmark_message2_decode(
    struct benchmark_message2_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)benchmark_message2_decode_inner));
}

void benchmark_message3_sub_message_init(
    struct benchmark_message3_sub_message_t *self_p,
    struct pbtools_heap_t *heap_p)
{
    self_p->base.heap_p = heap_p;
    self_p->field28 = 0;
    self_p->field2 = 0;
    self_p->field12 = 0;
    self_p->field19_p = "";
    self_p->field11 = 0;
}

void benchmark_message3_sub_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct benchmark_message3_sub_message_t *self_p)
{
    pbtools_encoder_write_int32(encoder_p, 11, self_p->field11);
    pbtools_encoder_write_string(encoder_p, 19, self_p->field19_p);
    pbtools_encoder_write_int32(encoder_p, 12, self_p->field12);
    pbtools_encoder_write_int64(encoder_p, 2, self_p->field2);
    pbtools_encoder_write_int32(encoder_p, 28, self_p->field28);
}

void benchmark_message3_sub_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_message3_sub_message_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 28:
            self_p->field28 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 2:
            self_p->field2 = pbtools_decoder_read_int64(decoder_p, wire_type);
            break;

        case 12:
            self_p->field12 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 19:
            pbtools_decoder_read_string(decoder_p, wire_type, &self_p->field19_p);
            break;

        case 11:
            self_p->field11 = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

void benchmark_message3_sub_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct benchmark_message3_sub_message_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct benchmark_message3_sub_message_t),
        (pbtools_message_encode_inner_t)benchmark_message3_sub_message_encode_inner);
}

void benchmark_message3_sub_message_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct pbtools_repeated_info_t *repeated_info_p,
    struct benchmark_message3_sub_message_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        repeated_info_p,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct benchmark_message3_sub_message_t),
        (pbtools_message_init_t)benchmark_message3_sub_message_init,
        (pbtools_message_decode_inner_t)benchmark_message3_sub_message_decode_inner);
}

void benchmark_message3_init(
    struct benchmark_message3_t *self_p,
    struct pbtools_heap_t *heap_p)
{
    self_p->base.heap_p = heap_p;
    self_p->field13.length = 0;
}

void benchmark_message3_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct benchmark_message3_t *self_p)
{
    benchmark_message3_sub_message_encode_repeated_inner(
        encoder_p,
        13,
        &self_p->field13);
}

void benchmark_message3_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_message3_t *self_p)
{
    int wire_type;
    struct pbtools_repeated_info_t repeated_info_field13;

    pbtools_repeated_info_init(&repeated_info_field13, 13);

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 13:
            pbtools_repeated_info_decode(&repeated_info_field13,
                                         decoder_p,
                                         wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }

    benchmark_message3_sub_message_decode_repeated_inner(
        decoder_p,
        &repeated_info_field13,
        &self_p->field13);
}

int benchmark_message3_field13_alloc(
    struct benchmark_message3_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated(
                (struct pbtools_repeated_message_t *)&self_p->field13,
                length,
                self_p->base.heap_p,
                sizeof(struct benchmark_message3_sub_message_t),
                (pbtools_message_init_t)benchmark_message3_sub_message_init));
}

void benchmark_message3_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct benchmark_message3_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct benchmark_message3_t),
        (pbtools_message_encode_inner_t)benchmark_message3_encode_inner);
}

void benchmark_message3_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct pbtools_repeated_info_t *repeated_info_p,
    struct benchmark_message3_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        repeated_info_p,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct benchmark_message3_t),
        (pbtools_message_init_t)benchmark_message3_init,
        (pbtools_message_decode_inner_t)benchmark_message3_decode_inner);
}

struct benchmark_message3_t *
benchmark_message3_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct benchmark_message3_t),
                (pbtools_message_init_t)benchmark_message3_init));
}

int benchmark_message3_encode(
    struct benchmark_message3_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)benchmark_message3_encode_inner));
}

int benchmark_message3_decode(
    struct benchmark_message3_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)benchmark_message3_decode_inner));
}

void benchmark_message_oneof_message1_init(
    struct benchmark_message_t *self_p)
{
    self_p->oneof.choice = benchmark_message_oneof_choice_message1_e;
    benchmark_message1_init(
        &self_p->oneof.value.message1,
        self_p->base.heap_p);
}

void benchmark_message_oneof_message2_init(
    struct benchmark_message_t *self_p)
{
    self_p->oneof.choice = benchmark_message_oneof_choice_message2_e;
    benchmark_message2_init(
        &self_p->oneof.value.message2,
        self_p->base.heap_p);
}

void benchmark_message_oneof_message3_init(
    struct benchmark_message_t *self_p)
{
    self_p->oneof.choice = benchmark_message_oneof_choice_message3_e;
    benchmark_message3_init(
        &self_p->oneof.value.message3,
        self_p->base.heap_p);
}

void benchmark_message_oneof_encode(
    struct pbtools_encoder_t *encoder_p,
    struct benchmark_message_oneof_oneof_t *self_p)
{
    switch (self_p->choice) {

    case benchmark_message_oneof_choice_message1_e:
        pbtools_encoder_sub_message_encode(
            encoder_p,
            1,
            &self_p->value.message1.base,
            (pbtools_message_encode_inner_t)benchmark_message1_encode_inner);
        break;

    case benchmark_message_oneof_choice_message2_e:
        pbtools_encoder_sub_message_encode(
            encoder_p,
            2,
            &self_p->value.message2.base,
            (pbtools_message_encode_inner_t)benchmark_message2_encode_inner);
        break;

    case benchmark_message_oneof_choice_message3_e:
        pbtools_encoder_sub_message_encode(
            encoder_p,
            7,
            &self_p->value.message3.base,
            (pbtools_message_encode_inner_t)benchmark_message3_encode_inner);
        break;

    default:
        break;
    }
}

static void benchmark_message_oneof_message1_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct benchmark_message_t *self_p)
{
    benchmark_message_oneof_message1_init(self_p);
    pbtools_decoder_sub_message_decode(
        decoder_p,
        wire_type,
        &self_p->oneof.value.message1.base,
        (pbtools_message_decode_inner_t)benchmark_message1_decode_inner);
}

static void benchmark_message_oneof_message2_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct benchmark_message_t *self_p)
{
    benchmark_message_oneof_message2_init(self_p);
    pbtools_decoder_sub_message_decode(
        decoder_p,
        wire_type,
        &self_p->oneof.value.message2.base,
        (pbtools_message_decode_inner_t)benchmark_message2_decode_inner);
}

static void benchmark_message_oneof_message3_decode(
    struct pbtools_decoder_t *decoder_p,
    int wire_type,
    struct benchmark_message_t *self_p)
{
    benchmark_message_oneof_message3_init(self_p);
    pbtools_decoder_sub_message_decode(
        decoder_p,
        wire_type,
        &self_p->oneof.value.message3.base,
        (pbtools_message_decode_inner_t)benchmark_message3_decode_inner);
}

void benchmark_message_init(
    struct benchmark_message_t *self_p,
    struct pbtools_heap_t *heap_p)
{
    self_p->base.heap_p = heap_p;
    self_p->oneof.choice = 0;
}

void benchmark_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct benchmark_message_t *self_p)
{
    benchmark_message_oneof_encode(encoder_p, &self_p->oneof);
}

void benchmark_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct benchmark_message_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            benchmark_message_oneof_message1_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        case 2:
            benchmark_message_oneof_message2_decode(
                decoder_p,
                wire_type,
                self_p);
            break;

        case 7:
            benchmark_message_oneof_message3_decode(
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

void benchmark_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct benchmark_message_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct benchmark_message_t),
        (pbtools_message_encode_inner_t)benchmark_message_encode_inner);
}

void benchmark_message_decode_repeated_inner(
    struct pbtools_decoder_t *decoder_p,
    struct pbtools_repeated_info_t *repeated_info_p,
    struct benchmark_message_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        decoder_p,
        repeated_info_p,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct benchmark_message_t),
        (pbtools_message_init_t)benchmark_message_init,
        (pbtools_message_decode_inner_t)benchmark_message_decode_inner);
}

struct benchmark_message_t *
benchmark_message_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct benchmark_message_t),
                (pbtools_message_init_t)benchmark_message_init));
}

int benchmark_message_encode(
    struct benchmark_message_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)benchmark_message_encode_inner));
}

int benchmark_message_decode(
    struct benchmark_message_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)benchmark_message_decode_inner));
}
