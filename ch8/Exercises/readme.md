# Chapter 8 Exercises #

## Exercise 1 ##

### **Question:** ###

We discussed using the expression `sizeof(a) / sizeof(a[0])` to calculate the number of elements in an array. The expression `sizeof(a) / sizeof(t)`, where *t* is the type of a's elements, would also work, but it's considered an inferior technique. Why?

### **Answer:** ###

Using the second expression would require us to hard code the type into the expression. If for some reason the type of the array has to change in the future it would no longer work as intended. By using the former expression we can ensure that no matter what type the array ends up being changed to it will give the correct length.

---

## Exercise 2 ##

### **Question:** ###

The Q&A section shows how to use *`letter`* as an array subscript. Describe how to use a *`digit`* (in character form) as a subscript.

### **Answer:** ###


---

## Exercise 3 ##

### **Question:** ###

Write a declaration of an array named `weekend` containing seven `bool` values. Include an initializer that makes the first and last values `true`; all other values should be `false`.

### **Answer:** ###

```C
    bool weekend[7] = {true, false, false, false, false, false, true};
```

Remember to include `<stdbool.h>`. We will avoid designated initializers in this exercise since it assumes C89.

---

## Exercise 4 ##

### **Question:** ###

(C99) Repeat exercise 3 but this time use a designated initializer. Make the initializer as short as possible.

### **Answer:** ###

```C
    bool weekend[7] = {[0] = true, [6] = true};
```
Assuming we are including `<stdbool.h>` this should work fine. We are using designated initializers to set the first and last elements of the array to true. By default, anything not initialized should be set to false. Remember that booleans in C are simply integers with a value of 0 or 1 for false and true respectively and int arrays always set uninitialized elements in a designated initializer array to 0.

---

## Exercise 5 ##

### **Question:** ###

The Fibonacci numbers are 0, 1, 1, 2, 3, 5, 8, 13, ..., where each number is the sum of the two preceding numbers. Write a program that declares an array named `fib_numbers` of length 40 and fills the array with the first 40 Fibonacci numbers. *Hint:* Fill in the first two numbers individually, then use a loop to compute the remaining numbers.

### **Answer:** ###

```C
#include<stdio.h>

int main(void) {

    //Hardcoding the first two elements and the last so that the array is initialized at the proper size.
    //We could also use a VLA instead for future proofing. We also may wish to use a long array in the future.
    int fib_numbers[] = {1, 1, [39] = 0};

    //Print the first two Fibonacci numbers before starting the loop since the logic will not work for these.
    printf("%d\n", fib_numbers[0]);
    printf("%d\n", fib_numbers[1]);

    //Iterate through the array calculating the new Fibonacci number. Currently 40 is hardcoded. We can calculate the array
    //size in the future using sizeof to make it independent.
    for (int i = 2; i < 39; i++) {

        fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i-2];
        printf("%d\n", fib_numbers[i]);

    }

    return 0;

}
```

Most of the pertinent points are included in the comments. There are some other ways to accomplish this but I feel this is solid enough. The major issue is that we cannot easily change the number of Fibonacci numbers to print in this current version. We would need to remove the "magic numbers" and make it so the array size is calculated instead of hardcoded into the for loop.

---

## Exercise 6 ##

### **Question:** ###

Calculators, watches, and other electronic devices often rely on seven-segment displays for numerical output. To form a digit, such devices "turn on" some of the seven segments while leaving others "off":
 
```
 _        _    _         _    _    _    _    _ 
| |   |   _|   _|  |_|  |_   |_     |  |_|  |_|
|_|   |  |_    _|    |   _|  |_|    |  |_|   _|

```

Suppose that we want to set up an array that remembers which segments should be "on" for each digit. Let's number the segments as follows.

```
    0
   561
   432

```

Here's what the array might look like, with each row representing one digit:

```c
    const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0}, ... };
```

I've given you the first row of the initializer; fill in the rest.

### **Answer:** ###

```C
    const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},     //0
                                 {0, 1, 1, 0, 0, 0, 0},     //1
                                 {1, 1, 0, 1, 1, 0, 1},     //2
                                 {1, 1, 1, 1, 0, 0, 1},     //3
                                 {0, 1, 1, 0, 0, 1, 1},     //4
                                 {1, 0, 1, 1, 0, 1, 1},     //5
                                 {1, 0, 1, 1, 1, 1, 1},     //6
                                 {1, 1, 1, 0, 0, 0, 0},     //7
                                 {1, 1, 1, 1, 1, 1, 1},     //8
                                 {1, 1, 1, 1, 0, 1, 1}      //9
                                 };                    
```

Very simple exercise, if tedious. Just follow the provided order of segments and any segment that should be on should have a 1 in the proper index.

---

## Exercise 7 ##

### **Question:** ###

Using the shortcuts described in Section 8.2, shrink the initializer for the segments array (Exercise 6) as much as you can.

### **Answer:** ###

---

## Exercise 8 ##

### **Question:** ###

Write a declaration for a two-dimensional array named `temperature_readings` that stores one month of hourly temperature readings. (For simplicity, assume that a mnth has 30 days.) The rows of the array should represent days of the month; the columns should represent hours of the day.

### **Answer:** ###

```C
    double temperature_readings[30][24] = {0};
```

Remember that for two-dimensional arrays the first number in brackets represents rows and the second represents columns. We are using a `double` as the type for the array since temperatures often include fractions of a degree in Celsius. We could have also used `float` if less precision was necessary. By putting only  a single `0` in brackets for the initializer, the entire array will be initialized with zeroes.

---

## Exercise 9 ##

### **Question:** ###

Using the array in Exercise 8, write a program fragment that computes the average temperature for a month (averaged over all the days of the month and all hours of the day).

### **Answer:** ###

```C
    for ()
```