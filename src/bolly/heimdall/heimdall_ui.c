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

# include <netlore/netlore.h>

# include <netlore/bolly/heimdall/heimdall_window.h>

/* Include all of the heimdall components */
# include <netlore/bolly/heimdall/components/heimdall_button.h>
# include <netlore/bolly/heimdall/components/heimdall_input.h>
# include <netlore/bolly/heimdall/components/heimdall_image.h>
# include <netlore/bolly/heimdall/components/heimdall_text.h>

# include <SDL2/SDL.h>

const char* 
heimdall_component_kind_string(component_kind_t kind)
{
    switch (kind)
    {
        case HEIMDALL_BUTTON_COMPONENT:
            return "BUTTON_COMPONENT";
            break;
        case HEIMDALL_INPUT_COMPONENT:
            return "INPUT_COMPONENT"
            break;
        case HEIMDALL_IMAGE_COMPONENT:
            return "IMAGE_COMPONENT";
            break;
        case HEIMDALL_TEXT_COMPONENT:
            return "TEXT_COMPONENT"
            break;
    }

    NETLORE_ERROR_NO_EXIT("unknown component kind");
    return "UNKNOWN_COMPONENT";
}

ui_t*
heimdall_initalize_ui(window_t* window)
{
    ui_t* ui = (ui_t*)netlore_calloc(1, sizeof(ui_t));

    ui->components_len = 1;
    ui->components     = (component_t*)netlore_calloc(ui->components_len, sizeof(component_t));
    ui->window         = window;

    window->ui         = ui;

    return ui;
}