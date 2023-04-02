# Chapter 20 Exercises #

## Exercise 1 ##

### **Question** ##

Show the output produced by each of the following program fragments. Assume that `i`, `j`, and `k`are `unsigned short` variables.

(a)
```C
i = 8; j = 9;
printf("%d", i >> 1 + j >> 1);
```
(b)
```C
i = 1;
printf("%d", i & ~i);
```
(c)
```C
i = 2; j = 1; k = 0;
printf("%d", ~i & j ^ k);
```

(d)
```C
i = 7; j = 8; k = 9;
printf("%d", i ^ j & k);
```

### **Answer**  ###

**Note:** For (b), (c), and (d) of the following answers I have included the binary steps through the process. While the exercises state we are using an `unsigned short` for each variable, which is typically 16-bits, I have I have opted to limit the binary math to 8-bits to keep things terse. With the values provided for the variables in the exercises the logic works out the exact same.

(a) Addition (`+`) has a higher precedence than bitwise shifting. Therefore the expression being evaluated is `i >> (1 + j) >> 1`. Therefore our output is `0` because bitshifting right by `10` and again by `1` leaves us with `0b00000000` since the set bits do not underflow.

(b) Remember that the complement operator (`~`) has higher precedence than the bitwise AND (`&`). `i` is originally set to `0b00000001` by taking the complement we change it to `0b11111110`. Therefore `i & ~i` gives us `0`. See below.

```
0b00000001 ~
------------
0b11111110
0b00000001 &
------------
0b00000000 FINAL = 0
```

(c) Once again let's look at operator precedence here. The complement (`~`) is highest followed by the bitwise AND (`&`) with the bitwise XOR (`^`) coming in last. This means our operation is `((~i) & j) ^ k)` which gives us `1` as our output.

```
0b00000010 ~
------------
0b11111101
0b00000001 &
------------
0b00000001 FINAL = 1
```
(d) `&` has higher precedence than `^` so we have `i ^ (j & k)`. Which gives us `15`
```
0b00001000
0b00001001 &
------------
0b00001000
0b00000111 ^
------------
0b00001111 FINAL = 15
```
---

## Exercise 2 ##

### **Question** ##

Describe a simple way to "toggle" a bit (change it from `0` to `1` or from `1` to `0`). Illustrate the technique by writing a statement that toggles bit 4 of the variable `i`.

### **Answer**  ###

We can easily set a bit to be a 1 by performing an OR (`|`) with a mask that contains a 1 bit in our desired location (In this case, bit 4.)

**Note:** I will be using a `uint8_t` which stores up to 8 bits for brevity.

```C
uint8_t i = 0x00;      //0b00000000
i |= 0x10;           //0x10 is our mask
```
```
0b00000000
0b00010000 |
------------
0b00010000 FINAL (i)
```
To set a bit to be a 0 (clearing it) we can perform an AND (`&`) operation with a mask that has a 0 bit in the desired position. 

```C
uint8_t i= 0x13;
i &= 0x03;
```
```
0b00010011
0b00000011 &
----------
0b00000011 FINAL (i)
```
We can also make a more general statement that toggles a bit (flips a bit regardless of if it is 1 or 0) by using an XOR (`^`) with a mask that has 1 bit set in the desired position.

```C
//This example has our 4th bit set to 1 but we want it to be set to 0
uint8_t i = 0x10;
i ^= 0x13;
```
```
0b00010000
0b00010011 ^
------------
0b00000011 FINAL (i)
```
Or

```C
//This example has our 4th bit initially set to 0 but we want it to be set to 1
uint8_t i = 0x03;
i ^= 0x10;
```
```
0b00000011
0b00010000 ^
------------
0b00010011 FINAL (i)
```
---

## Exercise 3 ##

### **Question** ##

Explain what effect the following macro has on its arguments. You may assume that the arguments have the same type.

```C
#define M(x,y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
```

### **Answer**  ###

This macro will swap the values stored in the `x` and `y` parameters.

For example, let `x = 0x0D` and `y = 0x0B`. In binary these have the values `0b00001101` and `0b00001011` respectively. We can follow what happens below.

