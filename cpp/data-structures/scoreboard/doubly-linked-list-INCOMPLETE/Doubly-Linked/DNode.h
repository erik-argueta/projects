//
//  DNode.h
//  Data-Structures-Notes
//
//  Created by Erik Argueta on 11/18/21.
//

#ifndef DNode_h
#define DNode_h

typedef int Elem;
class DNode {
	Elem elem;
	DNode* next;
	DNode* prev;
	
	friend class DLinkedList;
};

#endif /* DNode_h */
