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

#ifndef __NETLORE_NJORD_CSS_VALUE
#define __NETLORE_NJORD_CSS_VALUE

/* https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Values_and_Units */
typedef enum __css_value_type_t {
  /* Textual data types */

  /* It's just an custom identifier given by CSS 
   * To get value of it you need to call 
   * njord_css_value_get_unwrapped_custom_ident();
   */
  CUSTOM_IDENT,

  /* 
   * The same thing as CUSTOM_IDENT so if you would 
   * call function for CUSTOM_IDENT it would return
   * the KEYWORD_VALUES value
   *
   * Function for this type is 
   * njord_css_value_get_unwrapped_keyword_values();
   */
  KEYWORD_VALUES,

  /*
   * Just a string between ", Function for getting 
   * unwrapped value is 
   * njord_css_value_get_unwrapped_string();
   */
  STRING,

  /*
   * URL type is an value between url(value); To
   * get unwrapped value is 
   * njord_css_value_get_unwrapped_url();
   */
  URL,

  /* Numeric data types */

  /* An integer is one or more decimal digits, 0 through 9,
   * such as 1024 or -55. An integer may be preceded by a +
   * or - symbol, with no space between the symbol and the
   * integer.
   *
   * To get an unwrapped integer call
   * njord_css_value_get_unwrapped_integer(); if returned
   * pointer is NULL this means that CSS value isn't INTEGER 
   */
  INTEGER,

  /* A number represents a real number, which may or may
   * not have a decimal point with a fractional component,
   * for example 0.255, 128 or -1.2. Numbers may also be
   * preceded by a + or - symbol.
   *
   * To get an unwrapped number
   * call njord_css_value_get_unwrapped_number(); if returned
   * pointer is NULL this means that CSS value isn't NUMBER 
   */
  NUMBER,

  /* A dimension is a number with a unit attached to it, for 
   * example 45deg, 100ms, or 10px. The attached unit identifier 
   * is case insensitive. There is never a space or any other 
   * characters between the number and the unit identifier: i.e. '
   * 1 cm is not valid.
   *
   * CSS uses dimensions to specify:
   *  - length
   *  - angle
   *  - time
   *  - frequency
   *  - flex
   *  - resolution
   *
   * All of units are here: https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Values_and_Units#dimensions
   *
   * To get an unwrapped dimension you need to call function named
   * njord_css_value_get_unwrapped_dimensions(); which returns a pointer
   * to css_dimensions_t structure which represents the number and given
   * unit identifier.  
   */
  DIMENSIONS,

  /* A <percentage> is a type that represents a fraction of some other value.
   *
   * Percentage values are always relative to another quantity, for example 
   * a length. Each property that allows percentages also defines the quantity 
   * to which the percentage refers. This quantity can be a value of another 
   * property of the same element, the value of a property of an ancestor element,
   * a measurement of a containing block, or something else.
   *
   * To get an unwrapped percentage you need to call function named 
   * njord_css_value_get_unwrapped_percentage(); which will return double type
   * value.
   */
  PERCENTAGE,

} css_value_type_t;

typedef struct __css_value_t {
  css_value_type_t type;
  void *ptr_to_value;
} css_value_t;

/* https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Values_and_Units#dimensions */
typedef enum __css_unit_type_t {
  /* Distance units */
  UNIT_EM,
  UNIT_EX,
  UNIT_CAP,
  UNIT_CH,
  UNIT_IC,
  UNIT_REM,
  UNIT_LH,
  UNIT_RLH,
  UNIT_VW,
  UNIT_VH,
  UNIT_VI,
  UNIT_VB,
  UNIT_VMIN,
  UNIT_VMAX,

  /* TODO: maybe some day implement cqw, cqh and other ones */

  UNIT_CM, 
  UNIT_MM, 
  UNIT_Q, // Quater-millimeter who the frick uses it
  UNIT_IN, 
  UNIT_PC, 
  UNIT_PT, 
  UNIT_PX, 

  /* Angle units */
  UNIT_DEG,
  UNIT_GRAD,
  UNIT_RAD,
  UNIT_TURN,

  /* Time units */
  UNIT_SEC, 
  UNIT_MS, 

  /* Frequency units */
  UNIT_HZ,
  UNIT_KHZ,

  /* Flex unit, probably we will never 
   * support this type */
  UNIT_FR,

  /* Resolution units */
  UNIT_DPI,
  UNIT_DPCM,
  UNIT_DPPX,
} css_unit_type_t;

typedef struct __css_dimensions_t {
  css_unit_type_t unit_type;
  long double value;
} css_dimensions_t;

css_dimensions_t* njord_create_css_dimension(css_unit_type_t unit_type, long double value);

css_value_t* njord_create_css_value(css_value_type_t type, void* ptr_to_value);

/* Returns NULL on error or when the value type
 * is not CUSTOM_IDENT or KEYWORD_VALUES */
char* njord_css_value_get_unwrapped_custom_ident(css_value_t* css_value);

/* Returns NULL on error or when the value type
 * is not KEYWORD_VALUES or CUSTOM_IDENT */
char* njord_css_value_get_unwrapped_keyword_values(css_value_t* css_value);

/* Returns NULL on error or when the value type
 * is not STRING */
char* njord_css_value_get_unwrapped_string(css_value_t* css_value);

/* Returns NULL on error or when the value type
 * is not URL */
char* njord_css_value_get_unwrapped_url(css_value_t* css_value);

/* Returns NULL on error or when the value type
 * is not INTEGER */
long long* njord_css_value_get_unwrapped_integer(css_value_t* css_value);

/* Returns NULL on error or when the value type
 * is not NUMBER */
long double* njord_css_value_get_unwrapped_number(css_value_t* css_value);

/* Returns NULL on error or when the value type
 * is not DIMENSIONS */
css_dimensions_t* njord_css_value_get_unwrapped_dimensions(css_value_t* css_value);

/* Returns NULL on error or when the value type
 * is not PERCENTAGE */
long double* njord_css_value_get_unwrapped_percentage(css_value_t* css_value);

#endif /* __NETLORE_NJORD_CSS_VALUE */