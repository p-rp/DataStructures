#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


/**
 * functions parameters are formal parameters.
 * when calling function, those are actual parameters.
*/

// x and y are formal parameters.
void swap1(int x, int y)                // Pass by values. 
{                                       // A copy of the parameters are made, so any changes don't affect actual parameters.
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swap2(int* x, int* y)              // Pass by address. Formal params are pointers.
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

}


void swap3(int& x, int& y)              // Pass by reference. (C++ only)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}



void fun(int* A, int n)                // Pass array by address. Arrays cannot be passed by value. *A same as A[]
{
    A[4] = 99;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    cout << endl;
}

int* fun2(int size)                    // Return an array.
{
    int* p;
    p = new int[size];
    for (int i = 0; i < size; i++)
        p[i] = i + 1;

    return p;
}



void Function()
{
    cout << endl << "------------------Function------------------" << endl;

    // a and b are actual parameters.
    int a, b;
    a = 10;
    b = 20;
    int A[5] = { 2, 4, 6, 8, 10 };

    swap1(a, b);                    // Changes will not reflect in actual parameters.
    cout << a << " " << b << endl;

    swap2(&a, &b);                  // Variables will change.
    cout << a << " " << b << endl;

    swap3(a, b);                    // Variables will change.
    cout << a << " " << b << endl;

    fun(A, 5);                      // Pass array.

    int* arr, sz = 5;
    arr = fun2(5);

    for (int i = 0; i < sz; i++)
        cout << arr[i] << " ";

}