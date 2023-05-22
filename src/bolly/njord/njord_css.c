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

#include <netlore/bolly/njord/njord_css_tok.h>
#include <netlore/bolly/njord/njord_html.h>
#include <netlore/bolly/njord/njord_node.h>
#include <netlore/bolly/njord/njord_dom.h>
#include <netlore/bolly/njord/njord_css.h>

#define CSS_IS_WHITESPACE(space) ((space == ' ') || (space == '\t') || (space == '\n'))
#define CSS_IS_IDENTIFIER(char)  (((char >= 'a') && (char <= 'z')) || \
                                  ((char >= 'A') && (char <= 'Z')) || \
                                  ((char == '-')))                    \

#define CSS_CREATE_APPEND_TOKEN(lexer, kind, value) ({                   \
    njord_css_append_token(lexer, njord_css_create_token(kind, value));  \
})

void
njord_css_advance(css_lexer_t* lexer, int count)
{
    /* Advance html character buffer */
    lexer->index     += count;
    lexer->curr_char =  lexer->value[lexer->index];
}

void 
njord_css_append_token(css_lexer_t* lexer, css_token_t* token)
{
    lexer->tokens_len++;
    lexer->tokens[lexer->tokens_len - 1] = token;
    lexer->tokens = (css_token_t**)
                            netlore_realloc(lexer->tokens, (lexer->tokens_len + 1) * sizeof(css_token_t*));
}

bool
njord_css_tokenize_short_tokens(css_lexer_t* lexer)
{
    switch (lexer->curr_char)
    {
        case '#': 
            CSS_CREATE_APPEND_TOKEN(lexer, HASH, "#");
            lexer->space = false;

            return true;
        case ':': 
            CSS_CREATE_APPEND_TOKEN(lexer, COLON, ":");
            lexer->space = false;

            return true;
        case ';': 
            CSS_CREATE_APPEND_TOKEN(lexer, SEMICOLON, ";");
            lexer->space = false;

            return true;
        case '.': 
            CSS_CREATE_APPEND_TOKEN(lexer, DOT, ".");
            lexer->space = false;

            return true;
        case '{': 
            CSS_CREATE_APPEND_TOKEN(lexer, OPEN_BRACE, "{");
            lexer->space = false;

            return true;
        case '}': 
            CSS_CREATE_APPEND_TOKEN(lexer, CLOSE_BRACE, "}");
            lexer->space = false;
            
            return true;
        case '@': 
            CSS_CREATE_APPEND_TOKEN(lexer, AT_SIGN, "@");
            lexer->space = false;
            
            return true;
    }

    return false;
}

bool 
njord_css_character_is_identifier(css_lexer_t* lexer)
{
    bool is_identifier = CSS_IS_IDENTIFIER(lexer->curr_char);

    if (is_identifier)
        lexer->space = false;

    return is_identifier;
}

bool
njord_css_is_space(css_lexer_t* lexer)
{
    bool is_space = CSS_IS_WHITESPACE(lexer->curr_char);

    if (is_space)
        lexer->space = true;

    return is_space;
}

void
njord_css_tokenize_identifier(css_lexer_t* lexer)
{
    css_token_t* id_token = njord_css_create_token(IDENTIFIER, netlore_create_string_from_char(lexer->curr_char));
    njord_css_advance(lexer, 1);

    if (lexer->curr_char == '\0') return;

    while (true)
    {
        if (!CSS_IS_IDENTIFIER(lexer->curr_char)) break;

        netlore_append_to_alloc_string(id_token->value, lexer->curr_char);
        njord_css_advance(lexer, 1);
    }

    njord_css_append_token(lexer, id_token);
    njord_css_advance(lexer, -1);
}

/* This function is created based on CSS specifications
 * that can be found at:
 *  - https://www.w3.org/TR/css-syntax-3/#tokenization
 */
css_lexer_t* 
njord_tokenize_css(const char* value)
{
    css_lexer_t* lexer = (css_lexer_t*)netlore_calloc(1, sizeof(css_lexer_t));

    lexer->tokens     = (css_token_t**)netlore_calloc(1, sizeof(css_token_t*));
    lexer->value      = value;
    lexer->tokens_len = 0;
    lexer->curr_char  = 0;
    lexer->index      = 0;

    for (lexer->index = 0; lexer->index < (int)strlen(lexer->value); lexer->value++)
    {
        njord_css_advance(lexer, 0);
    
        if (lexer->curr_char == '/' && lexer->comment == false)
        {
            /* When we encounter a '/' character that means that
             * we maybe want to open a comment, so let's look at
             * the next character */
             
            if (lexer->value[lexer->index + 1] == '*')
            {
                lexer->comment = true;
                njord_css_advance(lexer, 1);
                continue;
            }
        }
        else if (lexer->curr_char == '*' && lexer->comment == true)
        {
            /* When we encounter a '*' character that means that
             * we maybe want to close a comment, so let's look at
             * the next character */

            if (lexer->value[lexer->index + 1] == '/')
            {
                lexer->comment = false;
                njord_css_advance(lexer, 1);
                continue;
            }
        }
        else if (lexer->comment == true) 
            continue;
        else if (njord_css_tokenize_short_tokens(lexer) == true) 
            continue;
        else if (njord_css_is_space(lexer) == true)
            continue;
        else if (njord_css_character_is_identifier(lexer) == true)
        {
            njord_css_tokenize_identifier(lexer);
            continue;
        }
    }

    for (int i = 0; i < lexer->tokens_len; i++)
    {
        printf("%d | \"%s\"\n", lexer->tokens[i]->kind, lexer->tokens[i]->value);
    }          

    return lexer;
}

void 
njord_parse_css(css_lexer_t* lexer, dom_t* dom)
{

}

/* This function gonna basically just loop through all 
 * dom->style_nodes and then tokenize, parse and apply
 * this style to DOM elements */
void
njord_tokenize_parse_all_css_dom(dom_t* dom)
{
    NETLORE_DEBUG("looking for style nodes..");

    if (dom->style_nodes_len == 0) return;

    NETLORE_DEBUG("found %lu style nodes", dom->style_nodes_len);

    for (int i = 0; i < (int)dom->style_nodes_len; i++)
    {
        NETLORE_DEBUG("tokenizing, parsing and applying style for %d style node", i + 1);

        dom_node_t* css_style_node = dom->style_nodes[i];
        const char* css_style_val  = css_style_node->content;

        css_lexer_t* css_lexer = njord_tokenize_css(css_style_val);
        njord_parse_css(css_lexer, dom);
    }
}