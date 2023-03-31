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

## Exercise 5 ##

### **Question** ##

State whether each of the following statements is `true` or `false`. Justify each answer.

(a) Every variable with `static` storage duration has file scope.

(b) Every variable declared inside a function has no linkage.

(c) Every variable with internal linkage has static storage duration.

(d) Every parameter has block scope.

### **Answer**  ###

(a) `false`: `static` storage duration does not necessarily imply the variable has file scope. For example, declaring a variable inside a function block as `static` retains the value of that variable for future invocations of that function but does not allow other parts of the file to access it.

(b) `false`: If a variable is declared `extern` inside of a function but was NOT declared `static` previously in the global scope it will have external linkage.

(c) `true`: Declaring a variable `static` gives us a variable with internal linkage (or no linkage if inside a function block). Therefore internal linkage is correlated with static storage duration.

(d) `true`: Function parameters only have scope for the function they are part of.

---

## Exercise 6 ##

### **Question** ##

The following function is supposed to print an error message. Each message is preceded by an integer, indicating the number of times the function has been called. Unfortunately, the function always displays `1` as the number of the error message. Locate the error and show how to fix it without making any changes outside of the function.

```C
void print_error(const char *message)
{
    int n = 1;
    printf("Error %d: %s\n", n++, message);
}
```

### **Answer**  ###

```C
void print_error(const char *message) {
    static int n = 1;
    printf("Error %d: %s\n", n++, message);
}
```
By declaring `n` as `static` we make sure it retains its value even after the function returns. Therefore, each call of `print_error` will have a properly incremented `n` from the previous call.

---

## Exercise 7 ##

### **Question** ##

Suppose that we declare `x` to be a `const` object. Which one the following statements about `x` is false?

(a) If `x` is of type `int`, it can be used as the value of a case label in a `switch` statement.

(b) The compiler will check that no assignment is made to `x`.

(c) `x` is subject to the same scope rules as variables.

(d) `x` can be of any type.

### **Answer**  ###

`(a)` is false. Declaring an object as `const` simply sets it to be `read only`. It does not make it usable as a constant expression which the `switch` statement requires.

---