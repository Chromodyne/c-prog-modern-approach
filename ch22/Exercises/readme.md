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
(a) A database management system opens a file containing records to be updated
(b) A mail program opens a file of saved messages so that it can add additional messages to the end
(c) A graphics program opens a file containing a picture to be displayed on the screen
(d) An operating system command interpreter opens a "shell script" (or "batch file") containing commands to be executed
```

### **Answer**  ###

(a) `r+b` since we likely want to open a existing file and will also likely want to read as well as write to it. We must use `rb+` over `r+` because database files are typically binaries.

(b) `a+` since we want to open an existing file and append data to it.

(c) `rb` since we're only planning to view the image and not edit it. We must use `rb` over `r` since we're opening a binary file.

(d) `r` since the shell script should already contain the necessary commands to be executed so it shouldn't require being written to.

---