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
 * This code is part of Heimdall (UI & Window Manager)
 * Component of Netlore project that can be found at 
 * the github repository at:
 *  - https://github.com/netlore-org/netlore
 */

#include <netlore/netlore.h>

#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/heimdall/heimdall_ui.h>

/* Include all of the heimdall components */
#include <netlore/bolly/heimdall/components/heimdall_checkbox.h>
#include <netlore/bolly/heimdall/components/heimdall_button.h>
#include <netlore/bolly/heimdall/components/heimdall_slider.h>
#include <netlore/bolly/heimdall/components/heimdall_input.h>
#include <netlore/bolly/heimdall/components/heimdall_image.h>
#include <netlore/bolly/heimdall/components/heimdall_text.h>
#include <netlore/bolly/heimdall/components/heimdall_box.h>

#include <SDL2/SDL.h>

const char* 
heimdall_component_kind_string(component_kind_t kind)
{
    switch (kind)
    {
        case 0x00:
            return "BUTTON_COMPONENT";
            break;
        case 0x01:
            return "INPUT_COMPONENT";
            break;
        case 0x02:
            return "IMAGE_COMPONENT";
            break;
        case 0x03:
            return "TEXT_COMPONENT";
            break;
    }

    NETLORE_ERROR_NO_EXIT("unknown component kind");
    return "UNKNOWN_COMPONENT";
}

ui_t*
heimdall_initalize_ui(window_t* window, SDL_Surface* web_content)
{
    ui_t* ui = (ui_t*)netlore_calloc(1, sizeof(ui_t));

    ui->components_len = 0;
    ui->components     = (component_t**)netlore_calloc(ui->components_len, sizeof(component_t*));

    ui->web_content = web_content;
    ui->window      = window;

    window->ui         = ui;

    return ui;
}

component_t*
heimdall_create_component(ui_t* ui, component_kind_t kind, 
                          size2_t size, vec2_t pos, bool web_content)
{
    component_t* component = (component_t*)
                                netlore_calloc(1, sizeof(component_t));

    component->layer = 0;
    component->size  = size;
    component->pos   = pos;

    component->ui_parent = ui;
    component->kind      = kind;
    component->id        = ui->components_len + 0xFF;

    component->web_content = web_content;

    switch (kind)
    {
        case HEIMDALL_COMPONENT_BUTTON:
            component->event_func  = heimdall_button_event;
            component->render_func = heimdall_button_render;
            component->init_func   = heimdall_button_init;
            break;
        case HEIMDALL_COMPONENT_IMAGE:
            component->event_func  = heimdall_image_event;
            component->render_func = heimdall_image_render;
            component->init_func   = heimdall_image_init;
            break;
        case HEIMDALL_COMPONENT_INPUT:
            component->event_func  = heimdall_input_event;
            component->render_func = heimdall_input_render;
            component->init_func   = heimdall_input_init;
            break;
        case HEIMDALL_COMPONENT_TEXT:
            component->event_func  = heimdall_text_event;
            component->render_func = heimdall_text_render;
            component->init_func   = heimdall_text_init;
            break;
        case HEIMDALL_COMPONENT_SLIDER:
            component->event_func  = heimdall_slider_event;
            component->render_func = heimdall_slider_render;
            component->init_func   = heimdall_slider_init;
            break;
        case HEIMDALL_COMPONENT_CHECKBOX:
            component->event_func  = heimdall_checkbox_event;
            component->render_func = heimdall_checkbox_render;
            component->init_func   = heimdall_checkbox_init;
            break;
        case HEIMDALL_COMPONENT_BOX:
            component->event_func  = heimdall_box_event;
            component->render_func = heimdall_box_render;
            component->init_func   = heimdall_box_init;
            break;
    }

    return component;
}

void 
heimdall_add_component(ui_t* ui, component_t* component)
{
    ui->components_len++;
    ui->components[ui->components_len - 1] = component;
    ui->components = (component_t**)
                        netlore_realloc(ui->components, (ui->components_len + 1) * sizeof(component_t*));
}

void 
heimdall_handle_render_ui(ui_t* ui)
{
    for (int i = 0; i < (int)ui->components_len; i++)
    {
        component_t* component = ui->components[i];

        if (component == NULL)
            continue;
        
        if (component->render_func != NULL)
            component->render_func(ui->window, component);
    }
}

void 
heimdall_handle_event_ui(ui_t* ui, SDL_Event event)
{
    for (int i = 0; i < (int)ui->components_len; i++)
    {
        component_t* component = ui->components[i];

        if (component == NULL)
            continue;
        
        if (component->event_func != NULL)
            component->event_func(ui->window, component, event);
    }
}

void 
heimdall_handle_init_ui(ui_t* ui)
{
    for (int i = 0; i < (int)ui->components_len; i++)
    {
        component_t* component = ui->components[i];
        
        if (component == NULL)
            continue;
        
        if (component->init_func != NULL)
        {
            component->init_func(ui->window, component);
        }
    }
}

component_t* 
heimdall_find_component_by_id(ui_t* ui, int id)
{
    for (int i = 0; i < (int)ui->components_len; i++)
    {
        component_t* component = ui->components[i];

        if ((int)component->id == id)
            return component;
    }

    return NULL;
}