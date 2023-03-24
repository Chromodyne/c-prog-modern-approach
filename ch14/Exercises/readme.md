# Chapter 14 Exercises #

## Exercise 1 ##

### **Question** ##

Write parameterized macros that computer the following values.

(a) The cube of `x`.

(b) The remainder when `n` is divided by 4.

(c) 1 if the product of `x` and `y` is less than 100, 0 otherwise.

Do your macros always work? If not, describe what arguments would make them fail.

### **Answer**  ###

(a)

```C
#define CUBE(x) ((x) * (x) * (x))
```
(b)

```C
#define REMAIN(n) ((n) % 2)
```

(c)

```C
#define CHECK_PRODUCT(x, y) (((x) * (y)) < 100 ? 1 : 0)
```

(a) and (b) are rather self-explanatory. For (c) we use the ternary operator (`?`) to perform the conditional requirements. Remember to keep your parameters in their own parentheses! Reread the subsection titled **Parameterized Macros** in **Section 14.3** if you are unsure of why.

All of the above macros only work if the arguments are numeric in nature.

---

## Exercise 2 ##

### **Question** ##

Write a macro `NELEMS(a)` that computes the number of elements in a one-dimensional array `a`. *Hint:* See the discussion of the `sizeof` operator in **Section 8.1**.

### **Answer**  ###

```C
#define NELEMS(a) (sizeof(a) / sizeof(a[0]))
```
Recall we can easily obtain the number of elements in a one-dimensional array by dividing the size of the array by the size of one of the elements.

*e.g.* If we have an array that holds a total of `40 bytes` and each element is `4 bytes`, we know the total number of elements must be equivalent `40 / 4` elements.

---

## Exercise 3 ##

### **Question** ##

Let `DOUBLE` be the following macro:

```C
#define DOUBLE(x) 2*x
```
(a) What is the value of `DOUBLE(1+2)`?

(b) What is the value of `4/DOUBLE(2)`?

(c) Fix the definition of `DOUBLE`.


### **Answer**  ###

(a) evaluates to `4`.

(b) evaluates to `4` as well.

(c)

```C
#define DOUBLE(x) (2 * (x))
```

Remember that parentheses are imperative for the proper order of operations. For example, (a) evaluates to 4 because it is seen as `(2 * 1) + 2` rather than the `2 * (1 + 2)` we might expect. Likewise, (b) is seen as `(4 / 2) * 2` rather than the `4 / (2 * 2)` we want.

---