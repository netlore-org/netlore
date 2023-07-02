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

#include <netlore/netlore.h> 

#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/heimdall/heimdall_geometry.h>
#include <netlore/bolly/heimdall/heimdall_utils.h>
#include <netlore/bolly/heimdall/heimdall_font.h>
#include <netlore/bolly/heimdall/heimdall_fm.h>

#include <netlore/bolly/njord/njord_style.h>
#include <netlore/bolly/njord/njord_html.h>
#include <netlore/bolly/njord/njord_dom.h>
#include <netlore/bolly/njord/njord_css_units.h>
#include <netlore/bolly/njord/njord_css.h>
#include <netlore/bolly/njord/njord_css_properties.h>
#include <netlore/bolly/njord/njord_css_value.h>
#include <netlore/bolly/njord/njord_node.h>
#include <netlore/bolly/njord/njord_render_box.h>

#define CALC_HEIGHT_FROM_PARENT(parent) (parent->render_box.height - parent->render_box.top - parent->render_box.margin.top)
#define CALC_WIDTH_FROM_PARENT(parent) (parent->render_box.width - parent->render_box.left - parent->render_box.margin.left)

#define UNWRAP_CSS_PROP_DIMENSION(node, dom, property) ({                                           \
    style_rule_t* rule = njord_find_css_property_in_all_parents(node, property);                    \
    long double value = 0.00;                                                                       \
                                                                                                    \
    if (rule != NULL)                                                                               \
    {                                                                                               \
        css_dimensions_t* dimension = ((css_dimensions_t*)rule->value->ptr_to_value);               \
        value = njord_css_convert_unit_to_px(dom, dimension->unit_type, dimension->value);          \
    }                                                                                               \
                                                                                                    \
    value;                                                                                          \
})

#define UNWRAP_CSS_PROP_PERCENTAGE(prop) 

#define UNWRAP_CSS_PROP_DIM_PREC(prop) 

static vec2_t children_positioning_layout = { 0, 0 };

void
loki_apply_padding_render_box(dom_t* dom, dom_node_t* node)
{
    long double padding_left_value   = UNWRAP_CSS_PROP_DIMENSION(node, dom, PaddingLeft);
    long double padding_right_value  = UNWRAP_CSS_PROP_DIMENSION(node, dom, PaddingRight);
    long double padding_top_value    = UNWRAP_CSS_PROP_DIMENSION(node, dom, PaddingTop);
    long double padding_bottom_value = UNWRAP_CSS_PROP_DIMENSION(node, dom, PaddingBottom);
    long double padding_value        = UNWRAP_CSS_PROP_DIMENSION(node, dom, Padding);

    njord_set_padding_node(node, padding_value, padding_value, padding_value, padding_value);
    njord_set_padding_node(node, padding_top_value    == 0.00 ? padding_value : padding_top_value, 
                              padding_bottom_value == 0.00 ? padding_value : padding_bottom_value, 
                                padding_left_value   == 0.00 ? padding_value : padding_left_value, 
                               padding_right_value  == 0.00 ? padding_value : padding_right_value);
}

void
loki_apply_margin_render_box(dom_t* dom, dom_node_t* node)
{
    long double margin_left_value   = UNWRAP_CSS_PROP_DIMENSION(node, dom, MarginLeft);
    long double margin_right_value  = UNWRAP_CSS_PROP_DIMENSION(node, dom, MarginRight);
    long double margin_top_value    = UNWRAP_CSS_PROP_DIMENSION(node, dom, MarginTop);
    long double margin_bottom_value = UNWRAP_CSS_PROP_DIMENSION(node, dom, MarginBottom);
    long double margin_value        = UNWRAP_CSS_PROP_DIMENSION(node, dom, Margin);

    njord_set_margin_node(node, margin_value, margin_value, margin_value, margin_value);
    njord_set_margin_node(node, margin_top_value    == 0.00 ? margin_value : margin_top_value, 
                             margin_bottom_value == 0.00 ? margin_value : margin_bottom_value, 
                               margin_left_value   == 0.00 ? margin_value : margin_left_value, 
                              margin_right_value  == 0.00 ? margin_value : margin_right_value);
}

