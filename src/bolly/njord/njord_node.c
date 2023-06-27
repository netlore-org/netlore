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
#include <netlore/netlore_utils.h>

#include <netlore/bolly/njord/njord_style.h>
#include <netlore/bolly/njord/njord_node.h>
#include <netlore/bolly/njord/njord_dom.h>

dom_node_t* 
njord_create_node(char* tag, char* content, dom_node_t* parent_node, 
                  attribute_t** attrs, render_box_t render_box, style_t* style)
{
    dom_node_t* node = (dom_node_t*)netlore_calloc(1, sizeof(dom_node_t));
    node->tag     = tag;
    node->content = content;

    node->children = (dom_node_t**) netlore_calloc(1, sizeof(dom_node_t*));
    node->attrs     = (attribute_t**)netlore_calloc(1, sizeof(attribute_t*));

    node->parent_node = parent_node;
    node->render_box  = render_box;
    node->style       = style;

    return node;
}

attribute_t**
njord_create_attributes_list()
{
    return (attribute_t**)netlore_calloc(1, sizeof(attribute_t*));
}

render_box_t 
njord_create_render_box(double width, double height, double top, double left, double margin_top,  double margin_left, double margin_right,  
                        double margin_bottom, double padding_top, double padding_left, double padding_right, double padding_bottom)
{
    render_box_t render_box;

    render_box.height = height;
    render_box.width  = width;
    render_box.left   = left;
	render_box.top    = top;

	render_box.margin.bottom = margin_bottom;
	render_box.margin.right  = margin_right;
	render_box.margin.left   = margin_left;
    render_box.margin.top    = margin_top;

	render_box.padding.bottom = padding_bottom;
	render_box.padding.right  = padding_right;
	render_box.padding.left   = padding_left;
    render_box.padding.top    = padding_top;

    return render_box;
}

dom_node_t* 
njord_find_children_by_content(dom_node_t* parent, char* content)
{
    for (int i = 0; i < (int)parent->children_len; i++)
    {
        if (strcmp(parent->children[i]->content, content) == 0)
            return parent->children[i];
    }

    return NULL;
}

dom_node_t* 
njord_find_children_by_class(dom_node_t* parent, char* class_name)
{
    for (int i = 0; i < (int)parent->children_len; i++)
    {
        dom_node_t* children = parent->children[i];

        char* value = netlore_create_copy_string(
                                (const char*)njord_find_attr_by_name(children, "class")->value);
        char* splited = strtok(value, " ");
        
        while (splited != NULL)
        {
            if (strcmp(splited, class_name) == 0)
                return children;
            splited = strtok(NULL, " ");
        }
    }

    return NULL;
}

dom_node_t* 
njord_find_children_by_id(dom_node_t* parent, char* id)
{
    for (int i = 0; i < (int)parent->children_len; i++)
    {
        dom_node_t* children = parent->children[i];

        attribute_t* id_attr = njord_find_attr_by_name(children, "id");
        if (strcmp(id_attr->value, id) == 0)
        {
            NETLORE_DEBUG("found children with id of %s", id);
            return children;
        }
    }

    return NULL;
}

dom_node_t* 
njord_find_children_by_tag(dom_node_t* parent, char* tag)
{
    for (int i = 0; i < (int)parent->children_len; i++)
    {
        if (strcmp(parent->children[i]->tag, tag) == 0)
            return parent->children[i];
    }

    return NULL;
}

void 
njord_add_children(dom_node_t* parent, dom_node_t* children)
{
    parent->children_len++;
    parent->children[parent->children_len - 1] = children;
    parent->children = (dom_node_t**)
                            netlore_realloc(parent->children, (parent->children_len + 1) * sizeof(dom_node_t*));
}

void 
njord_add_node_attribute(dom_node_t* parent, char* name, char* value)
{
    parent->attrs_len++;

    parent->attrs[parent->attrs_len - 1]  = (attribute_t*)netlore_calloc(1, sizeof(attribute_t));
    parent->attrs[parent->attrs_len - 1]->name  = name;
    parent->attrs[parent->attrs_len - 1]->value = value;

    parent->attrs = (attribute_t**)
                        netlore_realloc(parent->attrs, (parent->attrs_len + 1) * sizeof(attribute_t*));
}

