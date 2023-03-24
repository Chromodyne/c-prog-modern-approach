# Chapter 13 Exercises #

## Exercise 1 ##

### **Question** ##

The following function calls supposedly write a single new-line character, but some are incorrect. Identify which calls don't work and explain why.

```
(a) printf("%c", '\n');     (g) putchar('\n');
(b) printf("%c", "\n");     (h) putchar("\n");
(c) printf("%s", '\n');     (i) puts('\n');
(d) printf("%s", "\n");     (j) puts("\n");
(e) printf('\n');           (k) puts("");
(f) printf("\n");
```

### **Answer**  ###

`(b)` does not work because the `printf` function expects a character constant but we are supplying it with a string.

`(c)` does not work because the `printf` function is expecting a string but we are supplying it with a character.

`(e)` does not work because the `printf` function expects a string but we are supplying it with a character constant.

`(h)` does not work because the `putchar` function expects a character constant but we are supplying it with a string.

`(i)` does not work because the `puts` function expects a string but we are supplying it with a character.

`(j)` will give us two newline characters (`\n\n`) because the `puts` function automatically appends a newline character at the end of whatever it outputs.

---

## Exercise 2 ##

### **Question** ##

Suppose that `p` has been declared as follows:

```C
char *p = "abc";
```
Which of the following function calls are legal? Show the output produced by each legal call, and explain why the others are illegal.

```
(a) putchar(p);
(b) putchar(*p);
(c) puts(p);
(d) puts(*p);
```

### **Answer**  ###

(a) is illegal because the original assignment merely makes `p` point to the first character in the string. As such we are attempting to use `putchar` on an address.

(b) is legal because by using the indirection operator (`*`) we are getting the actual value of the first character in the string which is a character. In this case '`a`'.

(c) is legal because the `puts` function expects a char pointer and as such will output the entire string starting at the address specified by `p`.

(d) is illegal because puts expects a character pointer (address) but instead receives a value.


---

## Exercise 3 ##

### **Question** ##

Suppose that we call `scanf` as follows:

```C
scanf("%d%s%d", &i, s, &j);
```
If the user enters `12abc34 56def78`, what will be the values of `i`, `s`, and `j` after the call? (Assume that `i` and `j` are `int` variables and `s` is an array of characters.)

### **Answer**  ###

`i` have the value of `12`, `s` will have the value `"abc34"`, and `j` will have the value `56`.

The first `%d` will read decimal digits until it encounters anything that isn't a decimal digit. Next, `%s` will read any number of characers until it encounters whitespace. The final `%d` will read the remaining decimal digits while ignoring the preceding whitespace.

---

## Exercise 4 ##

### **Question** ##

Modify the `read_line` function in each of the following ways:


(a) Have it skip white space before beginning to store input characters.

(b) Have it stop reading at the first white-space character. *Hint:* To determine whether or not a character is white space, call the isspace function.

(c) Have it stop reading at the first new-line character, then store the new-line character in the string.

(d) Have it leave behind characters that it doesn't have room to store.


### **Answer**  ###

**TODO:** This answer is incomplete.

(a)

```C
int read_line(char str[], int n) {

    int ch, i = 0;

    while isspace(getchar());
    
    while ((ch = getchar()) != '\n') {

        //Check if we're still at the beginning and if the character read is a space. If so
        //discard the input character.
        if (i == 0 && isspace(ch)) {
            
            ;

        }

        if (i < n) {
            str[i++] = ch;
        }

    }

    str[i] = '\0';

    return i;
    
}
```

(b)

```C
int read_line(char str[], int n) {

    int ch, i = 0;

    while isspace(getchar());
    
    //Only get the characters input until whitespace is detected.
    while (!isspace(ch = getchar())) {

        if (i < n) {
            str[i++] = ch;
        }

    }

    str[i] = '\0';

    return i;
    
}
```
(c)

```C
int read_line(char str[], int n) {

    int ch, i = 0;

    while isspace(getchar());
    
    while ((ch = getchar()) != '\n') {

        if (i < n) {
            str[i++] = ch;
        }

    }

    str[i] = '\0';

    return i;
    
}
```



---