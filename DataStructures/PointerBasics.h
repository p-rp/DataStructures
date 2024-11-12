#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>                 // for malloc in C.
using namespace std;


/**
 * Pointer is a address variable. Stores address of data not data itself.
 * For indirectly accessing data.
 * Every variable declared will be in Stack.
*/


void Pointer()
{
    cout<<endl<< "------------------Pointer------------------" << endl;

    int a = 10;                     // Data var, created in stack. 

    int* p;                         // Declaration. Also in stack.

    p = &a;                         // Initialization. Set value of p to address of a.
    *p += 1;

    cout << "*p: " << *p << endl;         // Dereference (value pointer is pointing to)
    // * should be used at declaration and dereference. 


    int A[] = { 2, 4, 6, 8, 10 };
    int* P;
    P = A;                          // Don't use & for array.
    //  P = A[0];   same thing

    cout << "*P: " << *P << endl;
    cout << "P[1]: " << P[1] << endl;


    P = (int*)malloc(5 * sizeof(int));       // C. Array of size 5 on heap
    P = new int[5];                         //C++. Array of size 5 on heap

    P[0] = 10; P[1] = 15; P[2] = 20; P[3] = 25; P[4] = 30;


    //free(p);                          // C. Deallocate memory
    delete[] P;                         // C++. Deallocate memory

}