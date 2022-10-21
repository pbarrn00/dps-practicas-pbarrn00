/**
 * Author: Pablo Javier Barrio Navarro
*/

/**
 * 
 * In this small example I will try a small program to see some Integer Rules of CMU.
 * 
 * The analized rule will be: INT35-C. Use correct integer precisions
 * 
 * PROBLEM:Integer types in C have both a size and a precision. The size indicates the number of bytes 
 * used by an object and can be retrieved for any object or type using the sizeof operator.
 * The precision of an integer type is the number of bits it uses to represent values, excluding any sign and padding bits.
 * Padding bits contribute to the integer's size, but not to its precision. 
 * Consequently, inferring the precision of an integer type from its size may result in too large a value,
 * which can then lead to incorrect assumptions about the numeric range of these types.
 * Programmers should use correct integer precisions in their code, and in particular,
 * should not use the sizeof operator to compute the precision of an integer type on architectures that use padding bits or in strictly conforming (that is, portable) programs.
 * 
*/

#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#define PRECISION(umax_value) popcount(umax_value)

/**
 * REMINDER: This noncompliant code example illustrates a function that produces 2 raised to the power of the function argument.
 * To prevent undefined behavior in compliance with INT34-C. Do not shift an expression by a negative number of bits or by greater than or equal to the number of bits that exist in the operand,
 * the function ensures that the argument is less than the number of bits used to store a value of type unsigned int.
*/
unsigned int pow2(unsigned int exp) {
  if (exp >= sizeof(unsigned int) * CHAR_BIT) {
    /* Handle error */
  }
  return 1 << exp;
}

/**
 * SOLUTION: This compliant solution uses a popcount() function, which counts the number of bits set on any unsigned integer, 
 * allowing this code to determine the precision of any integer type, signed or unsigned.
*/

/* Returns the number of set bits */
size_t popcount(uintmax_t num) {
  size_t precision = 0;
  while (num != 0) {
    if (num % 2 == 1) {
      precision++;
    }
    num >>= 1;
  }
  return precision;
}
