#pragma once
#include <iostream>
using namespace std;

/**
 * Recursive func: function that calls itself
 *  Loops only have ascending, but recursion has ascending and descending.
*/

void fun(int n)
{
    if (n > 0)     // Base condition. This terminates recursion.
    {
        // Calling time statements. Ascending
        fun(n - 1);
        // Returning time statements. Descending
    }
}

// Calling time. First prints then goes to next call.
// Tail recursion
void recursionFun1(int n)
{
    if (n > 0)
    {
        cout << n << " ";       // n...5, 4, 3, 2, 1. (forward)
        recursionFun1(n - 1);
    }
    cout << endl;
    
} // Time Complexity: O(n).

// Returning time. Goes through all calls, then prints backwards.
// Head recursion
void recursionFun2(int n)
{
    if (n > 0)
    {
        recursionFun2(n - 1);
        cout << n;       // 1, 2, 3, 4, 5, ... n (backward)
    }
    cout << endl;
}

// Add all the numbers till n
int recursionFun3(int n)
{
    if (n > 0)
    {
        return recursionFun3(n - 1) + n;     // 0+1+2+3+4+5+...+n
    }
    return 0;
}

// Static recursion. 
// Value of x is same for all returning calls.
int recursionFun4(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;                    // x=1 -> x=2 -> x=3 -> ... x=n
        return recursionFun4(n - 1) + x;     // x + x + x + ... + x (n times)     n*n
    }
    return 0;
}

void Recursion()
{
    cout << endl << "------------------Recursion------------------" << endl;

    int a = 5;

    cout << "calling time: "; recursionFun1(a);

    cout << "returning time: "; recursionFun2(a);

    cout << "sum: " << recursionFun3(a) << endl;

    cout << "static sum: " << recursionFun4(a) << endl;
}