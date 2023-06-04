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

#ifndef __NETLORE_NJORD_CSS
#define __NETLORE_NJORD_CSS

#include <netlore/netlore.h>

#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/freja/freja_request.h>

#include <netlore/bolly/njord/njord_css_tok.h>
#include <netlore/bolly/njord/njord_node.h>

typedef struct __css_parse_style_rules_t {
    bool expect_style_rule_name;
    bool expect_style_rule_separator;
    bool expect_style_rule_value;
} css_parse_style_rules_t;

typedef struct __css_lexer_t {
    css_token_t** tokens;
    const char* value;
    char curr_char;

    int tokens_len;
    int index;

    bool hex_starts;
    bool comment;
    bool space;
} css_lexer_t;

typedef struct __css_parser_t {
    css_token_t* curr_token;
    css_lexer_t* lexer;

    dom_t* dom;
    int index;

    bool expect_object_style_name;
} css_parser_t;

typedef struct __css_object_style_t {
    dom_node_t** nodes;
    size_t nodes_len;

    const char* obj_class_name;
    const char* obj_tag_name;
    const char* obj_id_name;
} css_object_style_t;

void njord_css_advance(css_lexer_t* lexer, int count);

void njord_css_append_token(css_lexer_t* lexer, css_token_t* token);

css_lexer_t* njord_tokenize_css(const char* value);

void njord_parse_css(css_lexer_t* lexer, dom_t* dom);

/* This function gonna basically just loop through all 
 * dom->style_nodes and then tokenize, parse and apply
 * this style to DOM elements */
void njord_tokenize_parse_all_css_dom(dom_t* dom);

#endif /* __NETLORE_NJORD_CSS */