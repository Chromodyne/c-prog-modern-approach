# Chapter 22 Exercises #

## Exercise 1 ##

### **Question** ##

Indicate whether each of the following files is more likely to contain text data or binary data:

```
(a) A file of object code produced by a C compiler
(b) A program listing produced by a C compiler
(c) An email sent from one computer to another
(d) A file containing a graphics image
```

### **Answer**  ###

(a) Binary data, since object code is a compiled binary that hasn't been linked yet.

(b) Text data since program listings are code in human readable format.

(c) Text data since emails are primarily plaintext.

(d) Binary data since images are produced using encoded data.

---

## Exercise 2 ##

### **Question** ##

Indicate which mode string is most likely to be passed to `fopen` in each of the following situations:

```
(a) A database management system opens a file containing records to be updated.
(b) A mail program opens a file of saved messages so that it can add additional messages to the end.
(c) A graphics program opens a file containing a picture to be displayed on the screen.
(d) An operating system command interpreter opens a "shell script" (or "batch file") containing commands to be executed.
```

### **Answer**  ###

(a) `r+b` since we likely want to open a existing file and will also likely want to read as well as write to it. We must use `rb+` over `r+` because database files are typically binaries.

(b) `a+` since we want to open an existing file and append data to it.

(c) `rb` since we're only planning to view the image and not edit it. We must use `rb` over `r` since we're opening a binary file.

(d) `r` since the shell script should already contain the necessary commands to be executed so it shouldn't require being written to.

---

## Exercise 3 ##

### **Question** ##

Find the error in the following program fragment and show how to fix it.

```C
FILE *fp;

if (fp = fopen(filename, "r")) {
    /* read characters until end-of-file */
} 

fclose(fp);
```
### **Answer** ###

The issue with the above code fragment is that it attempts to use `fclose` on `fp` but doesn't test whether or not `fp` is `null`. We must always ensure that our pointer is not `null` before attempting to close it. 

There are various ways to do this but I opted to use a simple `else` statement to terminate execution if `fp` is `null`. This seems to be the simplest way here since we're reading characters inside the `if` statement.

```C
FILE *fp; ;

//Check if the pointer is null, if so, terminate program
if (fp = fopen(filename, "r")) {
   
   /* read characters until end-of-file */

} else {

    fprint(stderr, "Cannot open file: %s\n", filename);
    exit(EXIT_FAILURE);

}

fclose(fp);
```
---

## Exercise 4 ##

### **Question** ##

Show how each of the following numbers will look if displayed by `printf` with `%#012.5g` as the conversion specification:

(a) `83.7361`

(b) `28748.6607`

(c) `1054932234.0`

(d) `0.0000235218`

### **Answer** ###

Let's break down the conversion specification first:

`%` is simply indicates we're starting a conversion specification. `#` indicates trailing zeroes will not be removed since we're using the `g` conversion and as such we will always show a decimal point. `0` indicates we will pad with leading zeroes since we're using the `g` specifier. `12` indicates our minimum field width which means numbers that aren't this many characters long will be padded (and right justified). `.5` indicates our precision, or the number of significant digits (since we're using the `g` specifier.) `g` indicates we will convert a `double` to `f` or `e` form with the latter being selected if the exponent is less than -4 or `>=` to the precision. 

(a) `00000083.7361`

(b) `00000028649.`

(c) `001.0549e+09`

(d) `002.35222e-05`


**Note:** Regarding `(c)` and `(d)` above, depending on your compiler settings, exponents may show `3` digits by default. *e.g.* `e+009` instead of `e+09`. For example, after verifying my answers using `gcc` I found my answers to for `(c)` and `(d)` to use 3 digits instead of two. I have used the logical solutions I came to here despite the discrepancy during verification. The author's official solutions also use assume your compiler will have output show two digits *e.g.* `e+09`.

---

## Exercise 5 ##

### **Question** ##

Is there any difference between the `printf` conversion specification `%.4d` and `%04d`? If so, explain what it is.

### **Answer** ###

No. These statements are functionally equivalent.

In `%.4d` we are specifying the precision with the `.4` meaning the number of digits to print. If the number has fewer digits than specified (`4`) we will pad it with leading zeroes.

Next let's analyze `%04d`. The `0` indicates we will pad with leading zeroes up to the specified minimum field width (`4` in this case). The `0` flag will only be ignored if we had specified a precision as well, which we haven't.

Therefore these two conversion specifications are equivalent.

---

## Exercise 6 ##

### **Question** ##

Write a call of `printf` that prints

`1 widget`

if the `widget` variable (of type `int`) has the value `1`, and

`n widgets`

otherwise, where `n` is the value of `widget`. You are not allowed to use the `if` statement or any other statement; the answer must be a single call of `printf`.

### **Answer** ###

```C
printf("%d %s",(widget == 1 ? 1 : widget), (widget == 1 ? "widget\n" : "widgets\n"));
```
We can easily implement this functionality using a couple of ternary operations (`?`). We can also condense theses statements further by always using the value of `widget` and appending an `s` onto the end of our string if necessary; however, I have devised the about solution to be as easy to read as possible.


---