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

#ifndef __NETLORE_HEIMDALL_WINDOW
#define __NETLORE_HEIMDALL_WINDOW

# include <netlore/bolly/heimdall/heimdall_utils.h>
# include <netlore/bolly/heimdall/heimdall_ui.h>
# include <netlore/bolly/heimdall/heimdall_rgb.h>

# include <netlore/netlore.h>
# include <SDL2/SDL.h>

struct __window_t;

typedef void (*HEIMDALL_INPUT_FUNC) (struct __window_t* window, SDL_Event event);
typedef void (*HEIMDALL_RENDER_FUNC)(struct __window_t* window);

typedef struct __window_t {
    SDL_Window*   sdl_window;
    SDL_Renderer* sdl_renderer;

    color_t bg;
    color_t fg;
    
    bool window_loop_render;
    bool window_loop;

    HEIMDALL_RENDER_FUNC render_func;
    HEIMDALL_INPUT_FUNC  input_func;

    unsigned long frames;
    unsigned long fps;
    clock_t       last_tick; 
} window_t;

void heimdall_initialize();

window_t* heimdall_initalize_window(const char* window_title, size2_t window_size,
                                    color_t fg, color_t bg);

void heimdall_window_loop(window_t* window);

size2_t heimdall_window_get_size(window_t* window);

#endif /* __NETLORE_HEIMDALL_WINDOW */