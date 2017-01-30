#include "rsa.h"
#include <iostream>

//========================================================================
string decrypt(stringstream &message, int key, int n)
{
    int chr;
    char ascii;
    stringstream result;
    while(!message.eof()){
        message >> chr;
        ascii = (char) modular_pow(chr, key, n);
        result << ascii;
    }
    return result.str();
}
//========================================================================
string encrypt(string message, int key, int n)
{
    stringstream result;
    for(int i = 0; i < message.length(); i++){
        int chr = modular_pow(message[i], key, n);
        result << " " << chr; 
    }
    return result.str();
}
//========================================================================
long long int modular_pow(long long int base, long long int exponent, int modulus)
{
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
//========================================================================
bool extendedEuclid(int m, int n, int xygcd[3])
{
    int a = m, b = n, q, currx, lastx, curry, lasty, temp;
    bool switched = false;

    if (b > a) {//we switch them
        temp = a;
        a = b;
        b = temp;
        switched = true;
    }
    //begin function
    currx = 0;
    curry = 1;
    lastx = 1;
    lasty = 0;
    while (b != 0) {
        q = a / b;
        temp = a % b;
        a = b;
        b = temp;

        temp = currx;
        currx = lastx - q * currx;
        lastx = temp;

        temp = curry;
        curry = lasty - q * curry;
        lasty = temp;
    }

    xygcd[x] = lastx;
    xygcd[y] = lasty;
    xygcd[gcd] = a;
    return switched;
}
