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

## Exercise 6 ##

Translate the program fragment of **Exercise 1** into a single `for` statement.

### **Answer**  ###

```C
for (int i = 1; i <= 128; i *= 2) {
    printf("%d ", i);
}
```

---

## Exercise 7 ##

Translate the program fragment of **Exercise 2** into a single `for` statement.

### **Answer**  ###

```C
for (int i = 9384; i > 0; i /= 10) {
    printf("%d ", i);
}
```

---

## Exercise 8 ##

What output does the following `for` statement produce?

```C
for (i = 10; i >= 1; i /= 2)
    printf("%d ", i++);
```

### **Answer**  ###

`10 5 3 2 1 1 . . .` The `1` endlessly prints since the increment of `i` in the print statement will make the condition `i >= 1` continually return `true`.

---

## Exercise 9 ##

Translate the `for` statement of **Exercise 8** into an equivalent `while` statement. You will need one statement in addition to the `while` loop itself.

### **Answer**  ###

```C
int i = 10;

while (i >= 1) {
    printf("%d ", i++);
    i /= 2;
}
```

---

## Exercise 10 ##

Show how to replace a `continue` statement by an equivalent `goto` statement.

### **Answer**  ###

Here is an example using a continue statement

```C
int i = 10;

while (i >= 0) {

    if (i == 5) {
        continue;   //Jumps to the end of this loop iteration but remains within the loop.
    }

    printf("%d ", i);
    
    
    i--;

}
```

Here is the `goto` statement performing the same function.

```C
int i = 10;

while (i >= 0) {

    if (i == 5) {
        goto end;   //Jumps to the label which is at the end of the loop.
    }

    printf("%d ", i);
    
    
    i--;

end:

}
```

---