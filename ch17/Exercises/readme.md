# Chapter 17 Exercises #

## Exercise 1 ##

### **Question** ##

Having to check the return value of `malloc` (or any ofther memory allocation function) each time we call it can be an annoyance. Write a function named `my_malloc` that serves as a "wrapper" for `malloc`. When we call `my_malloc` and ask it to allocate `n` bytes, it in turn calls `malloc`, tests to make sure that `malloc` doesn't return a null pointer, and then returns the pointer from `malloc`. Have `my_malloc` print an error message and terminate the program if `malloc` returns a null pointer.

### **Answer**  ###

```C
void *my_malloc(size_t num_bytes) {

    //Attempt to reserve the number of bytes from the parameter.
    mp = malloc(num_bytes);

    //Check if the pointer returned by malloc is null. If so, terminate the program early.
    if(mp == NULL) {
        
        //Print an error message to the console.
        printf("Null pointer returned during memory allocation.");

        //Terminate the program early using predefined macro from stdlib.h as the argument for the exit function.
        exit(EXIT_FAILURE);
    }

    //Should the pointer not be null, return.
    return mp;

}
```
---

## Exercise 2 ##

### **Question** ##

Write a function named `duplicate` that uses dynamic storage allocation to create a copy of a string. For example, the call

```C
p = duplicate(str);
```
would allocate space for a string of the same length as `str`, copy the contents of `str` into the new string, and return a pointer to it. Have `duplicate` return a null pointer if the memory allocation fails.


### **Answer**  ###

```C
char * duplicate(char * str) {

    //Create new pointer variable to store the address of the new string we will create.
    char * new_string;

    //Attempt to allocate the requisite number of bytes.
    //Note: The cast to char * is uneccessary but included for completeness.
    new_string = (char *) malloc(strlen(str) + 1);

    //Check if the pointer returned by malloc is null. If so, print a message to the
    //console and return a null pointer. If the returned pointer is not null, copy
    //the parameter string str into new_string and return it.
    if (new_string == NULL) {
        printf("Null pointer returned during memory allocation.");
        return NULL;
    } else {
        strcpy(new_string, str);
        return new_string;
    }

}
```

---

## Exercise 3 ##

### **Question** ##

Write the following function:

```C
int *create_array(int n, int initial_value);
```
The function should return a pointer to a dynamically allocated `int` array with `n` numbers, each of which is initialized to `initial_value`. The return value should be `NULL` if the array can't be allocated.

### **Answer**  ###

```C
int * create_array(int n, int initial_value) {

    //Create a new pointer for the array.
    int * arp;

    //Allocate memory for the new array. Always use sizeof when calculating the requisite space since type sizes
    //can vary by machine.
    arp = malloc(n * sizeof(int));

    //Same as previous exercise.
    if (arp == NULL) {

        printf("Null pointer returned during allocation of new array.");
        return NULL;

    } else {

        //Initialize the array. Remember that we can ignore the fact that arp is a pointer and use it as an array name
        //once it points to a dynamically allocated block of memory. See Section 17.3 under the subsection concerning
        //using malloc for dynamically allocated arrays for more information on why this is possible.
        for(int i = 0; i < n; i++) {
            arp[i] = initial_value;
        }

        return arp;
    }

}
```
---

## Exercise 4 ##

### **Question** ##

Suppose that the following declarations are in effect:

```C
struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };
struct rectangle *p;
```
Assume that we want `p` to point to a `rectangle` structure whose upper-left corner is at `(10, 25)` and whose lower-right corner is at `(20, 15)`. Write a series of statements that allocate such a structure and initialize it as indicated.


### **Answer**  ###

```C
p  = malloc(sizeof(struct rectangle));

p->upper_left.x = 10;
p->upper_left.y = 25;
p->lower_right.x = 20;
p->lower_right.y = 15; 
```
Remember that arrow notation (`->`) is used to access members of structure through a pointer whereas dot notation (`.`) is used to access members of the structure directly.

e.g. 

**Structure** `p.upper_left.x = ...`

**Structure Pointer** `p->upper_left.x = ...`

Since we're dealing with a pointer due to the use of `malloc` we should use arrow notation.


---

## Exercise 5 ##

### **Question** ##

Suppose that `f` and `p` are declared as follows:

```C
struct {
    union {
        char a, b;
        int c;
    } d;
    int e[5];
} f, *p = &f;
```

Which of the following statements are legal?

```
(a) p->b = ' ';
(b) p->e[3] = 10
(c) (*p).d.a = '*';
(d) p->d->c = 20;
```

### **Answer**  ###

(b) and (c) are legal statements. 

The former is legal because `e` is a member of `f` and since `p` is a pointer to `f` we are using arrow notation as we should to access the member of a structure pointer. 

The latter is legal because by using the indirection operator (`*`) on `p` we are dereferencing it and are essentially acting on the structure itself. This means using dot notation to access members is correct.

(a) and (d) are illegal statements.

The former is illegal because we are attempting to reference the `b` member of `d` without actually stating it. e.g. `p->d.b = ' ';`

The latter is illegal because we are attempting to use arrow notation to reference the `c` member of `d` when we should be using dot notation. e.g. `p->d.c = 20;`

---

## Exercise 6 ##

### **Question** ##

Modify the `delete_from_list` function so that it uses only one pointer variable instead of two (`cur` and `prev`).

### **Answer**  ###

**TODO**: This exercise is incomplete.

```C
struct node *delete_from_list(struct node *list, int n) {
    
    struct node *cur, *prev;

    for (cur = list, prev = NULL;
         cur != NULL && cur->value != n;
         prev = cur, cur = cur->next) {
            if (cur == NULL) {
                return list;
            }
            if (prev == NULL) {
                list = list->next;
            } else {
                prev->next = cur->next;
            }
         }

         free(cur);
         return list;
}
```
---

## Exercise 7 ##

### **Question** ##

The following loop is supposed all nodes from a linked list and release the memory that they occupy. Unfortunately, the loop is incorrect. Explain what's wrong with it and show how to fix the bug.

```C
for (p = first; p != NULL; p = p->next)
    free(p);
```

### **Answer**  ###



---

## Exercise 8 ##

### **Question** ##



### **Answer**  ###


---

## Exercise 9 ##

### **Question** ##

True or false: If `x` is a structure and `a` is a member of that structure, then `(&x)->a` is the same as `x.a`. Justify your answer.

### **Answer**  ###

**True**. The **right arrow selection** operator (`->`) is a combination of the indirection (`*`) and dot (`.`) operators. It follows that `(&x)->a` expands to `*(&x).a`. Seeing that `*` and `&` are essentially inverses of one another the final statement would be `x->a` which is valid. A special note is that the order of precedence is only valid here because of the parentheses surrounding `&x` in the example. Without these parentheses the statement would not work as expected. This is due to the fact that `->` has a higher precedence than `&`. More can be found on this [here.](https://en.cppreference.com/w/c/language/operator_precedence)

---