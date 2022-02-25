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
char pop(linked* &head) {
	char headC = head->c;
	linked* temp = head;
	if (head->next != NULL) {
		head = head->next;
	}
	else {
		head = NULL;
	}
	delete temp;
	return headC;
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
void print(linked* head) {
	if (head != NULL) {
		cout << head->c;	
	}
	else {
		cout << endl;
	}
	if (head->next != NULL) {
		print(head->next);
	}
}
void reverse(linked* &head) {
	linked* output = NULL;
	while (head != NULL) {
		enqueue(output, pop(head));
	}
	head = output;
}



int main() { //main
	cout << "input expression:" << endl;
	char input[100];

	cin.get(input, 100);
	cin.get();

	linked* queue = NULL;
	linked* stack = NULL;
	linked* output = NULL;

	for (int i = 0; i <= strlen(input); i++) {
		char c = input[i];
		cout << c << endl;
		if (isdigit(c)) {
			enqueue(queue, c);
			cout << "digit queued" << endl;
		}
		else if (c=='+'||c=='-'||c=='*'||c=='/'||c=='^') {
			while (stack != NULL && top(stack) != '(') {
				char t = top(stack);
				if (c == '+' || c == '-') {
					/*if (t=='*'||t=='/'||t=='^') {
						break;
					}*/
					if (!(t=='+'||t=='-'||t=='*'||t=='/'||t=='^')) {
						break;
					}
				}
				else if (c == '*' || c == '/') {
					/*if (t=='^') {
						break;
					}*/
					if (!(t=='*'||t=='/'||t=='^')) {
						break;
					}
				}
				if (c == '^') {
					break;
				}
				cout << "enqueueing ";
				cout << top(stack) << endl;
				enqueue(queue, pop(stack));
			}
			push(stack, c);
		}
		else if (c == '(') {
			push(stack, c);
		}
		else if (c == ')') {
			while (top(stack) != '(') {
				if (stack != NULL) {
					cout << "Operator Stack Not Empty" << endl;
					enqueue(queue, pop(stack));
				}
				else {
					cout << "Mismatched Parenthesis" << endl;
					return 1;
				}
			}
			cout << "Left Parenthesis" << endl;
			pop(stack);
		}
	}
	while (stack != NULL) {
		if (top(stack) == '(' || top(stack) == ')') {
			cout << "Mismatched Parenthesis" << endl;
			return 1;
		}
		else {
			cout << "Not a left parenthesis" << endl;
			enqueue(queue, pop(stack));
		}

	}
	reverse(queue);
	print(queue);
	return 0;
}
