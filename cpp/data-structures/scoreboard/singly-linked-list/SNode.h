//
//  SNode.h
//  Data-Structures-Notes
//
//  Created by Erik Argueta on 11/14/21.
//

#ifndef SNode_h
#define SNode_h
#include "SLinkedList.h"

class SNode {
private:
	int score;
	SNode* next;
	
	friend class SLinkedList;
};

#endif /* SNode_h */
