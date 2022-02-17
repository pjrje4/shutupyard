#include <iostream>
#include <cstring>
#include "btnode.h"

#if 0
Justin Iness
2/7/2022
C++ Programming
Shunting Yard Algorithm
#endif

using namespace std;

struct linked {
	char c;
	linked(char cIn) {
		c = cIn;
	}
	linked* next = NULL;
};
void push(linked* &head, char cIn) {
	linked* temp = new linked(cIn);
	temp->next = head;
	head = temp;
}
void pop(linked* &head) {
	linked* temp = head;
	head = head->next;
	delete temp;
}
char top(linked* &head) {
	return head->c;
}

void enqueue(linked* &head, char cIn) {
	linked* temp = new linked(cIn);
	temp->next = head;
	head = temp;
}
char dequeue(linked* &head) {
	if (head->next != NULL) {
		if (head->next->next != NULL) {
			dequeue(head->next);
		}
		else {
			char temp = head->next->c;
			delete head->next;
			head->next = NULL;
			return temp;
		}
	}
	else {
		char temp = head->c;
		head = NULL;
		return temp;
	}
}


int main() { //main
	cout << "input expression:" << endl;
	char input[100];

	cin.get(input, 100);
	cin.get();

	linked* queue = NULL;
	linked* stack = NULL;

	for (int i = 0; i <= strlen(input); i++) {
		char c = input[i];
		cout << c << endl;
		if (isdigit(c)) {
			enqueue(queue, c);
		}
		else if (c=='+'||c=='-'||c=='*'||c=='/'||c=='^') {
			while (top(stack) != '(') {
				if (c == '+' || c == '-') {

				}
				else if (c == '*' || c == '/') {

				}
				else if (c == '^') {

				}
			}
			push(stack, c);
		}
		else if (c == '(') {
			push(stack, c);
		}
		else if (c == ')') {

		}
	}





	return 0;
}
