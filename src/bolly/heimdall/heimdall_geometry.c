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

#include <SDL2/SDL_pixels.h>
#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/heimdall/heimdall_events.h>
#include <netlore/bolly/heimdall/heimdall_utils.h>

#include <netlore/netlore.h>

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL.h>

#define HEIMDALL_IS_NULL_WINDOW(window) ({                                 \
    if (window == NULL)                                                    \
    {                                                                      \
        NETLORE_ERROR("window is null, couldn't execute the function");    \
        return;                                                            \
    }                                                                      \
})                                                                         \

#define HEIMDALL_IS_POS_CORRECT(pos) ({                                    \
    if (pos.x < 0 || pos.y < 0)                                            \
    {                                                                      \
        NETLORE_ERROR("incorrect given position, x or y is negative");     \
        return;                                                            \
    }                                                                      \
})                                                                         \

void
heimdall_draw_fill_rect(window_t* window, vec2_t pos, size2_t size, color_t color)
{
    HEIMDALL_IS_NULL_WINDOW(window);
    SDL_SetRenderDrawBlendMode(window->sdl_renderer, 
                               (color.a == 255) 
                                    ? SDL_BLENDMODE_NONE 
                                    : SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window->sdl_renderer, color.r, color.g, color.b, color.a);

    SDL_Rect rect = { .x = pos.x,  .y = pos.y, 
                      .w = size.w, .h = size.h };
    SDL_RenderFillRect(window->sdl_renderer, &rect);
}

void
heimdall_draw_rect(window_t* window, vec2_t pos, size2_t size, color_t color)
{
    HEIMDALL_IS_NULL_WINDOW(window);
    SDL_SetRenderDrawBlendMode(window->sdl_renderer, 
                               (color.a == 255) 
                                    ? SDL_BLENDMODE_NONE 
                                    : SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window->sdl_renderer, color.r, color.g, color.b, color.a);

    SDL_Rect rect = { .x = pos.x,  .y = pos.y, 
                      .w = size.w, .h = size.h };
    SDL_RenderDrawRect(window->sdl_renderer, &rect);
}

