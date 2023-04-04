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

If `i` is an `int` variable and `p` and `q` are pointers to `int`, which of the following assignments are legal?

(a) `p = i;`	(d) `p = &q;`	(g) `p = *q;`

(b) `*p = &i;`	(e) `p = *&q;`	(h) `*p = q;` 

(c) `&p = q;`	(f) `p = q;`	(i) `*p = *q;`

### **Answer**  ###

(e) `p = *&q;`, (f) `p = q;`, and (i) `*p = *q;` are all legal assignments.

In (e) we are assigning a pointer to another pointer since the `*&` before `q` undo each other and effectively give us `p = q;`. In (f) we are directly assigning a pointer to another pointer. Finally, in (i) we are assigning the value stored at the address that one pointer points to to the value stored at the address another pointer points to.

---

## Exercise 3 ##

### **Question** ##

The following function supposedly computes the sum and average of the numbers in the array `a`, which has length `n`. `avg` and `sum` point to variables that the function should modify. Unfortunately, the function contains several errors; find and correct them.

```C
void avg_sum(double a[], int n, double *avg, double *sum)
{
	int i;

	sum = 0.0;

	for (i = 0; i < n; i++)
		sum += a[i];
	
	avg = sum / n;

}
```

### **Answer**  ###

```C

void avg_sum(double a[], int n, double *avg, double *sum) {
	
	//We need to dereference sum using the indirection operator to change its value.
	*sum = 0.0;

	for (int i = 0; i < n; i++) {
		//Likewise here remember to dereference!
		*sum += a[i];
	}
	
	//Third times the charm! Dereference!
	*avg = *sum / n;

}
```

The key to this exercise is to realize that `sum` and `avg` are passed in as pointer variables. In order to modify their values we must dereference them with the indirection (`*`) operator!


---

## Exercise 4 ##

### **Question** ##

Write the following function:

```C
void swap(int *p, int *q);
```

When passed the addresses of two variables, `swap` should exchange the values of the variables:

```C
swap(&i, &j);		/* exchanges the values of i and j */
```

### **Answer**  ###

```C
void swap(int *p, int *q) {

	int temp = *p;

	*p = *q;
	*q = temp;

}
```

This is a very simple exercise. Store the value of one of the variables into a temporary variable (`temp` in this case), then perform the swap. Do not forget to dereference the pointer variables to properly assign values!

---

## Exercise 5 ##

### **Question** ##

Write the following function:

```C
void split_time(long total_sec, int *hr, int *min, int *sec);
```

`total_sec` is a time represented as the number of seconds since midnight. `hr`, `min`, and `sec` are pointers to variables in which the function will store the equivalent time in hours (0-23), minutes (0-59), and seconds (0-59), respectively.

### **Answer**  ###

```C
void split_time(long total_sec, int *hr, int *min, int *sec) {

	*hr = total_sec / 3600;
	total_sec -= (long) *hr / 3600;
	*min = total_sec / 60;
	total_sec -= (long) *min / 60;
	*sec = total_sec;
}
```

---
