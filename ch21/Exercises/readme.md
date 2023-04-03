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

## Exercise 6 ##

### **Question** ##

The `<ctype.h>` header usually defines most of its functions as macros as well. These macros rely on a static array that's declared in `<ctype.h>` but defined in a separate file. A portion of a typical `<ctype.h` header appears below. Use this sample to answer the following questions.

(a) Why do the names of the "bit" macros (such as `_UPPER`) and the `_ctype` array begin with an underscore?

(b) Explain what the `_ctype` array will contain. Assuming that the character set is ASCII, show the values of the array elements at position 9 (the horizontal tab character), 32 (the space character), 65 (the letter `A`), and 94 (the `^` character. See section 23.5 for a description of what each macro should return.

(c) What's the advantage of using an array to implement these macros?

```C
#define _UPPER	 0x01	/* upper-case letter */
#define	_LOWER	 0x02   /* lower-case letter */
#define _DIGIT	 0x04   /* decimal digit */
#define _CONTROL 0x08   /* control character */
#define _PUNCT	 0x10	/* punctuation character */ 
#define _SPACE	 0x20	/* white-space character */
#define _HEX	 0x40	/* hexadecimal digit */
#define _BLANK	 0x80	/* space character */

#define isalnum(c)	(_ctype[c] & (_UPPER|_LOWER|_DIGIT))
#define isalpha(c)	(_ctype[c] & (_UPPER|_LOWER))
#define iscntrl(c)	(_ctype[c] & _CONTROL)
#define isdigit(c)	(_ctype[c] & _DIGIT)
#define isgraph(c)	(_ctype[c] & (_PUNCT|_UPPER|_LOWER|_DIGIT))
#define islower(c)	(_ctype[c] & _LOWER)
#define isprint(c)	(_ctype[c] & (_BLANK|_PUNCT|_UPPER|_LOWER|_DIGIT))
#define ispunct(c)	(_ctype[c] & _PUNCT)
#define isspace(c)	(_ctype[c] & _SPACE)
#define isupper(c)	(_ctype[c] & _UPPER)
#define isxdigit(c)	(_ctype[c] & (_DIGIT|_HEX))
```

### **Answer**  ###

(a) Since macro names beginning with an underscore followed by a capital letter (e.g. `_UPPER`) are reserved for standard library use, this prevents the possibility of a collision with a user-defined macro. It also prevents the reuse of macro names in the same header file.

(b) The `_ctype` array is a bitfield (8-bit) lookup table.

The horizontal tab character is considered a white-space character; therefore, it will have the bit value `0b00100000`.

The space character is also considered a white-space character; therefore, it will have the bit value `0b00100000`.

The letter `A` is considered an upper-case letter; therefore, it will have the value `0b00000001`.

The `^` character is considered a punctuation character; therefore, it will have the value `0b00010000`.

(c) Array lookups by index is incredibly swift, O(1); therefore, the main advantage is speed.


## Exercise 7 ##

### **Question** ##

In which standard header would you expect to find each of the following?

```
(a) A function that determines the current day of the week
(b) A function that tests whether a character is a digit
(c) A macro that gives the largest unsigned int value
(d) A function that rounds a floating-point number to the next higher integer
(e) A macro that specifies the number of bits in a character
(f) A macro that specifies the number of significant digits in a double value
(g) A function that searches a string for a particular character
(h) A function that opens a file for reading
```

### **Answer**  ###

(a) `<time.h>`

(b) `<ctype.h>`

(c) `<limits.h>`

(d) `<math.h>`

(e) `<limits.h>`

(f) `<float.h>`

(g) `<string.h>`

(h) `<stdio.h>`

---
