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
#include "map.h"

#if CHAR_BIT != 8
#    error "Number of bits in a char must be 8."
#endif

void map_value_init(
    struct map_value_t *self_p,
    struct pbtools_heap_t *heap_p)
{
    self_p->base.heap_p = heap_p;
    self_p->v1 = 0;
}

void map_value_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct map_value_t *self_p)
{
    pbtools_encoder_write_bool(encoder_p, 1, self_p->v1);
}

void map_value_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct map_value_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            self_p->v1 = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

void map_value_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct map_value_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_value_t),
        (pbtools_message_encode_inner_t)map_value_encode_inner);
}

void map_value_decode_repeated_inner(
    struct pbtools_repeated_info_t *repeated_info_p,
    struct pbtools_decoder_t *decoder_p,
    struct map_value_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        repeated_info_p,
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_value_t),
        (pbtools_message_init_t)map_value_init,
        (pbtools_message_decode_inner_t)map_value_decode_inner);
}

struct map_value_t *
map_value_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct map_value_t),
                (pbtools_message_init_t)map_value_init));
}

int map_value_encode(
    struct map_value_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)map_value_encode_inner));
}

int map_value_decode(
    struct map_value_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)map_value_decode_inner));
}

void map_message_pbtools_map_map1_init(
    struct map_message_pbtools_map_map1_t *self_p,
    struct pbtools_heap_t *heap_p)
{
    self_p->base.heap_p = heap_p;
    self_p->key_p = "";
    self_p->value = 0;
}

void map_message_pbtools_map_map1_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct map_message_pbtools_map_map1_t *self_p)
{
    pbtools_encoder_write_bool(encoder_p, 2, self_p->value);
    pbtools_encoder_write_string(encoder_p, 1, self_p->key_p);
}

void map_message_pbtools_map_map1_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct map_message_pbtools_map_map1_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            pbtools_decoder_read_string(decoder_p, wire_type, &self_p->key_p);
            break;

        case 2:
            self_p->value = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

void map_message_pbtools_map_map1_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct map_message_pbtools_map_map1_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_message_pbtools_map_map1_t),
        (pbtools_message_encode_inner_t)map_message_pbtools_map_map1_encode_inner);
}

void map_message_pbtools_map_map1_decode_repeated_inner(
    struct pbtools_repeated_info_t *repeated_info_p,
    struct pbtools_decoder_t *decoder_p,
    struct map_message_pbtools_map_map1_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        repeated_info_p,
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_message_pbtools_map_map1_t),
        (pbtools_message_init_t)map_message_pbtools_map_map1_init,
        (pbtools_message_decode_inner_t)map_message_pbtools_map_map1_decode_inner);
}

void map_message_pbtools_map_map2_init(
    struct map_message_pbtools_map_map2_t *self_p,
    struct pbtools_heap_t *heap_p)
{
    self_p->base.heap_p = heap_p;
    self_p->key = 0;
    map_value_init(&self_p->value, heap_p);
}

void map_message_pbtools_map_map2_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct map_message_pbtools_map_map2_t *self_p)
{
    pbtools_encoder_sub_message_encode(
        encoder_p,
        2,
        &self_p->value.base,
        (pbtools_message_encode_inner_t)map_value_encode_inner);
    pbtools_encoder_write_int32(encoder_p, 1, self_p->key);
}

void map_message_pbtools_map_map2_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct map_message_pbtools_map_map2_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            self_p->key = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 2:
            pbtools_decoder_sub_message_decode(
                decoder_p,
                wire_type,
                &self_p->value.base,
                (pbtools_message_decode_inner_t)map_value_decode_inner);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

void map_message_pbtools_map_map2_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct map_message_pbtools_map_map2_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_message_pbtools_map_map2_t),
        (pbtools_message_encode_inner_t)map_message_pbtools_map_map2_encode_inner);
}

void map_message_pbtools_map_map2_decode_repeated_inner(
    struct pbtools_repeated_info_t *repeated_info_p,
    struct pbtools_decoder_t *decoder_p,
    struct map_message_pbtools_map_map2_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        repeated_info_p,
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_message_pbtools_map_map2_t),
        (pbtools_message_init_t)map_message_pbtools_map_map2_init,
        (pbtools_message_decode_inner_t)map_message_pbtools_map_map2_decode_inner);
}

void map_message_pbtools_map_map3_init(
    struct map_message_pbtools_map_map3_t *self_p,
    struct pbtools_heap_t *heap_p)
{
    self_p->base.heap_p = heap_p;
    self_p->key = 0;
    map_value_init(&self_p->value, heap_p);
}

