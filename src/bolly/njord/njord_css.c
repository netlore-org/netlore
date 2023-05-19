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

#include <netlore/bolly/njord/njord_css_tok.h>
#include <netlore/bolly/njord/njord_html.h>
#include <netlore/bolly/njord/njord_node.h>
#include <netlore/bolly/njord/njord_dom.h>
#include <netlore/bolly/njord/njord_css.h>

css_lexer_t* 
njord_tokenize_css(const char* value)
{
    css_lexer_t* lexer = (css_lexer_t*)netlore_calloc(1, sizeof(css_lexer_t));

    lexer->tokens     = (css_token_t**)netlore_calloc(1, sizeof(css_token_t*));
    lexer->value      = value;
    lexer->tokens_len = 0;
    lexer->curr_char  = 0;
    lexer->index      = 0;

}

void 
njord_parse_css(css_lexer_t* lexer, dom_t* dom)
{

}