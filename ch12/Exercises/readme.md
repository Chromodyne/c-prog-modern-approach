# Chapter 12 Exercises #

## Exercise 1 ##

### **Question** ##

Suppose the following declarations are in effect:

```C
int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
int *p = &a[1], *q = &a[5];
```

    (a) What is the value of *(p+3)?
    (b) What is the value of *(q-3)?
    (c) What is the value of q - p?
    (d) Is the condition p < q true or false?
    (e) Is the condition *p < *q true of false


### **Answer**  ###

(a) The value of `*(p+3)` is `14`.

(b) The value of `*(q-3)` is `34`.

(c) The value of `q - p` is `4`. Remember that subtracting one pointer from another gives the distance between the pointers in array elements.

(d) The condition `p < q` will be `true` because the address of `q` should be higher than `p`.

(e) The condition `*p < *q` will be `false` because by dereferencing the pointer with the indirection operator (*) we are getting an actual value pointed to. Therefore, `*p` will be `15` and `*q` will be `2`. 

---

## Exercise 2 ##

### **Question** ###

Suppose that `high`, `low`, and `middle` are all pointer variables of the same type, and that `low` and `high` point to elements of an array. Why is the following statement illegal, and how could it be fixed?

```C
middle = (low + high) / 2;
```

### **Answer** ###

The issue with this statement is that we are attempting to add pointers together. Pointers are simply addresses in memory and adding them together has no defined meaning. This makes the statement illegal. We can solve this by instead rewriting the statement to subtract the pointers rather than add them.

```C
middle = low + (low - high) / 2;
```

Notice that in the rewritten statement we are able to add `low` after performing the subtraction because pointers **CAN** be added to integers.

---

## **Exercise 3** ##

### **Question** ###

What will the contents of the `a` array be after the following statements are executed?

```C
#define N 10

int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int *p = &a[0], *q = &a[N-1], temp;

while(p < q) {
    temp = *p;
    *p++ = *q;
    *q-- = temp;
}
```

### **Answer:** ###

Recall that the post-script increment (x++) operator is handled after other operations unlike the pre-script increment (++x) operator. Therefore, in this exercise when operations are being performed on `p` the increment only happens after the other operations which means that during the other operations `p++` is actually just `p`.

This code fragment will reverse the order of the `a` array as it runs and our final array will be:

`a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};`

---

## **Exercise 4** ##

### **Question** ###

Rewrite the `make_empty`, `is_empty`, and `is_full` functions of Section 10.2 to use the pointer variable `top_ptr` instead of the integer variable `top`.

### **Answer:** ###

```C
    #include<stdbool.h>
    #define STACK_SIZE 100

    int contents[STACK_SIZE]
    int * top_ptr = 0;

    void make_empty(void) {
        //Set the top pointer to address of the first element of the array to make the
        //stack start at the beginning so it is empty.
        top_ptr = &contents[0];
    }

    bool is_empty(void) {
        //Return true if the top pointer is the same address as the first element of the
        //array indicating that the stack is empty.
        return top_ptr == &contents[0];
    }

    bool is_full(void) {
        //Return true if the address of the top pointer is the same as the array's final
        //element indicating that the stack is full.
        return top_ptr == &contents[STACK_SIZE];
    }


```
---

## **Exercise 5** ##

### **Question** ###

Suppose that `a` is a one-dimensional array and `p` is a pointer variable. Assuming that the assignment `p = a` has just been performed. Which of the following expressions are illegal because of mismatched types? Of the remaining expressions, which are true (have a nonzero value)?

```C
(a) p == a[0]
(b) p == &a[0]
(c) *p == a[0]
(d) p[0] == a[0]
```

### **Answer:** ###

`(a)` is illegal because you are comparing an address to a value. `(b)` is legal because you are comparing an address to an address and evaluates to `true` because `p` is an alias for `a` and when declaring an array as a pointer it points to the first element in the array. (Recall Section 12.3) `(c)` is legal because you are comparing a value to a value since `p` was dereferenced with the indirection operator and will evaluate to `true` for the same reason as the previous. `(d)` is also legal because we are comparing a value to another value and evaluates to `true` because we are comparing equivalent values.

---

## **Exercise 6** ##

### **Question** ###

Rewrite the following function to use pointer arithmetic instead of array subscripting. (In other words, eliminate the variable `i` and all uses of the `[]` operator.) Make as few changes as possible.

```C
int sum_array(const int a[], int n) {

    int i, sum;

    for (i = 0; i < n; i++) {
        sum += a[i];
    }

    return sum;

}
```

### **Answer:** ###

Recall that array parameters can be declared as a pointer since the compiler treats it as if it was identical to declaring it as an array.

```C
int sum_array(int * a, int n) {
    
    int sum = 0;
    int * p;

    for (p = a; p < a; p++) {
        sum += *p;
    }

    return sum;

}
```

---

## **Exercise 7** ##

### **Question** ###

Write the following function:

```C
bool search(const int a[], int n, int key);
```
`a` is an array to be searched, `n` is the number of elements in the array, and `key` is the search key. `search` should return `true` if `key` matches some elements of `a`, and `false` if it doesn't. Use pointer arithmetic--not subscripting--to visit array elements.

### **Answer:** ###

```C
bool search(const int a[], int n, int key) {

    //Defining p as a pointer.
    int * p;

    //Setup a boolean variable for us to return later for determining if a match is found. Defaults to false. Requires stdbool.h.
    bool match_found = false;

    //Setting p = a to set p = &a[0] before iterating through the array with pointer arithmetic.
    for (p = a; p < a + n; p++) {

        //Compare key value to the value of the current array element. If a match is found, set match_found to true.
        match_found = *p == key; 
    }

    return match_found;

}
```
Remember: We can use the array name alone as a pointer. (`a` in this case.) We can either use it alone for pointer arithmetic which will disallow us from incrementing `a`; therefore, we can declare a secondary pointer variable and copy `a` into it(`p`  in this case) to use for operations. Reread **Section 12.3** if you need review.

---

## **Exercise 8** ##

### **Question** ###

Rewrite the following function to use pointer arithmetic instead of array subscripting. (In other words, eliminate the variable `i` and all uses of the `[]` operator.) Make as few changes as possible.

```C
void store_zeros(int a[], int n) {
    
    int i;

    for (i = 0; i < n; i++) {
        a[i] = 0;
    }

}
```

### **Answer:** ###

```C
void store_zeros(int * a, int n) {

    int * p;

    for(p = a; p < a + n; p++) {
        *p = 0;
    }

}
```
We setup a pointer variable `p` that holds the same address as `a` so that we can make modifications to array which would not be possible if we simply used `a`. Re-read 12.3 if you are unsure of why this is the case.

---