void map_message_pbtools_map_map3_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct map_message_pbtools_map_map3_t *self_p)
{
    pbtools_encoder_sub_message_encode(
        encoder_p,
        2,
        &self_p->value.base,
        (pbtools_message_encode_inner_t)map_value_encode_inner);
    pbtools_encoder_write_int32(encoder_p, 1, self_p->key);
}

void map_message_pbtools_map_map3_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct map_message_pbtools_map_map3_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            self_p->key = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 2:
            pbtools_decoder_sub_message_decode(
                decoder_p,
                wire_type,
                &self_p->value.base,
                (pbtools_message_decode_inner_t)map_value_decode_inner);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

void map_message_pbtools_map_map3_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct map_message_pbtools_map_map3_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_message_pbtools_map_map3_t),
        (pbtools_message_encode_inner_t)map_message_pbtools_map_map3_encode_inner);
}

void map_message_pbtools_map_map3_decode_repeated_inner(
    struct pbtools_repeated_info_t *repeated_info_p,
    struct pbtools_decoder_t *decoder_p,
    struct map_message_pbtools_map_map3_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        repeated_info_p,
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_message_pbtools_map_map3_t),
        (pbtools_message_init_t)map_message_pbtools_map_map3_init,
        (pbtools_message_decode_inner_t)map_message_pbtools_map_map3_decode_inner);
}

void map_message_init(
    struct map_message_t *self_p,
    struct pbtools_heap_t *heap_p)
{
    self_p->base.heap_p = heap_p;
    self_p->map1.length = 0;
    self_p->map2.length = 0;
    self_p->map3.length = 0;
}

void map_message_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct map_message_t *self_p)
{
    map_message_pbtools_map_map3_encode_repeated_inner(
        encoder_p,
        3,
        &self_p->map3);
    map_message_pbtools_map_map2_encode_repeated_inner(
        encoder_p,
        2,
        &self_p->map2);
    map_message_pbtools_map_map1_encode_repeated_inner(
        encoder_p,
        1,
        &self_p->map1);
}

void map_message_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct map_message_t *self_p)
{
    int wire_type;
    struct pbtools_repeated_info_t repeated_info_map1;
    struct pbtools_repeated_info_t repeated_info_map2;
    struct pbtools_repeated_info_t repeated_info_map3;

    pbtools_repeated_info_init(&repeated_info_map1, 1, decoder_p);
    pbtools_repeated_info_init(&repeated_info_map2, 2, decoder_p);
    pbtools_repeated_info_init(&repeated_info_map3, 3, decoder_p);

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            pbtools_repeated_info_decode(&repeated_info_map1,
                                         decoder_p,
                                         wire_type);
            break;

        case 2:
            pbtools_repeated_info_decode(&repeated_info_map2,
                                         decoder_p,
                                         wire_type);
            break;

        case 3:
            pbtools_repeated_info_decode(&repeated_info_map3,
                                         decoder_p,
                                         wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }

    map_message_pbtools_map_map1_decode_repeated_inner(
        &repeated_info_map1,
        decoder_p,
        &self_p->map1);
    map_message_pbtools_map_map2_decode_repeated_inner(
        &repeated_info_map2,
        decoder_p,
        &self_p->map2);
    map_message_pbtools_map_map3_decode_repeated_inner(
        &repeated_info_map3,
        decoder_p,
        &self_p->map3);
}

int map_message_map1_alloc(
    struct map_message_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated(
                (struct pbtools_repeated_message_t *)&self_p->map1,
                length,
                self_p->base.heap_p,
                sizeof(struct map_message_pbtools_map_map1_t),
                (pbtools_message_init_t)map_message_pbtools_map_map1_init));
}

int map_message_map2_alloc(
    struct map_message_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated(
                (struct pbtools_repeated_message_t *)&self_p->map2,
                length,
                self_p->base.heap_p,
                sizeof(struct map_message_pbtools_map_map2_t),
                (pbtools_message_init_t)map_message_pbtools_map_map2_init));
}

int map_message_map3_alloc(
    struct map_message_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated(
                (struct pbtools_repeated_message_t *)&self_p->map3,
                length,
                self_p->base.heap_p,
                sizeof(struct map_message_pbtools_map_map3_t),
                (pbtools_message_init_t)map_message_pbtools_map_map3_init));
}

void map_message_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct map_message_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_message_t),
        (pbtools_message_encode_inner_t)map_message_encode_inner);
}

void map_message_decode_repeated_inner(
    struct pbtools_repeated_info_t *repeated_info_p,
    struct pbtools_decoder_t *decoder_p,
    struct map_message_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        repeated_info_p,
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_message_t),
        (pbtools_message_init_t)map_message_init,
        (pbtools_message_decode_inner_t)map_message_decode_inner);
}

