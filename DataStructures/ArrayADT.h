#include <iostream>
using namespace std;

class ArrayADT
{
private:
    int* A;
    int size;       // Size of array
    int length;     // # of elements in array
    void swap(int* x, int* y);

public:
   
    // Constructors
    ArrayADT();
    ArrayADT(int);
    ~ArrayADT();

    // Methods
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int BinarySearch_recursive(int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    ArrayADT* Merge(ArrayADT arr2);
    ArrayADT* Union(ArrayADT arr2);
    ArrayADT* Diff(ArrayADT arr2);
    ArrayADT* Inter(ArrayADT arr2);

    void single_missing_element();
    void single_missing_element_2();

    void multiple_missing_elements();
    void multiple_missing_elements_hash();

    void duplicates_sorted();
    void duplicates_unsorted_hash();
    void duplicates_unsorted();

    void two_sum_hash(int target);
    void pair_elements_sorted(int target);

    void max_min();  
};

void runArrayADT();