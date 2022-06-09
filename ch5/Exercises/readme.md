Chapter 5 Exercises
---

---

## Exercise 1 ##

### **Question:** ###

The following program fragments illustrate the relational and equality operators. Show the output produced by each, assuming that`i`, `j`, and `k` are `int` variables.

```C
    (a) i = 2; j = 3;
        k = i * j == 6;
        printf("%d", k);

    (b) i = 5; j = 10; k = 1;
        printf("%d", k > i < j);

    (c) i = 3; j = 2; k = 1;
        printf("%d", i < j == j < k);

    (d) i = 3; j = 4; k = 5;
        printf("%d", i % j + i < k);
```

### **Answer(s):** ###

This exercise requires you to not only understand what each operator does but also their order of precedence. You can find a handy [table to see the precedence of all C operators here](https://en.cppreference.com/w/c/language/operator_precedence).

```
    (a) 1
```
Since the multiplication `*` operator takes precedence over the equality `==` operator we will have `6 == 6` which yields 1.

```
    (b) 1
```
The relational operators `<` and `>` have the same precendence. They are also left-to-right associative which means they will be checked in order from left to right as `k > i` then `i < j`.

```
    (c) 0 
```
The relational operators `<` and `>` have higher precedence than the equality `==` operator and their operations will be perfomed first. Therefore, using parentheses to clarify, our overall operation is `(i < j) == (j < k)` which will yield `0`.

```
    (d) 0
```
Modulo `%` has the highest operator precedence here, followed by the addition `+`, and finally the relational less-than `<`. Following the order: `3 % 4 = 3`,  `3 + 3 = 6`, and `6 < 5 = 0`.

---

## Exercise 2 ##

### **Question:** ###

The following program fragments illustrate the logical operators. Show the output produced by each assuming that `i`, `j`, and `k` are `int` variables.

```C
    (a) i = 10; j = 5;
        printf("%d", !i < j);

    (b) i = 2; j = 1;
        printf("%d", !!i + !j);

    (c) i = 5; j = 0; k = -5;
        printf("%d", i && j || k);

    (d) i = 3; j = 4; k = 5;
        printf("%d", i % j + i < k);
```

### **Answer(s):** ###

```
    (a) 1
```
[Remember operator precedence!](https://en.cppreference.com/w/c/language/operator_precedence) The logical NOT `'!'` operator has a higher precedence than the relational operator `'<'`. Once we have that in mind we must also remember how C handles logical operations and some elementary boolean algebra. Because C sees any non-zero value as if it were a `true` boolean `!i` yields 0 because `i` is non-zero and `NOT(True)` gives us `False` or `0` in C. We then simply do the comparison `0 < 5` which is `true` or `1` in C.

```
    (b) 1
```
