# Uniary operator
    ++, --

# Binary operator
    +, -, *, \, %
    <, <=, >=, ==, !=
    &&, ||, !

# Ternary operator
    ?:

# XOR operator (^)
    - used in many questions to calculate odd one out or the one which is not repeating
    - toggle nth bit (on <-> off)

# Left and Right shift operator (<<, >>)
    - left shift -> multiply by 2
    - right shift -> divide by 2

# AND operator (&)
    - used to quickly check if a no is odd or even
    - to unset nth bit
        num &= (~(1 << pos))
    - to check if bit is set or unset
        bool bit = num & (1 << pos)

# OR operator (|)
    to set nth bit
        num |= (1 << pos)

# Not operator (~)
    1's compliment of a number 
        ~n = -(n+1)
    
# Negation operator (-)
    2's compliment of a number (-n)
    
# Stripping off the lowest set bit
    x = x & (x-1)
    eg. 1100 -> 1000
        1011 -> 1010

# Getting the lowest set bit (rsbm)
    int res = x & (-x)
    eg. 1100 -> 0100

# Clear all bits from LSB to ith bit
    mask = ~((1 << i+1 ) - 1);
    x &= mask;

# Clear all bits from MSB to ith bit
    mask = (1 << i) - 1;
    x &= mask;