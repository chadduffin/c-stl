// Copyright 2018 Chad S Duffin
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

// This file contains the various generic data structures that are needed
// by all of the containers.

#ifndef __GENERICS__
#define __GENERICS__

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "error.h"

typedef union KEY KEY;
typedef union DATA DATA;
typedef struct ITERATOR ITERATOR;

// @name    union KEY, KEY
// @purpose Provide a structure to act as a key for data structures that store
//          key - value pairs of data.
// @example
//
//          union KEY {
//            int my_num;
//            char *my_string;
//          };

union KEY {
  int number_;
  char *string_;
};

// @name    union DATA, DATA
// @purpose Provide a basic unit of storage for the containers that can be
//          expanded to include other data types.
// @example
//
//          union DATA {
//            int my_num;
//            void *my_void;
//          };

union DATA {
  int my_int;
};

struct ITERATOR {
  bool begin_, end_;
  void *container_;
  void (*next_)(ITERATOR*), (*prev_)(ITERATOR*);
  DATA* (*data_)(ITERATOR*);

  union {
    void *void_;
    unsigned int uint_;
  };
};

void iterator_delete(ITERATOR **iterator);

DATA* iterator_data(ITERATOR *iterator);
void iterator_next(ITERATOR *iterator);
void iterator_prev(ITERATOR *iterator);

// @name    is_less
// @purpose Return true if the data on the left is evaluated to be less than
//          the data on the right.
// @notes   When used with a PRIORITY_QUEUE it creates a minimum heap.

bool is_less(DATA *left, DATA *right);

// @name    is_greater
// @purpose Return true if the data on the left is evaluated to be greater than
//          the data on the right.
// @notes   When used with a PRIORITY_QUEUE it creates a maximum heap.

bool is_greater(DATA *left, DATA *right);

// @name    hash_string
// @purpose Return the hashed value of a character string in respect to the
//          given bucket count.
// @notes   If the string is not null terminated the hash will not be correct.

unsigned int hash_string(const char *string, unsigned int bucket_count);

// @name    hash_number
// @purpose Return the hashed value of an unsigned integer in respect to the
//          given bucket count.

unsigned int hash_number(const long int number, unsigned int bucket_count);

#endif // GENERICS //

