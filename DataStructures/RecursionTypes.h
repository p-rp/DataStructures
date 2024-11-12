#pragma once
#include <iostream>
using namespace std;

// Head recursion: recursive call is the first statement.
void head(int n)
{
    if (n > 0)
    {
        head(n - 1);
        cout << n << " ";
    }
    cout << endl;
}

// Tail Recursion: recursive call is the last statement.
void tail(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        tail(n - 1);
    }
    cout << endl;
}

/**
 * Linear Recursion: function calls itself once.
 * Tree Recursion: function calls itself more than once.
*/
void tree(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        tree(n - 1);
        tree(n - 1);
    }

}   // Time Complexity: O(2^n)



/**
 * Indirect recursion: funcs call other funcs rather than itself. Usually in circular manner.
 * A calls B. B calls C. C calls A.
*/
void funB(int n);
void funA(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        funB(n - 1);
    }
}

void funB(int n)
{
    if (n > 1)
    {
        cout << n << " ";
        funA(n / 2);
    }
}

/**
 * Nested recursion: func will pass paramater as recursive call
*/
int nested(int n)
{
    if (n > 100)
        return n - 10;
    else
        return nested(nested(n + 11));
}


void RecursionTypes()
{
    cout << endl << "------------------Recursion Types------------------" << endl;

    int a = 3;

    cout << "tree: "; tree(a);
    cout << endl;
    cout << "indirect: "; funA(20);
    cout << endl;
    cout << "nested: " << nested(95) << endl;

}