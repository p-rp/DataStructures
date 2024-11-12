#include "ArrayADT.h"
#include <vector>
using namespace std;


ArrayADT::ArrayADT()
{
    size = 10;
    length = 0;
    A = new int[size];
}

ArrayADT::ArrayADT(int sz)
{
    size = sz;
    length = 0;
    A = new int[size];
}

ArrayADT::~ArrayADT()
{
    delete[]A;
}

void ArrayADT::Display()
{
    cout << "\nElements are\n";
    for (int i = 0; i < length; i++)       // Loop through all the elements and print them
        cout << A[i] << " ";
    cout << endl;
}

// Add to end of the list
void ArrayADT::Append(int x)
{
    if (length < size)             // Check if there is space in size
        A[length++] = x;
}

// Add element at index
void ArrayADT::Insert(int index, int x)
{
    if (index >= 0 && index <= length)          // Check if index if valid.
    {
        for (int i = length; i > index; i--)   // Loop backwards till index and move elements to left.
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}

// Remove element from index
int ArrayADT::Delete(int index)
{
    int x = 0;

    if (index >= 0 && index < length)            // Check if index if valid.
    {
        x = A[index];
        for (int i = index; i < length - 1; i++)   // Loop from index to length and move elements to right.
            A[i] = A[i + 1];
        length--;
    }
    return x;
}

void ArrayADT::swap(int* x, int* y)    // Go to functionBasics.h for more
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Iterate through list from start to finish. O(n)
int ArrayADT::LinearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            swap(&A[i], &A[0]);         // Move element to the front of the list so earlier to find again.
            return i;
        }
    }
    return -1;
}

/**
 * Binary Search
 * Array must be sorted.
 * Checks if key is mid.
 * If not, reduce list in half, use the appropriate half. Repeat m
 * O(log2 n). b/c the tracing tree keep branching into two
*/
int ArrayADT::BinarySearch(int key)
{
    int low = 0;
    int high = length - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (key == A[mid])             // If key is at mid
            return mid;
        else if (key < A[mid])       // Go to lower half by moving high to mid
            high = mid - 1;
        else if (key > A[mid])       // Go to higher half by moving low to mid
            low = mid + 1;
    }

    return -1;
}

int ArrayADT::Get(int index)
{
    if (index >= 0 && index < length)
        return A[index];
    return -1;
}

void ArrayADT::Set(int index, int x)
{
    if (index >= 0 && index < length)
        A[index] = x;
}

int ArrayADT::Max()
{
    int max = A[0];

    for (int i = 1; i < length; i++)
        if (A[i] > max)
            max = A[i];

    return max;
}

int ArrayADT::Min()
{
    int min = A[0];

    for (int i = 0; i < length; i++)
        if (A[i] < min)
            min = A[i];

    return min;
}

int ArrayADT::Sum()
{
    int sum = 0;

    for (int i = 0; i < length; i++)
        sum += A[i];
    return sum;
}

float ArrayADT::Avg()
{
    return (float)Sum() / length;
}

void ArrayADT::Reverse()
{
    int* B = new int[length];
    int i, j;


    for (i = 0, j = length - 1; j >= 0; i++, j--) // Create new array and add elements backwards.
        B[i] = A[j];

    for (i = 0; i < length; i++)           // Set elements to original array. O(2n)
        A[i] = B[i];
}

// Swap first and last element, move 1 closer, flip again, repeat. O(n)
void ArrayADT::Reverse2()
{
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--)
        swap(&A[i], &A[j]);

}