void
heimdall_draw_fill_circle(window_t* window, vec2_t pos, unsigned int radius, color_t color)
{
    HEIMDALL_IS_NULL_WINDOW(window);
    
    int d       = radius - 1;
    int offsety = radius;
    int offsetx = 0;

    SDL_SetRenderDrawBlendMode(window->sdl_renderer, 
                               (color.a == 255) 
                                    ? SDL_BLENDMODE_NONE 
                                    : SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window->sdl_renderer, color.r, color.g, color.b, color.a);

    while (offsety >= offsetx) {
        SDL_RenderDrawLine(window->sdl_renderer, pos.x - offsety, pos.y + offsetx, pos.x + offsety, pos.y + offsetx);
        SDL_RenderDrawLine(window->sdl_renderer, pos.x - offsetx, pos.y + offsety, pos.x + offsetx, pos.y + offsety);
        SDL_RenderDrawLine(window->sdl_renderer, pos.x - offsetx, pos.y - offsety, pos.x + offsetx, pos.y - offsety);
        SDL_RenderDrawLine(window->sdl_renderer, pos.x - offsety, pos.y - offsetx, pos.x + offsety, pos.y - offsetx);

        if (d >= 2 * offsetx) 
        {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * ((int)radius - offsety)) 
        {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else 
        {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }
}

void
heimdall_draw_circle(window_t* window, vec2_t pos, unsigned int radius, color_t color)
{
    HEIMDALL_IS_NULL_WINDOW(window);

    int d       = radius - 1;
    int offsety = radius;
    int offsetx = 0;

    SDL_SetRenderDrawBlendMode(window->sdl_renderer, 
                               (color.a == 255) 
                                    ? SDL_BLENDMODE_NONE 
                                    : SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window->sdl_renderer, color.r, color.g, color.b, color.a);

    while (offsety >= offsetx) 
    {
        SDL_RenderDrawPoint(window->sdl_renderer, pos.x + offsetx, pos.y + offsety);
        SDL_RenderDrawPoint(window->sdl_renderer, pos.x + offsety, pos.y + offsetx);
        SDL_RenderDrawPoint(window->sdl_renderer, pos.x - offsetx, pos.y + offsety);
        SDL_RenderDrawPoint(window->sdl_renderer, pos.x - offsety, pos.y + offsetx);
        SDL_RenderDrawPoint(window->sdl_renderer, pos.x + offsetx, pos.y - offsety);
        SDL_RenderDrawPoint(window->sdl_renderer, pos.x + offsety, pos.y - offsetx);
        SDL_RenderDrawPoint(window->sdl_renderer, pos.x - offsetx, pos.y - offsety);
        SDL_RenderDrawPoint(window->sdl_renderer, pos.x - offsety, pos.y - offsetx);

        if (d >= 2*offsetx) 
        {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * ((int)radius - offsety)) 
        {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else 
        {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }
}

void
heimdall_draw_fill_triangle(window_t* window, vec2_t point1, vec2_t point2, vec2_t point3, color_t color)
{
    HEIMDALL_IS_NULL_WINDOW(window);

    NETLORE_NOT_IMPLEMENTED();
}

void
heimdall_draw_triangle(window_t* window, vec2_t point1, vec2_t point2, vec2_t point3, color_t color)
{
    HEIMDALL_IS_NULL_WINDOW(window);

    NETLORE_NOT_IMPLEMENTED();
}

void
heimdall_draw_line(window_t* window, vec2_t start, vec2_t end, color_t color)
{
    HEIMDALL_IS_NULL_WINDOW(window);

    NETLORE_NOT_IMPLEMENTED();
}

void
heimdall_surface_draw_fill_rect(SDL_Surface* surface, vec2_t pos, size2_t size, color_t color)
{
    SDL_SetSurfaceBlendMode(surface, 
                            (color.a == 255) 
                                ? SDL_BLENDMODE_NONE 
                                : SDL_BLENDMODE_BLEND);

    SDL_Rect rect = { .x = pos.x,  .y = pos.y, 
                      .w = size.w, .h = size.h };
    SDL_FillRect(surface, &rect, SDL_MapRGBA(surface->format, color.r, color.g, color.b, color.a));
}

void
heimdall_surface_draw_rect(SDL_Surface* surface, vec2_t pos, size2_t size, color_t color)
{
    SDL_SetSurfaceBlendMode(surface, 
                            (color.a == 255) 
                                ? SDL_BLENDMODE_NONE 
                                : SDL_BLENDMODE_BLEND);

    SDL_Rect rect        = { .x = pos.x,  .y = pos.y, 
                             .w = size.w, .h = size.h };
    SDL_Rect border_rect = { .x = pos.x,  .y = pos.y, 
                             .w = size.w, .h = 1           };

    unsigned int num_color = SDL_MapRGBA(surface->format, color.r, color.g, color.b, color.a);

    /* Draw top border */
    SDL_FillRect(surface, &border_rect, num_color); 

    /* Draw bottom border */
    border_rect.y += rect.h - 1;
    SDL_FillRect(surface, &border_rect, num_color);

    /* Draw left border */
    border_rect.y = rect.y;
    border_rect.w = 1;
    border_rect.h = rect.h;
    SDL_FillRect(surface, &border_rect, num_color);

    /* Draw Right border */
    border_rect.x += rect.w - 1;
    SDL_FillRect(surface, &border_rect, num_color); 
}

void
heimdall_surface_draw_fill_circle(SDL_Surface* surface, vec2_t pos, unsigned int radius, color_t color)
{
    NETLORE_NOT_IMPLEMENTED();
}

void
heimdall_surface_draw_circle(SDL_Surface* surface, vec2_t pos, unsigned int radius, color_t color)
{
    NETLORE_NOT_IMPLEMENTED();
}

void
heimdall_surface_draw_fill_triangle(SDL_Surface* surface, vec2_t point1, vec2_t point2, vec2_t point3, color_t color)
{
    NETLORE_NOT_IMPLEMENTED();
}

void
heimdall_surface_draw_triangle(SDL_Surface* surface, vec2_t point1, vec2_t point2, vec2_t point3, color_t color)
{
    NETLORE_NOT_IMPLEMENTED();
}

void
heimdall_surface_draw_line(SDL_Surface* surface, vec2_t start, vec2_t end, color_t color)
{
    NETLORE_NOT_IMPLEMENTED();
}