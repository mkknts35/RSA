#pragma once
#ifndef RSA_H_
#define RSA_H_

#include <string>
#include <sstream>

using namespace std;

enum {
    x, y, gcd
};
//========================================================================
// REQUIRES: Two valid integers and an integer array of size three
// MODIFIES: The contents of the given array
// EFFECTS: Uses the extended Euclidian algorithm to determine 
//          mx + ny = gcd(m,n) and returns the result in xygcd[].
//          xygcd[0] = x
//          xygcd[1] = y
//          xygcd[2] = gcd(m,n)
//========================================================================
bool extendedEuclid(int m, int n, int xygcd[3]);
//========================================================================
// REQUIRES: A string of numbers separated by white space, and two 
//           integers.
// MODIFIES: Nothing
// EFFECTS: Returns a string that is the result of RSA decryption 
//          calculations done on the numbers in the input stream treating 
//          each as a single character in some encrypted message.
//          eg. Input: 123345454356 123543211097 ... 908756005432
//              Output: Some plain text that was hidden in plain sight
//========================================================================
string decrypt(stringstream &message, int key, int n);
//========================================================================
// REQUIRES: A message of greater than zero length, and two integers
// MODIFIES: Nothing
// EFFECTS: Returns a string of numbers separated by white space that 
//          represent the characters of the given message after having  
//          gone through the RSA encryption steps.
//          eg. Input: Words in standard text format...
//              Output: 123345454356 123543211097 ... 908756005432
//========================================================================
string encrypt(string message, int key, int n);
//========================================================================
// REQUIRES: Three integers
// MODIFIES: Nothing
// EFFECTS: Uses RSA equations to modify base with exponent and modulus, 
//          and returns the result.
//========================================================================
long long int modular_pow(long long int base, long long int exponent, int modulus);

#endif