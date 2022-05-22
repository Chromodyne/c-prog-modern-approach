**Exercise 1**

Create and run Kernighan and Ritchie's famouse "Hello, world!" program:

```C
#include<stdio.h>

int main(void) {

    printf("Hello, world!\n");

}
```
**Answer:** The compiler spits a warning because the return statement was omitted from the main function. Simply add:
```C
    return 0;
```
after the printf statement to resolve the error.

---

**Exercise 2** 

Consider the following program:

```C
    #include<stdio.h>

    int main(void) {

        printf("Parkinson's Law:\nWork expands so as to ");
        printf("fill the time\n");
        printf("available for its completion.\n")l
        return 0;

    }
```

(a) Identity the directives and statements in the program.

(b) What output does the program produce?

**Answer:** 

(a) The only directive is the `#Include<stdio.h>` whereas the statements are the declaration of `int main()` and each of the `printf` lines.

```
Parkinson's Law:
Work expands so as to fill the time
available for its completion.
```
    
---

**Exercise 3**

Condense the dweight.c program by (1) replacing the assignments to height, length, and width with initializers and (2) removing the weight variable, instead calculating (volume+165) / 166 within the last `printf`.

```C
    #include<stdio.h>

    int main(void) {

        int height, length, width = 0;
        int volume;

        printf("Enter height of box: ");
        scanf("%d", &height);
        printf("Enter length of box: ");
        scanf("%d", &length);
        printf("Enter width of box: ");
        scanf("%d", &width);

        volume = height * length * width;

        printf("Volume (cubic inches): %d\n", volume);
        printf("Dimensionl weight (pounds): %d\n", (volume + 165) / 166);

        return 0;

    }

```

---

**Exercise 4**

Write a program that declares several `int` and `float` variables―without initializing them―and then prints their values. Is there any pattern to the values? (Usually there isn't.) 


**Answer:** (Yours may differ.)

```C
    #include<stdio.h>

    int main() {

        //Uninitalized variable declarations.
        int x;
        int y;
        float j;
        float k;

        printf("%d\n%d\n%f\n%f\n", x, y, j, k);

        return 0

    }
```

No pattern was observed. Garbage values were printed.

---

**Exercise 5**

Which of the following are not legal C identifiers?

```
    (a) 100_bottles
    (b) _100_bottles
    (c) one__hundred__bottles
    (d) bottles_by_the_hundred
```

**Answer:** `(a)` is not a legal identifier. Variables starting with a number are disallowed. Variables must start with either an underscore `_` or letter.

---

**Exercise 6**

Why is it not a good idea for an identifier to contain more than one adjacent underscore (as in current__balance, for example)?

**Answer:** 

Having multiple underscores hamper coad readability as it can be difficulty, at a glance, to discern how many underscores were used.

---

**Exercise 7**

Which of the following are keywords in C?

```
    (a) for
    (b) If
    (c) main
    (d) printf
    (e) while
```
**Answer:**

`(a)` and `(e)` are keywords in C. `(b)` is not considered a keyword in C because it is capitalized. If written as `if` it would be considered a keyword. `main` is a reserved function name but it is not considered a keyword by definition.

---

**Exercise 8**

How many tokens are there in the following statement?

```C
    answer=(3*q-p*p)/3;
```

**Answer:**

There are a total of 14 tokens in the statement.

Tokens include:

```
    (1)  answer
    (2)  =
    (3)  (
    (4)  3
    (5)  *
    (6)  q
    (7)  -
    (8)  p
    (9)  *
    (10) p
    (11) )
    (12) /
    (13) 3
    (14) ;
```

However, only 7 of them are unique. Don't forget the definition of a token! A common mistake is to forget to count your **statement terminator**(`;`) in the count.

---

**Exercise 9**

Insert spaces between the tokens in Exercise 8 to make the statement easier to read.

**Answer:**

```C
    answer = ( 3 * q - p * p) / 3 ;
```
**Note:** A bit strange to put a space before the `;` in my opinion but whatever.

---

**Exercise 10**

In the dweight.c progam, which spaces are essential?

**Answer:**

The only essential spaces are the space in the `#include <stdio.h>` preprocessor directive and the space in the `return 0` statement.
