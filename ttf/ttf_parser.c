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
#include <netlore/ttf/ttf_table.h>
#include <netlore/ttf/ttf_types.h>

ttf_i32
ttf_read_and_store_file(ttf_font_t* font)
{
    FILE* file = fopen(font->font_path, "r");

    if (file == NULL)
        return -1;

    fseek(file, 0, SEEK_END);
    long int res = ftell(file);
    fseek(file, 0, SEEK_SET);

    font->font_data_len = res;
    font->font_data     = malloc((sizeof(char) * res));

    char curr_char = 0;

    if (font->font_data == NULL)
        return -1;

    for (long int i = 0; i < res; i++) 
    {
        curr_char = fgetc(file);
        font->font_data[i] = curr_char;
    }

    fclose(file);

    return 0;
}

ttf_i32
ttf_is_file_easy_check(ttf_font_t* font)
{
    if (font->font_data[0] == 0 && font->font_data[1] == 1 &&
        font->font_data[2] == 0 && font->font_data[3] == 0)
        return 0;

    NETLORE_ERROR_NO_EXIT("font file named \"%s\" didn't passed easy check", 
            font->font_path);
    return -1;
}

ttf_i32
ttf_read_tables(ttf_font_t* font)
{
    font->table_cmap = ttf_parse_cmap(font, ttf_find_table(font, "cmap"));

    return 0;
}

ttf_font_t* 
ttf_load_font(const char* font_path)
{
    ttf_font_t* font = (ttf_font_t*)calloc(1, sizeof(ttf_font_t));
    font->font_path  = font_path;

    if (ttf_read_and_store_file(font) == -1)
        return NULL;
      
    if (ttf_is_file_easy_check(font) == -1)
        return NULL;

    if (ttf_read_tables(font) == -1)
        return NULL;
}
