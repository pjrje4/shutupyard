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

int main() { //main
	char input[30] = "himynameisstupid";
	btnode* n1 = new btnode(input[1]);
	btnode* n2 = new btnode(input[2]);
	btnode* n3 = new btnode(input[3]);

	n1->setNext(n2);
	n2->setPrev(n1);
	n2->setNext(n3);
	n3->setPrev(n2);

	cout << n1->getChar() << endl;
	cout << n2->getChar() << endl;
	cout << n3->getChar() << endl;

	cout << endl;
	
	cout << n1->getChar() << endl;
	cout << n1->getNext()->getChar() << endl;
	cout << n1->getNext()->getNext()->getChar() << endl;

	cout << endl;

	cout << n3->getChar() << endl;
	cout << n3->getPrev()->getChar() << endl;
	cout << n3->getPrev()->getPrev()->getChar() << endl;

	return 0;
}
