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
 * This code is part of Loki (DOM Rendering Engine) Component
 * of Netlore project that can be found at the github
 * repository at:
 *  - https://github.com/netlore-org/netlore
 */

#include "netlore/bolly/heimdall/components/heimdall_text.h"
#include <netlore/netlore.h>
#include <netlore/netlore_utils.h>

#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/heimdall/heimdall_geometry.h>
#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/heimdall/heimdall_utils.h>
#include <netlore/bolly/heimdall/heimdall_font.h>
#include <netlore/bolly/heimdall/heimdall_rgb.h>
#include <netlore/bolly/heimdall/heimdall_ui.h>

#include <netlore/bolly/heimdall/components/heimdall_box.h>

#include <netlore/bolly/njord/njord_builtin_colors.h>
#include <netlore/bolly/njord/njord_css_properties.h>
#include <netlore/bolly/njord/njord_css_value.h>
#include <netlore/bolly/njord/njord_dom.h>
#include <netlore/bolly/njord/njord_css.h>

#include <netlore/bolly/loki/loki_draw_dom.h>
#include <netlore/bolly/loki/loki_layout.h>

#define CALC_ELEMENT_POS(node)  ({ heimdall_create_vec2(node->render_box.left + node->render_box.margin.left,   \
                                                        node->render_box.top  + node->render_box.margin.top); })

void
loki_draw_node_on_window(dom_t* dom, dom_node_t* node, window_t* window, 
                         size2_t viewport_size, vec2_t viewport_pos)
{
    style_rule_t* rule_background = njord_find_css_property_in_all_parents(node, BackgroundColor);
    style_rule_t* rule_color      = njord_find_css_property_in_all_parents(node, Color);
    style_rule_t* rule_size       = njord_find_css_property_in_all_parents(node, FontSize);

    vec2_t element_pos = heimdall_create_vec2(node->render_box.left, node->render_box.top);

    if (rule_background != NULL)
    {
        if (rule_background->value->type == INTEGER)
        {
            long long color_number = (long long)rule_background->value->ptr_to_value;

            color_t color = heimdall_create_color_rgba((color_number >> 24) & 0xFF, 
                                                    (color_number >> 16) & 0xFF, 
                                                    (color_number >> 8)  & 0xFF, 
                                                    color_number >= 0xFFFFFF
                                                        ? (color_number) & 0xFF
                                                        : 0xFF);
            
            // heimdall_draw_fill_rect(window, viewport_pos, viewport_size, color);

            component_t* rect;

            if (strcmp(node->tag, "body") == 0 || strcmp(node->tag, "html") == 0)
            {
                rect = heimdall_create_component(window->ui, HEIMDALL_COMPONENT_BOX, viewport_size,
                                                            viewport_pos, true);
            }
            else 
            {
                rect = heimdall_create_component(window->ui, HEIMDALL_COMPONENT_BOX, heimdall_create_size2(node->render_box.width, node->render_box.height), 
                                                                element_pos, true);
            }

            rect->box.background = color;
            rect->box.filled     = true;
            heimdall_add_component(window->ui, rect);
        }
        else if (rule_background->value->type == KEYWORD_VALUES || rule_background->value->type == CUSTOM_IDENT)
        {
            color_t color = njord_get_builtin_color_by_name(
                            njord_css_value_get_unwrapped_custom_ident(rule_background->value));

            component_t* rect;

            if (strcmp(node->tag, "body") == 0 || strcmp(node->tag, "html") == 0)
            {
                rect = heimdall_create_component(window->ui, HEIMDALL_COMPONENT_BOX, viewport_size,
                                                            viewport_pos, true);
            }
            else 
            {
                rect = heimdall_create_component(window->ui, HEIMDALL_COMPONENT_BOX, heimdall_create_size2(node->render_box.width, node->render_box.height), 
                                                                element_pos, true);
            }

            rect->box.background = color;
            rect->box.filled     = true;
            heimdall_add_component(window->ui, rect);
        }
    }

    if (node->content[0] != '\0')
    {
        component_t* text = heimdall_create_component(window->ui, HEIMDALL_COMPONENT_TEXT, heimdall_create_size2(0, 0),
                                                     heimdall_create_vec2(element_pos.x, element_pos.y), true);

        if (rule_color != NULL)
        {
            if (rule_color->value->type == INTEGER)
            {
                long long color_number = (long long)rule_color->value->ptr_to_value;

                color_t color = heimdall_create_color_rgba((color_number >> 24) & 0xFF, (color_number >> 16) & 0xFF, (color_number >> 8)  & 0xFF,  color_number >= 0xFFFFFF ? (color_number) & 0xFF : 0xFF);
                
                text->text.text_color = color;
            }
            else if (rule_color->value->type == KEYWORD_VALUES || rule_color->value->type == CUSTOM_IDENT)
            {
                color_t color = njord_get_builtin_color_by_name(
                                njord_css_value_get_unwrapped_custom_ident(rule_color->value));

                text->text.text_color = color;
            }
        } else {
            text->text.text_color = heimdall_create_color_rgba(255, 255, 255, 255);
        }

        text->text.text_size = rule_size != NULL ? ((css_dimensions_t*)rule_size->value->ptr_to_value)->value : 16;
        text->text.text_value = node->content;
        text->text.text_line_break = node->render_box.width;

        heimdall_add_component(window->ui, text);
    }
}

void
loki_debug_node_draw(dom_node_t* node)
{
    char* attrs_as_string = njord_get_attrs_as_string(node->attrs, node->attrs_len);
    
    if (netlore_str_is_empty(attrs_as_string))
        NETLORE_DEBUG("drawing node \e[0;31m%s\e[0;0m", 
            node->tag);
    else
        NETLORE_DEBUG("drawing node \e[0;31m%s\e[0;0m with attrs { %s }", 
            node->tag, attrs_as_string);
    netlore_free(attrs_as_string);    
}

void 
loki_draw_node(dom_t* dom, dom_node_t* node, window_t* window, 
               size2_t viewport_size, vec2_t viewport_pos)
{
    loki_debug_node_draw(node);

    if (strcmp(node->tag, "head") != 0)
        loki_draw_node_on_window(dom, node, window, viewport_size, viewport_pos);

    if (node->children_len == 0) return;

    for (int i = 0; i < (int)node->children_len; i++)
    {
        dom_node_t* curr_node = node->children[i];

        loki_draw_node(dom, curr_node, window, viewport_size, viewport_pos);
    }
}

void 
loki_draw_dom(dom_t* dom, window_t* window, size2_t viewport_size, vec2_t viewport_pos)
{
    for (int i = 0; i < (int)dom->root_node->children_len; i++)
    {
        dom_node_t* curr_node = dom->root_node->children[i];
        loki_debug_node_draw(curr_node);

        if (strcmp(curr_node->tag, "head") != 0)
            loki_draw_node_on_window(dom, curr_node, window, viewport_size, viewport_pos);
        
        loki_draw_node(dom, curr_node, window, viewport_size, viewport_pos);
    }
}