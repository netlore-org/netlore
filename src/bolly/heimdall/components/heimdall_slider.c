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

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_mouse.h>
#include <netlore/netlore.h>

#include <netlore/bolly/heimdall/heimdall_geometry.h>
#include <netlore/bolly/heimdall/heimdall_utils.h>
#include <netlore/bolly/heimdall/heimdall_font.h>
#include <netlore/bolly/heimdall/heimdall_rgb.h>
#include <netlore/bolly/heimdall/heimdall_ui.h>

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

void 
heimdall_slider_render(window_t* window, component_t* component)
{
    heimdall_draw_fill_rect(window, component->pos, heimdall_create_size2(component->size.w, 5), component->slider.slider_background);

    vec2_t handler_position = heimdall_create_vec2(
        component->pos.x + ((component->size.w * component->slider.slider_value) / component->slider.slider_max_value), component->pos.y + 3);
    // heimdall_draw_fill_circle(window, handler_position, 4, component->slider.slider_handler_color);
    // heimdall_draw_fill_rect(window, handler_position, heimdall_create_size2(15, 15), component->slider.slider_handler_color);
    heimdall_draw_fill_circle(window, handler_position, 7, component->slider.slider_handler_color);
    heimdall_draw_circle(window, handler_position, 7, component->slider.slider_background);
}

void 
heimdall_slider_event(window_t* window, component_t* component, SDL_Event event)
{
    vec2_t handler_position = heimdall_create_vec2(
        component->pos.x + ((component->size.w * component->slider.slider_value) / component->slider.slider_max_value), component->pos.y - 5);

    bool handler_collision = heimdall_check_collision_box(handler_position.x, handler_position.y, 15, 15, 
                                                          event.button.x, event.button.y, 2, 2);

    bool slider_collision = heimdall_check_collision_box(component->pos.x, component->pos.y, component->size.w, 5, 
                                                         event.button.x, event.button.y, 2, 2);

    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        if (handler_collision)
        {
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
            component->slider.handler_is_dragged = true;
        }

        if (slider_collision)
        {
            // Move the handler here
            component->slider.slider_value = (component->slider.slider_max_value * (event.button.x - component->pos.x)) / component->size.w;

            NETLORE_DEBUG("new value of slider, slider_value=%.6f", 
                            component->slider.slider_value);
        }
    }

    if (event.type == SDL_MOUSEBUTTONUP)
    {
        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
        component->slider.handler_is_dragged = false;
    }

    if (event.type == SDL_MOUSEMOTION)
    {
        if ((event.motion.x - component->pos.x) > component->size.w) return;
        if ((event.motion.x                   ) < component->pos.x ) return;

        if (component->slider.handler_is_dragged)
        {
            component->slider.slider_value = (component->slider.slider_max_value * (event.motion.x - component->pos.x)) / component->size.w;
            NETLORE_DEBUG("new value of slider, slider_value=%.6f", 
                            component->slider.slider_value);
        }
    }
}

void
heimdall_slider_init(window_t* window, component_t* component)
{
    component->slider.slider_handler_color = heimdall_create_color_rgba(140, 149, 184, 255);
    component->slider.slider_background    = heimdall_create_color_rgba(40,  40,  40,  255);
    component->slider.slider_color         = heimdall_create_color_rgba(80,  80,  80,  255);
}