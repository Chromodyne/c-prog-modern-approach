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
printf("%d %s", (widget == 1 ? 1 : widget), (widget == 1 ? "widget\n" : "widgets\n"));
```
We can easily implement this functionality using a couple of ternary operations (`?`). We can also condense theses statements further by always using the value of `widget` and appending an `s` onto the end of our string if necessary; however, I have devised the above solution to be as easy to read as possible.

---

## Exercise 7 ##

### **Question** ##

Suppose that we call `scanf` as follows:

```C
n = scanf("%d%f%d", &i, &x, &j);
```
(`i`, `j`, and `n` are `int` variables and `x` is a `float` variable.) Assuming that the input stream contains the characters shown, give the values of `i`, `j`, `n`, and `x` after the call. In addition, indicate which characters were consumed by the call.

```
(a) 10●20●30¤
(b) 1.0●2.0●3.0¤
(c) 0.1●0.2●0.3¤
(d) .1●.2●.3¤
```
*Note:* Here `●` indicates a whitespace (` `) and `¤` indicates a newline character (`\n`).

### **Answer** ###

(a) `i = 10, x = 20.000000, j = 30, n = 3`

The above output is obtained because `scanf` is able to match each of the inputs successfully with the only thing of note being that `20` is converted to a `float` type automatically.

(b) `i = 1, x = 0.000000, j = 2, n = 3`

In this, the issue is that matching for the first input stops when the decimal is reached. This means that `i` is read as `1` and `x` as `.0`. This ultimately means that `j` is read as `2`.

(c) `i = 0, x = 0.100000, j = 0, n = 3`

As above, the decimal ceases `scanf` reading into `i` and makes `x` be input as the `.1` following the decimal. Likewise `j` ceases being written into by the decimal following `0` on `0.2`.

(d) `i = undefined, x = undefined, j = undefined, n = 0`

Here none of the matching is able to match correctly and as such all variables end up remaining with their original values.  `n` is `0` because nothing was successfully matched. I have used `undefined` here to indicate no change because if these variables were not initialized they would by definition be undefined.

---

## Exercise 8 ##

### **Question** ##

In previous chapters, we've used the `scanf` format string `" %c"` when we wanted to skip white-space characters and read a nonblank character. Some programmers use `"%1s"` instead. Are the two techniques equivalent? If not, what are the differences?

### **Answer** ###

No, these two techniques are not equivalent. The difference between the two lies in the fact that `%1s` will store a null character (`\0`) after storing a character whereas `" %c` will not. **Table 22.12** on **page 561** is a great reference for understanding this concept.

---

## Exercise 9 ##

### **Question** ##

Which one of the following calls is *not* a valid way of reading one character from the standard input stream?

```
(a) getch()
(b) getchar()
(c) getc(stdin)
(d) fgetc(stdin)
```

### **Answer** ###

`(a)` is not a valid way of reading from `stdin`. `getch()` requires an argument that is a pointer to the stream it will be reading from. `getch()` is defined as:

```C
int getc(FILE *stream);
```

---

## Exercise 10 ##

### **Question** ##

The `fcopy.c` program has one minor flaw: it doesn't check for errors as it's writing to the destination file. Errors during writing are rare, but do occasionally occur (the disk might become full, for example). Show how to add the missing error check to the program, assuming that we want it to display a message and terminate immediately if an error occurs.

### **Answer** ###

We can add an additional `if` statement inside the `while` loop that it uses to write to check if there is an issue:

```C
while ((ch = getc(source_fp)) != EOF) {

    //If we hit EOF unexpectedly, print a message to stderr and terminate execution.
    if (putc(ch, dest_fp) == EOF) {
        fprintf(stderr, "Failure during writing to file.\n");
        exit(EXIT_FAILURE);
    }

}
```
---

## Exercise 11 ##

### **Question** ##

The following loop appears in the `fcopy.c` program:

```C
while ((ch = getc(source_fp)) != EOF)
    putc(ch, dest_fp);
```
Suppose that we neglected to put parentheses around `ch = getc(source_fp`:

```C
while (ch = getc(source_fp) != EOF)
    putc(ch, dest_fp);
```
Would the program compile without an error? If so, what would the program do when it's run?

### **Answer** ###

While the program will compile, it would not perform as expected. 

The relational not-equal operator (`!=`) has a higher order of precedence than the assignment operator (`=`). `EOF` is defined as `-1` so `getc(source_fp) != EOF` will give us `1` (true) since `getc(source_fp)` will not equal `-1`. Therefore we will be assigning `ch` the value of `1` in the condition of the `while` loop.

---