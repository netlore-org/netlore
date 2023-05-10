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

#ifndef __NETLORE_HEIMDALL_UI
#define __NETLORE_HEIMDALL_UI

# include <netlore/netlore.h>

# include <netlore/bolly/heimdall/heimdall_window.h>

/* Include all of the heimdall components */
# include <netlore/bolly/heimdall/components/heimdall_checkbox.h>
# include <netlore/bolly/heimdall/components/heimdall_button.h>
# include <netlore/bolly/heimdall/components/heimdall_slider.h>
# include <netlore/bolly/heimdall/components/heimdall_input.h>
# include <netlore/bolly/heimdall/components/heimdall_image.h>
# include <netlore/bolly/heimdall/components/heimdall_text.h>
# include <netlore/bolly/heimdall/components/heimdall_box.h>

# include <SDL2/SDL.h>

# define EVENT_CLICK      (0xFF    )
# define EVENT_HOVER      (0xFF + 1)
# define EVENT_OUT_HOVER  (0xFF + 2)
# define EVENT_CHANGE     (0xFF + 3)

typedef unsigned short component_kind_t;

struct __component_t;
typedef void (*component_render_t)(window_t* window, struct __component_t* component);
typedef void (*component_event_t)(window_t* window, struct __component_t* component, SDL_Event event);
typedef void (*component_init_t)(window_t* window, struct __component_t* component);

struct __ui_t;

typedef struct __component_t {
    component_kind_t kind;

    component_checkbox_t checkbox;
    component_button_t   button;
    component_slider_t   slider;
    component_image_t    image;
    component_input_t    input;
    component_text_t     text;
    component_box_t      box;

    component_render_t render_func;
    component_event_t  event_func;
    component_init_t   init_func;

    size_t  layer;
    size2_t size;
    vec2_t  pos;

    struct __ui_t*  ui_parent;
    size_t          last_event;
    size_t          id;

    bool web_content;
} component_t;

typedef struct __ui_t {
    size_t        components_len;
    component_t** components;
    
    SDL_Surface* web_content;
    window_t*    window;
} ui_t;
 
const char* heimdall_component_kind_string(component_kind_t kind);

ui_t* heimdall_initalize_ui(window_t* window, SDL_Surface* web_content);

void heimdall_add_component(ui_t* ui, component_t* component);

component_t* heimdall_find_component_by_id(ui_t* ui, int id);

component_t* heimdall_create_component(ui_t* ui, component_kind_t kind,
                                       size2_t size, vec2_t pos, bool web_content);

void heimdall_handle_event_ui(ui_t* ui, SDL_Event event);
void heimdall_handle_render_ui(ui_t* ui);
void heimdall_handle_init_ui(ui_t* ui);

#endif /* __NETLORE_HEIMDALL_UI */