attribute_t*
njord_find_attr_by_name(dom_node_t* parent, char* name)
{
    for (int i = 0; i < (int)parent->attrs_len; i++)
    {
        if (parent->attrs[i]->name == name)
            return parent->attrs[i];
    }

    return NULL;
}

render_box_t 
njord_create_render_box_empty()
{
    render_box_t render_box;

    render_box.height = 0;
    render_box.width  = 0;
    render_box.left   = 0;
	render_box.top    = 0;

	render_box.margin.bottom = 0;
	render_box.margin.right  = 0;
	render_box.margin.left   = 0;
    render_box.margin.top    = 0;

	render_box.padding.bottom = 0;
	render_box.padding.right  = 0;
	render_box.padding.left   = 0;
    render_box.padding.top    = 0;

    return render_box;
}

dom_node_t*
njord_find_node_in_node_by_content(dom_node_t* parent, char* content)
{
    for (int i = 0; i < (int)parent->children_len; i++)
    {
        dom_node_t* children = parent->children[i];

        if (strcmp(children->content, content) == 0)
            return children;
        else
        {
            dom_node_t* node = njord_find_node_in_node_by_content(children, content);

            if (node != NULL)
                return node;
        }
    }

    return NULL;
}

dom_node_t* 
njord_find_node_in_node_by_class(dom_node_t* parent, char* class_name)
{
    for (int i = 0; i < (int)parent->children_len; i++)
    {
        dom_node_t* children = parent->children[i];

        attribute_t* class_attr = njord_find_attr_by_name(children, "class");
        if (class_attr == NULL)
        {
            dom_node_t* node = njord_find_node_in_node_by_class(children, class_name);
        
            if (node != NULL)
                return node;
        }

        char* value = netlore_create_copy_string((const char*)class_attr->value);
        char* splited = strtok(value, " ");
        
        while (splited != NULL)
        {
            if (strcmp(splited, class_name) == 0)
                return children;
            splited = strtok(NULL, " ");
        }

        dom_node_t* node = njord_find_node_in_node_by_class(children, class_name);

        if (node != NULL)
            return node;
    }

    return NULL;
}

dom_node_t* 
njord_find_node_in_node_by_tag(dom_node_t* parent, char* tag)
{
    for (int i = 0; i < (int)parent->children_len; i++)
    {
        dom_node_t* children = parent->children[i];

        if (strcmp(children->tag, tag) == 0)
            return children;
        else
        {
            dom_node_t* node = njord_find_node_in_node_by_tag(children, tag);

            if (node != NULL)
                return node;
        }
    }

    return NULL;
}

dom_node_t* 
njord_find_node_in_node_by_id(dom_node_t* parent, char* id)
{
    for (int i = 0; i < (int)parent->children_len; i++)
    {
        dom_node_t* children = parent->children[i];

        attribute_t* id_attr = njord_find_attr_by_name(children, "id");
        if (id_attr == NULL)
        {
            dom_node_t* node = njord_find_node_in_node_by_id(children, id);
        
            if (node != NULL)
                return node;
        }

        if (strcmp(id_attr->value, id) == 0)
            return children;
        else
        {
            dom_node_t* node = njord_find_node_in_node_by_id(children, id);

            if (node != NULL)
                return node;
        }
    }

    return NULL;
}

char* 
njord_get_attrs_as_string(attribute_t** attrs, size_t attrs_len)
{
    char* buf = (char*)netlore_calloc(1024 * 5, sizeof(char));

    for (int i = 0; i < (int)attrs_len; i++)
    {
        /* Name */
        strcat(buf, "\e[0;34m\"");
        strcat(buf, attrs[i]->name);
        strcat(buf, "\"\e[0;0m: ");

        /* Value */
        strcat(buf, "\"");
        strcat(buf, attrs[i]->value);
        if (i != (int)(attrs_len - 1))
            strcat(buf, "\", ");
        else
            strcat(buf, "\"");
    }

    return buf;
}