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

#include "netlore/bolly/heimdall/heimdall_utils.h"
#include <SDL2/SDL_render.h>
#include <netlore/netlore.h>

#include <netlore/bolly/heimdall/heimdall_ui.h>
#include <netlore/bolly/heimdall/components/heimdall_image.h>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

typedef struct __component_t component_t;

void
heimdall_image_render(window_t* window, component_t* component)
{
    if (component->image.image == NULL)
        return;

    SDL_Rect rect = {
        .x = component->pos.x, .y = component->pos.y,
        .w = component->size.w == -1
            ? component->image.size.w
            : component->size.w,
        .h = component->size.h == -1
            ? component->image.size.h
            : component->size.h
    };

    SDL_RenderCopy(window->sdl_renderer, component->image.image, 
                   NULL, &rect);
}

void
heimdall_image_event(window_t* window, component_t* component, SDL_Event event)
{

}

void
heimdall_image_init(window_t* window, component_t* component)
{
    if (component->image.image_path == NULL)
    {
        /* Image is on the server at image_url */
        NETLORE_ERROR_NO_EXIT("fetching images from internet is not supported yet");
    }

    if (component->image.image_url == NULL)
    {
        /* Local image, path is in image_path */
        SDL_Surface* img_surface = IMG_Load(component->image.image_path);

        if (img_surface == NULL)
        {
            NETLORE_ERROR_NO_EXIT("couldn't load image resource \"%s\"", 
                                  component->image.image_path);
            return;
        }

        component->image.image = SDL_CreateTextureFromSurface(window->sdl_renderer, img_surface);
        component->image.size  = heimdall_create_size2(img_surface->w, img_surface->h);

        if (component->image.image == NULL)
        {
            NETLORE_ERROR_NO_EXIT("couldn't create texture from image resource \"%s\"", 
                                  component->image.image_path);
            return;
        }

        SDL_FreeSurface(img_surface);
    }
}