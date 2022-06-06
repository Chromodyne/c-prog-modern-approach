Chapter 9 Exercises
---

---

## Exercise 1 ##

### **Question:** ###

The following function, which computes the area of a triangle, contains two errors. Locate the errors and show how to fix them. (*Hint:* There are no errors in the formula.)

```C
    double triangle_area(double base, double height) 
    double product;
    {
        product = base * height;
        return product / 2;
    }
```

### **Answer:** ###

**Error 1:** The parameter `height` has no type set.

**Error 2:** The code block surrounded by braces `{}` should be directly after the `triangle_area` function declaration and the variable `product` should be declared either in the global scope of the file or in the local scope of the new function.

**Fixed Code:**

```C
    double triangle_area(double base, double height) {
        double product;
        product = base * height;

        return product / 2;
    }
```

---

## Exercise 2 ##

### **Question:** ###

Write a function `check(x, y, n)` that returns 1 if both `x` and `y` fall between 0 and n-1 inclusive. The function should return 0 otherwise. Assume `x`, `y`, and `n` are all of type `int`. 

### **Answer:** ###

```C
    int check(int x, int y, int n) {

        if (x <= (n - 1) && y <= (n - 1) && x >= 0 && y >= 0) {
            return 1;
        }
        else {
            return 0;
        }

    }
```

A simple if, else statement can be used to provide this functionality. A switch statement may also be used. Remember to properly setup your parameters in the function declaration.

---

## Exercise 3 ##

### **Question:** ###

Write a function `gcd(m, n)` that calculates the greatest common divisor  of the integers `m` and `n`. (Programming Project 2 in Chapter 6 describes Euclid's algorithm for computing the GCD.)

### **Answer:** ###

```C
    int gcd(int m, int n) {

        int remain, greatest_divisor;

        while (n != 0) {

            remain = m % n;
            m = n;
            n = remain;
            
        }

        return greatest_divisor;

    }
```
As specified in the hint, recall Ch.6/Project 02. My return variable is given a bit of a longer name to distinguish it from the function name for greater code readability; however, they can both have the same name (gcd) if desired.

---

## Exercise 4 ##

### **Question:** ###

Write a function `day_of_year(month, day, year)` that returns the day of the year (an integer between 1 and 366) specified by three arguments.

### **Answer:** ###


This exercise is asking for the cumulative day of the year. A switch statement makes this easy. Don't forget the special case for February which has either 28 or 29 days depending on whether or not it is a leap year. The algorithm for determining leap years can be found [here](https://en.wikipedia.org/wiki/Leap_year#/media/File:Leap_Year_Algorithm.png). 

Also, notice we are modifying and returning the parameter variable `day` in the function. Since C **passes arguments by value** instead of by reference we can safely do this without worrying about permanently modifying the variable outside of the function call.

---

## Exercise 5 ##

### **Question:** ###

Write a function `num_digits(n)` that returns the number of digits in `n` (a positive integer) *Hint:* To determine the number of digits in a number `n`, divide it by 10 repeatedly. When `n` reaches 0, the number of divisions indicates how many digits `n` originally had.

### **Answer:** ###

```C
    int num_digits(unsigned int n) {

        int digits = 0;

        do {
            
            n /= 10;
            digits++;

        } while (n != 0)

        return digits;

    }
```

A `do while` loop will work great here. We have to use it over a simple `while` loop since if the argument received is zero it will never activate. The number `0` is considered a digit. Since the instructions explicitly state that `n` is a **positive integer** we will use an `unsigned int` as our parameter type; although, we could use an `unsigned long` if we're worried about overflow. We could also omit the `int` portion and declare it as simple `unsigned`. The function return type can also be declared as `unsigned` since there is no such thing as a negative number of digits.

---

## Exercise 6 ##

### **Question:** ###

Write a function `digit(n, k)` that returns the k<sup>th</sup> digit (from the right) in `n` (a positive integer). For example, `digit(829, 1)` returns 9, `digit(829, 2)` returns 2, and `digit(829, 3)` returns 8. If `k` is greater than the number of digits in `n`, have the function return 0.

### **Answer:** ###

```C
    int digit(unsigned int n, unsigned int k) {

        while (k-- >= 0) {
            if (n /= 10 == 0) {
                return 0;
            }

        }

        return n % 10;

    }
```

A simple function all things considered. Remember the procedure for how to determine the value of digits in the various powers of 10 explored in previous chapters. I am also opting to use `usigned int` as my parameter types due to the exercise specifically mentioning it will be a positive integer.

---

## Exercise 7 ##

### **Question:** ###

Suppose that a function `f` has the following definition.

```C
int f(int a, int b) {...}
```

Which of the following statements are legal? (Assume that `i` has type `int` and `x` has type `double`.)

```C
    (a) i = f(83, 12);
    (b) x = f(83, 12);
    (c) i = f(3.15, 9.28);
    (d) x = f(3.15, 9.28);
    (e) f(83, 12);
```

### **Answer:** ###

The major thing to consider here is whether or not the function was prototyped or defined prior to the line it was called. If not, the default (implicit) integral (C89) or integer (C99) conversions are performed. The details on these conversions can be found on **pages 145-146**. You can also find an excellent reference [here](https://en.cppreference.com/w/c/language/conversion).

Recalling the paragraphs about **Argument Conversions** on page 194, 

All statements are valid if the function was prototyped or defined prior to being called; however, a breakdown of each statement follows.

`(a)` is always a valid statement because the function `f` returns an integer by its type defintion; therefore, no conversion of return type is necessary. There is also no need to perform conversions on the arguments as they match the type of the declared parameters.

`(b)` is only valid if the function was prototyped or defined prior to the call.

`(c)` TODO

`(d)` is a valid statement. TODO

`(e)` is always a valid statement since it calling the `f` with the same argument types as the function definition.

---

## Exercise 8 ##

### **Question:** ###

Which of the following would be valid prototypes for a function that returns nothing and has one `double` parameter?

```C
    (a) void f(double x);
    (b) void f(double);
    (c) void f(x);
    (d) f(double x);
```

### **Answer:** ###

`(a)` and `(b)` are the only valid prototypes. While omission of the parameter names is acceptable, function prototypes must contain the return type and parameter types. As such `(c)` omits the parameter type which is invalid and `(d)` omits the return type.

## Exercise 9 ##

### **Question:** ###

What will be the output of the following program? 

```C
    #include<stdio.h>

    void swap(int a, int b);

    int main(void) {
        int i = 1, j = 2;

        swap(i, j);
        printf("i = %d, j = %d\n", i, j);
        return 0;
    }

    void swap(int a, int b) {
        int temp = a;
        a = b;
        b = temp;
    }
```

### **Answer:** ###