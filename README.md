# Stack-Based-Calculator-C++

A stack-based calculator program in C++. The calculator reads tokens (numbers and commands) from a specified input file. In the input file each token is separated by a space or a new line. Each number is placed on a stack and each command consumes one or more values from the stack. A command may result in a modification of the stack, an additional number added to the stack, and/or output printed to the console (stdout / cout). The calculator support int and double values and only promote an int to a double when necessary. The program is written in pure C++ (not C) and uses the C++ STL. When printing output double values are formatted to three decimal places.

Sample input:
10 20 sub
4 3 add
2 mult
16.0
2 repeat
sqrt
endrepeat
pop
2.0
mult
3 repeat
2
2 reverse
div
3 mult
endrepeat

Sample output:
20 - 10 = 10
3 + 4 = 7
2 * 7 = 14
sqrt 16.000 = 4.000
sqrt 4.000 = 2.000
2.000 * 14 = 28.000
28.000 / 2 = 14.000
3 * 14.000 = 42.000
42.000 / 2 = 21.000
3 * 21.000 = 63.000
63.000 / 2 = 31.500
3 * 31.500 = 94.500
