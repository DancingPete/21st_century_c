/*
 * Almost everything in a C program is:
 *     Preprocessor directives such as #include <stdio.h>
 *     Declarations of a variable or a type
 *     Function blocks containing expressions to evaluate
 * 
 * There are two types of comments:
 *    Single line comments introduces by double slashes //
 *    Multi line comments delineated by slash-star and star-slash, as is this
 *    comment.
 * 
 * There is no print keyword.
 * Instead, the printf function uses a sublanguage for the precise description
 * of the manner in which variables are printed.
 *    \n newline
 *    \t tab
 *    %i integer
 *    %g real number in general format
 *    %s string
 *    %% percent sign
 */

//21st_century_c/hello.c
#include <stdio.h>

int main() {
  printf("Hello, world.\n");
}
