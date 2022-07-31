//
//  main.cpp
//  LinkedList
//
//  Created by LySokHeng Huot on 5/30/22.
//

#include <iostream>

#include "Link.hpp"
#include "LinkList.hpp"

//driver code
int main(int argc, const char * argv[]) {
        
    LinkList LinkList; //create LinkList object
    LinkList.InitLinkList(); //initial LinkList
    LinkList.IsEmpty(); //ask LinkList isEmpty?
    
    //insert to data to our LinkList
    LinkList.InsertFirst(1, "Hello");
    LinkList.InsertFirst(2, "Bonjour");
    LinkList.InsertFirst(3, "Hi");
    LinkList.InsertFirst(4, "Salut");
    
    LinkList.DisplayLinkList();
    LinkList.RemoveFirst(); //remove first data in our LinkList
    LinkList.DisplayLinkList();
    LinkList.Size(); //check size for each element
    LinkList.DisplayLinkList();
    LinkList.InsertToPosition(2, "ola", 2); //Insert To Position
    LinkList.DisplayLinkList();
    LinkList.InsertTail(1, "ni hoa");
    LinkList.DisplayLinkList();
    LinkList.RemoveTail(); //remove tail from list
    LinkList.DisplayLinkList();
    LinkList.GetTail(); //print link at tail of list
    LinkList.DisplayLinkList();
    LinkList.GetFirst(); //print link at first of list
    LinkList.DisplayLinkList();
    LinkList.Find(2); //find by iData
//    LinkList.DeleteLinkList();
//    LinkList.DisplayLinkList();
    
    return 0;
}
