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

#include <netlore/netlore.h>

#include <netlore/bolly/heimdall/components/heimdall_checkbox.h>
#include <netlore/bolly/heimdall/components/heimdall_button.h>

#include <netlore/bolly/heimdall/heimdall_geometry.h>
#include <netlore/bolly/heimdall/heimdall_utils.h>
#include <netlore/bolly/heimdall/heimdall_font.h>
#include <netlore/bolly/heimdall/heimdall_rgb.h>
#include <netlore/bolly/heimdall/heimdall_ui.h>

#include <SDL2/SDL_ttf.h>

vec2_t
heimdall_calculate_lerp(vec2_t start, vec2_t end, float velocity)
{
    return heimdall_create_vec2(start.x + (end.x - start.x) * (float)velocity / 100.0f, 
                                start.y + (end.y - start.y) * (float)velocity / 100.0f);
}

void 
heimdall_checkbox_render(window_t* window, component_t* component)
{
    heimdall_draw_fill_circle(window, component->pos, component->size.w, component->checkbox.checkbox_background);
    heimdall_draw_fill_circle(window, heimdall_create_vec2(component->pos.x + component->size.w * 2, component->pos.y),
                              component->size.w, component->checkbox.checkbox_background);
    heimdall_draw_fill_rect  (window, heimdall_create_vec2(component->pos.x, component->pos.y - component->size.w), 
                              heimdall_create_size2(component->size.w * 2, component->size.w * 2 + 1), component->checkbox.checkbox_background);

    if (component->checkbox.checkbox_animation == false)
    {
        if (component->checkbox.checked == false)
            heimdall_draw_fill_circle(window, heimdall_create_vec2(component->pos.x + 2, component->pos.y),
                                    component->size.w - 2, component->checkbox.checkbox_foreground);
        else
            heimdall_draw_fill_circle(window, heimdall_create_vec2(component->pos.x + (2 * component->size.w) - 2, component->pos.y),
                                    component->size.w - 2, component->checkbox.checkbox_foreground);
    }
    else 
    {
        if (component->checkbox.checkbox_animation_curr.x > component->checkbox.checkbox_animation_end.x)
            component->checkbox.checkbox_animation_curr.x--;
        else 
            component->checkbox.checkbox_animation_curr.x++;
    
        heimdall_draw_fill_circle(window, component->checkbox.checkbox_animation_curr, component->size.w - 2, component->checkbox.checkbox_foreground);

        if (component->checkbox.checkbox_animation_curr.x == component->checkbox.checkbox_animation_end.x)
            component->checkbox.checkbox_animation = false;
    }
}

void 
heimdall_checkbox_event(window_t* window, component_t* component, SDL_Event event)
{
    bool checkbox_collision = heimdall_check_collision_box(component->pos.x - component->size.w, component->pos.y - component->size.w, component->size.w * 4 + 1, 
                                                           component->size.w * 2, event.button.x, event.button.y, 2, 2);

    if (checkbox_collision && event.type == SDL_MOUSEBUTTONDOWN)
    {
        if (component->checkbox.checked == true)
            component->checkbox.checked = false;
        else
            component->checkbox.checked = true;

        if (component->checkbox.checked == true)
            component->checkbox.checkbox_animation_curr = heimdall_create_vec2(component->pos.x + 2, component->pos.y);
        else
            component->checkbox.checkbox_animation_curr = heimdall_create_vec2(component->pos.x + (2 * component->size.w) - 2, component->pos.y);

        if (component->checkbox.checked == true)
            component->checkbox.checkbox_animation_end = heimdall_create_vec2(component->pos.x + (2 * component->size.w) - 2, component->pos.y);
        else
            component->checkbox.checkbox_animation_end = heimdall_create_vec2(component->pos.x + 2, component->pos.y);

        component->checkbox.checkbox_animation = true;
    }

    if (event.type == SDL_MOUSEMOTION)
    {
        if (checkbox_collision)
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
    }
}

void 
heimdall_checkbox_init(window_t* window, component_t* component)
{
    component->checkbox.checkbox_background = heimdall_create_color_rgba(40,  40,  40,  255);
    component->checkbox.checkbox_foreground = heimdall_create_color_rgba(140, 149, 184, 255);
}