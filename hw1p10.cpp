/*
	@Suyogya Rayamajhi
	@CSCI-313
	@Group 6
	@Date: 3/21/21
    Homework 1 Program 10
    C++ program that contains a function for a linked list that sorts the list 
    so that first all odd numbers are listed and then all even numbers.
*/

#include <iostream>
#include <time.h>
using namespace std;

class node {
public:
	int data;
	node* next;
};

node* BuildListForward(int size);
void PrintList(node* val);
void sort(node* head);
void sortAscendingOrder(node* head);


int main() {
	srand(time(nullptr));
	const int const size = 100;

	node* list = BuildListForward(size);
	PrintList(list);
	sort(list);
	sortAscendingOrder(list);
	PrintList(list);

	return 0;
}

//Traverses the list and swaps an even number with an odd number.
void sort(node* head) {
	node* curr, * ptr;
	ptr = head;
	curr = head->next;

	for (curr = head; curr != nullptr; curr = curr->next) {
		for (ptr = curr->next; ptr != nullptr; ptr = ptr->next)
		{
			if (curr->data % 2 == 0 && ptr->data % 2 != 0) {
				swap(curr->data, ptr->data);			
			}	
		}
	}
	
}
//Sorts odd section first by swapping adjacent elements and then does the same for
//even numbers.
void sortAscendingOrder(node* head) {
	node* curr, * ptr;
	ptr = head;
	curr = head->next;

	for (curr = head; curr != nullptr; curr = curr->next) {
		for (ptr = curr->next; ptr != nullptr; ptr = ptr->next)
		{
			if (curr->data %2!=0 && ptr->data % 2 != 0 && curr->data > ptr->data ||
				curr->data % 2 == 0 && ptr->data % 2 == 0 && curr->data > ptr->data) {
				swap(curr->data, ptr->data);
			}
		}
	}
}
//Builds a list and assigns random numbers.
node* BuildListForward(int size) {
	node* first, * last, * newNode;

	first = last = nullptr;

	for (int i = 0; i < size; i++) {

		newNode = new node;
		newNode->data = rand() % size + 1;;
		newNode->next = nullptr;

		if (first == nullptr) {
			first = last = newNode;
		}
		else {
			last->next = newNode;
			last = newNode;
		}
	}
	return first;
}

//Prints a list and stops when current is null.
void PrintList(node* val) {
	node* current = val;

	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl << endl;
}
