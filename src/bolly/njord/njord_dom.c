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

#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/freja/freja_request.h>
#include <netlore/bolly/njord/njord_node.h>
#include <netlore/bolly/njord/njord_dom.h>

#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>

dom_t* 
njord_create_dom(window_t* window)
{
    /* Prepare memory for the DOM structure and after it assign
     * everything which is needed*/
    dom_t* dom     = (dom_t*)netlore_calloc(1, sizeof(dom_t));
    dom->root_node = njord_create_node("root", "", NULL, njord_create_attributes_list(),
                                       njord_create_render_box_empty(), NULL);
    dom->request   = NULL;
    dom->title     = "None";
    dom->window    = window;

    /* Update the title of main (or not main) SDL window 
     * and return DOM (document) structure from the function */
    njord_update_window_title_by_dom(dom, window);
    return dom;
}

void 
njord_set_title_dom(dom_t* dom, char* title)
{
    /* Set DOM title simple thing.. */
    dom->title = title;

    /* Update the title of main (or not main) SDL window
     * and the DOM (document) window which is assign to it
     * at the creation of dom (njord_create_dom) */
    njord_update_window_title_by_dom(dom, dom->window);
}

void
njord_update_window_title_by_dom(dom_t* dom, window_t* window)
{
    /* Allocate memory for a buffer in which we will 
     * sprintf value. */
    char* buffer = (char*)netlore_malloc(sizeof(char) * (strlen(dom->title) + 16));
    NETLORE_NO_NULL_EXIT(buffer);

    sprintf(buffer, "Netlore - %s", dom->title);

    /* Set value as SDL window title */
    SDL_SetWindowTitle(window->sdl_window, buffer);

    /* Clean up and debug it */
    NETLORE_DEBUG("updated window title with dom (document) title");
    netlore_free(buffer);
}

void 
njord_set_request_dom(dom_t* dom, request_t* req)
{
    /* Just set the dom->request to req nothing
     * hard as you see... */
    dom->request = req;
}

dom_node_t* 
njord_find_node_in_dom_by_content(dom_t* dom, char* content)
{
    /* This function and 3 more (by_class, by_tag, by_id) 
     * does loop through every node that is linked with
     * another one and then look is the content the same. */

    dom_node_t* root = dom->root_node;

    /* Loop through every child in the root node */
    for (int i = 0; i < (int)root->childrens_len; i++)
    {
        dom_node_t* children = root->childrens[i];

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
njord_find_node_in_dom_by_class(dom_t* dom, char* class_name)
{
    /* This function and 3 more (by_content, by_tag, by_id) 
     * does loop through every node that is linked with
     * another one and then look is the content the same. */

    dom_node_t* root = dom->root_node;

    /* Loop through every child in the root node */
    for (int i = 0; i < (int)root->childrens_len; i++)
    {
        dom_node_t* children = root->childrens[i];

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
njord_find_node_in_dom_by_tag(dom_t* dom, char* tag)
{
    /* This function and 3 more (by_class, by_content, by_id) 
     * does loop through every node that is linked with
     * another one and then look is the content the same. */

    dom_node_t* root = dom->root_node;

    /* Loop through every child in the root node */
    for (int i = 0; i < (int)root->childrens_len; i++)
    {
        dom_node_t* children = root->childrens[i];

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
njord_find_node_in_dom_by_id(dom_t* dom, char* id)
{
    /* This function and 3 more (by_class, by_tag, by_content) 
     * does loop through every node that is linked with
     * another one and then look is the content the same. */

    dom_node_t* root = dom->root_node;

    /* Loop through every child in the root node */
    for (int i = 0; i < (int)root->childrens_len; i++)
    {
        dom_node_t* children = root->childrens[i];

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

void 
njord_dump_tree(dom_t* dom, dom_node_t* start_node, int spacing)
{
    /* Loop through every child in the root node */
    for (int i = 0; i < (int)start_node->childrens_len; i++)
    {
        dom_node_t* children = start_node->childrens[i];

        char* spacing_string = netlore_gen_spacing(spacing);
        printf("\n%s{\n\
%s    \"\e[0;33mtag\e[0m\": \"%s\",\n\
%s    \"\e[0;33mcontent\e[0m\": \"%s\",\n\
%s    \"\e[0;33mchildrens_len\e[0m\": \"%d\",\n\
%s    \"\e[0;33mattrs_len\e[0m\": \"%d\",\n\
%s    \"\e[0;33mattrs\e[0m\": [%s],\n\
%s    \"\e[0;33mchildrens\e[0m\": [",
        spacing_string, spacing_string, children->tag, 
        spacing_string, children->content, spacing_string,
        (int)children->childrens_len, spacing_string, (int)children->attrs_len, 
        spacing_string, njord_get_attrs_as_string(children->attrs, children->attrs_len),
        spacing_string);

        if (children->childrens_len != 0)
        {
            njord_dump_tree(dom, children, spacing + 2);
            printf("%s    ]\n%s}\n", spacing_string, spacing_string);
        }
        else
            printf("]\n%s}\n", spacing_string);
    }
}

