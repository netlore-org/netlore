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

#include <netlore/bolly/njord/njord_css_value.h>

css_dimensions_t* 
njord_create_css_dimension(css_unit_type_t unit_type, long double value)
{
    css_dimensions_t* dimension = (css_dimensions_t*)netlore_calloc(1, sizeof(css_dimensions_t));

    dimension->unit_type = unit_type;
    dimension->value = value;

    return dimension;
}

css_value_t* 
njord_create_css_value(css_value_type_t type, void* ptr_to_value)
{
    if (ptr_to_value == NULL) 
        return NULL;
    
    css_value_t* value = (css_value_t*)netlore_calloc(1, sizeof(css_value_t));

    value->ptr_to_value = ptr_to_value;
    value->type = type;
}

/* Returns NULL on error or when the value type
 * is not CUSTOM_IDENT or KEYWORD_VALUES */
char* 
njord_css_value_get_unwrapped_custom_ident(css_value_t* css_value)
{
    if (css_value->type != CUSTOM_IDENT || css_value->type != KEYWORD_VALUES)
        return NULL;

    return (char*)css_value->ptr_to_value;
}

/* Returns NULL on error or when the value type
 * is not KEYWORD_VALUES or CUSTOM_IDENT */
char* 
njord_css_value_get_unwrapped_keyword_values(css_value_t* css_value)
{
    if (css_value->type != CUSTOM_IDENT || css_value->type != KEYWORD_VALUES)
        return NULL;

    return (char*)css_value->ptr_to_value;
}

/* Returns NULL on error or when the value type
 * is not STRING */
char* 
njord_css_value_get_unwrapped_string(css_value_t* css_value)
{
    if (css_value->type != STRING)
        return NULL;

    return (char*)css_value->ptr_to_value;
}

/* Returns NULL on error or when the value type
 * is not URL */
char* 
njord_css_value_get_unwrapped_url(css_value_t* css_value)
{
    if (css_value->type != URL)
        return NULL;

    return (char*)css_value->ptr_to_value;
}

/* Returns NULL on error or when the value type
 * is not INTEGER */
long* 
njord_css_value_get_unwrapped_integer(css_value_t* css_value)
{
    if (css_value->type != INTEGER)
        return NULL;

    return ((long*)(&css_value->ptr_to_value));
}

/* Returns NULL on error or when the value type
 * is not NUMBER */
long double* 
njord_css_value_get_unwrapped_number(css_value_t* css_value)
{
    if (css_value->type != NUMBER)
        return NULL;

    return ((long double*)(&css_value->ptr_to_value));
}

/* Returns NULL on error or when the value type
 * is not DIMENSIONS */
css_dimensions_t* 
njord_css_value_get_unwrapped_dimensions(css_value_t* css_value)
{
    if (css_value->type != DIMENSIONS)
        return NULL;

    return (css_dimensions_t*)css_value->ptr_to_value;
}

/* Returns NULL on error or when the value type
 * is not PERCENTAGE */
long double* 
njord_css_value_get_unwrapped_percentage(css_value_t* css_value)
{
    if (css_value->type != PERCENTAGE)
        return NULL;

    return ((long double*)(&css_value->ptr_to_value));
}