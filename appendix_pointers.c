//21st_century_c/appendix_pointers.c
/*
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
#include <stdio.h>
#include <stdlib.h>

void double_int(int *int_ptr) { *int_ptr *= 2; }

int main()
{

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
}
