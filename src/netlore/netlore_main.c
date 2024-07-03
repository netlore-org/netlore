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

#include <netlore/bolly/freja/freja_request.h>
#include <netlore/bolly/freja/freja_https.h>

#include <netlore/bolly/heimdall/components/heimdall_checkbox.h>
#include <netlore/bolly/heimdall/components/heimdall_button.h>
#include <netlore/bolly/heimdall/components/heimdall_slider.h>
#include <netlore/bolly/heimdall/components/heimdall_input.h>
#include <netlore/bolly/heimdall/components/heimdall_image.h>
#include <netlore/bolly/heimdall/components/heimdall_text.h>
#include <netlore/bolly/heimdall/components/heimdall_box.h>

#include <netlore/bolly/heimdall/heimdall_geometry.h>
#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/heimdall/heimdall_events.h>
#include <netlore/bolly/heimdall/heimdall_utils.h>
#include <netlore/bolly/heimdall/heimdall_font.h>
#include <netlore/bolly/heimdall/heimdall_rgb.h>
#include <netlore/bolly/heimdall/heimdall_fm.h>
#include <netlore/bolly/heimdall/heimdall_ui.h>

#include <netlore/bolly/loki/loki_draw_dom.h>
#include <netlore/bolly/loki/loki_layout.h>

#include <netlore/bolly/njord/njord_builtin_colors.h>
#include <netlore/bolly/njord/njord_html_tok.h>
#include <netlore/bolly/njord/njord_css_tok.h>
#include <netlore/bolly/njord/njord_style.h>
#include <netlore/bolly/njord/njord_html.h>
#include <netlore/bolly/njord/njord_node.h>
#include <netlore/bolly/njord/njord_dom.h>
#include <netlore/bolly/njord/njord_css.h>

#include <netlore/ttf/ttf_parser.h>

#include <netlore/netlore_utils.h>
#include <netlore/netlore.h>

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL.h>

static SDL_Surface* web_content_surface;
static int          last_text_id;

void
main_render_func(window_t* window)
{
    // SDL_Texture* texture = SDL_CreateTextureFromSurface(window->sdl_renderer, web_content_surface);

    // SDL_Rect dest_rect = {
    //     .x = 0,                      .y = 0,
    //     .w = web_content_surface->w, .h = web_content_surface->h
    // };
    // SDL_RenderCopy(window->sdl_renderer, texture, NULL, &dest_rect);
}

void
go_callback(component_t* component, int event_type)
{
    if (event_type != EVENT_CLICK) return;

    component_t* input = heimdall_find_component_by_id(component->ui_parent, 255);
    NETLORE_NO_NULL_EXIT(input);

    request_t* request = freja_request_host(input->input.input_value);
    if (request == NULL)
    {
        component_t* title = heimdall_create_component(component->ui_parent, HEIMDALL_COMPONENT_TEXT, heimdall_create_size2(0, 0), heimdall_create_vec2(10, 60), true);
        title->text.text_color = heimdall_create_color_rgba(0, 0, 0, 255);
        title->text.text_value = "Network Error";
        title->text.text_size  = 32;
        heimdall_add_component(component->ui_parent, title);

        component_t* desc = heimdall_create_component(component->ui_parent, HEIMDALL_COMPONENT_TEXT, heimdall_create_size2(0, 0), heimdall_create_vec2(10, 60 + 40), true);
        desc->text.text_color = heimdall_create_color_rgba(0, 0, 0, 255);
        desc->text.text_value = "Couldn't send request to given host, check your internet connection and firewall.";
        desc->text.text_size  = 16;
        heimdall_add_component(component->ui_parent, desc);
    }
    else 
    {
        if (last_text_id != 0)
        {
            component_t* text     = heimdall_find_component_by_id(component->ui_parent, last_text_id);
            text->text.text_value = request->response->memory;
            NETLORE_NO_NULL_EXIT(text);
        }
        else 
        {
            component_t* text = heimdall_create_component(component->ui_parent, HEIMDALL_COMPONENT_TEXT, heimdall_create_size2(0, 0),
                                                    heimdall_create_vec2(10, 60), true);
            text->text.text_color = heimdall_create_color_rgba(0, 0, 0, 255);
            text->text.text_value = request->response->memory;
            text->text.text_size  = 16;
            heimdall_add_component(component->ui_parent, text);

            last_text_id = text->id;
        }
    }
}

