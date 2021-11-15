
/*
	 Write a class that maintains the top 10 scores for a game application,
 implementing the add and remove functions of Section 3.1.1, but use a singly
 linked list instead of an array.
 */

#include "SLinkedList.h"
#include "SNode.h"
#include <iostream>
#include <vector>
using namespace std;

void testCase() {
	vector<SLinkedList*> test(3);
	
	test[0] = new SLinkedList();
	
	test[0]->sortAdd(10);
	test[0]->sortAdd(20);
	test[0]->sortAdd(40);
	test[0]->sortAdd(50);
	test[0]->sortAdd(30);
	
	test[0]->sortAdd(60);
	test[0]->sortAdd(70);
	test[0]->sortAdd(80);
	test[0]->sortAdd(90);
	test[0]->sortAdd(100);
	
	test[0]->sortAdd(77);
	
	
	test[0]->print();
	
	
}

int main() {
	testCase();
	
	return 0;
}
