# Chapter 4 Exercises #

## Exercise 1 ##

### **Question:** ###

Show the output produced by each of the following program fragments. Assume that `i`, `j`, and `k` are `int` variables.

```C
    (a) i = 5; j = 3;
        printf("%d %d", i / j, i % j);
    (b) i = 2; j = 3;
        printf("%d", (i + 10) % j);
    (c) i = 7; j = 8; k = 9;
        printf("%d", (i + 10) % k / j);
    (d) i = 1; j = 2; k = 3;
        printf("%d", (i + 5) % (j + 2) / k)
```

### **Answer:** ###

```
    (a) 1 2
    (b) 0
    (c) 1
    (d) 0
```

The key on each of these is to follow the order of operator precedence and rules of associativity learned in the section. Multiplicative and additive operations are left-right associative which means they are evaluated left to right if not encased in parentheses. You should also remember that C99 always truncates division of integers.  This means any fractional numbers always round down. The modulus `%` operator gives you the remainder of division.

---

## Exercise 2 ##

### **Question:** ###

If `i` and `j` are positive integers does `(-i) / j` always have the same value as `-(i/j)`? Justify your answer.

### **Answer:** ###

No. The answer can vary depending on which version of the C standard you are using. For example, in C89 `(-14)/5` can give you either -2 or -3 whereas `-(14/5)` will always give you -2. However, in the C99 standard the truncation rule will always round the remainder to zero; therefore, the two expressions will be equivalent.

---

## Exercise 3 ##

### **Question:** ###

What is the value of each of the following expressions in C89? (Give all possible values if an expression may have more than one value.)

```
    (a) 8 / 5
    (b) -8 / 5
    (c) 8 / -5
    (d) -8 / -5
```
### **Answer:** ###

```
    (a) 1
    (b) -1 OR -2
    (c) -1 OR -2
    (d) 1 OR 2
```

Remember the quirks of C89 when it comes to negative division as discussed in the chapter.

---

## Exercise 4 ##

### **Question:** ###

Repeat the previous exercise but for C99.

### **Answer:** ###

```
    (a) 1
    (b) -1
    (c) -1
    (d) 1
```

Recall that C99 alleviates the ambiguity of these expressions and always truncates downward when performing division.

---

## Exercise 5 ##

### **Question:** ###

What is the value of each of the following expressions in C89? (Give all possible values if an expression may have more than one value.)

```
    (a) 8 % 5
    (b) -8 % 5
    (c) 8 % -5
    (d) -8 % -5
```

### **Answer:** ###

```
    (a) 3
    (b) -3 or 5
    (c) 3 or -5
    (d) 3 or 5
```

---

## Exercise 6 ##

### **Question:** ###

Repeat the previous exercise but for C99.

### **Answer:** ###

```
    (a) 3
    (b) -3
    (c) -3
    (d) 3
```

---

## Exercise 7 ##

### **Question:** ###

The algorithm for computing the UPC check digit ends with the following steps:

```
    Subtract 1 from the total.
    Compute the remainder when the adjusted total is divided by 10.
    Subtract the remainder from 9.
```

It's tempting to try to simplify the algorithm by using these steps instead:

```
    Compute the remainder when the total is divided by 10.
    Subtract the remainder from 10.
```

Why doesn't this technique work?

### **Answer:** ###

**NOTE:** Honestly not certain on this question just yet. The answer is wrong so it definitely has something to do with how C is processing the modulus. Using the example textbook UPC from earlier in the chapter, I have a feeling that 45 % 10 is ambiguous whether or not it gives 5 or 6 since putting the code into a sandbox to test does indeed give 4 instead of 5 as the answer. TODO

My Thoughts:

---

## Exercise 8 ##

### **Question:** ###

Would the `upc.c` program work if the expression `9 - ((total - 1) % 10)` were replaced by `(10 - (total % 10)) % 10`?

### **Answer:** ###


---

