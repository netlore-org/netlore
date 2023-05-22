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

#include <netlore/netlore_utils.h>
#include <netlore/netlore.h>

#include <netlore/bolly/njord/njord_html_tok.h>
#include <netlore/bolly/njord/njord_html.h>
#include <netlore/bolly/njord/njord_node.h>
#include <netlore/bolly/njord/njord_dom.h>

void 
njord_append_token(html_lexer_t* lexer, html_token_t* token)
{
    lexer->tokens_len++;
    lexer->tokens[lexer->tokens_len - 1] = token;
    lexer->tokens = (html_token_t**)
                            netlore_realloc(lexer->tokens, (lexer->tokens_len + 1) * sizeof(html_token_t*));
}

html_lexer_t* 
njord_tokenize_html(const char* value)
{
    html_lexer_t* lexer = (html_lexer_t*)netlore_calloc(1, sizeof(html_lexer_t));

    lexer->tokens     = (html_token_t**)netlore_calloc(1, sizeof(html_token_t*));
    lexer->value      = value;
    lexer->tokens_len = 0;
    lexer->curr_char  = 0;
    lexer->index      = 0;

    lexer->tag_content_opened = true;

    NETLORE_DEBUG("tokenizing html");
    NETLORE_DEBUG("input: \"%s\"", lexer->value);

    /* Start the for loops which will end at the end of lexer->value */
    for (lexer->index = 0; lexer->index < (int)strlen(lexer->value); lexer->index++)
    {
        /* Get the current character*/
        njord_html_advance(lexer, 0);

        if (lexer->curr_char == '<')
        {
            /* If the curr_char is < we add a new TAG_OPEN token
             * and set some important values up */
            njord_append_token(lexer, njord_html_create_token(TAG_OPEN, "<"));

            lexer->tag_is_opened    = true;
            lexer->tag_expect_name  = true;
            lexer->tag_expect_attrs = false;
        }
        else if (lexer->curr_char == '>')
        {
            /* If the curr_char is > we add a new TAG_END token
             * and set some important values up */
            njord_append_token(lexer, njord_html_create_token(TAG_END, ">"));  

            lexer->tag_expect_attrs   = false;
            lexer->tag_expect_name    = false;
            lexer->tag_is_opened      = false;
            lexer->tag_content_opened = true;
        }
        else if (lexer->curr_char == '/')
        {
            /* Just a TAG_DIV token which is used after < indicating 
             * closing tag, here's an example:
             * 
             * (...)
             * <  /  html  > 
             *    ↑
             *  ---------------------
             *  | This is it        |
             *  | as said indicates |
             *  | end tag           |
             *  --------------------
             */
            njord_append_token(lexer, njord_html_create_token(TAG_DIV, "/"));
        }
        else if (lexer->tag_is_opened)
        {
            /* If tag is opened means is the lexer in state
             * of opened tag "braces" here's what i mean
             *
             * < (tag_is_opened = true) ... > (tag_is_opened = false)
             */
            if (lexer->tag_expect_name)
            {
                /* If we expect an name of tag */

                /* When the name starts with \n or \t we just
                 * skip it because we don't need a name like this */
                if (lexer->curr_char == '\n' || lexer->curr_char == '\t') 
                    continue;

                /* Create a new token so we have an allocated string 
                 * token value which would be used to appending the
                 * tag name */
                html_token_t* tag_name_token = njord_html_create_token(TAG_NAME, "");
                while (true)
                {
                    /* If we hit any of these characters break the name
                     * appending process */
                    if (lexer->curr_char == ' '  || lexer->curr_char == '>' ||
                        lexer->curr_char == '\0' || lexer->curr_char == '/')
                        break;

                    /* We don't new lines or tabs in tag names at all */
                    if (lexer->curr_char == '\n' || lexer->curr_char == '\t') njord_html_advance(lexer, 1);
                
                    /* Append the character to allocated token string 
                     * and then skip to the next character in the
                     * html text buffer */
                    tag_name_token->value = netlore_append_to_alloc_string(tag_name_token->value, lexer->curr_char);
                    njord_html_advance(lexer, 1);
                }
                njord_append_token(lexer, tag_name_token);

                /* If the character after the tag name is any of them
                 * just perform some actions */
                if (lexer->curr_char == '>')
                {
                    /* If the curr_char is > we add a new TAG_END token
                     * and set some important values up */
                    njord_append_token(lexer, njord_html_create_token(TAG_END, ">"));  

                    lexer->tag_expect_attrs = false;
                    lexer->tag_expect_name  = false;
                    lexer->tag_is_opened    = false;
                    lexer->tag_content_opened = true;
                }
                else if (lexer->curr_char == '/')
                {
                    /* Just a TAG_DIV token which is used after < indicating 
                     * closing tag, here's an example:
                     * 
                     * (...)
                     * <  /  html  > 
                     *    ↑
                     *  ---------------------
                     *  | This is it        |
                     *  | as said indicates |
                     *  | end tag           |
                     *  --------------------
                     */
                    njord_append_token(lexer, njord_html_create_token(TAG_DIV, "/"));
                }
                else if (lexer->curr_char == ' ')
                {
                    /* If we hit a space we perform actions on setting some 
                     * important values for the lexer work */
                    lexer->tag_expect_attrs = true;
                    lexer->tag_expect_name  = false;
                    lexer->tag_is_opened    = true;
                }
            }
            else if (lexer->tag_expect_attrs)
            {
                /* Parse some attributes that are inside 
                 * the tag*/

                /* When the name starts with \n or \t we just
                 * skip it because we don't need a name like this */
                if (lexer->curr_char == '\n' || lexer->curr_char == '\t') 
                    continue;

                /* Create a new token so we have an allocated string 
                 * token value which would be used to appending the
                 * attribute name */
                html_token_t* attr_name_token = njord_html_create_token(ATTR_NAME, "");
                while (true)
                {
                    /* If we hit any of these characters break the name
                     * appending process */
                    if (lexer->curr_char == ' '  || lexer->curr_char == '>' ||
                        lexer->curr_char == '\0' || lexer->curr_char == '/' ||
                        lexer->curr_char == '=')
                        break;

                    /* Skip \n or \t */
                    if (lexer->curr_char == '\n' || lexer->curr_char == '\t') njord_html_advance(lexer, 1);
                
                    /* Append the character to allocated token string 
                     * and then skip to the next character in the
                     * html text buffer */
                    attr_name_token->value = netlore_append_to_alloc_string(attr_name_token->value, lexer->curr_char);
                    njord_html_advance(lexer, 1);
                }
                njord_append_token(lexer, attr_name_token);

                /* If the character after the tag name is any of them
                 * just perform some actions */
                if (lexer->curr_char == '>')
                {
                    /* If the curr_char is > we add a new TAG_END token
                     * and set some important values up */
                    njord_append_token(lexer, njord_html_create_token(TAG_END, ">"));  

                    lexer->tag_expect_attrs   = false;
                    lexer->tag_expect_name    = false;
                    lexer->tag_is_opened      = false;
                    lexer->tag_content_opened = true;
                }
                else if (lexer->curr_char == '/')
                {
                    /* Just a TAG_DIV token which is used after < indicating 
                     * closing tag, here's an example:
                     * 
                     * (...)
                     * <  /  html  > 
                     *    ↑
                     *  ---------------------
                     *  | This is it        |
                     *  | as said indicates |
                     *  | end tag           |
                     *  --------------------
                     */
                    njord_append_token(lexer, njord_html_create_token(TAG_DIV, "/"));
                }
                else if (lexer->curr_char == '=')
                {
                    /* After TAG_NAME we expect an TAG_EQ which is just an 
                     * '=' character */
                    njord_append_token(lexer, njord_html_create_token(ATTR_EQ, "="));
                    njord_html_advance(lexer, 2);

                    /* Collect TAG_VALUE after TAG_EQ */
                    html_token_t* attr_value_token = njord_html_create_token(ATTR_VALUE, "");
                    while (true)
                    {
                        /* If we hit any of them just break the loop */
                        if (lexer->curr_char == '\0' || lexer->curr_char == '\"')
                            break;

                        /* Allocate character to string which is allocated */
                        attr_value_token->value = netlore_append_to_alloc_string(attr_value_token->value, lexer->curr_char);
                        njord_html_advance(lexer, 1);
                    }

                    njord_append_token(lexer, attr_value_token);
                }
            }
        }
        else if (lexer->tag_content_opened)
        {
            /* When the tag content is opened we just easily parse it
             * here's what we parse
             *
             * <span>
             *
             *     Hello, World   ←----- We parse this thing and get it inside
             *                           a token
             *
             * </span>
             */
            html_token_t* tag_content = njord_html_create_token(CONTENT, "");
            
            /* This property check when the character is 
             * different than ' ' */
            bool already_character = false; 

            while (true)
            {
                /* When we hit any of these character we just
                 * break the loop */
                if (lexer->curr_char == '>' || lexer->curr_char == '\0' ||
                    lexer->curr_char == '<'                                )
                    break;

                /* Just skip this character when we find out
                 * the curr_char is \n or \t */
                if (lexer->curr_char == '\n' || lexer->curr_char == '\t') 
                {
                    njord_html_advance(lexer, 1);
                    continue;
                }

                /* When the character is different than ' ' we
                 * set already_character to true */
                if (lexer->curr_char != ' ')
                    already_character = true;

                /* Append character to string */
                if (already_character == true)
                    tag_content->value = netlore_append_to_alloc_string(tag_content->value, lexer->curr_char);
                njord_html_advance(lexer, 1);
            }
            njord_append_token(lexer, tag_content);

            if (lexer->curr_char == '<')
            {
                /* If the curr_char is < we add a new TAG_OPEN token
                 * and set some important values up */
                njord_append_token(lexer, njord_html_create_token(TAG_OPEN, "<"));

                lexer->tag_is_opened    = true;
                lexer->tag_expect_name  = true;
                lexer->tag_expect_attrs = false;
            }
            if (lexer->curr_char == '>')
            {
                /* If the curr_char is > we add a new TAG_END token
                 * and set some important values up */
                njord_append_token(lexer, njord_html_create_token(TAG_END, ">"));  

                lexer->tag_expect_attrs   = false;
                lexer->tag_expect_name    = false;
                lexer->tag_is_opened      = false;
                lexer->tag_content_opened = true;
            }
        }
    }

    return lexer;
}

