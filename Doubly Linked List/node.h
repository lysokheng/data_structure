//
//  node.h
//  Doubly Linked List
//
//  Created by LySokHeng Huot on 7/25/22.
//

#include <stddef.h>

#ifndef node_h
#define node_h

class node{
    public:
    node* prev;
    int data;
    node* next; 
      
    node(int value){  // A constructor is called here
        prev = NULL;      // By default previous pointer is pointed to NULL
        data = value;   // value is assigned to the data
        next = NULL;    // By default next pointer is pointed to NULL
    }
};

#endif /* node_h */