struct map_message_t *
map_message_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct map_message_t),
                (pbtools_message_init_t)map_message_init));
}

int map_message_encode(
    struct map_message_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)map_message_encode_inner));
}

int map_message_decode(
    struct map_message_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)map_message_decode_inner));
}

void map_message2_map1_init(
    struct map_message2_map1_t *self_p,
    struct pbtools_heap_t *heap_p)
{
    self_p->base.heap_p = heap_p;
    self_p->key_p = "";
    self_p->value = 0;
}

void map_message2_map1_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct map_message2_map1_t *self_p)
{
    pbtools_encoder_write_bool(encoder_p, 2, self_p->value);
    pbtools_encoder_write_string(encoder_p, 1, self_p->key_p);
}

void map_message2_map1_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct map_message2_map1_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            pbtools_decoder_read_string(decoder_p, wire_type, &self_p->key_p);
            break;

        case 2:
            self_p->value = pbtools_decoder_read_bool(decoder_p, wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

void map_message2_map1_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct map_message2_map1_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_message2_map1_t),
        (pbtools_message_encode_inner_t)map_message2_map1_encode_inner);
}

void map_message2_map1_decode_repeated_inner(
    struct pbtools_repeated_info_t *repeated_info_p,
    struct pbtools_decoder_t *decoder_p,
    struct map_message2_map1_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        repeated_info_p,
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_message2_map1_t),
        (pbtools_message_init_t)map_message2_map1_init,
        (pbtools_message_decode_inner_t)map_message2_map1_decode_inner);
}

void map_message2_map2_init(
    struct map_message2_map2_t *self_p,
    struct pbtools_heap_t *heap_p)
{
    self_p->base.heap_p = heap_p;
    self_p->key = 0;
    map_value_init(&self_p->value, heap_p);
}

void map_message2_map2_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct map_message2_map2_t *self_p)
{
    pbtools_encoder_sub_message_encode(
        encoder_p,
        2,
        &self_p->value.base,
        (pbtools_message_encode_inner_t)map_value_encode_inner);
    pbtools_encoder_write_int32(encoder_p, 1, self_p->key);
}

void map_message2_map2_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct map_message2_map2_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            self_p->key = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 2:
            pbtools_decoder_sub_message_decode(
                decoder_p,
                wire_type,
                &self_p->value.base,
                (pbtools_message_decode_inner_t)map_value_decode_inner);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

void map_message2_map2_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct map_message2_map2_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_message2_map2_t),
        (pbtools_message_encode_inner_t)map_message2_map2_encode_inner);
}

void map_message2_map2_decode_repeated_inner(
    struct pbtools_repeated_info_t *repeated_info_p,
    struct pbtools_decoder_t *decoder_p,
    struct map_message2_map2_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        repeated_info_p,
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_message2_map2_t),
        (pbtools_message_init_t)map_message2_map2_init,
        (pbtools_message_decode_inner_t)map_message2_map2_decode_inner);
}

void map_message2_map3_init(
    struct map_message2_map3_t *self_p,
    struct pbtools_heap_t *heap_p)
{
    self_p->base.heap_p = heap_p;
    self_p->key = 0;
    map_value_init(&self_p->value, heap_p);
}

void map_message2_map3_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct map_message2_map3_t *self_p)
{
    pbtools_encoder_sub_message_encode(
        encoder_p,
        2,
        &self_p->value.base,
        (pbtools_message_encode_inner_t)map_value_encode_inner);
    pbtools_encoder_write_int32(encoder_p, 1, self_p->key);
}

void map_message2_map3_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct map_message2_map3_t *self_p)
{
    int wire_type;

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            self_p->key = pbtools_decoder_read_int32(decoder_p, wire_type);
            break;

        case 2:
            pbtools_decoder_sub_message_decode(
                decoder_p,
                wire_type,
                &self_p->value.base,
                (pbtools_message_decode_inner_t)map_value_decode_inner);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }
}

void map_message2_map3_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct map_message2_map3_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_message2_map3_t),
        (pbtools_message_encode_inner_t)map_message2_map3_encode_inner);
}

void map_message2_map3_decode_repeated_inner(
    struct pbtools_repeated_info_t *repeated_info_p,
    struct pbtools_decoder_t *decoder_p,
    struct map_message2_map3_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        repeated_info_p,
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_message2_map3_t),
        (pbtools_message_init_t)map_message2_map3_init,
        (pbtools_message_decode_inner_t)map_message2_map3_decode_inner);
}

void map_message2_init(
    struct map_message2_t *self_p,
    struct pbtools_heap_t *heap_p)
{
    self_p->base.heap_p = heap_p;
    self_p->map1.length = 0;
    self_p->map2.length = 0;
    self_p->map3.length = 0;
}

