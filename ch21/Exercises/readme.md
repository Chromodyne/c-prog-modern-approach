# Chapter 21 Exercises #

## Exercise 1 ##

### **Question** ##

Locate where header files are kept on your system. Find the nonstandard headers and determine the purpose of each.

### **Answer**  ###

On my Linux partition, headers are located in the `/usr/include` directory. 

On my Windows 10 partition there are various locations for them since they are not included with Windows by default. For example, I have MinGW installed which includes GCC which has the headers located deep in its file structure.

---

## Exercise 2 ##

### **Question** ##

Having located the header files on your system (see **Exercise 1**), find a standard header in which a macro hides a function.

### **Answer**  ###

An example of a standard header with a macro that hides a function is `setjmp.h`.

```C
extern int setjmp(jump_buf __env) __THROWNL;
```

is hidden by:

```C
#define setjmp(env) _setjmp (env)
```

There are numerous other examples.

---

## Exercise 3 ##

### **Question** ##

When a macro hides a function, which must come first in the header file: the macro definition or the function prototype? Justify your answer.

### **Answer**  ###

The function prototype must come first. This is because the preprocessor must be aware of the function before it can hide it. It cannot be aware of it if it has not encountered the function or its prototype first.

---

## Exercise 4 ##

### **Question** ##

Make a list of all reserved identifiers in the "future library directions" section of the C99 standard. Distinguish between identifiers that are reserved for use only when a specific header is included versus identifiers that are reserved for use as external names.

### **Answer**  ###

The following reserved identifiers can be found on Pg.400 (Sec. 7.26) of the ISO/IEC 9899:1999 standard.

"**All** external names described below are reserved no matter what headers are included by the program."

**<complex.h>**

```
cerf	cexpm1	clog2
cerfc	clog10	clgamma
cexp2	clog1p	ctgamma
```

This as well as any of the same names suffixed with `f` or `l`.

**<ctype.h>**

Function names that begin with either `is` or `to` and a lowercase letter.


**<errno.h>**

Macros that begin with `E` and a digit of `E` and an uppercase letter.

**<inttypes.h>**

Macro names that begin with `PRI` or `SCN` followed by any lowercase letter or `X`.

**<locale.h>**

Macros that begin with `LC_` and an uppercase letter.

**<signal.h>**

Macros that begin with `SIG` and an uppercase letter or `SIG_` and an uppercase letter.

**<stdint.h>**

Typedef names beginning with `int` or `uint` and ending with `_t`. Macro names beginning with `INT` or `UINT` and ending with `_MAX`, `_MIN`, or `_C`.

**<stdio.h>**

Lowercase letters when used in conversion specifiers and length modifiers in `fprintf` and `fscanf`.

**<stdlib.h>**

Function names that begin with `str` and a lowercase letter.

**<string.h>**

Function names that begin with `str`, `mem`, or `wcs` and a lowercase letter.

**<wchar.h>**

Function names that begin with `wcs` and a lowercase letter. Also lowercase letters when used as conversion specifiers and length modifiers in `fwprintf` and `fwscanf`.

**<wctype.h>**

Function names that begin with `is` or `to` and a lowercase letter.

---

## Exercise 5 ##

### **Question** ##

The `islower` function, which belongs to `<ctype.h>`, tests whether a character is a lower-case letter. Why would the following macro version of `islower` not be legal, according to the C standard? (You may assume that teh character set is ASCII.)

```C
#define islower(c) ((c) >= 'a' && (c) <= 'z')
```

### **Answer**  ###

Per section 7.14 of the C standard regarding use of library functions, a macro definition must be suppressed locally by enclosing the name of the function in parentheses. Alongside this, an invocation of a library function that is implemented as a macro must expand to code that evaluates each of its arguments exactly once.

As we can see from the example macro its name is not enclosed in parentheses and its argument, (`c`), is evaluated twice. Therefore, by the C standard the above macro is illegal.

---
