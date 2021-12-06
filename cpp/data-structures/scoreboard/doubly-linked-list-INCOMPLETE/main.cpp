/*
 Perform the previous project but use a doubly linked list. Moreover, your
 implementation of remove(i) should make the fewest number of pointer
 hops to get to the game entry at index i.
 */

#include "DNode.h"
#include "DLinkedList.h"
#include <iostream>
#include <vector>
using namespace std;

void testCase() {
	vector<DLinkedList*> test(1);
	test[0] = new DLinkedList;
	
	for (int i = 10; i <= 100; i += 10) { test[0]->sortAdd(i); }
	
	test[0]->sortAdd(45);
	
	cout << "DONE" << endl;

}

int main() {
	testCase();
	return 0;
}
