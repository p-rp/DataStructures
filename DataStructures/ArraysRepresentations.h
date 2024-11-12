#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

/**
 * Array: collection of similar data elements.
*/

void array_declaration()
{
    int A[5];                           // Array of size 5 with garbage values
    int B[5] = {2,4,6,8,10};            // [2, 4, 6, 8, 10]
    int C[5] = {2, 4};                  // [2, 4, 0, 0, 0]
    int D[5] = {0};                     // [0, 0, 0, 0, 0]
    int E[] = {2,4,6,8,10,12};          // [2, 4, 6, 8, 10, 12]

    // Access arrays
    cout << B[2] << endl;               // access 3rd element
    cout << 2[B] << endl;               // same thing
    cout << *(B + 2) << endl;           // same thing
}

void static_dynamic()
{
    int A[5];           // Static array (in stack). Size CANNOT change.

    int* P;
    P = new int[5];     // Dynamic array (in heap). Size CAN change. 
    P = (int*)malloc(5 * sizeof(int));  // Same thing as ^

}

void increase_size()
{
    int* p, * q;
    int i;
    p = new int[5];
    p[0] = 3; p[1] = 5; p[2] = 7; p[3] = 9; p[4] = 11;

    q = new int[10];

    for (i = 0; i < 5; i++)
        q[i] = p[i];

    free(p);
    p = q;
    q = NULL;

    for (i = 0; i < 5; i++)
        printf("%d \n", p[i]);
}

void array_2d()
{
    // Static 2D array
    int A[3][4] = { {1,2,3,4},{2,4,6,8},{1,3,5,7} };

    int* B[3];      // Pointer to array
    int** C;        // Double pointer

    // Create arrays for each pointer
    B[0] = (int*)malloc(4 * sizeof(int));
    B[1] = (int*)malloc(4 * sizeof(int));
    B[2] = (int*)malloc(4 * sizeof(int));

    // Create array of int pointers
    C = (int**)malloc(3 * sizeof(int*));      // C = new int*[3];
    C[0] = (int*)malloc(4 * sizeof(int));      // C[0] = new int[4]
    C[1] = (int*)malloc(4 * sizeof(int));      // C[1] = new int[4]
    C[2] = (int*)malloc(4 * sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
}


void ArraysRepresentations()
{
    cout << endl << "------------------Arrays Representations------------------" << endl;

    array_declaration();
    array_2d();
}