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

#ifndef __NETLORE_HEIMDALL_GEOMETRY
#define __NETLORE_HEIMDALL_GEOMETRY

# include <netlore/netlore.h>

# include <netlore/bolly/heimdall/heimdall_window.h>
# include <netlore/bolly/heimdall/heimdall_utils.h>
# include <netlore/bolly/heimdall/heimdall_rgb.h>

/*
 * In this file you can find function that will draw:
 *  - Rectangle
 *  - Circle
 *  - Triangle
 *  - Line
 *
 * If you are searching for font rendering function go to
 *  - include/netlore/bolly/heimdall/heimdall_font.h
 */

void heimdall_draw_fill_rect(window_t* window, vec2_t pos, size2_t size, color_t color);
void heimdall_draw_rect(window_t* window, vec2_t pos, size2_t size, color_t color);

void heimdall_draw_fill_circle(window_t* window, vec2_t pos, unsigned int radius, color_t color);
void heimdall_draw_circle(window_t* window, vec2_t pos, unsigned int radius, color_t color);

void heimdall_draw_fill_triangle(window_t* window, vec2_t point1, vec2_t point2, vec2_t point3, color_t color);
void heimdall_draw_triangle(window_t* window, vec2_t point1, vec2_t point2, vec2_t point3, color_t color);

void heimdall_draw_line(window_t* window, vec2_t start, vec2_t end, color_t color);

/*
 * From now all of these function can be only used
 * on SDL_Surfaces, it is for the web content drawing
 * purpose
 */

void heimdall_surface_draw_fill_rect(SDL_Surface* surface, vec2_t pos, size2_t size, color_t color);
void heimdall_surface_draw_rect(SDL_Surface* surface, vec2_t pos, size2_t size, color_t color);

void heimdall_surface_draw_fill_circle(SDL_Surface* surface, vec2_t pos, unsigned int radius, color_t color);
void heimdall_surface_draw_circle(SDL_Surface* surface, vec2_t pos, unsigned int radius, color_t color);

void heimdall_surface_draw_fill_triangle(SDL_Surface* surface, vec2_t point1, vec2_t point2, vec2_t point3, color_t color);
void heimdall_surface_draw_triangle(SDL_Surface* surface, vec2_t point1, vec2_t point2, vec2_t point3, color_t color);

void heimdall_surface_draw_line(SDL_Surface* surface, vec2_t start, vec2_t end, color_t color);

#endif /* __NETLORE_HEIMDALL_GEOMETRY */