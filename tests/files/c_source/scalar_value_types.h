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

#ifndef SCALAR_VALUE_TYPES_H
#define SCALAR_VALUE_TYPES_H

#include "pbtools.h"

/**
 * Message scalar_value_types.Message.
 */
struct scalar_value_types_message_repeated_t {
    int length;
    struct scalar_value_types_message_t **items_pp;
    struct scalar_value_types_message_t *head_p;
    struct scalar_value_types_message_t *tail_p;
};

struct scalar_value_types_message_t {
    struct pbtools_message_base_t base;
    bool v1;
    struct pbtools_bytes_t v2;
    double v3;
    uint32_t v4;
    uint64_t v5;
    float v6;
    int32_t v7;
    int64_t v8;
    int32_t v9;
    int64_t v10;
    int32_t v11;
    int64_t v12;
    struct pbtools_bytes_t v13;
    uint32_t v14;
    uint64_t v15;
};

/**
 * Create a new message Message in given workspace.
 *
 * @param[in] workspace_p Message workspace.
 * @param[in] size Workspace size.
 *
 * @return Initialized address book, or NULL on failure.
 */
struct scalar_value_types_message_t *scalar_value_types_message_new(
    void *workspace_p,
    size_t size);

/**
 * Encode message Message defined in package scalar_value_types.
 *
 * @param[in] self_p Message to encode.
 * @param[out] encoded_p Buffer to encode the message into.
 * @param[in] size Encoded buffer size.
 *
 * @return Encoded data length or negative error code.
 */
int scalar_value_types_message_encode(
    struct scalar_value_types_message_t *self_p,
    uint8_t *encoded_p,
    size_t size);

/**
 * Decode message Message defined in package scalar_value_types.
 *
 * @param[in,out] self_p Initialized message to decode into.
 * @param[in] encoded_p Buffer to decode.
 * @param[in] size Size of the encoded message.
 *
 * @return Number of bytes decoded or negative error code.
 */
int scalar_value_types_message_decode(
    struct scalar_value_types_message_t *self_p,
    const uint8_t *encoded_p,
    size_t size);

#endif
