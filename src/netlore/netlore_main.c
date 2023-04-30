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

#include <netlore/bolly/freja/freja_request.h>
#include <netlore/bolly/freja/freja_https.h>

#include <netlore/bolly/heimdall/heimdall_geometry.h>
#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/heimdall/heimdall_events.h>
#include <netlore/bolly/heimdall/heimdall_utils.h>
#include <netlore/bolly/heimdall/heimdall_font.h>
#include <netlore/bolly/heimdall/heimdall_rgb.h>
#include <netlore/bolly/heimdall/heimdall_fm.h>
#include <netlore/bolly/heimdall/heimdall_ui.h>

#include <netlore/netlore.h>

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL.h>

#include <stdio.h>

SDL_Surface* main_surface;

void
main_render_func(window_t* window)
{
    // SDL_Texture* texture = SDL_CreateTextureFromSurface(window->sdl_renderer, main_surface);

    // SDL_Rect dest_rect = {
    //     .x = 0,               .y = 0,
    //     .w = main_surface->w, .h = main_surface->h
    // };
    // SDL_RenderCopy(window->sdl_renderer, texture, NULL, &dest_rect);
}

int 
main(int argc, char** argv)
{
    NETLORE_USE(argc);
    NETLORE_USE(argv);

    freja_network_init();

    heimdall_initialize();
    heimdall_init_font_manager("./res/font2.ttf", 64);
    heimdall_initalize_ui();

    window_t* window = heimdall_initalize_window("Netlore", heimdall_create_size2(1280, 720), 
                                                 heimdall_create_color_rgba(255, 255, 255, 255), heimdall_create_color_rgba(255, 255, 255, 255));

    window->render_func = main_render_func;

    // main_surface = SDL_CreateRGBSurfaceWithFormat(0, 1280, 720, 32, SDL_PIXELFORMAT_RGBA32);
    // heimdall_surface_draw_fill_rect(main_surface, heimdall_create_vec2(10, 10), 
    //                                 heimdall_create_size2(100, 100), heimdall_create_color_rgba(255, 255, 0, 255));
    
    heimdall_window_loop(window);
}