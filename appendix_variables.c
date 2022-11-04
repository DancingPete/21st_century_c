//21st_century_c/ten_pi.c

/*
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
 */

#include <stdio.h>
#include <string.h>

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
  return (ratio_struct){
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
  return (ratio_struct){
    .numerator = ratio_left.numerator*ratio_right.denominator + ratio_right.numerator*ratio_left.denominator,
    .denominator = ratio_right.denominator * ratio_right.denominator,
    .value = ratio_left.value + ratio_right.value};
}

// Examples of use of variables
int main() 
{

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
}
