//
//  SLinkedList.h
//  Data-Structures-Notes
//
//  Created by Erik Argueta on 11/14/21.
//

#ifndef SLinkedList_h
#define SLinkedList_h

#include "SNode.h"

class SLinkedList {
public:
	SLinkedList();
	~SLinkedList();
	bool empty() const;
	bool tempEmpty() const;
	const int& front() const;
	const int& tempFront() const;
	void addFront(const int& s);
	void addFrontTemp(const int& t);
	void transferScore();
	void transferBack();
	void removeFront();
	void removeFrontTemp();
	void sortAdd(const int& s);

	void print();
private:
	SNode* head;
	SNode* temporaryHead;
	int maxScores;
	int currentTotal; int tempTotal;
	int tempScore; int currentScore;
};


#endif /* SLinkedList_h */
