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

#include <netlore/bolly/njord/njord_style.h>
#include <netlore/bolly/njord/njord_css_properties.h>
#include <netlore/bolly/njord/njord_css_value.h>
#include <netlore/bolly/njord/njord_dom.h>

style_t* 
njord_create_style()
{
    style_t* style = (style_t*)netlore_calloc(1, sizeof(style_t));

    style->style_rules     = (style_rule_t**)netlore_calloc(1, sizeof(style_rule_t*));
    style->style_rules_len = 0;

    return style;
}

void 
njord_append_style_rule_to_style(style_t* style, style_rule_t* style_rule)
{
    style->style_rules_len++;
    style->style_rules = (style_rule_t**)netlore_realloc(style->style_rules, (style->style_rules_len + 1) * sizeof(style_rule_t*));
    style->style_rules[style->style_rules_len - 1] = style_rule;
}

style_rule_t* 
njord_create_style_rule(css_properties_t property, css_value_t* value)
{
    style_rule_t* style_rule = (style_rule_t*)netlore_calloc(1, sizeof(style_rule_t));

    style_rule->property = property;
    style_rule->value    = value;

    return style_rule;
}