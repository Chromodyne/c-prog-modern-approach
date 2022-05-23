# Chapter 3 Exercises #

## Exercise 1 ##

### **Question:** ###

What output do the following calls of `printf` produce?

```
    (a) printf("%6d,%4d", 86, 1040);
    (b) printf("%12.5e", 30.253);
    (c) printf("%.4f," 83.162);
    (d) printf("%-6.2g", 0.0000009979);
```

### **Answer:** ###

**Note:** `'-'` characters denote spaces in these answers.
```
    (a) ----86,1040
    (b) 3.02530e+01
    (c) 83.1620
    (d) 1e-07
```

Remember that the number before the decimal in format specifiers determines digits to print. Including extra digits for numbers that do not need them affects the justification of the number in the output with positive numbers right-justifying and negative numbers left-justifying.

---

## Exercise 2 ##

### **Question:** ###

Write calls of `printf` that display a `float` variable `x` in the following formats: 
           
```
    (a) Exponential notation; left-justified in a field of size 8; one digit after the decimal point.
    (b) Exponential notation; right-justified in a field of size 10; six digits after the decimal point.
    (c) Fixed decimal notation, left-justified in a field size of 8; three digits after the decimal point.
    (d) Fixed decimal notation, right-justified in a field size of 6; no digits after the decimal point.
```

### **Answer:** ###

**Note:** The newline escape character `\n` is optional but makes output look nicer.

```
    (a) printf("%-8.1e\n", x);
    (b) printf("%10.6e\n", x);
    (c) printf("%-8.3f\n", x);
    (d) printf("%6.0f\n", x);
```

---

## Exercise 3

### **Question:** ###

For each of the following pairs of `scanf` format strings, indicate whether or not the two strings are equivalent. If they're not, show how they can be distinguished.

```
    (a) "%d"            versus      " %d"
    (b) "%d-%d-%d"      versus      "%d -%d -%d"  
    (c) "%f"            versus      "%f "
    (d) "%f,%f"         versus      "%f, %f"
```

### **Answer:** ###

```
    (a) Equivalent.
    (b) Equivalent.
    (c) Not equivalent.
    (d) Equivalent
```
`(a)`, `(b)`, and `(d)` are equivalent; however, `(c)` is not. This is due to the nature of the `scanf` function. The function typically skips over whitespace characters looking for the next matching input type.  On `(c)` a space occuring after the format specifier requires input of a character (that isn't a space) to signify the end of the whitespace as the whitespace makes it continue looking for new input after it is skipped over.

---
## Exercise 4 ##

### **Question:** ###

Suppose that we call `scanf` as follows:

```C
    scanf("%f%d%f", &i, &x, &j);
```
If the user enters
``` 
10.3 5 6
```
what will be the values of `i`, `x`, and `j` after the call? (Assume that `x` and `y` are `int` variables and `x` is a `float` variable.) 

### **Answer:** ###

```
   i = 10
   x = 0.3
   j = 5
```
This seemingly strange behavior is due to the way `scanf` reads inputs. It will read the `10` as the first input matching the `int` type as the following decimal will end the input for it. `x` will be 0.3 since it is considered a `float` value and the decimal tells it to begin there and ends at the whitespace. Afterwards, looking for the final value it will encounter 5 after the whitespace and set `j` equal to it.

---

## Exercise 5 ##

### **Question:** ###

Suppose that we call `scanf` as follows:

```C
    scanf("%f%d%f", &x, &i, &y);
```
If the user enters
```
12.3 45.6 789
```
what will be the values of `i`, `x`, and `y` after the call? (Assume that `x` and `y` are `float` variables and `i` is an `int` variable.)

### **Answer:** ###

```
    x = 12.3
    i = 45
    y = 0.6
```
Much like the preceding exercise the `scanf` function appears to behave strangely but it actually makes sense if we dig deeper into how the function works. For the value of `x` there is no issue as `x` is considered a `float` and as such it will read the entire first number input as 12.3. For `i` however, since it is an `int` the `scanf` function will only read up to the decimal point on the second number and end reading. Afterwards it will read the decimal as part of `y` and end once it reaches the whitespace.

---

## Exercise 6 ##

### **Question:** ###

Show how to modify the `addfrac.c` program of Section 3.2 so that the user is allowed to enter fractions that contain spaces before and after each `/` character.

### **Answer:** ###

```C
    #include<stdio.h>

    int main(void) {

        int num1, denom1, num2, denom2, result_num, result_denom;

        printf("Enter first fraction: ");
        scanf("%d /%d", &num1, &denom1);

        printf("Enter second fraction: ");
        scanf("%d /%d", &num2, &denom2);

        result_num = num1 * denom2 * num2 * denom1;

        result_denom = denom1 * denom2;
        printf("The sum is %d/%d\n", result_num, result_denom);

        return 0;
    }
```
As you can see, we simply have to add a space before the `/` in each of our `scanf` statements. If you're unsure why, make sure you reread the section on how the `scanf` whitespace pattern matching works!
