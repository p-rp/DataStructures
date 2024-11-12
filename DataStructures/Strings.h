#pragma once
#include <iostream>
using namespace std;

void displayString(char* string)
{
    for (int i = 0; string[i] != '\0'; i++)        // Iterate through string
        cout << string[i];
}
int stringLength(char* string)
{
    int i;
    for (i = 0; string[i] != '\0'; i++)
        i++;
    return i;
}


void Strings()
{
    cout << endl << "------------------Strings------------------" << endl;
    // Size of string in C/C++ is string length + 1 b/c last character is 
    // string delimeter / NULL char to signify end of string.

    char name[] = { 'J', 'o', 'h', 'n', '\0' };
    char name2[] = "John";
    char* name3 = name;

    cout << "array size: " << sizeof(name) << endl;    // length = 4+1
    cout << "array size: " << sizeof(name2) << endl;

    displayString(name);

    cout << endl;

    cout << "String length: " << stringLength(name);

}