void map_message2_encode_inner(
    struct pbtools_encoder_t *encoder_p,
    struct map_message2_t *self_p)
{
    map_message2_map3_encode_repeated_inner(
        encoder_p,
        3,
        &self_p->map3);
    map_message2_map2_encode_repeated_inner(
        encoder_p,
        2,
        &self_p->map2);
    map_message2_map1_encode_repeated_inner(
        encoder_p,
        1,
        &self_p->map1);
}

void map_message2_decode_inner(
    struct pbtools_decoder_t *decoder_p,
    struct map_message2_t *self_p)
{
    int wire_type;
    struct pbtools_repeated_info_t repeated_info_map1;
    struct pbtools_repeated_info_t repeated_info_map2;
    struct pbtools_repeated_info_t repeated_info_map3;

    pbtools_repeated_info_init(&repeated_info_map1, 1, decoder_p);
    pbtools_repeated_info_init(&repeated_info_map2, 2, decoder_p);
    pbtools_repeated_info_init(&repeated_info_map3, 3, decoder_p);

    while (pbtools_decoder_available(decoder_p)) {
        switch (pbtools_decoder_read_tag(decoder_p, &wire_type)) {

        case 1:
            pbtools_repeated_info_decode(&repeated_info_map1,
                                         decoder_p,
                                         wire_type);
            break;

        case 2:
            pbtools_repeated_info_decode(&repeated_info_map2,
                                         decoder_p,
                                         wire_type);
            break;

        case 3:
            pbtools_repeated_info_decode(&repeated_info_map3,
                                         decoder_p,
                                         wire_type);
            break;

        default:
            pbtools_decoder_skip_field(decoder_p, wire_type);
            break;
        }
    }

    map_message2_map1_decode_repeated_inner(
        &repeated_info_map1,
        decoder_p,
        &self_p->map1);
    map_message2_map2_decode_repeated_inner(
        &repeated_info_map2,
        decoder_p,
        &self_p->map2);
    map_message2_map3_decode_repeated_inner(
        &repeated_info_map3,
        decoder_p,
        &self_p->map3);
}

int map_message2_map1_alloc(
    struct map_message2_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated(
                (struct pbtools_repeated_message_t *)&self_p->map1,
                length,
                self_p->base.heap_p,
                sizeof(struct map_message2_map1_t),
                (pbtools_message_init_t)map_message2_map1_init));
}

int map_message2_map2_alloc(
    struct map_message2_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated(
                (struct pbtools_repeated_message_t *)&self_p->map2,
                length,
                self_p->base.heap_p,
                sizeof(struct map_message2_map2_t),
                (pbtools_message_init_t)map_message2_map2_init));
}

int map_message2_map3_alloc(
    struct map_message2_t *self_p,
    int length)
{
    return (pbtools_alloc_repeated(
                (struct pbtools_repeated_message_t *)&self_p->map3,
                length,
                self_p->base.heap_p,
                sizeof(struct map_message2_map3_t),
                (pbtools_message_init_t)map_message2_map3_init));
}

void map_message2_encode_repeated_inner(
    struct pbtools_encoder_t *encoder_p,
    int field_number,
    struct map_message2_repeated_t *repeated_p)
{
    pbtools_encode_repeated_inner(
        encoder_p,
        field_number,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_message2_t),
        (pbtools_message_encode_inner_t)map_message2_encode_inner);
}

void map_message2_decode_repeated_inner(
    struct pbtools_repeated_info_t *repeated_info_p,
    struct pbtools_decoder_t *decoder_p,
    struct map_message2_repeated_t *repeated_p)
{
    pbtools_decode_repeated_inner(
        repeated_info_p,
        decoder_p,
        (struct pbtools_repeated_message_t *)repeated_p,
        sizeof(struct map_message2_t),
        (pbtools_message_init_t)map_message2_init,
        (pbtools_message_decode_inner_t)map_message2_decode_inner);
}

struct map_message2_t *
map_message2_new(
    void *workspace_p,
    size_t size)
{
    return (pbtools_message_new(
                workspace_p,
                size,
                sizeof(struct map_message2_t),
                (pbtools_message_init_t)map_message2_init));
}

int map_message2_encode(
    struct map_message2_t *self_p,
    uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_encode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_encode_inner_t)map_message2_encode_inner));
}

int map_message2_decode(
    struct map_message2_t *self_p,
    const uint8_t *encoded_p,
    size_t size)
{
    return (pbtools_message_decode(
                &self_p->base,
                encoded_p,
                size,
                (pbtools_message_decode_inner_t)map_message2_decode_inner));
}
