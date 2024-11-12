#pragma once
#include <iostream>
using namespace std;

/**
 * Sum of First n Natural Numbers
*/
int sum(int n)
{
    if (n <= 0)
        return 0;
    
    return sum(n - 1) + n;
}

/**
 * Factorial
*/
int factorial(int n)
{
    if (n <= 1)
        return 1;
    
    return factorial(n - 1) * n;
}

/**
 * Power
 * m^n
*/
int power(int m, int n)
{
    return 0;
}

// Optimized
int power_O(int m, int n)
{
    return 0;

}
/**
 * Taylor Series using recursion
*/

/**
 * Taylor Series Horner's Rule
*/

/**
 * Taylor Series Iterative
*/

/**
 * Fibonacci
*/

/**
 * nCr
*/

/**
 * Tower of Hanoi
*/

void RecursionExamples()
{
    cout << endl << "------------------Recursion Examples------------------" << endl;

    cout << "sum: " << sum(5) << endl;

    cout << "factorial: " << factorial(5) << endl;

    cout << "power: " << power(2, 9) << endl;

}