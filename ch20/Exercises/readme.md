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

(a) Addition (`+`) has a higher precedence than bitwise shifting. Therefore the expression being evaluated is `i >> (1 + j) >> 1`. Therefore our output is `0` because bitshifting right by `10` and again by `1` leaves us with `0b00000000` since the set bits do not underflow.

(b) Remember that the complement operator (`~`) has higher precedence than the bitwise AND (`&`). `i` is originally set to `0b00000001` by taking the complement we change it to `0b11111110`. Therefore `i & ~i` gives us `0`. See below.

```
0b00000001 ~
----------
0b11111110
0b00000001 &
----------
0b00000000 FINAL = 0
```

(c) Once again let's look at operator precedence here. The complement (`~`) is highest followed by the bitwise AND (`&`) with the bitwise XOR (`^`) coming in last. This means our operation is `((~i) & j) ^ k)` which gives us `1` as our output.

```
0b00000010 ~
----------
0b11111101
0b00000001 &
----------
0b00000001 FINAL = 1
```
(d) `&` has higher precedence than `^` so we have `i ^ j & k`. Which gives us `15`
```
0b00001000
0b00001001 &
------------
0b00001000
0b00000111 ^
-----------
0b00001111 FINAL = 15
```



---