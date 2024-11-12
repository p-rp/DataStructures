#pragma once
#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node* next;
} *first;

void create(int A[], int n)
{
	int i;
	struct Node* t, * last;
	first = (struct Node*)malloc(sizeof(struct Node));		// Initialize in C.
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (int i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}

}

void display(struct Node *p)
{
	while (p != NULL)		// iterate through linked list until node is NULL
	{
		cout << p->data << " ";
		p = p->next;
	}
}

void display_recursive(struct Node* p)
{
	if (p != NULL)
	{
		cout << p->data << " ";
		display_recursive(p->next);
	}
}

int length(struct Node* p)
{
	int count = 0;

	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

int length_recursive(struct Node* p)
{
	if (p == NULL)
		return 0;

	if (p != NULL)
		return length_recursive(p->next) + 1;		// addition is done at returning time

	
}

int sum(struct Node* p)
{
	int sum = 0;
	while (p != NULL)
	{
		sum += p->data;
		p = p->next;
	}

	return sum;
}

int sum_recursive(struct Node* p)
{
	if (p == NULL)
		return 0;

	if (p != NULL)
		return sum_recursive(p->next) + p->data;
}

int max(struct Node* p)
{
	int max = p->data;
	while (p != NULL)
	{
		if (p->data > max)
			max = p->data;
		p = p->next;  
	}

	return max;
}

int max_recursive(struct Node* p)
{
	int x = 0;

	if (p == NULL)
		return INT_MIN;
	else
	{
		x = max_recursive(p->next);
		if (x > p->data)
			return x;
		else
			return p->data;
	}
}

int max_recursive2(struct Node* p)
{
	int x = 0;
	if (p == NULL)
		return INT_MIN;

	x = max_recursive2(p->next);

	// ternary operator
	return x > p->data ? x : p->data;		// if (x > p->data) return x else return p->data
}

Node* linear_search(struct Node* p, int key)
{
	while (p != NULL)
	{
		if (p->data == key)
			return p;
		
		p = p->next;
	}
	return NULL;		// if there is no node that matches key
}

Node* linear_search_recursive(struct Node* p, int key)
{
	if (p == NULL)
		return NULL;

	if (p->data == key)
		return p;

	return linear_search_recursive(p->next, key);
}

// Move recently found node to front of list
Node* linear_search_improved(struct Node* p, int key)
{
	Node* q = NULL;		// previous node
	while (p != NULL)
	{
		if (key == p->data)
		{
			q->next = p->next;		// set previous_node->next to the one after next
			p->next = first;
			first = 0;
			return p;
		}
		q = p;				// Move nodes forward
		p = p->next;
	}
}

// Insert node at given position
void insert(struct Node* p,int value, int key)
{
	// Create new node with data
	
	
	

}

void LinkedList()
{
	cout << endl << "------------------Linked Lists------------------" << endl;

	struct Node* P;		// Declaration
	P = new Node;		// Initialization 
	P->data = 10;		// Data
	P->next = NULL;

	if (P == NULL);		// 3 ways to check if pointer is NULL.
	if (P == 0);
	if (!P);

	if (P != NULL);		// 3 ways to check if pointer is valid.
	if (P != 0);
	if (P);

	int A[] = { 3, 5, 7, 10, 15 };

	create(A, 5);
	
	cout << "Display linked list: ";  display(first);

	cout << endl;

	cout << "Length: " << length(first);

	cout << endl;

	cout << "Sum: " << sum(first);

	cout << endl;

	cout << "Max: " << max(first);

	cout << endl;

	cout << "Linear Search: " << linear_search(first, 7)->data;

	cout << endl;

}