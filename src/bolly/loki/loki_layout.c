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

#include "netlore/bolly/heimdall/heimdall_window.h"
#include "netlore/bolly/njord/njord_render_box.h"
#include <netlore/netlore.h> 

#include <netlore/bolly/heimdall/heimdall_geometry.h>
#include <netlore/bolly/heimdall/heimdall_utils.h>
#include <netlore/bolly/heimdall/heimdall_font.h>
#include <netlore/bolly/heimdall/heimdall_fm.h>

#include <netlore/bolly/njord/njord_style.h>
#include <netlore/bolly/njord/njord_html.h>
#include <netlore/bolly/njord/njord_dom.h>

#define CALC_HEIGHT_FROM_PARENT(parent) (parent->render_box.height - parent->render_box.top - parent->render_box.margin.top)
#define CALC_WIDTH_FROM_PARENT(parent) (parent->render_box.width - parent->render_box.left - parent->render_box.margin.left)

void
loki_recognize_layout_of_node(dom_t* dom, dom_node_t* node, size2_t viewport_size)
{
    /* 1. Apply CSS style to render box */
    
    /* Set render box by knowing the parent, just 
     * calculate some values from it, for example 
     * height, width */
    const dom_node_t* parent = node->parent_node;

    if (strcmp(node->tag, "body"))
    {
        node->render_box.height = viewport_size.h;
        node->render_box.width  = viewport_size.w;

        node->render_box.left = 0;
        node->render_box.top  = 0;
        
        njord_set_padding_node(node, 0, 0, 0, 0);
        njord_set_margin_node (node, 0, 0, 0, 0);
    }

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
    loki_recognize_layout_of_node(dom, node, viewport_size);

    if (node->children_len == 0) return;

    for (int i = 0; i < (int)node->children_len; i++)
    {
        dom_node_t* curr_node = node->children[i];

        loki_debug_node_layout(curr_node);
        loki_layout_node(dom, curr_node, viewport_size);
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