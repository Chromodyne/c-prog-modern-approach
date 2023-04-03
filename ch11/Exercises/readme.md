# Chapter 11 Exercises #

## Exercise 1 ##

### **Question** ##

If `i` is a variable and `p` points to `i`, which of the following expressions are aliases for `i`?

(a) `*p`	(c) `*&p`	(e) `*i`	(g) `*&i`

(b) `&p`	(d) `&*p`	(f) `&i`	(h) `&*i`

### **Answer**  ###

(a) `*p` and (g) `*&i` are both aliases for `i`. 

With the former we are using the indirection operator (`*`) to dereference the pointer and obtain the actual value stored. In the latter the indirection and address of operators combined (`*&`) act as inverses and give us `i` directly. Therefore, both of these expressions are aliases for `i`.

---

## Exercise 2 ##

### **Question** ##



### **Answer**  ###



---
