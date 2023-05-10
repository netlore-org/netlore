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

#ifndef __NETLORE_NJORD_DOM
#define __NETLORE_NJORD_DOM

#include <netlore/netlore.h>

#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/freja/freja_request.h>
#include <netlore/bolly/njord/njord_node.h>

typedef struct __dom_node_t dom_node_t;

typedef struct __dom_t {
    char* title;
    request_t* request;

    dom_node_t* root_node;
    window_t*   window;
} dom_t;

dom_t* njord_create_dom(window_t* window);

void njord_set_request_dom(dom_t* dom, request_t* req);
void njord_set_title_dom(dom_t* dom, char* title);

void njord_update_window_title_by_dom(dom_t* dom, window_t* window);

dom_node_t* njord_find_node_in_dom_by_content(dom_t* dom, char* content);
dom_node_t* njord_find_node_in_dom_by_class(dom_t* dom, char* class_name);
dom_node_t* njord_find_node_in_dom_by_tag(dom_t* dom, char* tag);
dom_node_t* njord_find_node_in_dom_by_id(dom_t* dom, char* id);

void njord_dump_tree(dom_t* dom, dom_node_t* start_node, int spacing);

#endif /* __NETLORE_NJORD_DOM */