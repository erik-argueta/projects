//
//  DLinkedList.cpp
//  Data-Structures-Notes
//
//  Created by Erik Argueta on 11/18/21.
//

#ifndef DLinkedList_H
#define DLinkedList_H
#include "DNode.h"


class DLinkedList {
public:
	DLinkedList();
	~DLinkedList();
	bool empty() const;
	
	// accessor functions
	const Elem& front() const;
	const Elem& back() const;
	
	// add functions
	void addFront(const Elem& e);
	void addBack(const Elem& e);
	
	// remove functions
	void removeFront();
	void removeBack();
	
	
	// adding the sortAdd
	void sortAdd(const Elem& e);
	
	// cycling
	void cycleBack(const Elem& e);
	void cycleFront(const Elem& e);
	
	
protected:
	void add(DNode* v, const Elem& e);
	void remove(DNode* v);
private:
	DNode* header;
	DNode* trailer;
	DNode* singleHold;
	const int MAX_SIZE;
	int currentSize;
	int lastScore;
};

#endif // DLINKEDLIST_H