void 
njord_html_advance(html_lexer_t* html, int count)
{
    /* Advance html character buffer */
    html->index     += count;
    html->curr_char =  html->value[html->index];
}

void
njord_is_node_style(dom_t* dom, dom_node_t* node)
{
    /* Does this node even represents <style> tag */
    if (strcmp(node->tag, "style") != 0) return;

    /* Get the CSS Style content, the easiest way
     * to get it is just collecting the first children
     * node and check does it represents content node */
    if (node->childrens_len == 0   ) return;
    if (node->childrens[0]  == NULL) return;

    dom_node_t* first_children = node->childrens[0];

    if (strcmp(first_children->tag, "__tag") == 0)
    {
        /* Now we know that this is a correct <style> tag,
         * so we append it to the global dom field named
         * style_nodes in which we store all css nodes.
         * After HTML Parsing we will parse this css too
         * and apply all styles to DOM Nodes */
        dom->style_nodes[dom->style_nodes_len] = first_children;
        dom->style_nodes_len++;

        dom->style_nodes = netlore_realloc(dom->style_nodes, sizeof(dom_node_t*) * (dom->style_nodes_len + 1));
    }
}

/* Simple function for getting the last stack element */
dom_node_t*
njord_parse_get_last_stack_element(dom_t* dom, dom_node_t* stack[1024], int stack_len)
{
    for (int i = stack_len; i >= 0; i--)
    {
        if (stack[i] == NULL) continue;
        
        return stack[i];
    }

    NETLORE_ERROR_NO_EXIT("couldn't get the last stack element");
    return NULL;
}

