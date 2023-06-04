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


#include <SDL2/SDL_stdinc.h>
#include <netlore/netlore.h>
#include <netlore/netlore_utils.h>

#include <netlore/bolly/heimdall/heimdall_window.h>
#include <netlore/bolly/freja/freja_request.h>

#include <netlore/bolly/njord/njord_builtin_colors.h>
#include <netlore/bolly/njord/njord_css_properties.h>
#include <netlore/bolly/njord/njord_css_value.h>
#include <netlore/bolly/njord/njord_css_tok.h>
#include <netlore/bolly/njord/njord_style.h>
#include <netlore/bolly/njord/njord_html.h>
#include <netlore/bolly/njord/njord_node.h>
#include <netlore/bolly/njord/njord_dom.h>
#include <netlore/bolly/njord/njord_css.h>
#include <stdbool.h>
#include <stdlib.h>

#define CSS_IS_WHITESPACE(space) ((space == ' ') || (space == '\t') || (space == '\n'))

#define CSS_IS_IDENTIFIER(char) (((char >= 'a') && (char <= 'z')) || \
                                 ((char >= 'A') && (char <= 'Z')) || \
                                 ((char == '-')))

#define CSS_IS_NUMBER(char)     (((char >= '0') && (char <= '9')))

#define CSS_IS_HEX(char)        (((char >= '0') && (char <= '9')) || \
                                 ((char >= 'a') && (char <= 'f')) || \
                                 ((char >= 'A') && (char <= 'F')))

#define CSS_WAIT_UNTIL_SEMICOLON_OR_END(parser) ({                                              \
    while (true)                                                                                \
    {                                                                                           \
        if (parser->curr_token->kind == SEMICOLON || parser->curr_token->kind == CLOSE_BRACE)   \
            break;                                                                              \
                                                                                                \
        parser->index++;                                                                        \
        parser->curr_token = parser->lexer->tokens[parser->index];                              \
    }                                                                                           \
})

const char* css_keywords[] = {
    /* TODO: create a css keyword array */
};

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

void
njord_css_delete_last_token(css_lexer_t* lexer)
{
    if (lexer->tokens_len == 0) return;

    lexer->tokens_len--;
    lexer->tokens[lexer->tokens_len] = NULL;
}

