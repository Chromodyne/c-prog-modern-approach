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

---
