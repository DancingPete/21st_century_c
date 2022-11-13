# Structure

Almost everything in a C program is:

* Preprocessor directives such as #include <stdio.h>
* Declarations of a variable or a type
* Function blocks containing expressions to evaluate

There are two types of comments:

* Single line comments introduces by double slashes `//`
* Multi line comments delineated by slash-star and star-slash, `/* */`

There is no print keyword.
Instead, the printf function uses a sublanguage for the precise description
of the manner in which variables are printed.

* `\n`  newline
* `\t`  tab
* `%i`  integer
* `%g`  real number in general format
* `%s`  string
* `%%`  percent sign

# Variables

C, unlike many scripting languages, does not infer the type of
variables.
The type types of variables are declared along with their names.

There are three basic types used throughout this book:

* `int`     integer
* `double`  double-precision floating-point real number
* `char`    character

Multiple variables of the same type may be declared on the same line:

    int first_int = 5, second_int, third_int = 70; // second int is declared
                                                   // but uninitialized

Similarly, function types need to be declared, however, in addition to the
type returned by the function, they also declare the names and types
taken as parameters.
This may be accomplished in the single step of defining the function,
or accomplished in two steps, first as a declaration, then as an implementation,
as demonstrated below.

Function declarations as distinct from function implementation do not describe
how the function achieves the outputs in commits to deliver from the inputs,
it only describes the necessary information that will permit the compiller
to determine whether each of its uses are appropriate to its definition.

A lot of C code is written and read from the bottom up, with main as the last
component of the file, and above that the functions used by main.

A function may also return void, which is to say it returns nothing, but
has some other effects, such as the writing of a file.

Basic typse can be aggregated into arrays and structs.
An array is a list of identically typed elements, while a struct
is a collection of heterogeneous types.

The sizeof operator returns the quantity of memory required to store
an instance of that type.
It take a type name.

There is no special string type.
A string in C is an array of individual chars.
The end of the string is marked by a NUL character, `'\0'`.
Note that single characters are demarcated by single ticks,
where strings are demarcated by quotation marks.
The function strlen(str) will count the number of characters comprising
the string, excluding the NUL char.

# Expressions

Expressions are the means by which a program executes some action.
In C, expressions are always grouped into functions.

The scope of a variable is the range of the program over which it
can be used.
If a variable is declared outside some function, then it can be used by 
any expression from the declaration until the end of the file.
Variable declared inside a block, are available by any expression
following that declaration and within the same block.

Any C expression that needs to be evaluated need to be stated within
the body of a function.
The evaluation of the program starts with the evaluation of the 
expressions in the main function.

Because the operating system calls the main function, it may take only
one of two forms:

    int main(void); // or as int main();
    int main(int, char**); // or as int main(int argc, char** argv);

Expressions are delimited by semicolons.

Variables may be incremented or scaled using shorthand notation:

 * `x++;`     pre-increment
 * `++x;`     post-increment
 * `x--;`     pre-decrement
 * `--x;`     post-decrement
 * `x+=3;`    add 3 to x
 * `x-=3;`    subtract 3 from x
 * `x*=3;`    multiply x by 3
 * `x/=3;`    divide x by 3
 * `x%=3;`    replace x with the remainder of x/3

If the expression value is 0 or the NULL character '\0', the expression
evaluates to False.
Otherwise, it evaluates to True.
Logical expression will evaluate to 0 or 1, representing False and True,
respectively:

* `!x`
* `x==y`
* `x != y`
* `x < y`
* `x > y`
* `x || y`
* `x && y`
* `x > y || y >= z`

Logical and, &&, and or, ||, operators are 'lazy', and will only evaluate
an expression sufficiently to yield a result.

    (0 || 0) && (1 || 1) // will only evaluate the first operator as the 
                         // second is unecessary to evaluate, given that the
                         // falsity of the first make the truth-value of the 
                         // second irrelevant - the expression is false
 
C has three distinct division operators, where the two first are identical
in notation

* `/`   float division
* `/`   integer division
* `%`   modulo

C has a ternary operator: ?, such that an expression may be evaluated
on the basis of the truth or falsity of the first operand.

    x ? a : b; // if x then a, else b

The ternary operator is lazy in the same sense as logical operators.
b is never evaluated if the test operand is true.

Branching and looping are implemented in C similarly to most programming
languages:

* if (condition) { expressions } elif (condition) { expressions } else { expressions }
* while (condition) {expressions}
* do { expressions } while (condition);
* for (initializer; condition; incrementor) { expression }
 
# Pointers

Pointers refers to locations in memory that hold some value rather than
the value itself.
This allows pointers, or references to data to be changed where any change
to a referenced value is executed, unlike copies of the data itself, wherein
a change to one copy does not affect any of the other copies or original.

Arrays can be understood as a notational convenience for the allocation of
contiguous blocks of memory of some size, such that 

    int[100] <=> malloc(100*sizeof(int)

A pointer to a scalar is, in the above sense, just a one item array, such that

    i[0] <=> *i 

Given the declaration, 

    ratio_struct *ptr;

We know that `ptr` is a pointer to a `ratio_struct`, not a ratio itself.
The size of `ptr` is the size of an address in memory, not the `struct`.
Getting an element of the struct may there be done:

    (*ptr).element

However, there is a lovely notational convenience:

    ptr->element

Function parameters send copies of the arguments supplied to those parameters.
Consequently, the arguments manipulated by name in a function do not change 
the value of the arguments as supplied - only their copies.
Defining parameters as pointers instead of varibles, allows the function
calls to pass pointers as arguments, which in turn allows the function to
make changes to the values in memory at the pointer address.

If x is a variable, &x is a pointer to that variable.
