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

#ifndef __NETLORE_HEIMDALL_RGB
#define __NETLORE_HEIMDALL_RGB

# include <netlore/netlore.h>

# include <SDL2/SDL.h>

typedef struct __color_t {
    unsigned char r, g, b, a;
} color_t;

color_t heimdall_create_color_rgb(unsigned char r, unsigned char g, 
                                  unsigned char b);

color_t heimdall_create_color_rgba(unsigned char r, unsigned char g, 
                                   unsigned char b, unsigned char a);

SDL_Color heimdall_color_to_sdl(color_t color);

unsigned long heimdall_create_hex_color(color_t color);

# define HEIMDALL_COLOR_TO_ARGS_RGBA(color) color.r, color.g, color.b, color.a
# define HEIMDALL_COLOR_TO_ARGS_RGB (color) color.r, color.g, color.b

#endif /* __NETLORE_HEIMDALL_RGB */