bool
njord_css_tokenize_short_tokens(css_lexer_t* lexer)
{
    switch (lexer->curr_char)
    {
        case '#': 
            CSS_CREATE_APPEND_TOKEN(lexer, HASH, "#");
            lexer->hex_starts = true;
            lexer->space      = false;

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

bool
njord_css_character_is_number(css_lexer_t* lexer)
{
    bool is_num = CSS_IS_NUMBER(lexer->curr_char);

    if (is_num)
        lexer->space = false;

    return is_num;
}

bool
njord_css_character_is_hex_number(css_lexer_t* lexer)
{
    if (!lexer->hex_starts) 
        return false;

    bool is_hex = CSS_IS_HEX(lexer->curr_char);

    if (is_hex)
        lexer->space = false;

    return is_hex;
}

void
njord_css_tokenize_number(css_lexer_t* lexer)
{
    css_token_t* num_token = njord_css_create_token(TOK_NUMBER, netlore_create_string_from_char(lexer->curr_char));
    njord_css_advance(lexer, 1);

    if (lexer->curr_char == '\0') return;

    while (true)
    {
        if (!CSS_IS_NUMBER(lexer->curr_char))
            break;

        netlore_append_to_alloc_string(num_token->value, lexer->curr_char);
        njord_css_advance(lexer, 1);
    }

    njord_css_append_token(lexer, num_token);
    njord_css_advance(lexer, -1);
}

void
njord_css_tokenize_identifier(css_lexer_t* lexer)
{
    css_token_t* id_token = njord_css_create_token(IDENTIFIER, netlore_create_string_from_char(lexer->curr_char));
    njord_css_advance(lexer, 1);

    if (lexer->curr_char == '\0') return;

    while (true)
    {
        if (!CSS_IS_IDENTIFIER(lexer->curr_char)) 
            if (!CSS_IS_NUMBER(lexer->curr_char))
                break;

        netlore_append_to_alloc_string(id_token->value, lexer->curr_char);
        njord_css_advance(lexer, 1);
    }

    njord_css_append_token(lexer, id_token);
    njord_css_advance(lexer, -1);
}

void
njord_css_tokenize_hex_number(css_lexer_t* lexer)
{
    njord_css_delete_last_token(lexer);

    char* str = (char*)netlore_calloc(3, sizeof(char));
    str[0] = '#';
    str[1] = lexer->curr_char;
    str[2] = '\0';

    css_token_t* hex_token = njord_css_create_token(TOK_NUMBER, str);
    njord_css_advance(lexer, 1);

    if (lexer->curr_char == '\0') return;

    while (true)
    {
        if (!CSS_IS_HEX(lexer->curr_char))
            break;
        
        netlore_append_to_alloc_string(hex_token->value, lexer->curr_char);
        njord_css_advance(lexer, 1);
    }

    njord_css_append_token(lexer, hex_token);
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
    
        if (lexer->curr_char == '/' && !lexer->comment)
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
        else if (lexer->curr_char == '*' && lexer->comment)
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
        else if (lexer->comment) 
            continue;
        else if (njord_css_tokenize_short_tokens(lexer)) 
            continue;
        else if (njord_css_is_space(lexer))
            continue;
        else if (njord_css_character_is_hex_number(lexer))
        {
            njord_css_tokenize_hex_number(lexer);
            lexer->hex_starts = false;

            continue;
        }
        else if (njord_css_character_is_identifier(lexer))
        {
            njord_css_tokenize_identifier(lexer);
            continue;
        }
        else if (njord_css_character_is_number(lexer))
        {
            njord_css_tokenize_number(lexer);
            continue;
        }

        lexer->hex_starts = false;
    }

    return lexer;
}

css_object_style_t*
njord_css_parse_and_find_node_style_object(css_parser_t* parser)
{
    css_object_style_t* obj_style = (css_object_style_t*)netlore_calloc(1, sizeof(css_object_style_t));

    obj_style->nodes_len = 0;
    obj_style->nodes = (dom_node_t**)netlore_calloc(1, sizeof(dom_node_t*));
    
    /* Parse the object name or something else for example
     *   .class { styles }
     *    / \
     *     |
     */

    css_token_t* obj_token = NULL;

    bool expect_class_name = false;
    bool expect_id_name    = false;
    bool expect_anything   = true;

    while (true)
    {
        obj_token = parser->lexer->tokens[parser->index];

        if (obj_token->kind == OPEN_BRACE || obj_token->kind == CLOSE_BRACE) return obj_style;

        if (expect_anything)
        {
            // If we're here this can mean:
            //  - We're expecting class name
            //  - We're expecting id name
            //  - This is the first loop count and we need to
            //    recognize the syntax

            if (expect_class_name)
            {
                if (obj_token->kind != IDENTIFIER)
                {
                    NETLORE_ERROR_NO_EXIT("expected IDENTIFER after DOT");
                    break;
                }

                obj_style->obj_class_name = (const char*)obj_token->value;
                break;
            }
            if (expect_id_name)
            {
                if (obj_token->kind != IDENTIFIER)
                {
                    NETLORE_ERROR_NO_EXIT("expected IDENTIFER after HASH");
                    break;
                }

                obj_style->obj_id_name = (const char*)obj_token->value;
                break;
            }
            else 
            {
                if (obj_token->kind == DOT)
                    expect_class_name = true;
                else if (obj_token->kind == HASH)
                    expect_id_name = true;
                else if (obj_token->kind == IDENTIFIER)
                {
                    obj_style->obj_tag_name = (const char*)obj_token->value;
                    break;
                }
                else 
                {
                    NETLORE_ERROR_NO_EXIT("unexpected CSS token");
                    return obj_style;
                }
            }
        }

        parser->index++;
    }

    return obj_style;
}

bool
njord_css_is_keyword(char* str)
{
    /* TODO: create a css keywords array and compare given str
     *       to element from array */
    
    return false;
}

/* This function can return 0 which just means that
 * actions in this function gone well, 1 when we want
 * to skip to the next loop cycle, 2 for returning 
 * NULL in main called function 
 */
int
njord_css_parse_expect_style_rule_name(css_parser_t* parser, style_t* style, css_parse_style_rules_t* parse_style_rules)
{
    if (parser->curr_token->kind == IDENTIFIER)
    {
        /* 1. Validate is it a correct rule style name
            *    if not send an error and return NULL */
        css_properties_t css_property = njord_parse_css_property(parser->curr_token->value);

        if (css_property == (css_properties_t)-1)
        {
            NETLORE_ERROR_NO_EXIT("unknown css property named `%s`. stopping css parser because of it.", 
                        parser->curr_token->value);

            /* Indicates return NULL */
            return 2; 
        }

        /* 2. Create a new style rule and set expect_style_rule_separator
            *    to true */

        njord_append_style_rule_to_style(style, njord_create_style_rule(css_property, NULL));

        parse_style_rules->expect_style_rule_name      = false;
        parse_style_rules->expect_style_rule_separator = true;

        parser->index++;
        parser->curr_token = parser->lexer->tokens[parser->index];

        /* Indicates continue */
        return 1;
    }
    else 
    {
        NETLORE_ERROR_NO_EXIT("expected identifier as style rule name. stopping css parser because of it.");

        /* Indicates return NULL */
        return 2; 
    }

    /* Shouldn't happened */
    NETLORE_VERIFY_NOT_REACHED();
    return 0; 
}

/* This function can return 0 which just means that
 * actions in this function gone well, 1 when we want
 * to skip to the next loop cycle, 2 for returning 
 * NULL in main called function 
 */
int
njord_css_parse_expect_style_separator(css_parser_t* parser, style_t* style, css_parse_style_rules_t* parse_style_rules)
{
    if (parser->curr_token->kind == COLON)
    {
        parse_style_rules->expect_style_rule_separator = false;
        parse_style_rules->expect_style_rule_value     = true;

        parser->index++;
        parser->curr_token = parser->lexer->tokens[parser->index];

        return 1;
    }
    else 
    {
        NETLORE_ERROR_NO_EXIT("expected colon as style rule separator. stopping css parser because of it.");
        return 2;
    }

    NETLORE_VERIFY_NOT_REACHED();
    return 0;
}

bool
njord_css_is_str_number_hex(char* str)
{
    return str[0] == '#' 
                ? true 
                : false;
}

/* This function can return 0 which just means that
 * actions in this function gone well, 1 when we want
 * to skip to the next loop cycle, 2 for returning 
 * NULL in main called function 
 */
int
njord_css_parse_expect_style_value(css_parser_t* parser, style_t* style, css_parse_style_rules_t* parse_style_rules)
{
    /* How do we parser style rule value? That's a harder one
     * we need to recognize what's the value for example when we 
     * get an identifier which represents color it does mean that
     * is a color when we encounter an 100 token and px token this 
     * means that we want to create a number like value. */

    if (parser->curr_token->kind == IDENTIFIER)
    {
        /* First of all look up isn't it a color */
        netlore_to_lower_string(parser->curr_token->value);
        unsigned long color = 
                njord_get_builtin_color_by_name((const char*)parser->curr_token->value);

        if (color == 0x00000000)
        {
            /* Just set value as an custom ident or keyword */

            css_value_t* css_value = njord_create_css_value(CUSTOM_IDENT, (void*)parser->curr_token->value);

            if (njord_css_is_keyword(parser->curr_token->value))
            {
                css_value->type = KEYWORD_VALUES;
                style->style_rules[style->style_rules_len - 1]->value = css_value;
                // style->style_rules_len++;
                // style->style_rules = (style_rule_t**)
                //         netlore_realloc(style->style_rules, (style->style_rules_len + 1) * sizeof(style_rule_t*));
            }
            else 
            {
                css_value->type = CUSTOM_IDENT;
                style->style_rules[style->style_rules_len - 1]->value = css_value;
                // style->style_rules_len++;
                // style->style_rules = (style_rule_t**)
                //         netlore_realloc(style->style_rules, (style->style_rules_len + 1) * sizeof(style_rule_t*));
            }

            parser->index++;
            parser->curr_token = parser->lexer->tokens[parser->index];

            parse_style_rules->expect_style_rule_name  = true;
            parse_style_rules->expect_style_rule_value = false;

            if (parser->curr_token->kind != SEMICOLON)
                CSS_WAIT_UNTIL_SEMICOLON_OR_END(parser);

            return 1;
        }
        else 
        {
            /* Create a number value for color */

            css_value_t* css_value = njord_create_css_value(INTEGER, (void*)color);
            style->style_rules[style->style_rules_len - 1]->value = css_value;
            // style->style_rules_len++;
            // style->style_rules = (style_rule_t**)
            //         netlore_realloc(style->style_rules, (style->style_rules_len + 1) * sizeof(style_rule_t*));

            parser->index++;
            parser->curr_token = parser->lexer->tokens[parser->index];

            parse_style_rules->expect_style_rule_name  = true;
            parse_style_rules->expect_style_rule_value = false;

            if (parser->curr_token->kind != SEMICOLON)
                CSS_WAIT_UNTIL_SEMICOLON_OR_END(parser);

            return 1;
        }

        return 1;
    }
    else if (parser->curr_token->kind == TOK_NUMBER)
    {
        if (njord_css_is_str_number_hex(parser->curr_token->value) == true)
        {
            /* We have detected that given token number is a hex one, now we
             * need to cut # character and convert it into a normal number
             * and apply it to the css value */
            
            /* Cut # character */
            NETLORE_USE(*parser->curr_token->value++);

            char* end_ptr = (char*)(parser->curr_token->value + (strlen(parser->curr_token->value) * sizeof(char)));
            long long num = strtoll(parser->curr_token->value, &end_ptr, 16);

            // css_value_t* css_value = njord_create_css_value(INTEGER, (void*)num);
            // style->style_rules[style->style_rules_len - 1]->value = css_value;

            return 1;
        }

        /* We have detected that given token numbers isn't a hex base, it's 
         * a decimal one, so basically we need to convert it into a normal
         * number and apply it to the css value */
        
        return 1;
    }
    else 
    {
        NETLORE_DEBUG("for now returning if the curr_token->kind isn't identifier for style value");
        return 2;
    }

    NETLORE_VERIFY_NOT_REACHED();
    return 0;
}

#define CSS_CALL_PARSE_STYLE_RULES_FUNC(parser, style, parse_style_rules, func) ({ \
    int ret = func(parser, style, parse_style_rules);                              \
                                                                                   \
    if (ret == 1)                                                                  \
        continue;                                                                  \
    else if (ret == 2)                                                             \
        return NULL;                                                               \
})

