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
#include <netlore/netlore.h>

#include <netlore/bolly/heimdall/components/heimdall_text.h>
#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/heimdall/heimdall_font.h>
#include <netlore/bolly/heimdall/heimdall_ui.h>
#include <netlore/bolly/heimdall/heimdall_fm.h>

#include <SDL2/SDL.h>

typedef struct __component_t component_t;

void
heimdall_text_render(window_t* window, component_t* component)
{   
    SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(heimdall_get_default_font(component->text.text_size), component->text.text_value, 
                                                          heimdall_color_to_sdl(component->text.text_color), component->text.text_line_break);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(window->sdl_renderer, surface);

    size2_t font_size = heimdall_create_size2(0, 0);
    SDL_QueryTexture(texture, NULL, NULL, 
                     &font_size.w, &font_size.h);

    SDL_Rect rect = { 
        .x = component->pos.x, .y = component->pos.y, 
        .w = font_size.w,      .h = font_size.h 
    };
    SDL_RenderCopy(window->sdl_renderer, texture, NULL, &rect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

    // TODO: make text selection
}

void
heimdall_text_event(window_t* window, component_t* component, SDL_Event event)
{

}

void
heimdall_text_init(window_t* window, component_t* component)
{
    /* Nothing really to initialize... */

    return;
}