void
loki_calculate_size_of_element(dom_t* dom, dom_node_t* node, size2_t viewport_size)
{
    /* Is it a text? */
    if (node->content[0] != '\0')
    {
        long double font_size = UNWRAP_CSS_PROP_DIMENSION(node, dom, FontSize);

        SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(heimdall_get_default_font(font_size != 0 ? font_size : 16), 
                                                              node->content, (SDL_Color){255, 255, 255, 255}, 
                                                              viewport_size.w - node->render_box.padding.right - node->render_box.margin.right
                                                                   - node->render_box.left - node->render_box.margin.left - node->render_box.padding.left  - children_positioning_layout.x);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(dom->window->sdl_renderer, surface);

        size2_t element_font_size = heimdall_create_size2(0, 0);
        SDL_QueryTexture(texture, NULL, NULL, 
                        &element_font_size.w, &element_font_size.h);

        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);

        node->render_box.width  += element_font_size.w;
        node->render_box.height += element_font_size.h;

        // node->render_box.left += node->render_box.padding.left;
        // node->render_box.top  += node->render_box.padding.top;
        return;
    }

    node->render_box.width  += node->render_box.padding.left + node->render_box.padding.right;
    node->render_box.height += node->render_box.padding.top  + node->render_box.padding.bottom;
}

void
loki_recognize_layout_of_node(dom_t* dom, dom_node_t* node, size2_t viewport_size)
{
    /* Apply CSS style to render box like padding,
     * margin, top and left */
    loki_apply_padding_render_box(dom, node);
    loki_apply_margin_render_box(dom, node);
    
    /* Set render box by knowing the parent, just 
     * calculate some values from it, for example 
     * height, width */
    const dom_node_t* parent = node->parent_node;

    if (strcmp(node->tag, "body") == 0)
    {
        node->render_box.height = viewport_size.h;
        node->render_box.width  = viewport_size.w;

        node->render_box.left = 0;
        node->render_box.top  = 0;
        
        // njord_set_padding_node(node, 0, 0, 0, 0);
        // njord_set_margin_node (node, 0, 0, 0, 0);
    }

    /* Is element a text if so we need to render it
     * inside memory and get width and height of this
     * element */
    loki_calculate_size_of_element(dom, node, viewport_size);

    if (node->children_len != 0)
    {
        children_positioning_layout.x += node->render_box.margin.left + node->render_box.padding.left;
        children_positioning_layout.y += node->render_box.margin.top  + node->render_box.padding.top;
    }

    node->render_box.left = children_positioning_layout.x + node->render_box.margin.left;
    node->render_box.top  = children_positioning_layout.y + node->render_box.margin.top;

    node->render_box.width -= node->render_box.padding.right;
    node->render_box.width -= node->render_box.margin.right;

    node->render_box.height -= node->render_box.padding.bottom;
    node->render_box.height -= node->render_box.margin.bottom;

    NETLORE_USE(parent);
}

void
loki_debug_node_layout(dom_node_t* node)
{
    char* attrs_as_string = njord_get_attrs_as_string(node->attrs, node->attrs_len);
    
    if (attrs_as_string[0] == '\0')
        NETLORE_DEBUG("creating layout for node \e[0;31m%s\e[0;0m", 
            node->tag);
    else 
        NETLORE_DEBUG("creating layout for node \e[0;31m%s\e[0;0m with attrs { %s }", 
            node->tag, attrs_as_string);
    netlore_free(attrs_as_string);    
}

void 
loki_layout_node(dom_t* dom, dom_node_t* node, size2_t viewport_size)
{
    vec2_t copy_children_positioning_layout = children_positioning_layout;
    loki_recognize_layout_of_node(dom, node, viewport_size);

    if (node->children_len == 0) return;

    for (int i = 0; i < (int)node->children_len; i++)
    {
        dom_node_t* curr_node = node->children[i];

        loki_debug_node_layout(curr_node);
        loki_layout_node(dom, curr_node, viewport_size);
        
        children_positioning_layout = copy_children_positioning_layout;
    }
}

void 
loki_layout_dom(dom_t* dom, size2_t viewport_size)
{
    dom->root_node->render_box.height = viewport_size.h;
    dom->root_node->render_box.width  = viewport_size.w;
    dom->root_node->render_box.left   = 0;
    dom->root_node->render_box.top    = 0;
    
    njord_set_padding_node(dom->root_node, 0, 0, 0, 0);
    njord_set_margin_node (dom->root_node, 0, 0, 0, 0);

    for (int i = 0; i < (int)dom->root_node->children_len; i++)
    {
        dom_node_t* curr_node = dom->root_node->children[i];

        loki_debug_node_layout(curr_node);
        loki_layout_node(dom, curr_node, viewport_size);
    }
}