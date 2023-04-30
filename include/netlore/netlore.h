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

#ifndef __NETLORE_NETLORE
#define __NETLORE_NETLORE

# pragma GCC diagnostic ignored "-Wunused-parameter"

# include <sys/socket.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdlib.h>
# include <stdio.h>

# define NETLORE_CURL
# ifdef NETLORE_CURL
#  include <curl/curl.h>
# endif

# define __netlore_ERROR_HEADER "\e[0;33m%p\e[0;0m %s: \e[0;31merror\e[0;0m: "
# define __netlore_DEBUG_HEADER "\e[0;33m%p\e[0;0m %s: \e[0;32mdebug\e[0;0m: "

# define NETLORE_ERROR(fmt, ...) ({   \
    printf(__netlore_ERROR_HEADER,    \
           __FUNCTION__,              \
           __PRETTY_FUNCTION__);      \
    printf(fmt, ##__VA_ARGS__);       \
    printf("\n");                     \
    exit(1);                          \
})

# define NETLORE_ERROR_NO_EXIT(fmt, ...) ({   \
    printf(__netlore_ERROR_HEADER,            \
           __FUNCTION__,                      \
           __PRETTY_FUNCTION__);              \
    printf(fmt, ##__VA_ARGS__);               \
    printf("\n");                             \
})

# define NETLORE_DEBUG(fmt, ...) ({   \
    printf(__netlore_DEBUG_HEADER,    \
           __FUNCTION__,              \
           __PRETTY_FUNCTION__);      \
    printf(fmt, ##__VA_ARGS__);       \
    printf("\n");                     \
})

# define netlore_malloc  malloc
# define netlore_calloc  calloc
# define netlore_realloc realloc
# define netlore_free    free

# define NETLORE_VERSION "0.2.4"
# define NETLORE_USE(x)  ((void)x)

# define NETLORE_NO_NULL(x) (               \
    (x == NULL)                             \
        ? NETLORE_ERROR("out of memory")    \
        : ((void)x)                         \
)                                           \

# define NETLORE_NOT_IMPLEMENTED() ({                           \
    NETLORE_ERROR_NO_EXIT("this function is not implemented");  \
    return;                                                     \
})                                                              \

#endif /* __NETLORE_NETLORE */