# Chapter 1 - Set Yourself Up for Easy Compilation

## Using a Package Manager

Package managers makes C libraries readily available, they are the means by
which those libraries may be included in one's own work, and they 
are the means for distributing one's own C libraries to the C 
programming community.

## Which Way to the Library?

Compiling C source code using a robust toolchain will result in a three step
process:

* Set a variable using the compiler flags
* Set a variable listing the libraries to which the compiler will link
* Set up a system that will these variables to ochestrate the compilation

Using a library requires that the compiler be told to import functions from the
library header for type checking, and that the linker be told to link the 
actual library code to the program for functionality.

For the standard library, this is accomplished in one step using the #include
preprocessor directive and the -l  and the letter flag for the library in
question at compilation.

List of recomended flags:

* `-g`: Adds symbols for debugging used by gdb and other debugging programs
* `std=gnu11`: Specifies that the compiler should allow code conforming to C11
 and POSIX standards - clang and gcc specific
* `-std=gnu99`: Specifies that the compiler should allow code conforming to C99
* `-03`: Specifies optimization level three, which tries every trick to build 
 faster code
* `-Wall`: Specifies the addition of compiler warnings - alternatively, -w1
 displays the warning without the remarks

There are three typical locations for libraries:

* The default location of the OS vendor provided libraries that are subject
 to variability from one update to another
* The default location defined by the OS vendor for system administrator
 added libraries and hacked versions of standard libraries that shouldn't
 be overwritten by the next OS update
* The default location of users who have no write privileges to the other two
 locations

Compiler flag `-I` adds a given path to the `#include` search path
Compiler flag `-L` adds to the library search path

Library and header linking and preprocessing need to be flagged in order where
those have a dependency relationship to each other - the dependency must be
flagged first.

The pkg-config command provides, as output, the series of compiler flags 
necessary correctly flagging the inclusion of libraries necessary to the
compiling and linking any included libraries.

Static libraries are linked by the compiler, which copies the contents of the
library into the final executable so that the program works more or less as 
a stand alone system.
Shared libraries are linked to your program at runtime, which reproduces
the problem of discovering the location of those libraries at each run.

When compiling a program for users using Autotools, Libtool knows how to
add the right flags; when compiling the program with gcc, clong, or icc,
it is necessary to add the `LDADD=-Llibpath -Wl -Rlibpath` flgs to the 
makefile.

At runtime, the linker will use an additional path variable to find
libraries stored in unusual places or annotated with the `-Wl`, `-R` flags.
This path can be set in the shell's startup script (e.g. zprofile, zshrc)
To ensure any such path is searched, use 

* `export LS-LIBRARY_PATH=libpath:$LD_LIBRARY_PATH`

# Using Makefiles
   
Makefiles provide simple, centralized approach to handling the large number
of compilations options introduced above.
If is an organized set of variables and sequences of one-line shell scripts.
The make program reads the makefile for instructions and variables, and then
assembles the long and tedious command lines for us, providing a simple
alternative to calling the compiller directly.

Smallest, practicable makefile for a program depending on some library:

    P=program_name
    OBJECTS=
    CFLAGS = -g -Wall -03
    LDLIBS=
    CC=c99

    $(P): $(OBJECTS)

Unlike the shell, make wants variables invoked in shell scripts to be 
noted according as follows: $(var)

Environment variables are accessible to C programs via the `getenv()` function
defined in the `stdlib.h` header.

Ignoring the variables that may be included in a makefile script, the makefile
is expected to adhere to the following format:

    target: dependencies
        script

Where `target` is the name included in the calling of make: make `target`.
For example, setting `f` on the command line as an environment variable,
`make` (by default make without arguments runs the first target) 
would run the html, doc, and publish scripts in order, using
the `f` environment variable.
   
   all: html doc publish

   doc:
     pdflatex $(f).text

   html:
     latex -interaction bactchmode $(f)
   
   publish:
     scp $(f).pdf $(Blogserver)


# Using Libraries from Source


# Compiling C Programs via Here Document

