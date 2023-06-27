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

#include <netlore/bolly/heimdall/heimdall_utils.h>
#include <netlore/bolly/heimdall/heimdall_rgb.h>

#include <netlore/netlore.h>

#define DEFAULT_ALPHA (0xFF)

color_t
heimdall_create_color_rgb(unsigned char r, unsigned char g, 
                          unsigned char b)
{
    return ((color_t){
        .r = r, .g = g,
        .b = b, .a = DEFAULT_ALPHA
    });
}

color_t
heimdall_create_color_rgba(unsigned char r, unsigned char g, 
                           unsigned char b, unsigned char a)
{
    return ((color_t){
        .r = r, .g = g,
        .b = b, .a = a
    });
}

SDL_Color 
heimdall_color_to_sdl(color_t color)
{
    return (SDL_Color){ color.r, color.g, color.b, color.a };
}

unsigned long 
heimdall_create_hex_color(color_t color)
{
    return ((color.r >> 24) | (color.g >> 16) |
            (color.g >> 8)  | color.a); 
}