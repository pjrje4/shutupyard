#if 0
Justin Iness
2/7/2022
C++ Programming
BINARY TREE NODE CLASS
#endif

#include "btnode.h"
btnode::btnode(char charIn) { // para const
	this->c = charIn;
	this->next = NULL;
	this->prev = NULL;
}
btnode::~btnode() { // destruct
	cout << "btnode deconstructor called" << endl;
}
//getters and setters
char btnode::getChar() {
	return this->c;
}
btnode* btnode::getNext() {
	return this->next;
}
btnode* btnode::getPrev() {
	return this->prev;
}
void btnode::setPrev(btnode* prevIn) {
	this->prev = prevIn;
}
void btnode::setNext(btnode* nextIn) {
	this->next = nextIn;
}
