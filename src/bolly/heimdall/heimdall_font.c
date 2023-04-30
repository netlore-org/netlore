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

#include <SDL2/SDL_pixels.h>
#include <netlore/netlore.h>

#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/heimdall/heimdall_utils.h>
#include <netlore/bolly/heimdall/heimdall_font.h>
#include <netlore/bolly/heimdall/heimdall_fm.h>

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

#include <stdarg.h>
#include <string.h>

/* This macro defines the buffer size, so the
 * fmt argument can be bigger than 20kB */
#define BUFFER_SIZE (1024 * 20)

/* Used for vsprintf function so we can
 * parse the va_list */
static char buffer[BUFFER_SIZE];

/* Rendering the font in memory and getting the
 * texture size */
size2_t 
heimdall_size_render_font(window_t* window, int size, 
                          vec2_t pos, const char* fmt)
{
    /* Create text texture in which all pixels are
     * saved */
    SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(heimdall_get_default_font(size), fmt, 
                                                          (SDL_Color){255, 255, 255, 255}, heimdall_window_get_size(window).w - 10);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(window->sdl_renderer, surface);

    /* Get texture size so we can use it later */
    size2_t font_size = heimdall_create_size2(0, 0);
    SDL_QueryTexture(texture, NULL, NULL, 
                     &font_size.w, &font_size.h);

    /* Clean up.. */
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

    return font_size;
}

size2_t 
heimdall_size_render_fontf(window_t* window, int size, 
                           vec2_t pos, const char* fmt, ...)
{
    va_list list;
    va_start(list, fmt);

    vsprintf(buffer, fmt, list);
    size2_t __size = heimdall_size_render_font(window, size, pos, buffer);

    memset(buffer, 0, BUFFER_SIZE);
    va_end(list);
    return __size;
}

/* Rendering the font on screen */
size2_t 
heimdall_render_font(window_t* window, int size, color_t color,
                     vec2_t pos, const char* fmt)
{
    /* Create text texture in which all pixels are
     * saved */
    SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(heimdall_get_default_font(size), fmt, 
                                                          heimdall_color_to_sdl(color), heimdall_window_get_size(window).w - 10);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(window->sdl_renderer, surface);

    /* Get texture size so we can use it later*/
    size2_t font_size = heimdall_create_size2(0, 0);
    SDL_QueryTexture(texture, NULL, NULL, 
                     &font_size.w, &font_size.h);

    /* Create SDL_Rect which gives the font size and position information
     * to render mechanism so it can be putted on the screen */
    SDL_Rect rect = { 
        .x = pos.x,       .y = pos.y, 
        .w = font_size.w, .h = font_size.h 
    };
    SDL_RenderCopy(window->sdl_renderer, texture, NULL, &rect);

    /* Clean up.. */
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

    return font_size;
}

size2_t 
heimdall_render_fontf(window_t* window, int size, color_t color,
                      vec2_t pos, const char* fmt, ...)
{
    va_list list;
    va_start(list, fmt);

    vsprintf(buffer, fmt, list);
    size2_t __size = heimdall_render_font(window, size, color, pos, buffer);
    
    memset(buffer, 0, BUFFER_SIZE);
    va_end(list);
    return __size;
}