style_t*
njord_css_parse_style_rules(css_parser_t* parser)
{
    /* So how would we parse style rules? That's easy tbh
     * let's look at an example css code where inside {} 
     * are some style rules.
     *
     * body { background-color: green; }
     *
     * Basically what we need to do is take the style rule 
     * token name and find it as an enum property next look
     * out for : and parse the value of it for this it's green
     * so we need to lookup at our builtin colors table
     */

    style_t* style = njord_create_style();

    css_parse_style_rules_t* parse_style_rules = netlore_malloc(sizeof(css_parse_style_rules_t));
    parse_style_rules->expect_style_rule_name      = true;
    parse_style_rules->expect_style_rule_separator = false;
    parse_style_rules->expect_style_rule_value     = false;

    while (true)
    {
        if (parser->curr_token->kind == SEMICOLON)
        {
            parser->index++;
            parser->curr_token = parser->lexer->tokens[parser->index];
            continue;
        }

        if (parser->curr_token->kind == CLOSE_BRACE)
            break;

        if (parse_style_rules->expect_style_rule_name)
        {
            CSS_CALL_PARSE_STYLE_RULES_FUNC(parser, style, parse_style_rules, njord_css_parse_expect_style_rule_name);
        }
        else if (parse_style_rules->expect_style_rule_separator)
        {
            CSS_CALL_PARSE_STYLE_RULES_FUNC(parser, style, parse_style_rules, njord_css_parse_expect_style_separator);
        }
        else if (parse_style_rules->expect_style_rule_value)
        {
            CSS_CALL_PARSE_STYLE_RULES_FUNC(parser, style, parse_style_rules, njord_css_parse_expect_style_value);
        }

        NETLORE_VERIFY_NOT_REACHED();
        break;
    }

    return style;
}

