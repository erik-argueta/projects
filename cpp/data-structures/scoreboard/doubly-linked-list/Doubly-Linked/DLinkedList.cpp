//
//  DLinkedList.cpp
//  Data-Structures-Notes
//
//  Created by Erik Argueta on 11/18/21.
//

#include "DLinkedList.h"
#include "DNode.h"
#include <iostream>

DLinkedList::DLinkedList() : MAX_SIZE(10), currentSize(NULL), lastScore(NULL) {
	header = new DNode;
	trailer = new DNode;
	singleHold = new DNode;
	header->next = trailer;
	trailer->prev = header;
}

DLinkedList::~DLinkedList() {
	while (!empty()) {
		removeFront();
	}
	delete header;
	delete trailer;
}

bool DLinkedList::empty() const {
	return (header->next == trailer);
}

// ACCESSOR FUNCTIONS
const Elem& DLinkedList::front() const {
	return header->next->elem;
}
const Elem& DLinkedList::back() const {
	return trailer->prev->elem;
}


// ADD FUNCTIONS
void DLinkedList::add(DNode* cur, const Elem& e) {
	DNode* newNode = new DNode; newNode->elem = e;
	newNode->next = cur;
	newNode->prev = cur->prev;
	cur->prev->next = newNode;
	cur->prev = newNode;
}

void DLinkedList::addFront(const Elem& e) {
	add(header->next, e);
	currentSize++;
}

void DLinkedList::addBack(const Elem& e) {
	add(trailer, e);
	currentSize++;
}


// REMOVE FUNCTIONS
void DLinkedList::remove(DNode* cur) {
	DNode* priorNode = cur->prev;
	DNode* followingNode = cur->next;
	priorNode->next = followingNode;
	followingNode->prev = priorNode;
	currentSize--;
}

void DLinkedList::removeFront() {
	remove(header->next);
}

void DLinkedList::removeBack() {
	remove(trailer->prev);
}



// sortAdd function
void DLinkedList::sortAdd(const Elem& e) {
	if (empty()) { addFront(e); }
	
	else if (currentSize >= MAX_SIZE) {
		if (e > back()) { removeFront(); addBack(e); }
		else if (e > front()) { cycleFront(e); }
	}
	
	else {
		if (e > back()) { addBack(e); }
		else if (e > front()) { cycleFront(e); }
		else { addFront(e); }
	}
}

// cycleBack
void DLinkedList::cycleBack(const Elem& e) {
	
}

// cycleFront
void DLinkedList::cycleFront(const Elem& e) {
	
	while (e > front()) {
		//DNode* transferNode = new DNode;
		
		// add node to singleHold
		add(singleHold->next, front());
		removeFront();
	}
	
	addFront(e);
	
	while ( singleHold->elem || currentSize <= MAX_SIZE) {
		addFront(singleHold->elem);
		remove(singleHold->next);
	}
	
}
