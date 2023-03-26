# Chapter 10 Exercises #

## Exercise 1 ##

### **Question** ##

The following program outline shows only function definitions and variable declarations.

```C
int a;

void f(int b)
{
    int c;
}

void g(void)
{
    int d;
    {
        int e;
    }
}

int main(void)
{
    int f;
}
```

For each of the following scopes, list all variable and parameter names visible in that scope.

(a) The `f` function

(b) The `g` function

(c) The block in which `e` is declared

(d) The `main` function

### **Answer**  ###

(a) `a`, `b`, and `c` are all visible in the scope of the `f` function.

(b) `a` and `d` are both visible in the scope of the `g` function. `e`, while in the function, is only visible in the block in which it is declared.

(c) `a`, `d`, and `e` are visible in the block where `e` is declared.

(d) `a` and `f` are both visible in the `main` function.

---

## Exercise 2 ##

### **Question** ##

The following program outline shows only function definitions and variable declarations.

```C
int b, c;

void f(void)
{
    int b, d;
}

void g(int a)
{
    int c;
    {
        int a, d;
    }
}

int main(void)
{
    int c, d;
}
```
For each of the following scopes, list all variable and parameter names visible in that scope. If there's more than one variable or parameter with the same name, indicate which one is visible.

(a) The `f` function

(b) The `g` function

(c) The block in which `a` and `d` are declared

(d) The `main` function

### **Answer**  ###

(a) `c`, and `d` are visible. `b` is visible but specifically the one local (declared in the function) to the `f` function since this declaration overrides the external variable of the same name in this particular scope.

(b) The external variable `b` is visible. `c` is visible but specifically the one locally declared in `g`. 

(c) The `a` and `d` local to this specific block are visible. As is the variable `c` which is contained within the `g` function. Finally, the external variable `b` is visible.

(d) `c` is visible but specifically the one locally declared. The local `d` variable is visible. Finally, the external (global) `b` variable is visible.

---

## Exercise 3 ##

### **Question** ##

Suppose that a program has only one function (`main`). How many different variables named `i` could this program contain?

### **Answer**  ###

Theoretically, an unlimited number of variables named `i` could be contained in this program. We can have one external (global) `i` variable, one in the immediate scope of `main` and an unending regress of variables named `i` as we create deeper and deeper blocks of code within `main` all with their own `i` variable declaration.

---