void 
njord_parse_css(css_lexer_t* lexer, dom_t* dom)
{
    css_parser_t* parser = (css_parser_t*)netlore_calloc(1, sizeof(css_parser_t));
    parser->curr_token   = NULL;
    parser->lexer        = lexer;
    parser->index        = 0;
    parser->dom          = dom;

    parser->expect_object_style_name = true;

    for (parser->index = 0; parser->index < lexer->tokens_len; parser->index++)
    {
        parser->curr_token = lexer->tokens[parser->index];
        
        if (parser->expect_object_style_name)
        {
            css_object_style_t* nodes_objects = njord_css_parse_and_find_node_style_object(parser);
            NETLORE_DEBUG("parsed style object: class_name=\"%s\", tag_name=\"%s\", id_name=\"%s\"", 
                          nodes_objects->obj_class_name, 
                          nodes_objects->obj_tag_name,
                          nodes_objects->obj_id_name);

            if (parser->curr_token->kind != OPEN_BRACE)
            {
                /* Wait until we get OPEN_BRACE ('{') as current
                 * token */
                while (true)
                {
                    if (parser->curr_token->kind == OPEN_BRACE)
                        break;
                    
                    parser->index++;
                    parser->curr_token = lexer->tokens[parser->index];
                }
            }

            /* Skip OPEN_BRACE ('{') token */
            parser->index++;
            parser->curr_token = lexer->tokens[parser->index];

            /* Parse style rules */
            style_t* parse_style_rules = njord_css_parse_style_rules(parser);

            if (parse_style_rules == NULL)
            {
                NETLORE_ERROR_NO_EXIT("returned parse_style_rules is equal to NULL");
                return;
            }

            /* FIXME: parse_style_rules->style_rules gives some null values without
             *        any bigger reason. Don't have time rn for fixing it. */

            for (int i = 0; i < (int)parse_style_rules->style_rules_len; i++)
            {
                style_rule_t* rule = parse_style_rules->style_rules[i];

                if (rule == NULL) 
                    continue;

                printf(" - property=%d, rule_value->type=%d ", 
                        rule->property, rule->value->type);

                switch (rule->value->type)
                {
                    case CUSTOM_IDENT:
                        printf("rule_value->value=\"%s\"\n", njord_css_value_get_unwrapped_custom_ident(rule->value));
                        break;
                    case KEYWORD_VALUES:
                        printf("rule_value->value=\"%s\"\n", njord_css_value_get_unwrapped_keyword_values(rule->value));
                        break;
                    case STRING:
                        printf("rule_value->value=\"%s\"\n", njord_css_value_get_unwrapped_string(rule->value));
                        break;
                    case URL:
                        printf("rule_value->value=\"url(%s)\"\n", njord_css_value_get_unwrapped_url(rule->value));
                        break;
                    case INTEGER:
                        printf("rule_value->value=%.8llx\n", (long long)rule->value->ptr_to_value);
                        break;
                    case NUMBER:
                        break;
                    case DIMENSIONS:
                        break;
                    case PERCENTAGE:
                        break;
                    default:
                        printf("\n");
                        break;
                }
            }

            if (parser->curr_token->kind != CLOSE_BRACE)
            {
                NETLORE_ERROR_NO_EXIT("expected CLOSE_BRACE after style rules");
                break;
            }

            parser->expect_object_style_name = true;
        }
    }
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