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

We can easily toggle a bit to be a 1 by performing an OR (`|`) with a mask that contains a 1 bit in our desired location (In this case, bit 4.)

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
To toggle a bit to be a 0 (clearing it) we can perform an AND (`&`) operation with a mask that has a 0 bit in the desired position. 

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