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
	linked* next = NULL;
};

int main() { //main
	cout << "input expression:" << endl;
	char input[100];

	cin.get(input, 100);
	cin.get();
	
	linked* queue = new linked(input[0]);
	linked* stack = new linked(input[0]);

	queue->setNext(input[1]);


	return 0;
}