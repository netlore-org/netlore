/*
 * Copyright (c) 2023 Netlore Team
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef __NETLORE_TTF_CMAP
#define __NETLORE_TTF_CMAP

#include <netlore/netlore.h>

#include <netlore/ttf/ttf_parser.h>
#include <netlore/ttf/ttf_types.h>
#include <netlore/ttf/ttf_table.h>

// https://learn.microsoft.com/en-us/typography/opentype/spec/cmap

typedef enum ttf_cmap_platform_id_t {
    TTF_CMAP_PLATFORM_UNICODE,
    TTF_CMAP_PLATFORM_MACINTOSH,
    TTF_CMAP_PLATFORM_ISO,
    TTF_CMAP_PLATFORM_WINDOWS,
    TTF_CMAP_PLATFORM_CUSTOM,
} ttf_cmap_platform_id_t;

typedef struct ttf_cmap_encoding_record_t {
    ttf_u16 platform_id;
    ttf_u16 encoding_id;
    ttf_u32 subtable_offset;
} ttf_cmap_encoding_record_t;

typedef struct ttf_table_cmap_t {
    ttf_u16 version;
    ttf_u16 num_tables;

    ttf_cmap_encoding_record_t encoding_records[num_tables];
} ttf_table_cmap_t;

#endif /* __NETLORE_TTF_CMAP */