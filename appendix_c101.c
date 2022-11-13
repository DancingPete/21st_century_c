/*
 * Structure
 * *********
 *
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
 *
 * Variables
 * *********
 *
 * C, unlike many scripting languages, does not infer the type of
 * variables.
 * The type types of variables are declared along with their names.
 *
 * There are three basic types used throughout this book:
 *    int integer
 *    double double-precision floating-point real number
 *    char character
 * 
 * Multiple variables of the same type may be declared on the same line:
 *    int first_int = 5, second_int, third_int = 70; // second int is declared
 *                                                   // but uninitialized
 *
 * Similarly, function types need to be declared, however, in addition to the
 * type returned by the function, they also declare the names and types
 * taken as parameters.
 * This may be accomplished in the single step of defining the function,
 * or accomplished in two steps, first as a declaration, then as an implementation,
 * as demonstrated below.
 *
 * Function declarations as distinct from function implementation do not describe
 * how the function achieves the outputs in commits to deliver from the inputs,
 * it only describes the necessary information that will permit the compiller
 * to determine whether each of its uses are appropriate to its definition.
 *
 * A lot of C code is written and read from the bottom up, with main as the last
 * component of the file, and above that the functions used by main.
 *
 * A function may also return void, which is to say it returns nothing, but
 * has some other effects, such as the writing of a file.
 *
 * Basic typse can be aggregated into arrays and structs.
 * An array is a list of identically typed elements, while a struct
 * is a collection of heterogeneous types.
 * 
 * The sizeof operator returns the quantity of memory required to store
 * an instance of that type.
 * It take a type name.
 * 
 * There is no special string type.
 * A string in C is an array of individual chars.
 * The end of the string is marked by a NUL character, '\0'.
 * Note that single characters are demarcated by single ticks,
 * where strings are demarcated by quotation marks.
 * The function strlen(str) will count the number of characters comprising
 * the string, excluding the NUL char.
 *
 * Expressions
 * ***********
 *
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
 * 
 * Pointers
 * ********
 *
 * Pointers refers to locations in memory that hold some value rather than
 * the value itself.
 * This allows pointers, or references to data to be changed where any change
 * to a referenced value is executed, unlike copies of the data itself, wherein
 * a change to one copy does not affect any of the other copies or original.
 *
 * Arrays can be understood as a notational convenience for the allocation of
 * contiguous blocks of memory of some size, such that 
 *    int[100] <=> malloc(100*sizeof(int)
 * 
 * A pointer to a scalar is, in the above sense, just a one item array, such that
 *    i[0] <=> *i 
 *
 * Given the declaration, 
 *
 *    ratio_struct *ptr;
 *
 * we know that ptr is a point to a ratio_struct, not a ratio itself.
 * The size of ptr is the size of an address in memory, not the struct.
 * Getting an element of the struct may there be done:
 *
 *    (*ptr).element
 *
 * However, there is a lovely notational convenience:
 *
 *    ptr->element
 * 
 * Function parameters send copies of the arguments supplied to those parameters.
 * Consequently, the arguments manipulated by name in a function do not change 
 * the value of the arguments as supplied - only their copies.
 * Defining parameters as pointers instead of varibles, allows the function
 * calls to pass pointers as arguments, which in turn allows the function to
 * make changes to the values in memory at the pointer address.
 *
 * If x is a variable, &x is a pointer to that variable.
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void double_int(int *int_ptr) { *int_ptr *= 2; }


// Function declarations
int add_two_ints(int a, int b);

void error_print(FILE *error_file, int error_code, char *error_message);

// Function implementation
int add_two_ints(int a, int b) { return a + b; }

void error_print(FILE *error_file, int error_code, char *error_message) {
  fprintf(error_file, "Error #%i occured: %s.\n", error_code, error_message);
}

// Structs as aggregates of heterogeneous basic types
typedef struct {
  int numerator, denominator;
  double value;
} ratio_struct;

// Ratio struct generator
ratio_struct new_ratio(int numerator, int denominator) {
  return (ratio_struct) {
    .numerator=numerator,
    .denominator=denominator,
    .value=numerator/(double)denominator};
}

// Ratio struct printer
void ratio_print(ratio_struct ratio) {
  printf("%i/%i = %g\n", ratio.numerator, ratio.denominator, ratio.value);
}

// Ratio struct adder
ratio_struct ratio_add(ratio_struct ratio_left, ratio_struct ratio_right) {
  return (ratio_struct) {
    .numerator = ratio_left.numerator*ratio_right.denominator + ratio_right.numerator*ratio_left.denominator,
    .denominator = ratio_right.denominator * ratio_right.denominator,
    .value = ratio_left.value + ratio_right.value
  };
}

// Examples of use of variables
int main() 
{
  printf("Hello, world.\n");

  // Function declarations and use in printf statements
  double pi = 3.14159265; // POSIX defined the constant M_PI in math.h
  int count = 10;
  printf("%g times %i = %g.\n", pi, count, pi*count);

  // Writing of error file as example of function returning void
  FILE *error_file = fopen("example_error_file", "w"); // File handle open for wriitng
  error_print(error_file, 37, "Out of karma");

  // List as aggregates of homogenous basic types
  int intlist[10];
  int len = 20;
  char string[len];

  intlist[7] = 7;
  snprintf(string, len, "Item seven is %i.", intlist[7]);
  printf("string says: <<%s>>\n", string);

  // Print ratio struct 
  ratio_struct twothirds = new_ratio(2, 3);
  ratio_struct onequarter = new_ratio(1, 4);
  ratio_print(onequarter);
  ratio_print(twothirds);
  ratio_print(ratio_add(twothirds, onequarter));

  // Determine the size of types
  printf("Size of two ints: %zu\n", 2*sizeof(int));
  printf("size of two ints: %zu\n", sizeof(int[2]));
  printf("size of a double: %zu\n", sizeof(double));
  printf("size of ratio_struct: %zu\n", sizeof(ratio_struct));

  // Working with string
  char* str = "Hello";
  printf("the value of str: %s\n", str);
  // str[4] = '\0'; // changing the last letter to a null character
  // printf("the value of str: %s\n", str);

  char *str1 = "hello", str2[100];
  printf("the length of str1: %lu\n", strlen(str1));
  strncpy(str2, str1, 100);
  printf("the copy of str1 to str2: %s\n", str2); //copy at most 100 bytes from str1 to str2
  strncat(str2, str1, 100); //append at most 100 bytes from str1 to str2
  printf("the concatenation of str2 and str1: %s\n", str2);

  if (strcmp(str1, str2)) { printf("str1 and str2 are identical.\n"); }
  else { printf("str1 and str2 are not identical\n"); } // compare str1 and str2

  // Creating a pointer to an allocated memory space the size of 3000 integers
  int *intspace1 = malloc(3000*sizeof(int)); // using malloc
  int *intspace2 = calloc(3000, sizeof(int)); // using calloc

  // Filling the space of the memory allocations with incrementing integers
  for (int i=0; i<3000; i++) { intspace1[i] = i; }
  for (int i=2999; i>=0; i--) { intspace2[i] = i; }

  FILE *counter_file = fopen("counter_file", "w");
  for (int i=0; i<3000; i++) fprintf(counter_file, "%i\n", intspace1[i]);
  fclose(counter_file); // close the open file

  // Free the heap allocated space
  free(intspace1);
  free(intspace2);

  // Comparing pointers to scalars with single item arrays
  int list[100];
  int *list2 = list;

  *list2 = 7;
  assert(list[0] == 7);

  // Passing arguments by reference using pointers
  int x[1];
  *x = 10;
  printf("the original value of x: %i\n", *x);
  double_int(x);
  printf("the doubled value of x following the function call: %i\n", *x);

  // Passing arguments by reference using pointers using the & notation
  int y = 10;
  printf("the original value of y: %i\n", y);
  double_int(&y);
  printf("the doubled value of y following the function call: %i\n", y);

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