```
0b00001101          x       = 0x0D
0b00001011 ^        y       = 0x0B
------------
0b00000110          x (new) = 0x06
0b00001011 ^        y       = 0x0B
------------
0b00001101          y (new) = 0x0D
0b00000110 ^        x       = 0x06
------------
0b00001011          x (new) = 0x0B

0b00001011          x FINAL = 0x0B
0b00001101          y FINAL = 0x0D
```

Notice how the `x` and `y` values have swapped places at the end.

---

## Exercise 4 ##

### **Question** ##

In computer graphics, colors are often stored as three numbers, representing red, green, and blue intensities. Suppose that each number requires eight bits, and we'd like to store all three values in a single long integer. Write a macro named `MK_COLOR` with three parameters (the red, green, and blue intensities). `MK_COLOR` should return a `long` in which the last three bytes contain the red, green, and blue intensities, with the red value as the last byte and the green value as the next-to-last byte.

### **Answer**  ###

Assuming the required bits are already clear and that by "last byte" we mean the one furthest left of the others we can derive the following macro.

```C
//Remember to typecast the result to a long
#define MK_COLOR(r, g, b) ((long) (r) << 16 | (g) << 8 | (b))
```
If instead by "last byte" the opposite order is intended we can simply change the positions of `r` and `b` in the macro.

---

## Exercise 5 ##

### **Question** ##

Write macros named `GET_RED`, `GET_GREEN`, and `GET_BLUE` that, when given a color as an argument (see **Exercise 4**), returns its 8-bit red, green, and blue intensities.

### **Answer**  ###

```C
#define GET_RED(c)      ((c) >> 16 & 0xFF)   
#define GET_GREEN(c)    ((c) >> 8 & 0xFF)
#define GET_BLUE(c)     ((c) & 0xFF)
```
Since our color is coded in the first 24-bits of our bit field I will only be showing those. For example, if our original color is encoded as `0b101101011101101110111010` we can access the red value by bitshifting to the right 16 (`>> 16`) before ANDing (`&`) with `0xFF`.

```
0b101101011101101110111010 >> 16
-----------------------------
0b000000000000000010110101 
0b000000000000000011111111 &
----------------------------
0b000000000000000010110101

```
This exercise can be repeated for each of macros to test their validity.

Recall from **Exercise 4**, I assumed by "last byte" they meant the highest byte was meant as red. If instead blue was intended to be the higher order byte we would simply swap from bitshifting for red by 16 to instead blue.

```C
#define GET_RED(c)      ((c) & 0xFF)   
#define GET_GREEN(c)    ((c) >> 8 & 0xFF)
#define GET_BLUE(c)     ((c) >> 16 & 0xFF)
```
Because bitshifting has a higher order of precedence than bitwise ANDing we do not need parentheses around the bitshift in our macro.

---

## Exercise 5 ##

### **Question** ##

(a) Use the bitwise operators to write the following function:

```C
unsigned short swap_bytes(unsigned short i);
```
`swap_bytes` should return the number that results from swapping the two bytes in `i`. (Short integers occupy two bytes on most computers.) For example, if `i` has the value `0x1234` (00010010 00110100 in binary), then `swap_bytes` should return `0x3412` (00110100 00010010 in binary). Test your function by writing a program that reads a number in hexadecimal, then writes the number with its bytes swapped.

`Enter a hexadecimal number (up to four digits): 1234`

`Number with bytes swapped: 3412`

*Hint:* Use the `%hx` conversion to read and write the hex numbers.

(b) Condense the `swap_bytes` function so that its body is a single statement.


### **Answer**  ###

(a)

```C
#include<stdio.h>

unsigned short swap_bytes(unsigned short i);

int main(void) {

    unsigned short entered;
    
    printf("Enter a hexadecimal number (up to four digits): ");
    scanf("%4hx", &entered);

    printf("Your number: 0x%hx", swap_bytes(entered));

    return 0;

}

unsigned short swap_bytes(unsigned short i) {

    //Use variables to store the high and low parts of i by shifting.
    unsigned short high = i >> 8;
    unsigned short low = i << 8;

    //OR the high and low parts together to get the complete number
    return high | low;
    
}
```
(b)
```C
unsigned short swap_bytes(unsigned short i) {

    //Rather than using variables to store the high and low parts perform it
    //in one statement.
    return (i >> 8) | (i << 8);

}
```

---