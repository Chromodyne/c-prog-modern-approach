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

## Exercise 4 ##

### **Question** ##

For each of the following macros, give an example that illustrates a problem with the macro and show how to fix it.

(a) 

```C
#define AVG(x,y) (x+y)/2
```

(b)

```C
#define AREA(x,y) (x) * (y)
```

### **Answer**  ###

(a)

```C
int z = 5 / AVG(6, 4);
```
We would expect the above to evaluate to `1` with the operation `5 / ((6 + 4) / 2)`; however, the compiler instead sees this as `5 / (6 + 4) / 2` which gives us `0`. 

```C
#define AVG(x,y) (((x) + (y)) / 2)
```
These added parentheses will ensure that the proper order of operations we expect is followed.


(b)

```C
int z = 16/AREA(2, 4);
```
Here we expect it to evaluate to `2` but instead it evaluates to `32`. This is once again due to lack of parentheses upsetting the order of operations one might expect. Instead of `16 / (2 * 4)` this example is read as `(16 / 2) * 4`.

```C
#define AREA((x) * (y))
```
As mentioned above, this issue can be fixed by changing the macro to use the necessary parentheses to ensure correct order of operations.

---

## Exercise 5 ##

### **Question** ##

Let `TOUPPER` be the following macro:

```C
#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))
```

Let `s` be a string and let `i` be an `int` variable. Show the output produced by each of the following program fragments.

(a)

```C
strcpy(s, "abcd");
i = 0;
putchar(TOUPPER(s[++i]));
```
(b)

```C
strcpy(s, "0123");
i = 0;
putchar(TOUPPER(s[++i]));
```

### **Answer**  ###


---