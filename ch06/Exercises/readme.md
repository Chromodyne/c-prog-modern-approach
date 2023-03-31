# Chapter 6 Exercises #

## Exercise 1 ##

What output does the following program fragment produce?

```C
i = 1;

while (i <= 128) {
    printf("%d ", i);
    i *= 2;
}
```

### **Answer**  ###

```
1 2 4 8 16 32 64 128
```

---

## Exercise 2 ##

What output does the following program fragment produce?

```C
i = 9384;

do {
    printf("%d ", i);
    i /= 10;
} while (i > 0);
```

### **Answer**  ###

```
9384 938 93 9 
```
---

## Exercise 3 ##

What output does the following `for` statement produce?

```C
for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
    printf(" %d", i);
```

### **Answer**  ###

`5 4 3 2 `

Remember that if we wanted to test both conditionals we would need to use `i > 0 && j > 0`. Since we used a comma in place of `&&` we will never see `1` printed.

---

## Exercise 4 ##

Which one of the following statements is not equivalent to the other two (assuming that the loop bodies are the same)?

(a) `for (i = 0; i < 10; i++) {...}`

(b) `for (i = 0; i < 10; ++i) {...}`

(c) `for (i = 0; i++ < 10; ) {...}`

### **Answer**  ###

`(c)` is not equivalent to the others because it will increment `i` prior to the loop being executed. 

---

## Exercise 5 ##

Which one of the following statements is not equivalent to the other two (assuming that the loop bodies are the same)?

(a) `while (i < 10) {...}`

(b) `for (; i < 10;) {...}`

(c) `do {...} while (i < 10)` 

### **Answer**  ###

`(c)` is not equivalent to the others because a `do while` loop will always execute at least once prior to checking the `while` condition.

---

