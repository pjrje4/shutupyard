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

struct linked { //linked list for shunting yard stack / queue
	char c;
	linked(char cIn) {
		c = cIn;
	}
	linked* next = NULL;
};
struct btstack { //binary tree node stack for generating binary tree
	btnode* n;
	btstack(btnode* nIn) {
		n = nIn;
	}
	btstack* next = NULL;
};
void btpush (btstack* &head, btnode* n) { //binary tree stack push
	btstack* temp = new btstack(n);
	temp->next = head;
	head = temp;
}
void push(linked* &head, char cIn) { //stack push
	linked* temp = new linked(cIn);
	temp->next = head;
	head = temp;
}
char pop(linked* &head) { //stack pop
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
btnode* btpop(btstack* &head) { //binary tree stack pop
	btnode* headN = head->n;
	btstack* temp = head;
	if (head->next != NULL) {
		head = head->next;
	}
	else {
		head = NULL;
	}
	delete temp;
	return headN;
}
char top(linked* &head) { //stack top
	return head->c;
}
btnode* bttop(btstack* &head) { //binary tree stack top
	return head->n;
}

void enqueue(linked* &head, char cIn) { // queue enqueue
	linked* temp = new linked(cIn);
	temp->next = head;
	head = temp;
}
char dequeue(linked* &head) { // queue dequeue
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
void print(linked* head) { // print stack / queue for testing
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
void reverse(linked* &head) { // flip stack / queue
	linked* output = NULL;
	while (head != NULL) {
		enqueue(output, pop(head));
	}
	head = output;
}

int length(linked* head) { // length of stack / queue
	int l = 0;
	if (head != NULL) {
		l++;
	}
	while (head->next != NULL) {
		l++;
		head = head->next;
	}
	return l;
}



void infix(btnode* bt) { // infix recursion from binary tree
	if (bt != NULL) {
		if (bt->getChar()=='+'||bt->getChar()=='-'||bt->getChar()=='*'||bt->getChar()=='/'||bt->getChar()=='^') {
			cout << '(';
		}
		infix(bt->getPrev());
		cout << bt->getChar();
		infix(bt->getNext());
		if (bt->getChar()=='+'||bt->getChar()=='-'||bt->getChar()=='*'||bt->getChar()=='/'||bt->getChar()=='^') {
			cout << ')';
		}
		
	}
}
void postfix(btnode* bt) { // postfix recursion from binary tree
	if (bt != NULL) {
		postfix(bt->getPrev());
		postfix(bt->getNext());
		cout << bt->getChar();
	}
}
void prefix(btnode* bt) { // prefix recursion from binary tree
	if (bt != NULL) {
		cout << bt->getChar();
		prefix(bt->getPrev());
		prefix(bt->getNext());

	}
}






int main() { //main
	cout << "input expression:" << endl;
	char input[100];

	cin.get(input, 100); // user input
	cin.get();

	linked* queue = NULL;
	linked* stack = NULL;
	linked* output = NULL;

	for (int i = 0; i <= strlen(input); i++) { // walk through input 
		char c = input[i];
		cout << c << endl;
		if (isdigit(c)) {  // number
			enqueue(queue, c);
			cout << "digit queued" << endl;
		}
		else if (c=='+'||c=='-'||c=='*'||c=='/'||c=='^') { // operator
			while (stack != NULL && top(stack) != '(') {
				char t = top(stack);
				if (c == '+' || c == '-') { //t1
					/*if (t=='*'||t=='/'||t=='^') {
						break;
					}*/
					if (!(t=='+'||t=='-'||t=='*'||t=='/'||t=='^')) {
						break;
					}
				}
				else if (c == '*' || c == '/') { // t2
					/*if (t=='^') {
						break;
					}*/
					if (!(t=='*'||t=='/'||t=='^')) {
						break;
					}
				}
				if (c == '^') { //t3
					break;
				}
				cout << "enqueueing ";
				cout << top(stack) << endl;
				enqueue(queue, pop(stack));
			}
			push(stack, c);
		}
		else if (c == '(') { // left para
			push(stack, c);
		}
		else if (c == ')') { // right para
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
	while (stack != NULL) { // check for mismatched parents and dump stack into output
		if (top(stack) == '(' || top(stack) == ')') {
			cout << "Mismatched Parenthesis" << endl;
			return 1;
		}
		else {
			cout << "Not a left parenthesis" << endl;
			enqueue(queue, pop(stack));
		}

	}
	reverse(queue); // reverse because backwards
	print(queue);
	cout << endl;
	stack = queue; // stack output because why not

	cout << length(stack) << endl;

	btstack* bts = NULL;
	for (int i = 0; i <= length(stack) - 1; i++) { // read the postfix into a tree
		linked* headT = stack;
		for (int j = 0; j < i; j++) {
			headT = headT->next;
		}
		btnode* temp = new btnode(headT->c);
		if (headT->c=='+'||headT->c=='-'||headT->c=='*'||headT->c=='/'||headT->c=='^') { // operator
			temp->setNext(btpop(bts));
			temp->setPrev(btpop(bts));
		}
		btpush(bts, temp);
		cout << headT->c;
		cout << endl;
	}
	cout << "(I)nfix, (P)refix, or p(O)stfix" << endl;
	cin.get(input, 100);
        cin.get(); // userinput
	if (input[0] == 'I') { //infix
		infix(bts->n);
	}
	if (input[0] == 'O') { // postfix
		postfix(bts->n);
	}
	if (input[0] == 'P') {//prefix
		prefix(bts->n);
	}
	cout << endl;
	return 0;
}
