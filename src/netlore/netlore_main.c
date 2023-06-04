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
    NETLORE_USE(argc);
    NETLORE_USE(argv);

    freja_network_init();

    heimdall_initialize();
    heimdall_init_font_manager("./res/font2.ttf", 64);

    window_t* window = heimdall_initalize_window("Netlore", heimdall_create_size2(1280, 720),
                                                 heimdall_create_color_rgba(255, 255, 255, 255), heimdall_create_color_rgba(255, 255, 255, 255));

    window->render_func = main_render_func;

    web_content_surface = SDL_CreateRGBSurfaceWithFormat(0, 1280, 720, 32, SDL_PIXELFORMAT_RGBA32);

    ui_t* ui = heimdall_initalize_ui(window, web_content_surface);

    component_t* input = heimdall_create_component(ui, HEIMDALL_COMPONENT_INPUT, heimdall_create_size2(250, 35),
                                                       heimdall_create_vec2(10, 10), true);
    input->input.input_default_colors = true;
    input->input.input_value_length   = strlen("netlore.solindek.ct8.pl");
    input->input.input_value          = malloc((size_t)((int)sizeof(char) * (int)(input->input.input_value_length + 1)));

    strcpy(input->input.input_value, "netlore.solindek.ct8.pl");
    heimdall_add_component(ui, input);

    component_t* button = heimdall_create_component(ui, HEIMDALL_COMPONENT_BUTTON, heimdall_create_size2(40, 35),
                                                       heimdall_create_vec2(265, 10), true);
    button->button.button_default_colors = true;
    button->button.button_value          = "Go!";
    button->button.callback              = go_callback;
    heimdall_add_component(ui, button);

    dom_t* dom = njord_create_dom(window);

    html_lexer_t* lex = njord_tokenize_html("<html>\n\
<head>\n\
    <style>\n\
        body {\n\
            background-color: red;\n\
        }\n\
\n\
        span {\n\
            color: #ff00ffff;\n\
        }\n\
    </style>\n\
</head>\n\
<body>\n\
    <span class=\"title\">Netlore!</span>\n\
</body>\n\
</html>");

    njord_parse_html(lex, dom);
    // njord_dump_tree(dom, dom->root_node, 0);

    njord_tokenize_parse_all_css_dom(dom);
    loki_layout_dom(dom);

    heimdall_window_loop(window);
    
    heimdall_clean_up_fonts();
    heimdall_clean_up_window(window);
}