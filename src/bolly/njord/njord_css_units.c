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


#include <netlore/bolly/njord/njord_css_units.h>

#include <netlore/netlore.h>
#include <netlore/netlore_utils.h>

#include <netlore/bolly/njord/njord_css_properties.h>
#include <netlore/bolly/njord/njord_css_value.h>
#include <netlore/bolly/njord/njord_css.h>

css_unit_type_t
njord_css_unit_convert_from_str(char* unit_str)
{
    if (strcmp(unit_str, "px") == 0)
        return UNIT_PX;
    if (strcmp(unit_str, "em") == 0)
        return UNIT_EM;
    if (strcmp(unit_str, "ex") == 0)
        return UNIT_EX;
    if (strcmp(unit_str, "cap") == 0)
        return UNIT_CAP;
    if (strcmp(unit_str, "ch") == 0)
        return UNIT_CH;
    if (strcmp(unit_str, "ic") == 0)
        return UNIT_IC;
    if (strcmp(unit_str, "rem") == 0)
        return UNIT_REM;
    if (strcmp(unit_str, "lh") == 0)
        return UNIT_LH;
    if (strcmp(unit_str, "rlh") == 0)
        return UNIT_RLH;
    if (strcmp(unit_str, "vw") == 0)
        return UNIT_VW;
    if (strcmp(unit_str, "vh") == 0)
        return UNIT_VH;
    if (strcmp(unit_str, "vi") == 0)
        return UNIT_VI;
    if (strcmp(unit_str, "vb") == 0)
        return UNIT_VB;
    if (strcmp(unit_str, "vmin") == 0)
        return UNIT_VMIN;
    if (strcmp(unit_str, "vmax") == 0)
        return UNIT_VMAX;
    if (strcmp(unit_str, "cm") == 0)
        return UNIT_CM;
    if (strcmp(unit_str, "mm") == 0)
        return UNIT_MM;
    if (strcmp(unit_str, "q") == 0)
        return UNIT_Q;
    if (strcmp(unit_str, "in") == 0)
        return UNIT_IN;
    if (strcmp(unit_str, "pc") == 0)
        return UNIT_PC;
    if (strcmp(unit_str, "pt") == 0)
        return UNIT_PT;
    if (strcmp(unit_str, "px") == 0)
        return UNIT_PX;
    if (strcmp(unit_str, "deg") == 0)
        return UNIT_DEG;
    if (strcmp(unit_str, "grad") == 0)
        return UNIT_GRAD;
    if (strcmp(unit_str, "rad") == 0)
        return UNIT_RAD;
    if (strcmp(unit_str, "turn") == 0)
        return UNIT_TURN;
    if (strcmp(unit_str, "sec") == 0)
        return UNIT_SEC;
    if (strcmp(unit_str, "ms") == 0)
        return UNIT_MS;
    if (strcmp(unit_str, "hz") == 0)
        return UNIT_HZ;
    if (strcmp(unit_str, "khz") == 0)
        return UNIT_KHZ;
    if (strcmp(unit_str, "fr") == 0)
        return UNIT_FR;
    if (strcmp(unit_str, "dpi") == 0)
        return UNIT_DPI;
    if (strcmp(unit_str, "dpcm") == 0)
        return UNIT_DPCM;
    if (strcmp(unit_str, "dppx") == 0)
        return UNIT_DPPX;

    return -1;
}

char*
njord_css_unit_convert_to_str(css_unit_type_t unit_type)
{
    if (unit_type == UNIT_EM)
            return "em";
    if (unit_type == UNIT_EX)
            return "ex";
    if (unit_type == UNIT_CAP)
            return "cap";
    if (unit_type == UNIT_CH)
            return "ch";
    if (unit_type == UNIT_IC)
            return "ic";
    if (unit_type == UNIT_REM)
            return "rem";
    if (unit_type == UNIT_LH)
            return "lh";
    if (unit_type == UNIT_RLH)
            return "rlh";
    if (unit_type == UNIT_VW)
            return "vw";
    if (unit_type == UNIT_VH)
            return "vh";
    if (unit_type == UNIT_VI)
            return "vi";
    if (unit_type == UNIT_VB)
            return "vb";
    if (unit_type == UNIT_VMIN)
            return "vmin";
    if (unit_type == UNIT_VMAX)
            return "vmax";
    if (unit_type == UNIT_CM)
            return "cm";
    if (unit_type == UNIT_MM)
            return "mm";
    if (unit_type == UNIT_Q)
            return "q";
    if (unit_type == UNIT_IN)
            return "in";
    if (unit_type == UNIT_PC)
            return "pc";
    if (unit_type == UNIT_PT)
            return "pt";
    if (unit_type == UNIT_PX)
            return "px";
    if (unit_type == UNIT_DEG)
            return "deg";
    if (unit_type == UNIT_GRAD)
            return "grad";
    if (unit_type == UNIT_RAD)
            return "rad";
    if (unit_type == UNIT_TURN)
            return "turn";
    if (unit_type == UNIT_SEC)
            return "sec";
    if (unit_type == UNIT_MS)
            return "ms";
    if (unit_type == UNIT_HZ)
            return "hz";
    if (unit_type == UNIT_KHZ)
            return "khz";
    if (unit_type == UNIT_FR)
            return "fr";
    if (unit_type == UNIT_DPI)
            return "dpi";
    if (unit_type == UNIT_DPCM)
            return "dpcm";
    if (unit_type == UNIT_DPPX)
            return "dppx";

    return " unknown unit";
}