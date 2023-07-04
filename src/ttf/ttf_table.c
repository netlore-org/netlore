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

#include <netlore/ttf/ttf_parser.h>
#include <netlore/ttf/ttf_table.h>

#include <netlore/netlore.h>

ttf_table_t* 
ttf_find_table(ttf_font_t* parser, char* table_name)
{
    for (long int i = 0; i < parser->font_data_len; i++)
    {
        if (parser->font_data[i + 0] == table_name[0] && 
            parser->font_data[i + 1] == table_name[1] &&
            parser->font_data[i + 2] == table_name[2] &&
            parser->font_data[i + 3] == table_name[3])
        {
            ttf_table_t* table = (ttf_table_t*)netlore_calloc(1, sizeof(ttf_table_t));
            table->start_data_table = (void*)parser->font_data + (i - 1) + 4;

            return table;
        }
    }

    return NULL;
}