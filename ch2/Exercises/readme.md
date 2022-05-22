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

