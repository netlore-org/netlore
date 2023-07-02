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

#include <netlore/netlore.h>

#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/freja/freja_request.h>

#include <netlore/bolly/njord/njord_render_box.h>
#include <netlore/bolly/njord/njord_node.h>
#include <netlore/bolly/njord/njord_dom.h>

void
njord_set_padding_node(dom_node_t* node, double top, double bottom, double left, double right)
{
    njord_set_padding_render_box(&node->render_box, top, bottom, left, right);
}

void
njord_set_margin_node(dom_node_t* node, double top, double bottom, double left, double right)
{
    njord_set_margin_render_box(&node->render_box, top, bottom, left, right);
}

void
njord_set_padding_render_box(render_box_t* rnd_box, double top, double bottom, double left, double right)
{
    rnd_box->padding.bottom = bottom;
    rnd_box->padding.right  = right;
    rnd_box->padding.left   = left;
    rnd_box->padding.top    = top;

    NETLORE_USE(rnd_box);
}

void
njord_set_margin_render_box(render_box_t* rnd_box, double top, double bottom, double left, double right)
{
    rnd_box->margin.bottom = bottom;
    rnd_box->margin.right  = right;
    rnd_box->margin.left   = left;
    rnd_box->margin.top    = top;

    NETLORE_USE(rnd_box);
}