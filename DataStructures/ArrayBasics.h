#pragma once
#include <iostream>

using namespace std;


void Array()
{
    cout << "------------------Array------------------" << endl;

	int A[5];                          // Declaration. Size should be constant value.
    A[0] = 12;
    A[1] = 15;  
    A[2] = 25;

    cout<<"Size: "<< sizeof(A)<<endl;                       // int size: 4 bytes. 4*5 = 20 bytes
    cout << "Length: " << sizeof(A) / sizeof(int) << endl;


    int B[5] = {2, 4, 6, 8, 10};     // Initialization. (don't need to specify size)

    cout << "\n" << "Print B:" << endl;
    for(int x: B)       // for each loop
    {
        cout<<x<<" ";
    }

    int C[10] = {1, 2};
    cout<<"\n"<< "Value not initialized: " << C[5] << endl;         // If value is not initialized, it will be 0.

    //int n;
    //cout<<"Enter Size: ";
    //cin>>n;
    //int D[n] = {1, 2, 3, 4};      //Cannot initialize variable size array.
    //int D[n];

}
