#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <netlore/bolly/freja/freja_request.h>
#include <netlore/bolly/freja/freja_https.h>

#include <netlore/bolly/heimdall/heimdall_geometry.h>
#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/heimdall/heimdall_events.h>
#include <netlore/bolly/heimdall/heimdall_utils.h>
#include <netlore/bolly/heimdall/heimdall_font.h>
#include <netlore/bolly/heimdall/heimdall_rgb.h>
#include <netlore/bolly/heimdall/heimdall_fm.h>

#include <netlore/netlore.h>

#include <stdio.h>

SDL_Surface* main_surface;
char* http_response;

void
main_render_func(window_t* window)
{
    // SDL_Texture* texture = SDL_CreateTextureFromSurface(window->sdl_renderer, main_surface);

    // SDL_Rect dest_rect = {
    //     .x = 0,               .y = 0,
    //     .w = main_surface->w, .h = main_surface->h
    // };
    // SDL_RenderCopy(window->sdl_renderer, texture, NULL, &dest_rect);
    heimdall_render_fontf(window, 14, heimdall_create_color_rgba(0, 0, 0, 255), 
                          heimdall_create_vec2(10, 10), "%s", http_response);
}

int 
main(int argc, char** argv)
{
    NETLORE_USE(argc);
    NETLORE_USE(argv);

    freja_network_init();

    heimdall_initialize();
    heimdall_init_font_manager("./res/font2.ttf", 64);

    window_t* window = heimdall_initalize_window("Netlore", heimdall_create_size2(1280, 720), 
                                                 heimdall_create_color_rgba(255, 255, 255, 255), heimdall_create_color_rgba(255, 255, 255, 255));

    window->render_func = main_render_func;

    request_t* req = freja_request_host("https://serenityos.org/");
    http_response = req->response->memory;

    // main_surface = SDL_CreateRGBSurfaceWithFormat(0, 1280, 720, 32, SDL_PIXELFORMAT_RGBA32);
    // heimdall_surface_draw_fill_rect(main_surface, heimdall_create_vec2(10, 10), 
    //                                 heimdall_create_size2(100, 100), heimdall_create_color_rgba(255, 255, 0, 255));
    
    heimdall_window_loop(window);
}