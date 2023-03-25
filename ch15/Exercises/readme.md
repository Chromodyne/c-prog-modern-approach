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