int
main(int argc, char** argv)
{
    char* open_up_page = "start";
    FILE* file;

    freja_network_init();
    
    heimdall_initialize();
    heimdall_init_font_manager("./res/font2.ttf", 64);
    window_t* window = heimdall_initalize_window("Netlore", heimdall_create_size2(1280, 720),
                                                 heimdall_create_color_rgba(255, 255, 255, 255), heimdall_create_color_rgba(255, 255, 255, 255));

    window->render_func = main_render_func;
    ui_t* ui = heimdall_initalize_ui(window, web_content_surface);

    if (argc > 1)
    {
        open_up_page = argv[1];

        file = fopen(open_up_page, "r");
        if (file == NULL)
        {
            component_t* title = heimdall_create_component(ui, HEIMDALL_COMPONENT_TEXT, heimdall_create_size2(0, 0),
                                                            heimdall_create_vec2(10, 10), true);
            title->text.text_color = heimdall_create_color_rgba(0, 0, 0, 255);
            title->text.text_size  = 32;
            title->text.text_value = "NETLORE";

            heimdall_add_component(ui, title);

            component_t* text = heimdall_create_component(ui, HEIMDALL_COMPONENT_TEXT, heimdall_create_size2(0, 0),
                                                            heimdall_create_vec2(10, 10 + 10 + 32), true);
            text->text.text_color = heimdall_create_color_rgba(0, 0, 0, 255);
            text->text.text_size  = 16;
            text->text.text_value = "This part of browser is in creation right now, i suggest you to open the browser in cmd and write \"netlore <file.html/url>\"";

            heimdall_add_component(ui, text);

            heimdall_window_loop(window); 

            heimdall_clean_up_fonts();
            heimdall_clean_up_window(window);
            return 0;
        }

        fseek(file, 0, SEEK_END);
        long int res = ftell(file);
        fseek(file, 0, SEEK_SET);

        char* bytes = malloc((sizeof(char) * res));
        char c = 'A';

        for (long int i = 0; i < res; i++) {
            c = fgetc(file);
            bytes[i] = c;
        }
    
        fclose(file);

        dom_t* dom = njord_create_dom(window);
        html_lexer_t* lex = njord_tokenize_html(bytes);

        njord_parse_html(lex, dom);
        // njord_dump_tree(dom, dom->root_node, 0);

        njord_tokenize_parse_all_css_dom(dom);

        size2_t viewport_size = heimdall_window_get_size(window);
        vec2_t  viewport_pos  = heimdall_create_vec2(0, 0);

        loki_layout_dom(dom, viewport_size);
        loki_draw_dom(dom, window, viewport_size, viewport_pos);

        heimdall_window_loop(window); 

        njord_clean_up_dom(dom);
        njord_clean_up_lexer(lex);

        heimdall_clean_up_fonts();
        heimdall_clean_up_window(window);

        free(bytes);     
    } else {
        component_t* title = heimdall_create_component(ui, HEIMDALL_COMPONENT_TEXT, heimdall_create_size2(0, 0),
                                                        heimdall_create_vec2(10, 10), true);
        title->text.text_color = heimdall_create_color_rgba(0, 0, 0, 255);
        title->text.text_size  = 32;
        title->text.text_value = "NETLORE";

        heimdall_add_component(ui, title);

        component_t* text = heimdall_create_component(ui, HEIMDALL_COMPONENT_TEXT, heimdall_create_size2(0, 0),
                                                        heimdall_create_vec2(10, 10 + 10 + 32), true);
        text->text.text_color = heimdall_create_color_rgba(0, 0, 0, 255);
        text->text.text_size  = 16;
        text->text.text_value = "This part of browser is in development right now, i suggest you to open cmd and write \"netlore <file.html/url>\"";

        heimdall_add_component(ui, text);

        heimdall_window_loop(window); 

        heimdall_clean_up_fonts();
        heimdall_clean_up_window(window);
        return 0;
    }
}