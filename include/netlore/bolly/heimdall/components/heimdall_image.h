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

#ifndef __NETLORE_HEIMDALL_COMPONENTS_IMAGE
#define __NETLORE_HEIMDALL_COMPONENTS_IMAGE

# include <netlore/netlore.h>
# include <netlore/bolly/heimdall/heimdall_window.h>
# include <netlore/bolly/heimdall/heimdall_ui.h>

# include <SDL2/SDL_ttf.h>

# define HEIMDALL_COMPONENT_IMAGE 0x02

typedef struct __component_image_t {

} component_image_t;

typedef struct __component_t component_t;
typedef struct __window_t window_t;

void heimdall_image_render(window_t* window, component_t* component);

void heimdall_image_event(window_t* window, component_t* component, SDL_Event event);

void heimdall_image_init(window_t* window, component_t* component);

#endif /* __NETLORE_HEIMDALL_COMPONENTS_IMAGE */