void
njord_loop_through_node_styles(dom_t* dom, dom_node_t* node)
{
    for (int i = 0; i < (int)node->childrens_len; i++)
    {
        njord_is_node_style(dom, node->childrens[i]);
        njord_loop_through_node_styles(dom, node->childrens[i]);
    }
}

void 
njord_parse_html(html_lexer_t* lexer, dom_t* dom)
{
    dom_node_t* stack[1024];
    int stack_len = 0;

    stack[0] = dom->root_node;

    dom->style_nodes     = netlore_calloc(1, sizeof(dom_node_t*));
    dom->style_nodes_len = 0;

    NETLORE_DEBUG("parsing html tokens into a DOM Tree");

    for (int i = 0; i < lexer->tokens_len; i++)
    {
        html_token_t* token = lexer->tokens[i];

        if (token->kind == TAG_OPEN)
        {
            /* Get TAG_NAME token */
            i++;
            token = lexer->tokens[i];

            if (token == NULL)
            {
                NETLORE_ERROR_NO_EXIT("parser_error: expected token after TAG_OPEN");
                break;
            }

            if (!(token->kind == TAG_NAME || token->kind == TAG_DIV))
            {
                NETLORE_ERROR_NO_EXIT("parser_error: expected TAG_NAME or TAG_DIV after TAG_OPEN");
                break;
            }

            bool tag_end = false;
            if (token->kind == TAG_DIV)
            {
                i++;
                token = lexer->tokens[i];
                tag_end = true;

                if (token == NULL)
                {
                    NETLORE_ERROR_NO_EXIT("parser_error: expected token after TAG_DIV");
                    break;
                }

                if (token->kind != TAG_NAME)
                {
                    NETLORE_ERROR_NO_EXIT("parser_error: expected TAG_NAME after TAG_DIV");
                    break;
                }
            }

            char* tag_name = token->value;

            /* Are they some attrs? */
            i++;
            token = lexer->tokens[i];

            if (token == NULL)
            {
                NETLORE_ERROR_NO_EXIT("parser_error: expected token after TAG_NAME");
                break;
            }

            attribute_t** attrs = njord_create_attributes_list();

            if (token->kind == TAG_END)
            {
                if (tag_end == true)
                {
                    dom_node_t* stack_element = NULL;
                    int i = 0;
                        
                    for (i = stack_len; i >= 0; i--)
                    {
                        stack_element = stack[i];

                        if (stack_element == NULL)
                            continue;
                        if (strcmp(stack_element->tag, tag_name) == 0)
                            break;
                    }

                    if (i == 0 && stack_element == dom->root_node)
                    {
                        // This if condition check does this loop didn't got too 
                        // far, which basically means that the given HTML have an
                        // bug with a closing tag that doesn't close anything
                        continue;
                    }

                    stack[i] = NULL;
                }
                else 
                {
                    dom_node_t* parent_node = njord_parse_get_last_stack_element(dom, stack, stack_len);

                    if (parent_node == NULL)
                        parent_node = dom->root_node;

                    stack_len++;
                    stack[stack_len] = njord_create_node(tag_name, "", parent_node, attrs, 
                                                         njord_create_render_box_empty(), NULL);
                    njord_add_children(parent_node, stack[stack_len]);
                }

            }
            else if ((token->kind == ATTR_NAME || token->kind == ATTR_VALUE) && tag_end == false)
            {
                dom_node_t* parent_node = njord_parse_get_last_stack_element(dom, stack, stack_len);

                if (parent_node == NULL)
                    parent_node = dom->root_node;

                stack_len++;
                stack[stack_len] = njord_create_node(tag_name, "", parent_node, attrs, 
                                                        njord_create_render_box_empty(), NULL);
                
                bool expect_token_name  = true;
                bool expect_token_value = false;
                bool expect_token_eq    = false;

                dom_node_t* node = stack[stack_len];

                while (true)
                {
                    if (!(token->kind == ATTR_NAME || token->kind == ATTR_VALUE || token->kind == ATTR_EQ))
                        break;
                    

                    if (expect_token_name)
                    {
                        if (token->kind == ATTR_NAME)
                        {
                            if (token->value[0] == '\0')
                            {
                                i++;
                                token = lexer->tokens[i];
                                continue;
                            }

                            njord_add_node_attribute(node, token->value, "");

                            i++;
                            token = lexer->tokens[i];

                            expect_token_name  = false;
                            expect_token_value = false;
                            expect_token_eq    = true;
                            continue;
                        }
                    }
                    else if (expect_token_value)
                    {
                        if (token->kind == ATTR_VALUE)
                        {
                            node->attrs[node->attrs_len - 1]->value = netlore_create_copy_string(token->value);
                            i++;
                            token = lexer->tokens[i];

                            expect_token_name  = true;
                            expect_token_value = false;
                            expect_token_eq    = false;
                            continue;
                        }
                    }
                    else if (expect_token_eq)
                    {
                        if (token->kind == ATTR_EQ)
                        {
                            i++;
                            token = lexer->tokens[i];

                            expect_token_name  = false;
                            expect_token_value = true;
                            expect_token_eq    = false;
                            continue;
                        }
                        else if (token->kind == ATTR_NAME)
                        {
                            if (token->value[0] == '\0')
                            {
                                i++;
                                token = lexer->tokens[i];
                                continue;
                            }
                            
                            njord_add_node_attribute(node, token->value, "");

                            i++;
                            token = lexer->tokens[i];

                            expect_token_name  = false;
                            expect_token_value = false;
                            expect_token_eq    = true;
                            continue;
                        }
                    }

                    i++;
                    token = lexer->tokens[i];
                }
                
                njord_add_children(parent_node, stack[stack_len]);
            }
            else 
            {
                if (tag_end == true)
                {
                    dom_node_t* stack_element = NULL;
                    int i = 0;

                    for (i = stack_len; i >= 0; i--)
                    {
                        stack_element = stack[i];

                        if (stack_element == NULL)
                            continue;
                        if (strcmp(stack_element->tag, tag_name))
                            break;
                    }

                    if (i == 0 && stack_element == dom->root_node)
                    {
                        // This if condition check does this loop didn't got too 
                        // far, which basically means that the given HTML have an
                        // bug with a closing tag that doesn't close anything
                        continue;
                    }

                    stack[i] = NULL;
                }

                NETLORE_ERROR_NO_EXIT("parser_error: expected token ATTR_NAME, ATTR_VALUE or TAG_END after TAG_NAME");
                break;            
            }
        }
        else if (token->kind == CONTENT)
        {
            if (token->value[0] == '\0') continue;
            
            dom_node_t* parent_node = njord_parse_get_last_stack_element(dom, stack, stack_len);

            dom_node_t* node = njord_create_node("__tag", token->value, parent_node, njord_create_attributes_list(), 
                                                 njord_create_render_box_empty(), NULL);
            njord_add_children(parent_node, node);
        }
        else 
            continue;
    }

    for (int i = 0; i < (int)dom->root_node->childrens_len; i++)
    {
        njord_is_node_style(dom, dom->root_node->childrens[i]);
        njord_loop_through_node_styles(dom, dom->root_node->childrens[i]);
    }
    // njord_dump_tree(dom, dom->root_node, 0);
}
