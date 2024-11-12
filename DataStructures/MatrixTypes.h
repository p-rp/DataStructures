#pragma once
#include <iostream>

using namespace std;

// i are rows, j are columns and index starts at 1. 

// Diagonal Matrix: 
// m[i,j] = 0	if i != j
// m[i,j] != 0	if i == j 
class Diagonal
{
private:
	int n;
	int* matrix;

public:
	Diagonal(int n)
	{
		this->n = n;
		matrix = new int[n];
	}

	// Only store elements if i==j (at diagonal)
	void set(int i, int j, int x)
	{
		if (i == j)
			matrix[i - 1] = x;
	}


	int get(int i, int j)
	{
		if (i == j)
			return matrix[i - 1];
		else
			return 0;
	}


	void display()
	{
		cout << "Diagonal matrix: " << endl;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					cout << matrix[i] << " ";
				else
					cout << "0 ";
			}
			cout << endl; 
		}
	}

	~Diagonal()
	{
		delete[]matrix;
	}
};

// Lower Triangle Matrix:
// m[i,j] = 0	if i < j	1+2+3+4...(n-1) -> n(n-1)/2		total 0 elements
// m[i,j] != 0	if i >= j	1+2+3+4+5...n -> n(n+1)/2		total non-0 elements
class LowerTraingle
{

};

class UpperTriange
{

}; 

void MatrixTypes()
{ 
	cout << endl << "------------------Matrix Types------------------" << endl;

	Diagonal d(4);
	d.set(1, 1, 5);
	d.set(2, 2, 8);
	d.set(3, 3, 9);
	d.set(4, 4, 12);
	d.display();

}