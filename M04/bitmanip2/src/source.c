/*
Implement below function **mergeBits** which takes two 4 bit number as input values 
and returns a 8 bit value. This 8 bit value is formed from the two input values **a**
and **b**. The value **a** forms the 4 higher order bits of the return value whereas
**b** forms 4 lower order bits of the return value. For example, when a function 
is called as follows: `mergeBits (0x6, 0xD)`, then result will be eight-bit number, 
which is the hexadecimal representation `6D`.
*/

#define BIT_MASK ((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3)) //sama kuin 0x0F 0000 1111

// define mergeBits function here
unsigned char mergeBits(unsigned char a, unsigned char b) {
    a = a & BIT_MASK;
    b = b & BIT_MASK;
    return a << 4 | b;
}
