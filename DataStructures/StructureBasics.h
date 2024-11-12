#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle
{
    int length;     // 4 bytes
    int breadth;    // 4 bytes
    char x;         // 4 bytes (not 1 byte. Because padding it can access 4 bytes at a time.)
}r1, r2, r3;        // Declaration of global variable.

// struct Rectangle r1, r2, r3;         // Same thing as ^

void fun1(struct Rectangle r)           // Pass struct by value
{
    cout << r.length << " " << r.breadth << endl;
}

void fun2(struct Rectangle* p)           // Pass struct by address
{
    p->length = 99;
    cout << p->length << " " << p->breadth << endl;
}

void fun3(struct Rectangle& r)           // Pass struct by reference. C++ only
{
    r.length = 100;
    cout << r.length << " " << r.breadth << endl;
}


void Structure()
{
    cout<<endl<<"------------------Structure------------------" << endl;

    struct Rectangle r4 = {10, 5};      // Initialization
    cout << "Size: " << sizeof(r4) << endl;
    cout << "Length: " << r4.length << endl;

    Rectangle r = { 20, 10 };
    cout << r.length << " " << r.breadth << endl;


    Rectangle* p = &r;                  // Pointer to struct
    cout << p->length << endl;             // Use -> for pointer instead of.
    cout << p->breadth << endl;

    p = (struct Rectangle*)malloc(sizeof(struct Rectangle));        // C. Struct on heap
    p = new struct Rectangle;                                       // C++. Struct on heap

    p->length = 2;                                                // Initialize struct pointer values. 
    p->breadth = 1;

    fun1(r);

    fun2(&r);

    fun3(r);

}
