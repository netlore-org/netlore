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

#include <netlore/bolly/njord/njord_builtin_colors.h>
#include <netlore/bolly/heimdall/heimdall_rgb.h>

builtin_color_t builtin_colors[] = {
    { "aliceblue", { 0xf0, 0xf8, 0xff, 0xff } },
    {
      "antiquewhite",
      { 0xfa, 0xeb, 0xd7, 0xff }
    },
    { "aqua", { 0x00, 0xff, 0xff, 0xff } },
    { "aquamarine", { 0x7f, 0xff, 0xd4, 0xff } },
    { "azure", { 0xf0, 0xff, 0xff, 0xff } },
    { "beige", { 0xf5, 0xf5, 0xdc, 0xff } },
    { "bisque", { 0xff, 0xe4, 0xc4, 0xff } },
    { "black", { 0x00, 0x00, 0x00, 0xff } },
    {
      "blanchedalmond",
      { 0xff, 0xeb, 0xcd, 0xff }
    },
    { "blue", { 0x00, 0x00, 0xff, 0xff } },
    { "blueviolet", { 0x8a, 0x2b, 0xe2, 0xff } },
    { "brown", { 0xa5, 0x2a, 0x2a, 0xff } },
    { "burlywood", { 0xde, 0xb8, 0x87, 0xff } },
    { "cadetblue", { 0x5f, 0x9e, 0xa0, 0xff } },
    { "chartreuse", { 0x7f, 0xff, 0x00, 0xff } },
    { "chocolate", { 0xd2, 0x69, 0x1e, 0xff } },
    { "coral", { 0xff, 0x7f, 0x50, 0xff } },
    {
      "cornflowerblue",
      { 0x64, 0x95, 0xed, 0xff }
    },
    { "cornsilk", { 0xff, 0xf8, 0xdc, 0xff } },
    { "crimson", { 0xdc, 0x14, 0x3c, 0xff } },
    { "cyan", { 0x00, 0xff, 0xff, 0xff } },
    { "darkblue", { 0x00, 0x00, 0x8b, 0xff } },
    { "darkcyan", { 0x00, 0x8b, 0x8b, 0xff } },
    {
      "darkgoldenrod",
      { 0xb8, 0x86, 0x0b, 0xff }
    },
    { "darkgray", { 0xa9, 0xa9, 0xa9, 0xff } },
    { "darkgrey", { 0xa9, 0xa9, 0xa9, 0xff } },
    { "darkgreen", { 0x00, 0x64, 0x00, 0xff } },
    { "darkkhaki", { 0xbd, 0xb7, 0x6b, 0xff } },
    { "darkmagenta", { 0x8b, 0x00, 0x8b, 0xff } },
    {
      "darkolivegreen",
      { 0x55, 0x6b, 0x2f, 0xff }
    },
    { "darkorange", { 0xff, 0x8c, 0x00, 0xff } },
    { "darkorchid", { 0x99, 0x32, 0xcc, 0xff } },
    { "darkred", { 0x8b, 0x00, 0x00, 0xff } },
    { "darksalmon", { 0xe9, 0x96, 0x7a, 0xff } },
    {
      "darkseagreen",
      { 0x8f, 0xbc, 0x8f, 0xff }
    },
    {
      "darkslateblue",
      { 0x48, 0x3d, 0x8b, 0xff }
    },
    {
      "darkslategray",
      { 0x2f, 0x4f, 0x4f, 0xff }
    },
    {
      "darkslategrey",
      { 0x2f, 0x4f, 0x4f, 0xff }
    },
    {
      "darkturquoise",
      { 0x00, 0xce, 0xd1, 0xff }
    },
    { "darkviolet", { 0x94, 0x00, 0xd3, 0xff } },
    { "deeppink", { 0xff, 0x14, 0x93, 0xff } },
    { "deepskyblue", { 0x00, 0xbf, 0xff, 0xff } },
    { "dimgray", { 0x69, 0x69, 0x69, 0xff } },
    { "dimgrey", { 0x69, 0x69, 0x69, 0xff } },
    { "dodgerblue", { 0x1e, 0x90, 0xff, 0xff } },
    { "firebrick", { 0xb2, 0x22, 0x22, 0xff } },
    { "floralwhite", { 0xff, 0xfa, 0xf0, 0xff } },
    { "forestgreen", { 0x22, 0x8b, 0x22, 0xff } },
    { "fuchsia", { 0xff, 0x00, 0xff, 0xff } },
    { "gainsboro", { 0xdc, 0xdc, 0xdc, 0xff } },
    { "ghostwhite", { 0xf8, 0xf8, 0xff, 0xff } },
    { "gold", { 0xff, 0xd7, 0x00, 0xff } },
    { "goldenrod", { 0xda, 0xa5, 0x20, 0xff } },
    { "gray", { 0x80, 0x80, 0x80, 0xff } },
    { "grey", { 0x80, 0x80, 0x80, 0xff } },
    { "green", { 0x00, 0x80, 0x00, 0xff } },
    { "greenyellow", { 0xad, 0xff, 0x2f, 0xff } },
    { "honeydew", { 0xf0, 0xff, 0xf0, 0xff } },
    { "hotpink", { 0xff, 0x69, 0xb4, 0xff } },
    { "indianred", { 0xcd, 0x5c, 0x5c, 0xff } },
    { "indigo", { 0x4b, 0x00, 0x82, 0xff } },
    { "ivory", { 0xff, 0xff, 0xf0, 0xff } },
    { "khaki", { 0xf0, 0xe6, 0x8c, 0xff } },
    { "lavender", { 0xe6, 0xe6, 0xfa, 0xff } },
    {
      "lavenderblush",
      { 0xff, 0xf0, 0xf5, 0xff }
    },
    { "lawngreen", { 0x7c, 0xfc, 0x00, 0xff } },
    {
      "lemonchiffon",
      { 0xff, 0xfa, 0xcd, 0xff }
    },
    { "lightblue", { 0xad, 0xd8, 0xe6, 0xff } },
    { "lightcoral", { 0xf0, 0x80, 0x80, 0xff } },
    { "lightcyan", { 0xe0, 0xff, 0xff, 0xff } },
    {
      "lightgoldenrodyellow",
      { 0xfa, 0xfa, 0xd2, 0xff }
    },
    { "lightgray", { 0xd3, 0xd3, 0xd3, 0xff } },
    { "lightgrey", { 0xd3, 0xd3, 0xd3, 0xff } },
    { "lightgreen", { 0x90, 0xee, 0x90, 0xff } },
    { "lightpink", { 0xff, 0xb6, 0xc1, 0xff } },
    { "lightsalmon", { 0xff, 0xa0, 0x7a, 0xff } },
    {
      "lightseagreen",
      { 0x20, 0xb2, 0xaa, 0xff }
    },
    {
      "lightskyblue",
      { 0x87, 0xce, 0xfa, 0xff }
    },
    {
      "lightslategray",
      { 0x77, 0x88, 0x99, 0xff }
    },
    {
      "lightslategrey",
      { 0x77, 0x88, 0x99, 0xff }
    },
    {
      "lightsteelblue",
      { 0xb0, 0xc4, 0xde, 0xff }
    },
    { "lightyellow", { 0xff, 0xff, 0xe0, 0xff } },
    { "lime", { 0x00, 0xff, 0x00, 0xff } },
    { "limegreen", { 0x32, 0xcd, 0x32, 0xff } },
    { "linen", { 0xfa, 0xf0, 0xe6, 0xff } },
    { "magenta", { 0xff, 0x00, 0xff, 0xff } },
    { "maroon", { 0x80, 0x00, 0x00, 0xff } },
    {
      "mediumaquamarine",
      { 0x66, 0xcd, 0xaa, 0xff }
    },
    { "mediumblue", { 0x00, 0x00, 0xcd, 0xff } },
    {
      "mediumorchid",
      { 0xba, 0x55, 0xd3, 0xff }
    },
    {
      "mediumpurple",
      { 0x93, 0x70, 0xdb, 0xff }
    },
    { "mediumseagreen", { 0x3c, 0xb3, 0x71, 0xff } },
    { "mediumslateblue", { 0x7b, 0x68, 0xee, 0xff } },
    { "mediumspringgreen", { 0x00, 0xfa, 0x9a, 0xff } },
    { "mediumturquoise", { 0x48, 0xd1, 0xcc, 0xff } },
    { "mediumvioletred", { 0xc7, 0x15, 0x85, 0xff } },
    { "midnightblue", { 0x19, 0x19, 0x70, 0xff } },
    { "mintcream", { 0xf5, 0xff, 0xfa, 0xff } },
    { "mistyrose", { 0xff, 0xe4, 0xe1, 0xff } },
    { "moccasin", { 0xff, 0xe4, 0xb5, 0xff } },
    { "navajowhite", { 0xff, 0xde, 0xad, 0xff } },
    { "navy", { 0x00, 0x00, 0x80, 0xff } },
    { "oldlace", { 0xfd, 0xf5, 0xe6, 0xff } },
    { "olive", { 0x80, 0x80, 0x00, 0xff } },
    { "olivedrab", { 0x6b, 0x8e, 0x23, 0xff } },
    { "orange", { 0xff, 0xa5, 0x00, 0xff } },
    { "orangered", { 0xff, 0x45, 0x00, 0xff } },
    { "orchid", { 0xda, 0x70, 0xd6, 0xff } },
    { "palegoldenrod", { 0xee, 0xe8, 0xaa, 0xff } },
    { "palegreen", { 0x98, 0xfb, 0x98, 0xff } },
    { "paleturquoise", { 0xaf, 0xee, 0xee, 0xff } },
    { "palevioletred", { 0xdb, 0x70, 0x93, 0xff } },
    { "papayawhip", { 0xff, 0xef, 0xd5, 0xff } },
    { "peachpuff", { 0xff, 0xda, 0xb9, 0xff } },
    { "peru", { 0xcd, 0x85, 0x3f, 0xff } },
    { "pink", { 0xff, 0xc0, 0xcb, 0xff } },
    { "plum", { 0xdd, 0xa0, 0xdd, 0xff } },
    { "powderblue", { 0xb0, 0xe0, 0xe6, 0xff } },
    { "purple", { 0x80, 0x00, 0x80, 0xff } },
    { "rebeccapurple", { 0x66, 0x33, 0x99, 0xff }},
    { "red", { 0xff, 0x00, 0x00, 0xff } },
    { "rosybrown", { 0xbc, 0x8f, 0x8f, 0xff } },
    { "royalblue", { 0x41, 0x69, 0xe1, 0xff } },
    { "saddlebrown", { 0x8b, 0x45, 0x13, 0xff } },
    { "salmon", { 0xfa, 0x80, 0x72, 0xff } },
    { "sandybrown", { 0xf4, 0xa4, 0x60, 0xff } },
    { "seagreen", { 0x2e, 0x8b, 0x57, 0xff } },
    { "seashell", { 0xff, 0xf5, 0xee, 0xff } },
    { "sienna", { 0xa0, 0x52, 0x2d, 0xff } },
    { "silver", { 0xc0, 0xc0, 0xc0, 0xff } },
    { "skyblue", { 0x87, 0xce, 0xeb, 0xff } },
    { "slateblue", { 0x6a, 0x5a, 0xcd, 0xff } },
    { "slategray", { 0x70, 0x80, 0x90, 0xff } },
    { "slategrey", { 0x70, 0x80, 0x90, 0xff } },
    { "snow", { 0xff, 0xfa, 0xfa, 0xff } },
    { "springgreen", { 0x00, 0xff, 0x7f, 0xff } },
    { "steelblue", { 0x46, 0x82, 0xb4, 0xff } },
    { "tan", { 0xd2, 0xb4, 0x8c, 0xff } },
    { "teal", { 0x00, 0x80, 0x80, 0xff } },
    { "thistle", { 0xd8, 0xbf, 0xd8, 0xff } },
    { "tomato", { 0xff, 0x63, 0x47, 0xff } },
    { "turquoise", { 0x40, 0xe0, 0xd0, 0xff } },
    { "violet", { 0xee, 0x82, 0xee, 0xff } },
    { "wheat", { 0xf5, 0xde, 0xb3, 0xff } },
    { "white", { 0xff, 0xff, 0xff, 0xff } },
    { "whitesmoke", { 0xf5, 0xf5, 0xf5, 0xff } },
    { "yellow", { 0xff, 0xff, 0x00, 0xff } },
    { "yellowgreen", { 0x9a, 0xcd, 0x32, 0xff } }
};

#define GET_BUILTIN_COLORS_ARRAY_LEN() (sizeof(builtin_colors) / sizeof(builtin_color_t))

color_t
njord_get_builtin_color_by_name(const char* color_name)
{
    for (int i = 0; i < njord_get_builtin_color_array_length(); i++)
    {
        if (strcmp(builtin_colors[i].color_name, color_name) == 0)
            return builtin_colors[i].color_struct;
    }

    return heimdall_create_color_rgba(0, 0, 0, 0);
}

builtin_color_t**
njord_get_builtin_color_array()
{
    return (builtin_color_t**)builtin_colors;
}

int 
njord_get_builtin_color_array_length()
{
    return GET_BUILTIN_COLORS_ARRAY_LEN();
}