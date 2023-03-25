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

## Exercise 3 ##

### **Question** ##

(a) Show how to declare a tag named `complex` for a structure with two members, `real` and `imaginary`, of type `double`.

(b) Use the `complex` tag to declare variables named `c1`, `c2`, and `c3`.

(c) Write a function named `make_complex` that stores its two arguments (both of type `double`) in a `complex` structure, then returns the structure.

(d) Write a function named `add_complex` that adds the corresponding members of its arguments (both `complex` structures), then returns the result (another `complex` structure).

### **Answer**  ###

(a)

```C
struct complex {
    double real, imaginary;
}
```
Remember that a **tag** is simply a name used to identify a particular kind of structure. See **Section 16.2**.

(b)

```C
struct complex c1, c2, c3;
```
Do not make the mistake of omitting the `struct` before using the tag `complex`.

e.g. 
```C
complex c1, c2, c3      /*---WRONG---*/
```
(c)

```C
struct make_complex(double real, double imaginary) {

    struct complex c;

    c.real = real;
    c.imaginary = imaginary;

    return c;

}
```
Notice that this function is awfully similar to object constructors in object-oriented languages.

(d)

```C
struct add_complex(struct complex a, struct complex b) {

    struct complex c;

    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b.imaginary;

    return c;

}
```

---

## Exercise 4 ##

### **Question** ##

Repeat **Exercise 3**, but this time using a *type* named `Complex`.

### **Answer**  ###

(a)

```C
typedef struct {
    double real, imaginary;
} Complex;
```
(b)

```C
Complex c1, c2, c3;
```
Notice how now that `Complex` is defined as a `type` we can use it without `struct` beforehand. Indeed, we **MUST** omit the `struct` part since `Complex` is now a defined type. 

(c)

```C
Complex make_complex(double real, double imaginary) {

    Complex c;

    c.imaginary = imaginary;
    c.real = real;

    return c;

}
```

(d)

```C
Complex add_complex(Complex a, Complex b) {

    Complex c;

    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b.imaginary;

    return c;

}
```

---

## Exercise 5 ##

### **Question** ##

Write the following functions, assuming that the `date` structure contains three members: `month`, `day`, and `year` (all of type `int`).

(a)
```C
int day_of_year(struct date d);
```
Returns the day of the year (an integer between `1` and `366`) that corresponds to the date `d`.

(b)
```C
int compare_dates(struct date d1, struct date d2);
```
Returns `-1` if `d1` is an earlier date than `d2`, `+1` if `d1` is a later date than `d2`, and `0` if `d1` and `d2` are the same.

### **Answer**  ###

(a)
```C
int day_of_year(struct date d) {

    int cumulative = 0;
    int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //Check if leap year.
    if ((d.year % 4 == 0 || d.year % 400 == 0) && d.year % 100 != 0) {

        //Add a day to february if leap year.
        daysPerMonth[1] = 29;

    }

    //Iterate through the daysPerMonth array to get the cumulative number of days elapsed
    //until the current month. Be careful with conditional to make sure we don't count
    //the current month as a full month.
    for (int i = 0; i < d.month - 1; i++) {
        cumulative += daysPerMonth[i];
    }

    //Add the days of the current month.
    cumulative += d.day;

    return cumulative;

}
```
(b)
```C
int compare_dates(struct date d1, struct date d2) {

    //Get the cumulative number of elapsed days for each parameter using the previous
    //function we created.
    int days1 = day_of_year(d1);
    int days2 = day_of_year(d2);

    //Compare the current day number and return values based on condition.
    if (days1 > days2) {
        return -1;
    } else if (days2 > days1) {
        return 1;
    } else {
        return 0;
    }

}
```

---