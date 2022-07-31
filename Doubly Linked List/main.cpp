//
//  main.cpp
//  Doubly Linked List
//
//  Created by LySokHeng Huot on 7/25/22.
//

#include <iostream>

#include "node.h"
#include "operations.h"

using namespace std;

int main() {
    node* head = NULL; // declaring an empty doubly linked list
        
    cout<<"\nAfter Insert Tail: "<<endl;
    InsertTail(head, 1);
    InsertTail(head, 2);
    InsertTail(head, 3);
    InsertTail(head, 4);
    InsertTail(head, 5);
    Display(head);
    
    cout<<"\nAfter Insert First: "<<endl;
    InsertFirst(head, 0);
    Display(head);
    
    cout<<"\nAfter Insert Tail: "<<endl;
    InsertTail(head, 6);
    Display(head);
    
    cout<<"\nCheck Size in list: "<<endl;
    Size(head);
    
    cout<<"\nAfter Insert In The Position 3: "<<endl;
    InsertInThePosition(head, 20, 3);
    Display(head);

    cout<<"\nAfter Remove First: "<<endl;
    DeleteNode(&head, head);
    Display(head);

    cout<<"\nAfter Remove Link In Position 2: "<<endl;
    RemoveLinkInPosition(&head, 2);
    Display(head);

    cout<<"\nAfter Remove Tail: "<<endl;
    RemoveTail(head);
    Display(head);

    cout<<"\nis Empty? "<<endl;
    
   if(isEmpty(head))
       cout<<"The list is empty!"<<endl;

   else {
       cout<<"The list is not empty! List contains:"<<endl;
       Display(head);
   }
   
    
    return 0;
}