// Insert into sorted array
void ArrayADT::InsertSort(int x)
{
    int i = length - 1;

    while (A[i] > x && i >= 0)        // Start from right and shift elements to right, to make space. Till less than x.
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

int ArrayADT::isSorted()
{
    for (int i = 0; i < length - 1; i++)
        if (A[i] > A[i + 1])
            return 0;
    return 1;
}

// Negative on left side, positive on right side.
void ArrayADT::Rearrange()
{
    int i = 0;
    int j = length - 1;
    while (i < j)              // i starts on left and increments. j starts on right and decrements.
    {
        while (A[i] < 0)       // keep incrementing i until positive #
            i++;
        while (A[j] >= 0)      // keep decrementing j until negative #
            j--;

        if (i < j)
            swap(&A[i], &A[j]);    // swap 
    }
}

// Merge 2 sorted arrays into 1
ArrayADT* ArrayADT::Merge(ArrayADT arr2)
{
    int i, j, k;
    i = j = k = 0;

    ArrayADT* arr3 = new ArrayADT(length + arr2.length);

    while (i < length && j < arr2.length)       // Loop until the shortest array finishes
    {
        if (A[i] < arr2.A[j])                // If arr1 is smaller -> add to arr3 and increment i
            arr3->A[k++] = A[i++];
        else                                // If arr2 is smaller -> add to arr3 and increment j
            arr3->A[k++] = arr2.A[j++];
    }

    for (; i < length; i++)            // Loop through rest of arr1 and add to arr3
        arr3->A[k++] = A[i];

    for (; j < arr2.length; j++)      // Loop through rest of arr2 and add to arr3
        arr3->A[k++] = arr2.A[j];

    arr3->length = length + arr2.length;  // Update length

    return arr3;
}

// Union of sorted. (merge two array with no duplicates)
ArrayADT* ArrayADT::Union(ArrayADT arr2)
{
    int i, j, k;
    i = j = k = 0;

    ArrayADT* arr3 = new ArrayADT(length + arr2.length);

    while (i < length && j < arr2.length)       // Loop until the shortest array finishes
    {
        if (A[i] < arr2.A[j])                // if arr1 is smaller -> add to arr3 and increment i
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])             // if arr2 is smaller -> add to arr3 and increment j
            arr3->A[k++] = arr2.A[j++];
        else                                // if they are both same -> add 1 and increment both
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    for (; i < length; i++)            // Loop through rest of arr1 and add to arr3
        arr3->A[k++] = A[i];

    for (; j < arr2.length; j++)      // Loop though rest of arr2 and add to arr3
        arr3->A[k++] = arr2.A[j++];

    arr3->length = k;               // Update length

    return arr3;
}

// Intersection of sorted array. (only elements that are in both)
ArrayADT* ArrayADT::Inter(ArrayADT arr2)
{
    int i, j, k;
    i = j = k = 0;

    ArrayADT* arr3 = new ArrayADT(length + arr2.length);      // Loop until the shortest array finishes

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])            // if arr1 is smaller -> just increment i
            i++;
        else if (arr2.A[j] < A[i])         // if arr2 is smaller -> just increment j
            j++;
        else                            // if they are both same -> add to arr3 and increment both
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    for (; i < length; i++)            // Loop through rest of arr1 and add to arr3
        arr3->A[k++] = A[i];

    for (; j < arr2.length; j++)      // Loop though rest of arr2 and add to arr3
        arr3->A[k++] = arr2.A[j++];

    arr3->length = k;           // Update length

    return arr3;
}

// Difference (A-B). Take elements in A that are not in B.
ArrayADT* ArrayADT::Diff(ArrayADT arr2)
{
    int i, j, k;
    i = j = k = 0;

    ArrayADT* arr3 = new ArrayADT(length + arr2.length);

    while (i < length && j < arr2.length)   // Loop until the shortest array finishes
    {
        if (A[i] < arr2.A[j])            // if arr1 is smaller -> add to arr3 and increment i
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])         // if arr2 is smaller -> increment j
            j++;
        else                            // if they are both same -> increment both
        {
            i++;
            j++;
        }
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];

    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j++];

    arr3->length = k;

    return arr3;
}

// Find single missing element in sorted array. Array starts with 1 and ends with last number
void ArrayADT::single_missing_element()
{
    // Sum of n elements: n(n+1)/2 .Expected sum - actual sum = missing element.

    int n = A[length - 1];    // last element = # of elements
    cout << n * (n + 1) / 2 - Sum();
}

/** Find single missing element in sorted array.
 * Array starts with any number
 * Get difference b/w number and index and find the first one that doesn't match
 */
