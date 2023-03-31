# Chapter 19 Exercises #

## Exercise 1 ##

### **Question** ##

A **queue** is similar to a stack, except that items are added at one end but removed from the other in a **FIFO** (first-in, first-out) fashion. Operations on a queue might include:

```
Inserting an item at the end of the queue
Removing an item from the beginning of a queue.
Returning the first item in the queue (without changing the queue)
Returning the last item in the queue (without changing the queue)
Testing whether the queue is empty
```

### **Answer**  ###

**TODO:** This answer is incomplete. Debating whether or not to use abstact data-types.

`queue.h` has the following contents:

```C
#ifndef QUEUE_H
#define #QUEUE_H

#include<stdbool.h>

//The push function will move the current
void q_insert();
void q_remove();
bool q_is_empty(void);
void q_first();
void q_last();

#endif
```

---

## Exercise 2 ##

### **Question** ##

Modify the `stack2.c` file to use the `PUBLIC` and `PRIVATE` macros.

### **Answer**  ###

```C
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define PUBLIC
#define PRIVATE static

struct node {
    int data;
    struct node *next;
};

PRIVATE struct node *top = NULL;

PRIVATE void terminate(const char *messages)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

PUBLIC void make_empty(void)
{
    while (!is_empty())
        pop();
}

PUBLIC bool is_empty(void)
{
    return top == NULL;
}

PUBLIC void push(int i) 
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: stack is full.");

    new_node->data = i;
    new_node->next = top;
    top = new_node; 
}

PUBLIC int pop(void)
{
    struct node *old_top;
    int i;

    if (is_empty())
        terminate("Error in pop: stack is empty.");

    old_top = top;
    i = top->data;
    top = top->next;
    free(old_top);
    return i;
}
```

---