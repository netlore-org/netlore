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

/*
 * This code is part of Heimdall (UI & Window Manager)
 * Component of Netlore project that can be found at 
 * the github repository at:
 *  - https://github.com/netlore-org/netlore
 */

#include <netlore/netlore.h>

#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/heimdall/heimdall_utils.h>
#include <netlore/bolly/heimdall/heimdall_fm.h>

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

/* This macro calculates the fonts length, so if
 * max_size would be 100 the font range there
 * would be 97 fonts from 3 to 100 size */
#define REMOVE_FIRST_SIZES (3)

/* Some important font manager variables that
 * can be get by functions like 
 *  - `heimdall_fm_get_font_name`
 *  - `heimdall_fm_get_max_size_font` */
static const char* default_font;
static TTF_Font**  fonts;

static int max_size;
static int fonts_len;

void 
heimdall_open_fonts()
{
    for (int i = 0; i < fonts_len; i++)
    {
        fonts[i] = TTF_OpenFont(default_font, i + REMOVE_FIRST_SIZES);

        if (fonts[i] == NULL)
            NETLORE_ERROR("couldn't open font at \"%s\" with size of %d",
                          default_font, i + REMOVE_FIRST_SIZES);
    }

    NETLORE_DEBUG("successfully loaded all fonts");
}

void 
heimdall_init_font_manager(const char* __default_font, int __max_size)
{
    /* Set these variables so they can be globally
     * used */
    max_size   = __max_size;
    fonts_len  = __max_size - REMOVE_FIRST_SIZES;

    default_font = __default_font;
    fonts        = (TTF_Font**)
                        netlore_calloc(fonts_len, sizeof(TTF_Font*));

    heimdall_open_fonts();    
}

const char*
heimdall_fm_get_font_name()
{
    return default_font;
}

int
heimdall_fm_get_max_size_font()
{
    return max_size;
}

void heimdall_clean_up_fonts();
TTF_Font* 
heimdall_get_default_font(int size)
{
    if (size > max_size)
    {
        NETLORE_ERROR_NO_EXIT("couldn't find font with size: %d", size);
        return NULL;
    }

    return fonts[size - REMOVE_FIRST_SIZES];
}

void 
heimdall_clean_up_fonts()
{
    for (int i = 0; i < fonts_len; i++)
        TTF_CloseFont(fonts[i]);

    NETLORE_DEBUG("closed all fonts that was in use");
}
