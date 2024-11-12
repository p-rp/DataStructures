#pragma once
#include <iostream>

using namespace std;

/**
 * Nickname (alias) given to a variable. Another name for a variable
 * Must be initialized when declared.
 * Used for parameter passing.
 * Cannot change reference.
*/

void Reference()
{
    cout << endl << "------------------Reference------------------" << endl;

    int a = 10;
    int& r = a;             // Reference. Must be initialized when declared.
    cout << r << endl;

    int b = 15;
    r = b;
    cout << r << endl << a << endl;

}