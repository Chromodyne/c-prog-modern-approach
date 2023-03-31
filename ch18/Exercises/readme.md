# Chapter 18 Exercises #

## Exercise 1 ##

### **Question** ##

For each of the following declarations, identify the storage class, type qualifiers, type specifiers, declarators, and initializers.

(a) `static char **lookup(int level);`

(b) `volatile unsigned long io_flags;`

(c) `extern char *file_name[MAX_FILES], path[]`

(d) `static const char token_buf[] = "";`

### **Answer**  ###

(a) `static` is the storage class. There is no type qualifier. `char` is the type specifier. `**lookup(int level)` is the declarator.

(b) The storage class for this variable is not specified explicitly; therefore, it can be `auto` or `static` depending on whether it was declared inside a block or outside a block respectively. `volatile` is the type qualifier. `unsigned long` is the type specifier. `io_flags` is the declarator.

(c) `extern` is the storage class. There is no type qualifer. `char *` is the type specifier. `file_name[MAX_FILES]` and `path[]` are both declarators.

(d) `static` is the storage class. `const` is thge type qualifier. `char` is the type specifier. `token_buf[]` is the declarator. `= ""` is the initializer.

---

## Exercise 2 ##

### **Question** ##

Answer each of the following questions with `auto`, `extern`, `register`, and/or `static`.

(a) Which storage class is user primarily to indicate that a variable or function can be shared by several files?

(b) Suppose that a variable `x` is to be shared by several functions in one file but hidden from functions in other files. Which storage class should `x` be declared to have?

(c) Which storage classes can affect the storage duration for a variable?

### **Answer**  ###

(a) `extern`

(b) `static`

(c) `static` and `extern`

---

## Exercise 3 ##

### **Question** ##

List the storage duration (`static` or `automatic`), scope (block or file), and linkage (internal, external, or none) of each variable and parameter in the following file:

```C
extern float a;

void f(register double b)
{
    static int c;
    auto char d;
}
```

### **Answer**  ###

`a` has `static` storage duration, file scope, and external linkage.

`b` has `automatic` storage duration, block scope, and no linkage.

`c` has `static` storage duration, block scope, and no linkage.

`d` has `automatic` storage duration, block scope, and no linkage.

---

## Exercise 4 ##

### **Question** ##

Let `f` be the following function. What will be the value of `f(10)` if `f` has never been called before? What will be the value of `f(10)` if `f` has been called five times previously?

```C
int f(int i)
{
    static int j = 0;
    return i * j++;
}
```

### **Answer**  ###

`f(10)` will be `0` if it has never been called before and `f(10)` will be `50` if it has been called five times previously. This is due `j` having the the storage class of `static`. This means that `j` will not be reinitialized to `0` on every function call but instead will keep its value meaning each invocation of `f` will increment the value of `j`. 

---