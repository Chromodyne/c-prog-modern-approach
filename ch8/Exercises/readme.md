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

    //Iterate through the array calculating the new Fibonacci number. Currently 40 is hardcoded. We calculate the array
    // size in the future using sizeof to make it independent.
    for (int i = 2; i < 39; i++) {

        fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i-2];
        printf("%d\n", fib_numbers[i]);

    }

    return 0;

}
```

Most of the pertinent points are included in the comments. There are some other ways to accomplish this but I feel this is solid enough. The major issue is that we cannot easily change the number of Fibonacci numbers to print in this current version. We would need to remove the "magic numbers" and make it so the array size is calculated instead of hardcoded into the for loop.

---