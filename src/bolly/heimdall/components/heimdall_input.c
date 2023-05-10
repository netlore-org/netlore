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

#include <netlore/bolly/heimdall/components/heimdall_input.h>

#include <netlore/bolly/heimdall/heimdall_geometry.h>
#include <netlore/bolly/heimdall/heimdall_utils.h>
#include <netlore/bolly/heimdall/heimdall_font.h>
#include <netlore/bolly/heimdall/heimdall_rgb.h>
#include <netlore/bolly/heimdall/heimdall_ui.h>

#include <SDL2/SDL.h>

typedef struct __component_t component_t;

void
heimdall_input_render(window_t* window, component_t* component)
{
    heimdall_draw_fill_rect(window, component->pos, component->size, 
                            component->input.input_background);
    heimdall_draw_rect(window, component->pos, component->size, 
                       component->input.input_border);

    size2_t font_size = heimdall_size_render_font(window, 16, heimdall_create_vec2(0, 0), component->input.input_value);
    vec2_t  font_pos  = heimdall_create_vec2(component->pos.x + 8, (component->pos.y + (component->size.h / 2 - font_size.h / 2)));

    heimdall_render_font(window, 16, component->input.input_foreground, 
                         font_pos, component->input.input_value);

    if (component->input.input_typing && component->input.input_value[0] != '\0')
        heimdall_draw_fill_rect(window, heimdall_create_vec2(font_size.w + font_pos.x + 2, font_pos.y + 2), 
                                heimdall_create_size2(1, font_size.h - 4), component->input.input_foreground);
}

void
heimdall_input_event(window_t* window, component_t* component, SDL_Event event)
{
    bool collision_2d = heimdall_check_collision_box((int)component->pos.x,  (int)component->pos.y, 
                                                     (int)component->size.w, (int)component->size.h,
                                                     event.motion.x, event.motion.y, 2, 2);

    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        if (collision_2d)
        {
            NETLORE_DEBUG("clicked input, id=%lu", component->id);
            SDL_StartTextInput();
            component->input.input_typing = true;
            component->last_event = EVENT_CLICK;
            if (component->input.callback != NULL)
                ((INPUT_CALLBACK_FUNC)component->input.callback)(component, EVENT_CLICK);
        } 
        else
        {
            SDL_StopTextInput();
            component->input.input_typing = false;
        }
    }
    else if (event.type == SDL_MOUSEMOTION)
    {
        if (collision_2d)
        {
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM));
            if (component->input.input_default_colors == true)
                component->input.input_background = heimdall_create_color_rgba(30, 30, 30, 255);
            component->last_event = EVENT_HOVER;
            if (component->input.callback != NULL)
                ((INPUT_CALLBACK_FUNC)component->input.callback)(component, EVENT_HOVER);
        }
        else
        {
            if (component->last_event == EVENT_HOVER)
            {
                SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
                if (component->input.input_default_colors == true)
                    component->input.input_background = heimdall_create_color_rgba(30, 30, 30, 255);
                component->last_event = EVENT_OUT_HOVER;
                if (component->input.callback != NULL)
                    ((INPUT_CALLBACK_FUNC)component->input.callback)(component, EVENT_OUT_HOVER); 
            }
        }
    }
    else if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == 42)
    {
        if (component->input.input_value_length != 0)
        {
            component->input.input_value_length--;
            component->input.input_value[component->input.input_value_length - 1] = '\0';
            
            if (component->input.callback != NULL)
                ((INPUT_CALLBACK_FUNC)component->input.callback)(component, EVENT_CHANGE); 
            component->last_event = EVENT_CHANGE;
        }
    }
    else if (event.type == SDL_TEXTINPUT)
    {
        component->input.input_value_length++;
        component->input.input_value = realloc(component->input.input_value, (size_t)((size_t)sizeof(char) * (size_t)(component->input.input_value_length + 2)));
        strcat(component->input.input_value, event.text.text);

        if (component->input.callback != NULL)
            ((INPUT_CALLBACK_FUNC)component->input.callback)(component, EVENT_CHANGE); 
        component->last_event = EVENT_CHANGE;
    }
}

void
heimdall_input_init(window_t* window, component_t* component)
{
    component->input.input_background = heimdall_create_color_rgba(40,  40,  40,  255);
    component->input.input_foreground = heimdall_create_color_rgba(255, 255, 255, 255);
    component->input.input_border     = heimdall_create_color_rgba(140, 149, 184, 255);


}