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

#include <SDL2/SDL_thread.h>
#include <netlore/bolly/heimdall/heimdall_geometry.h>
#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/heimdall/heimdall_events.h>
#include <netlore/bolly/heimdall/heimdall_utils.h>
#include <netlore/bolly/heimdall/heimdall_font.h>
#include <netlore/bolly/heimdall/heimdall_rgb.h>
#include <netlore/bolly/heimdall/heimdall_fm.h>
#include <netlore/bolly/heimdall/heimdall_ui.h>

#include <netlore/netlore.h>

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

#define IMG_INIT_FLAGS (IMG_INIT_JPG  | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP)

void
heimdall_initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        NETLORE_ERROR("failed to initialize SDL");

    if (TTF_Init() != 0)
        NETLORE_ERROR("failed to initialize SDL TTF");

    if (IMG_Init(IMG_INIT_FLAGS) == 0)
        NETLORE_ERROR("failed to initialize SDL Image");

    NETLORE_DEBUG("successfully initialized all SDL libraries");
}

window_t*
heimdall_initalize_window(const char* window_title, size2_t window_size,
                          color_t fg, color_t bg)
{
    window_t* window = (window_t*)calloc(1, sizeof(window_t));
    NETLORE_NO_NULL(window);

    window->sdl_window   = SDL_CreateWindow(window_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                          window_size.w, window_size.h, SDL_WINDOW_SHOWN);
    window->sdl_renderer = SDL_CreateRenderer(window->sdl_window, -1, 0);

    window->window_loop = false;
    window->render_func = NULL;
    window->input_func  = NULL;

    window->frames = 0;
    window->fps    = 0;

    window->bg = bg;
    window->fg = fg;

    NETLORE_DEBUG("successfully created window with title \"%s\"", window_title);

    return window;
}

void 
heimdall_window_clear(window_t* window)
{
    SDL_SetRenderDrawColor(window->sdl_renderer, HEIMDALL_COLOR_TO_ARGS_RGBA(window->bg));
    SDL_RenderClear(window->sdl_renderer);
}

void
heimdall_window_swap_buffer(window_t* window)
{
    SDL_RenderPresent(window->sdl_renderer);
}

void 
heimdall_window_fps(window_t* window)
{
    clock_t now = clock();
    window->frames++;

    if (now > (window->last_tick + CLOCKS_PER_SEC)) 
    {           
        window->fps         = window->frames;
        window->frames      = 0;
        window->last_tick   = now;

#ifdef __NETLORE_FPS_DEBUG__
        NETLORE_DEBUG("fps: %lu", window->fps);
#endif /* __NETLORE_FPS_DEBUG__ */
    
    }
}

int
heimdall_event_loop(void* data)
{
    window_t* window = ((window_t*)data);

    while (!window->window_loop)
        heimdall_window_inputs(window);

    return 0;
}

void 
heimdall_window_loop(window_t* window)
{
    heimdall_handle_init_ui(window->ui);

    SDL_CreateThread(heimdall_event_loop, "events", window);

    while (!window->window_loop)
    {
        if (window->frames % 5 == 0)
        {
            heimdall_window_clear(window);

            window->render_func(window);
            if (window->ui != NULL)
                heimdall_handle_render_ui(window->ui);

            heimdall_window_swap_buffer(window);
        }

        heimdall_window_fps(window);
    }
}

size2_t
heimdall_window_get_size(window_t* window)
{
    size2_t size = heimdall_create_size2(0, 0);
    SDL_GetWindowSize(window->sdl_window, &size.w, &size.h);

    return size;
}

void
heimdall_clean_up_window(window_t* window)
{
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();

    netlore_free(window);

    NETLORE_DEBUG("closed all sdl libraries and unallocated window memory");
}