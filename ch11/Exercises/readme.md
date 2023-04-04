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

The key to this exercise is to realize that `sum` and `avg` are passed in as pointer variables. In order to modify their values we mustdereference them with the indirection (`*`) operator!


---
