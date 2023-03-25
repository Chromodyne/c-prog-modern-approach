# Chapter 15 Exercises #

## Exercise 1 ##

### **Question** ##

**Section 15.1** listed several advantages of dividing a program into multiple source files.

(a) Describe several other advantages.

(b) Describe some disadvantages.

### **Answer**  ###

(a) Splitting the program can help aid the ability to compartmentalize functionality in separate files which not only aids in reusability of the code but also in debugging and narrowing down issues that may crop up.

(b) One disadvantage would be a potentially bloated source file structure made of many individual files and directories which could cause future confusion. Another aspect of that
issue would be that finding particular functions or blocks of code that one needs to modify can become cumbersome as the project grows. 

---

## Exercise 2 ##

### **Question** ##

Which of the following should *not* be put in a header file? Why not?

(a) Function prototypes
(b) Function definitions
(c) Macro definitions
(d) Type definitions

### **Answer**  ###

(b) Function definitions should not be put in a header file. The reason for this is that the same function can potentially be defined multiple times if multiple source files include the header file the function definition is in.

---

## Exercise 3 ##

### **Question** ##

We saw that writing `#include<file>` instead of `#include "file"` may not work if *file* is one that we've written. Would there be any problem with writing `#include "file"` instead of `#include<file>` if *file* is a system header?

### **Answer**  ###

No, there should not be an issue due to the way the preprocessor works. When using the form `#include<file>` the preprocessor will look in a defined location for C standard files ONLY. However, when using `#include "file"` the preprocessor will first look elsewhere and if not found will finally look in the defined location for C standard files as if `#include<file>` was used.

---

## Exercise 4 ##

### **Question** ##

Assume that `debug.h` is a header file with the following contents:

```C
#ifdef DEBUG
#define PRINT_DEBUG(n) printf("Value of " #n ": %d\n", n)  
#else
#define PRINT_DEBUG(n)
#endif
```

Let `testdebug.c` be the following source file:

```C
#include<stdio.h>

#define DEBUG
#include "debug.h"

int main(void) 
{
    int i = 1, j = 2, k = 3;

#ifdef DEBUG
    printf("Output if DEBUG is defined:\n");
#else
    printf("Output if DEBUG is not defined:\n");
#endif

    PRINT_DEBUG(i);
    PRINT_DEBUG(j);
    PRINT_DEBUG(k);
    PRINT_DEBUG(i + j);
    PRINT_DEBUG(2 * i + j - k);

    return 0;

}
```
(a) What is the output when the program is executed?

(b) What is the output if the `#define` directive is removed from `testdebug.c`?

(c) Explain why the output is different in parts (a) and (b).

(d) Is it necessary for the `DEBUG` macro to be defined *before* `debug.h` is included in order for `PRINT_DEBUG` to have the desired effect? Justify your answer.

### **Answer**  ###

(a) The output when the program is executed will be:

```
Output if DEBUG is defined:
Value of i: 1
Value of j: 2
Value of k: 3
Value of i + j: 3
Value of 2 * i + j - k: 1
```

(b) If the `#define` directive is removed from `testdebug.c` the output will be:

```
Output if DEBUG is not defined:
```
(c) The output differs between (a) and (b). Firstly, the behavior is because of the `#ifdef` block in `debug.h`. This block is only handled if `DEBUG` is defined. This makes whatever follows the `#else` moot. Secondly, the `#if` block in `testdebug.c` will fall back to the code following `#else` since `DEBUG` is not defined. Nothing will print past `Output if DEBUG is not defined:` because, once again, the `PRINT_DEBUG` parameterized macro will only be defined if `DEBUG` is defined first.

(d) Yes. The preprocessor always works top-to-bottom. If `DEBUG` is not defined prior to `debug.h` being included the `#ifdef` in `debug.h` will not see `DEBUG` defined and, as such, `PRINT_DEBUG` will not have the desired effect.

---

## Exercise 5 ##

### **Question** ##

Suppose that a program consists of three source files--`main.c`, `f1.c`, and `f2.c`--plus two header files, `f1.h` and `f2.h`. All three source files include `f1.h`, but only `f1.c` and `f2.c` include `f2.h`. Write a makefile for this program, assuming that the compiler is `gcc` and that the executable file is to be named `demo`.

### **Answer**  ###

```
demo: main.o f1.o f2.o
    gcc -o demo main.o f1.o f2.o

main.o: main.c f1.h
    gcc -c main.c

f1.o: f1.c f1.h f2.h
    gcc -c f1.c

f2.o: f2.c f1.h f2.h
    gcc -c f2.c
```

---

## Exercise 6 ##

### **Question** ##



### **Answer**  ###



---