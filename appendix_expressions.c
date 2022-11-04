//21st_century_c/appendix_expressions.c

/*
 * Expressions are the means by which a program executes some action.
 * In C, expressions are always grouped into functions.
 *
 * The scope of a variable is the range of the program over which it
 * can be used.
 * If a variable is declared outside some function, then it can be used by 
 * any expression from the declaration until the end of the file.
 * Variable declared inside a block, are available by any expression
 * following that declaration and within the same block.
 *
 * Any C expression that needs to be evaluated need to be stated within
 * the body of a function.
 * The evaluation of the program starts with the evaluation of the 
 * expressions in the main function.
 *
 * Because the operating system calls the main function, it may take only
 * one of two forms:
 *
 *    int main(void); // or as int main();
 *    int main(int, char**); // or as int main(int argc, char** argv);
 *
 * Expressions are delimited by semicolons.
 *
 * Variables may be incremented or scaled using shorthand notation:
 *    x++; // pre-increment
 *    ++x; // post-increment
 *    x--; // pre-decrement
 *    --x; // post-decrement
 *    x+=3; // add 3 to x
 *    x-=3; // subtract 3 from x
 *    x*=3; // multiply x by 3
 *    x/=3; // divide x by 3
 *    x%=3; // replace x with the remainder of x/3
 * 
 * If the expression value is 0 or the NULL character '\0', the expression
 * evaluates to False.
 * Otherwise, it evaluates to True.
 * Logical expression will evaluate to 0 or 1, representing False and True,
 * respectively:
 *    !x
 *    x==y
 *    x != y
 *    x < y
 *    x > y
 *    x || y
 *    x && y
 *    x > y || y >= z
 * 
 * Logical and, &&, and or, ||, operators are 'lazy', and will only evaluate
 * an expression sufficiently to yield a result.
 *
 *  (0 || 0) && (1 || 1) // will only evaluate the first operator as the 
 *                       // second is unecessary to evaluate, given that the
 *                       // falsity of the first make the truth-value of the 
 *                       // second irrelevant - the expression is false
 * 
 * C has three distinct division operators, where the two first are identical
 * in notation
 *
 *    / // float division
 *    / // integer division
 *    % // modulo
 * 
 * C has a ternary operator: ?, such that an expression may be evaluated
 * on the basis of the truth or falsity of the first operand.
 *
 *    x ? a : b; // if x then a, else b
 * 
 * The ternary operator is lazy in the same sense as logical operators.
 * b is never evaluated if the test operand is true.
 * 
 * Branching and looping are implemented in C similarly to most programming
 * languages:
 *    if (condition) { expressions } elif (condition) { expressions } else { expressions }
 *
 *    while (condition) {expressions}
 *
 *    do { expressions } while (condition);
 *
 *    for (initializer; condition; incrementor) { expression }
 */

#include <math.h>
#include <stdio.h>

int main() {
  int x = 1;

  // Pre-increment
  printf("Value of x: %i\n", x);
  printf("Value of pre-incremented x: %i\n", x++);
  printf("Value of x: %i\n", x);

  // Type of division: float, integer, modulo
  printf("13./5=%g\n", 13./5);
  printf("13/5=%i\n", 13/5);
  printf("13%%5=%i\n", 13%5);

  // Example of ternary operatory
  double y = 49;
  printf("The truncated sqaure root of x is %g\n", y > 0 ? sqrt(y) : 0);
}
