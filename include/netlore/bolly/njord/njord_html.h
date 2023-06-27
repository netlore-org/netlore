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

#ifndef __NETLORE_NJORD_HTML
#define __NETLORE_NJORD_HTML

#include <netlore/netlore.h>

#include <netlore/bolly/njord/njord_html_tok.h>
#include <netlore/bolly/njord/njord_html.h>
#include <netlore/bolly/njord/njord_node.h>
#include <netlore/bolly/njord/njord_dom.h>

typedef struct __html_token_t html_token_t;

typedef struct __html_lexer_t {
    html_token_t** tokens;
    const char* value;
    char curr_char;

    int tokens_len;
    int index;

    bool tag_content_opened;
    bool tag_expect_attrs;
    bool tag_expect_name;
    bool tag_is_opened;
} html_lexer_t;

html_lexer_t* njord_tokenize_html(const char* value);

void njord_parse_html(html_lexer_t* lexer, dom_t* dom);

void njord_html_advance(html_lexer_t* html, int count);

void njord_clean_up_lexer(html_lexer_t* lexer);

#endif /* __NETLORE_NJORD_HTML */