void ArrayADT::single_missing_element_2()
{
    int diff = A[0] - 0;
    for (int i = 0; i < length; i++)
    {
        if (A[i] - i != diff)
            cout << i + diff << endl;

    }
}

// Missing elements in unsorted array. Check if difference doesn't match, then increment it.
void ArrayADT::multiple_missing_elements()
{
    int diff = A[0] - 0;
    for (int i = 0; i < length; i++)
    {
        if (A[i] - i != diff)          // If differences don't match
        {
            while (diff < A[i] - i)      // Keep printing missing elements until difference matches
            {
                cout << i + diff << endl;
                diff++;
            }
        }
    }
} // O(n). The while loop only fills in the gap b/w elements

// Missing elements in unsorted array.
// Create a hash array and change to 1 where element exists. Not changed ones
void ArrayADT::multiple_missing_elements_hash()
{

    vector<int> hash(Max() + 1);            // Create empty hash array of max element size

    for (int i = 0; i < length; i++)        // Set indices of hash that are elements in arr to 1
        hash[A[i]] = 1;

    for (int i = 1; i < Max() + 1; i++)     // Print the indices from hash that are 0 (missing)
        if (hash[i] == 0)
            cout << i << " ";
    cout << endl;
} // O(n)

// Duplicates in sorted array and keep count.
// Iterates through array and check if next one is a duplicate, then counts how many times it occurs.
void ArrayADT::duplicates_sorted()
{
    int  lastDuplicate = 0;             // Keep track of duplicate

    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] == A[i + 1])     // Check if next is duplicate
        {
            int j = i + 1;                  // j = index of duplicate.
            while (A[j] == A[i]) j++;    // Keep increasing j until 
            cout << A[i] << " is appearing " << j - i << " times." << endl;
            i = j - 1;                      // update i to element before j
        }
    }
}

// Duplicates in unsorted and keep count using hash
void ArrayADT::duplicates_unsorted_hash
()
{
    vector<int> hash(Max() + 1);            // Create empty hash array of max element size

    for (int i = 0; i < length; i++)         // Add 1 to the hash index which is the element number
        hash[A[i]]++;

    for (int i = 0; i < Max() + 1; i++)        // Print the ones that are more than 1 
        if (hash[i] > 1)
            cout << i << " is appearing " << hash[i] << " times." << endl;

}

// Two Sum
// Given an array and a target, find a pair of elements so they're sum equals target 
void ArrayADT::two_sum_hash(int target)
{
    vector<int> hash(Max() + 1);            // Create empty hash array of max element size

    for (int i = 0; i < length; i++)
    {
        if(target - A[i] >=0 && target - A[i] <= Max())     /// Check if index at target-element is in range of vector.
            if (hash[target - A[i]] != 0)                   // Check if index at target-element = 0. If there is that would mean there is a pair.
                cout << A[i] << " " << target - A[i] << endl;
        hash[A[i]]++;

        
    }
}

// Given a sorted array and a target, find a pair of elements so they're sum equals target
// Start from both ends keep coming together until pair is found
void ArrayADT::pair_elements_sorted(int target)
{
    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        if (A[i] + A[j] == target)        // If they meet target move both closer
        {
            cout << A[i] << " " << A[j] << endl;
            i++;
            j--;
        }
        else if (A[i] + A[j] < target)   // If their sum is less than target, increase i
            i++;
        else                            // IF their sum is more than target, decrease j 
            j--;
    }
}

void ArrayADT::max_min()
{
    int max = A[0];
    int min = A[0];

    for (int i = 1; i < length; i++)
    {
        if (A[i] < min)
            min = A[i];

        else if (A[i] > max)
            max = A[i];
    }

    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
}

void runArrayADT()
{
     cout << endl << "------------------Array ADT------------------" << endl;

    ArrayADT* arr1 = new ArrayADT(10);
    ArrayADT* arr2 = new ArrayADT(50);

    for (int i = 0; i < 10; i++)
    {
        arr1->Append(i);
    }

    arr1->Display();
    arr1->two_sum_hash(10);
}


