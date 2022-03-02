#if 0
Justin Iness 
2/7/2022
C++ Programming
BINARY TREE NODE CLASS
#endif

#ifndef BTNODEHEADER
#define BTNODEHEADER

#include <iostream>
//include data
using namespace std;
class btnode{
	public:
		btnode(char charIn); //para const
		~btnode(); //destruct
		//getters and setters
		char getChar();
		btnode* getPrev();
		btnode* getNext();
		void setPrev(btnode* prevIn);
		void setNext(btnode* nextIn);
	private:
		char c; // storage
		btnode* next; 
		btnode* prev;
};

#endif
