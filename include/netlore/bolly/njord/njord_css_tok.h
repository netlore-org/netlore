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

#ifndef __NETLORE_NJORD_CSS_TOK
#define __NETLORE_NJORD_CSS_TOK

#include <netlore/netlore.h>

#include <netlore/bolly/njord/njord_html.h>
#include <netlore/bolly/njord/njord_node.h>
#include <netlore/bolly/njord/njord_dom.h>

typedef enum __css_token_kind_t {
    IDENTIFIER, // background-color
    TOK_NUMBER,     // 10

    SEMICOLON, // ;
    AT_SIGN,   // @
    COLON,     // :
    HASH,      // #
    DOT,       // .
    
    OPEN_BRACE, // {
    CLOSE_BRACE // }
} css_token_kind_t;

typedef struct __css_token_t {
    css_token_kind_t kind;
    char* value;
} css_token_t;

css_token_t* njord_css_create_token(css_token_kind_t kind, char* value);

#endif /* __NETLORE_NJORD_CSS_TOK */