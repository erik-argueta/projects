//
//  SLinkedList.cpp
//  Data-Structures-Notes
//
//  Created by Erik Argueta on 11/14/21.
//

#include "SLinkedList.h"
#include "SNode.h"
#include <iostream>
using std::cout;
using std::endl;


SLinkedList::SLinkedList() : head(NULL), temporaryHead(NULL), maxScores(10), currentTotal(0), tempTotal(0), currentScore(0), tempScore(0) { }

SLinkedList::~SLinkedList() {
	while (!empty()) {
		removeFront();
	}
}

bool SLinkedList::empty() const {
	return head == NULL;
}

bool SLinkedList::tempEmpty() const { return temporaryHead == NULL; }

const int& SLinkedList::front() const {
	return head->score;
}

const int& SLinkedList::tempFront() const {
	return temporaryHead->score;
}

// we wanna keep highest scores to the front
void SLinkedList::addFront(const int& s) {
	currentScore = s;
	
	SNode* add = new SNode;
	add->score = s;
	add->next = head;
	
	head = add;
	currentTotal++;
}

// addFront to the temp list
void SLinkedList::addFrontTemp(const int& t) {
	SNode* temp = new SNode;
	temp->score = t;
	temp->next = temporaryHead;
	temporaryHead = temp;
}

// transfer head to temporaryHead
void SLinkedList::transferScore() {
	
	SNode* transTo = new SNode;
	transTo->score = currentScore;
	tempScore = currentScore;
	transTo->next = temporaryHead;
	temporaryHead = transTo;
	
	removeFront();
	tempTotal++;
	if (empty()) { currentScore = 0; }
	else {currentScore = head->score; }
}

// transfer temporaryHead->score to head->score
void SLinkedList::transferBack() {
	SNode* transBack = new SNode;
	transBack->score = tempScore;
	currentScore = tempScore;
	transBack->next = head;
	head = transBack;
	
	removeFrontTemp();
	currentTotal++;
	if (tempEmpty()) { tempScore = 0;}
	else { tempScore = temporaryHead->score; }
	
}

void SLinkedList::removeFront() {
	SNode* old = head;
	head = old->next;
	delete old;
	currentTotal--;
}

void SLinkedList::removeFrontTemp() {
	SNode* tempOld = temporaryHead;
	temporaryHead = tempOld->next;
	delete tempOld;
	tempTotal--;
}

void SLinkedList::sortAdd(const int& item) {
	/*
		Maybe the goal should be to keep the highest scores towards the tail.
		This is because higher scores are harder to achieve irl.
	*/
	
	if (empty()) { addFront(item); currentScore = item; }
	
	// this implies there is a score on the list lower than new score
	else {
		while (item > currentScore && !empty()) {
			transferScore();
		}
		if (item < currentScore || empty()) {
			addFront(item);
			while (tempTotal > 0 && currentTotal < 10) {
				transferBack();
			}
		}
		
		while (currentTotal == 10 && tempTotal > 0) {
			removeFrontTemp();
		}
	}
	
}


void SLinkedList::print() {
	while (!empty()) {
		cout << front() << endl;
		removeFront();
	}
}
