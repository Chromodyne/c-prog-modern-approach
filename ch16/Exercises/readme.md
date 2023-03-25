# Chapter 16 Exercises #

## Exercise 1 ##

### **Question** ##

In the following declarations, the `x` and `y` structures have members named `x` and `y`:

```C
struct { int x, y; } x;
struct { int x, y; } y;
```
Are these declarations legal on an individual basis? Could both declarations appear as shown in a program? Justify your answer.

### **Answer**  ###

Yes, these declarations are legal and both could appear as shown in a program. This is because each structure has a separate namespace for its members. This means that the scope of each structure where the members are located will not conflict with other names in the program that are in a separate scope.

---

## Exercise 2 ##

### **Question** ##

(a) Declare structure variables named `c1`, `c2`, and `c3`, each having members `real` and `imaginary` of type `double`.

(b) Modify the declaration in part (a) so that `c1`'s members initially have values `0.0` amd `1.0`, while `c2`'s members are `1.0` and `0.0` initially. (`c3` is not initialized.)

(c) Write statements that copy the members of `c2` into `c1`. Can this be done in one statement, or does it require two?

(d) Write statements that add the corresponding members of `c1` and `c2`, storing the result in `c3`.

### **Answer**  ###

(a)

```C
struct {
    double real, imaginary;
} c1, c2, c3;
```
(b)

```C
struct {
    double real, imaginary;
} c1 = {0.0, 1.0}, 
  c2 = {1.0, 0.0},
  c3;
```
Here we are not using **designated initializers** so we must take care that the values of the initializers must appear in the same order as the members of the structure. If one wishes to vary the order of the members initialized we can instead use **designated initializers** like so:

```C
struct {
    double real, imaginary;
} c1 = {.imaginary = 1.0, .real = 0.0},
  c2 = {.real = 1.0, .imaginary = 0.0},
  c3;
```

(c)

```C
c1 = c2
```
This can be done in one statement since `c1` and `c2` are structures of compatible types.

(d)

```C
c3.real = c1.real + c2.real;
c3.imaginary = c1.imaginary + c2.imaginary;
```

---