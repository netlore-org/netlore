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
#include <netlore/netlore_utils.h>
#include <string.h>

char* 
netlore_create_copy_string(const char* str)
{
    char* allocated = netlore_calloc(strlen(str) + 1, sizeof(char));
    memcpy(allocated, str, strlen(str) + 1);

    return allocated;
}

char* 
netlore_gen_spacing(int spacing_amount)
{
    char* spacing = (char*)netlore_calloc((spacing_amount * 4) + 1, sizeof(char));

    for (int i = 0; i < spacing_amount; i++)
        strcat(spacing, "    ");

    return spacing;
}

char*
netlore_append_to_alloc_string(char* str, const char c)
{
    /* Reallocate string with 2 bytes more that there 
     * already is and then append char to the end
     * and end discriminator */
    size_t str_length = (size_t)strlen(str);

    str = (char*)netlore_realloc(str, (str_length + 2) * sizeof(char));
    str[str_length    ] = c;
    str[str_length + 1] = 0;

    return str;
}

char*
netlore_create_string_from_char(const char c)
{
    char buf[2];
    buf[0] = c;
    buf[1] = '\0';

    return netlore_create_copy_string(buf);
}