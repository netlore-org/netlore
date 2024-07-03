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

#include <netlore/netlore.h>

#include <netlore/ttf/ttf_parser.h>
#include <netlore/ttf/ttf_types.h>
#include <netlore/ttf/ttf_table.h>

#include <netlore/ttf/ttf_cmap.h>

// https://learn.microsoft.com/en-us/typography/opentype/spec/cmap

ttf_u16 be_u16(const ttf_u8* ptr)
{
    return (((ttf_u16)ptr[0]) << 8) | ((ttf_u16)ptr[1]);
}

ttf_table_cmap_t* 
ttf_parse_cmap(ttf_font_t* font, ttf_table_t* table)
{
    ttf_table_cmap_t* cmap_table = (ttf_table_cmap_t*)(font->font_data + table->start_data_table);

    printf("%hu\n", cmap_table->version);
    printf("%hu\n", cmap_table->num_tables);
}