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
 * This code is part of Njord (HTML, CSS Parser) Component
 * of Netlore project that can be found at the github
 * repository at:
 *  - https://github.com/netlore-org/netlore
 */

#ifndef __NETLORE_NJORD_NODE
#define __NETLORE_NJORD_NODE

#include <netlore/bolly/njord/njord_style.h>
#include <netlore/bolly/njord/njord_dom.h>

typedef struct __style_t style_t;

typedef struct __render_box_t {
	double width, height;
	double top, left;

	union {
        double top, left, right, bottom;
    } margin;

    union {
        double top, left, right, bottom;
    } padding;
} render_box_t;

typedef struct __attribute_t {
    char *name, *value;
} attribute_t;

typedef struct __dom_node_t {
    char* tag;
    char* content;

    struct __dom_node_t** children;
    struct __dom_node_t*  parent_node;

    size_t children_len;
    size_t attrs_len;

    render_box_t  render_box;
    attribute_t** attrs;
    style_t*      style;
} dom_node_t;

dom_node_t* njord_create_node(char* tag, char* content, dom_node_t* parent_node, 
                              attribute_t** attrs, render_box_t render_box, style_t* style);

attribute_t** njord_create_attributes_list();

render_box_t njord_create_render_box(double width, double height, double top, double left, double margin_top,  double margin_left, double margin_right,  
                                     double margin_bottom, double padding_top, double padding_left, double padding_right, double padding_bottom);
render_box_t njord_create_render_box_empty();

/*
 * Ton of utility function for looking out for children :3
 */
dom_node_t* njord_find_children_by_content(dom_node_t* parent, char* content);
dom_node_t* njord_find_children_by_class(dom_node_t* parent, char* class_name);
dom_node_t* njord_find_children_by_tag(dom_node_t* parent, char* tag);
dom_node_t* njord_find_children_by_id(dom_node_t* parent, char* id);

/*
 * Ton of utility function for looking out for nodes in nodes in nodes lol
 */
dom_node_t* njord_find_node_in_node_by_content(dom_node_t* parent, char* content);
dom_node_t* njord_find_node_in_node_by_class(dom_node_t* parent, char* class_name);
dom_node_t* njord_find_node_in_node_by_tag(dom_node_t* parent, char* tag);
dom_node_t* njord_find_node_in_node_by_id(dom_node_t* parent, char* id);

void njord_add_children(dom_node_t* parent, dom_node_t* children);

void njord_add_node_attribute(dom_node_t* parent, char* name, char* value);

attribute_t* njord_find_attr_by_name(dom_node_t* parent, char* name);

char* njord_get_attrs_as_string(attribute_t** attrs, size_t attrs_len);

#endif /* __NETLORE_NJORD_NODE */