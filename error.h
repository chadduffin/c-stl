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

// This file contains the macros function signatures and macros that simplify
// the basic error checking used by the containers.

#ifndef __ERROR__
#define __ERROR__

#include <stdio.h>
#include <stdlib.h>

// @name    ERROR_ZERO
// @purpose Causes an error if X is equal to 0 and outputs an appropriate 
//          error message.

#define ERROR_ZERO(X)      if (!X) { print_error(__FILE__, __LINE__, "cannot be zero"); }

// @name    ERROR_NULL
// @purpose Causes an error if X is NULL and outputs an appropriate error
//          message.

#define ERROR_NULL(X)      if (!X) { print_error(__FILE__, __LINE__, "invalid pointer"); }

// @name    ERROR_RANGE
// @purpose Causes an error if X is not within the range of Y to Z and outputs
//          an appropriate error message.

#define ERROR_RANGE(X,Y,Z) if ((X < Y) || (X > Z)) { print_error(__FILE__, __LINE__, "value outside range"); }

// @name    print_error
// @purpose Outputs a descriptive error message that contains the file name and
//          line number where the error occured and exits the program.

void print_error(const char *file, int line, const char *error);

#endif // ERROR //

