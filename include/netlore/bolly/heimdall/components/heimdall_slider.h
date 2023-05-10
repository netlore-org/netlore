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

#ifndef __NETLORE_HEIMDALL_COMPONENTS_SLIDER
#define __NETLORE_HEIMDALL_COMPONENTS_SLIDER

# include <netlore/netlore.h>

# include <netlore/bolly/heimdall/heimdall_rgb.h>

# include <SDL2/SDL_ttf.h>

# define HEIMDALL_COMPONENT_SLIDER 0x04

typedef struct __component_t component_t;
typedef struct __window_t window_t;

typedef void (*SLIDER_CALLBACK_FUNC)(component_t* component, int event_type);

typedef struct __component_slider_t {
    double slider_min_value;
    double slider_max_value;
    double slider_value;

    color_t slider_handler_color;
    color_t slider_background;
    color_t slider_color;

    bool handler_is_dragged;
} component_slider_t;

void heimdall_slider_render(window_t* window, component_t* component);

void heimdall_slider_event(window_t* window, component_t* component, SDL_Event event);

void heimdall_slider_init(window_t* window, component_t* component);

#endif /* __NETLORE_HEIMDALL_COMPONENTS_SLIDER */