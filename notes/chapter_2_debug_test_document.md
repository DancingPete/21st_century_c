# Chapter 2 - Debug, Test, Document

# GDB - GNU Debugger

GDB is the GNU debugger, which allows the user to step through a program, stoping
at any function to examine the program state within the context of any of its frames.

The debugger is invoked with `gdb <program_name>`.

Within the debugger, `h[elp]` is used to get a summary of commands available
by category.

## breakpoints

* b[reak]      Set a breakpoint at specified location
* d[elete]      Delete all or some breakpoints
* en[able]      Enable all or some breakpoints

## data

* display       Print value of expression EXP each time the program stops
* p[rint]       Print value of expression EXP

## running

* advance       Continue the program up to the given location
* c[ontinue]    Continue debugged program after signal or breakpoint
* r[un]         Start or restart debugged program
* n[ext]        Step program, proceeding though subroutine calls
* s[tep]        Step program until it reaches a different source line
* u[ntil]       Execute until past the current line or past a LOCATION

## stack

* do[wn]        Select and print stack frame called by the current frame
* f[rame]       Select and print a stack frame by address
* up            Select and print stack frame that called this one

## status

* i\[nfo\] [[b]reakpoints|threads|local|args]   Displays value of current breakpoints,
  threads, local variables, or program arguments, respectively

# GDB Variables

It is possible to set variables for the convenience of avoiding the invocation 
of commands using heavily nested elements of complex data structures.

gdb variables are set using the `set` command with the `$` introducing the variable
name.
Once set the variable value may be printed using the standard variable notation
rather than typing repeatedly the complex hierarchy definition.
For example:

    set $variable_name = model->dataset->vector->data
    print *$variable_name@10

The use of variables can be useful in conjunction with pointer arithmetic for 
data structures, allowing the the debugger to step through the values of the 
data structure.

    set $ptr=&x[3]
    print *($ptr++)

# Print your Structures

Simple macros may be used for displaying nontrivial data structures.

For example, a gdb function may be used print an xml document:

    define pxml
        print xmlElemDump(stdout, $arg0, xmlDocGetRootElement($arg0))
    end
    document pxml
    Print the three of an already opened XML document to the screen.
    This will probably be seceral pages long.
    use: pxml doc
    end

As another example, the following gdb function may be used to display a linked
list quickly:

    define phead
        set $ptr = $arg1
        plistdata $arg0
    end
    document phead
    Print the first element of a list. E.g. given the declaration
        Glist *datalist;
        g_list_add(datalist, "Hello");
    View the list with something like
        phead char datalist
        pnext char
        pnext char
    This macor defines $ptr as the current pointed-to list struct,
    and $pdata as the data in that list element.
    end

    define pnext
        set $ptr = $ptr->next
        plistdata $arg0
    end
    document pnext
    You need to call phead first; that will set $ptr.
    This macro will step forward in teh list, then show the value at that
    next element.
    Give the type of the list data as the only argument.

    This macro defines $ptr as the current pointed-to list struct, and 
    $pdata as teh data in that list element.
    end

    define plistdata
        if $ptr
            set $pdata = $ptr->data
        else
            set $pdata = 0
        end
        if $pdata
            p ($arg0*)$pdata
        else
            p "NULL"
        end
    end
    document plistdata
    This is intended to be used by phead and pnext.
    It sets $pdata and prints it value.
    end
