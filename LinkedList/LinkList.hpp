//
//  LinkList.hpp
//  LinkedList
//
//  Created by LySokHeng Huot on 5/30/22.
//

#ifndef LinkList_hpp
#define LinkList_hpp

#include <stdio.h>
#include <iostream>

#include "Link.hpp"

using namespace std;


//LinkList Class
class LinkList{
    Link* pfirst; //ptr to first link on list
public:
    void InitLinkList();
    bool IsEmpty();
    void InsertFirst(int d, string s);
    void RemoveFirst();
    void DeleteLinkList();
    void Size(); //return number item/link in the list
    
    //Create a new link with these values: i & s. In case pos
    //is in the range thus insert the new link to the position
    void InsertToPosition(int intData, string sName, int pos);
    void InsertTail(int intData, string sName); //insert a link with value i to tail of the list
    void RemoveTail(); //remove a link from the list
    Link* GetTail(); //return a link at tail of the list
    Link* GetFirst(); //return the first link or head link
    Link* Find(int data); //return a link with a value iData equal to data
    
    //create functions by my own
    void DisplayLinkList();
    Link* getLink(int data);
    
    //... other Methods here
};

//InitLinkList
void LinkList::InitLinkList(){
    cout<<"==========InitLinkList function=========="<<endl;
    
    pfirst = NULL; //(no links on list yet)
    
    cout<<"InitLinkList\npfirst: "<<pfirst<<endl;
}

//IsEmpty
bool LinkList::IsEmpty(){
    cout<<"\n==========IsEmpty function=========="<<endl;
    
    //if pfirst is null
    if (pfirst==NULL){
        
        cout<<"Empty"<<endl;
        return true;
        
    }else{
        
        cout<<"Not Empty"<<endl;
        return false;
    };
};

//InsertFirst
void LinkList::InsertFirst(int i, string s){
    cout<<"\n==========InsertFirst function=========="<<endl;
    
    Link* NewLink = new Link(); //make new link
    NewLink->InitLink(i, s);
    NewLink->pNext = pfirst; //newLink-->old first
    pfirst = NewLink; //first-->newLink
    
    cout<<"link added"<<endl;
};

//DisplayLinkList
void LinkList::DisplayLinkList(){
    cout<<"\n==========DisplayLinkList function=========="<<endl;

    Link* pTemp = pfirst; //save first

    while (pTemp != NULL) {
        cout<< "iData: " << pTemp->iData <<endl;
        cout<< "sName: " << pTemp->sName <<endl;
        cout<< "Own address: " << pTemp <<endl;
        cout<< "Address of next: " << pTemp->pNext <<endl<<endl;
        pTemp = pTemp->pNext;
    }
}

//delete first link
void LinkList::RemoveFirst(){
    cout<<"\n==========RemoveFirst function=========="<<endl;

    //if list is not empty
    if(pfirst != NULL){
        
    Link* pTemp = pfirst; //save first
    pfirst = pfirst->pNext; //unlink it: first-->old next
    delete pTemp; //delete old first
    cout<<"Remove first link in LinkList"<<endl;
        
    }else{
        //if list is empty
        cout<<"Can not remove because pfirst is null"<<endl;
    }
};

//DeleteLinkList
void LinkList::DeleteLinkList(){
    cout<<"\n==========DeleteLinkList function=========="<<endl;

    Link* pCurrent = pfirst; //start at beginning of list
    while (pCurrent != NULL) { //until end of list
        Link* pOldCur = pCurrent; //save current link
        pCurrent = pCurrent->pNext; //move to next link
        delete pOldCur;
    }
    
    cout<<"LinkList has been deleted"<<endl;
}

//Size
void LinkList::Size(){
    cout<<"\n==========Size function=========="<<endl;
    
    //Size of linked list
    int size = 0;
    
    Link* pTemp = pfirst; //save first

    
    //count until pfirst = null
    while (pTemp != NULL)
    {
        size++;
        pTemp = pTemp->pNext;
    }
    
    cout<<"Size: "<<size<<endl;
}

//InsertToPosition
void LinkList::InsertToPosition(int intData, string sName, int pos){
    cout<<"\n==========InsertToPosition function=========="<<endl;
    
    //save first
    Link* head = pfirst;
    
    //allocating space
    Link* newLink = new Link();
 
    //inserting the required data
    newLink->iData = intData;
    newLink->sName = sName;
    newLink->pNext = NULL;
    
    //if our position under number 1
    if(pos < 1){
        cout<<"position should be >= 1."<<endl;
        
        //if position = 1
    }else if(pos == 1){
        
        //let it to the first link
        newLink->pNext = head;
        head = newLink;
        
        //else perform below
    }else{
        //save head to temp
        Link* temp = head;
        
        //to check make sure our list not null
        for (int i = 1; i < pos-1; i++) {
            
            //if temp not null then tell temp shift to the next link
            if(temp != NULL){
                temp = temp->pNext;
            }
        }
        
        //if temp not equal to null then our new link stay into old link
        if(temp != NULL){
            newLink->pNext = temp->pNext;
            temp->pNext = newLink;

            //on the other hand, The previous link is null
        }else{
            cout<<"The previous link is null."<<endl;
        }
    }
    
    cout<<"insert to position "<<pos<<" with information below: "<<endl;
    cout<<"iData: "<<newLink->iData<<endl;
    cout<<"sName: "<<newLink->sName<<endl;
}

//InsertTail
void LinkList::InsertTail(int intData, string sName){
    cout<<"\n==========InsertTail function=========="<<endl;

    //save first
    Link* head = pfirst;
    
    //allocating space
    Link* newLink = new Link();
 
    //inserting the required data
    newLink->iData = intData;
    newLink->sName = sName;
    newLink->pNext = NULL;
    
    //Check the Linked List is empty or not,
    //if empty make the new Link as head
    if(head == NULL) {
        head = newLink;
        
    } else {
        
        //Else, traverse to the last node
        Link* temp = head;
        
        while(temp->pNext != NULL)
            temp = temp->pNext;

        //Change the next of last node to new node
        temp->pNext = newLink;
      }
    cout<<"insert tail with information below: "<<endl;
    cout<<"iData: "<<newLink->iData<<endl;
    cout<<"sName: "<<newLink->sName<<endl;
}

//RemoveTail
void LinkList::RemoveTail(){
    cout<<"\n==========RemoveTail function=========="<<endl;
    
    //save first
    Link* head = pfirst;

    if (head->pNext == NULL){
        delete head;
    }
    
    // Find the second last node
    Link* second_last = head;
    
    while (second_last->pNext->pNext != NULL)
        second_last = second_last->pNext;
     
    // Delete last node
    delete (second_last->pNext);
     
    // Change next of second last
    second_last->pNext = NULL;
    
    cout<<"remove tail in list"<<endl;
}

//GetTail
Link* LinkList::GetTail(){
    cout<<"\n==========GetTail function=========="<<endl;

    //save first
    Link* head = pfirst;

    if (head->pNext == NULL){
        delete head;
    }
    
    // Find the second last node
    Link* second_last = head;
    
    while (second_last->pNext->pNext != NULL)
        second_last = second_last->pNext;
     
    // Delete last node
    delete (second_last->pNext);
    
    cout<<"get tail with information below: "<<endl;
    cout<<"iData: "<<second_last->pNext->iData<<endl;
    cout<<"sName: "<<second_last->pNext->sName<<endl;
    
    return second_last->pNext;
}

//GetFirst
Link* LinkList::GetFirst(){
    cout<<"\n==========GetFirst function=========="<<endl;

    //save first
    Link* head = pfirst;
    
    //if list is not empty
    if(pfirst != NULL){
        
    cout<<"get first with information below: "<<endl;
    cout<<"iData: "<<head->iData<<endl;
    cout<<"sName: "<<head->sName<<endl;
    }else{
        //if list is empty
        cout<<"the list is null"<<endl;
    }
    
    return head;
};

//function to search element in the linked list
Link* LinkList::Find(int data){
    cout<<"\n==========Find function========= ="<<endl;
    
    cout<<"Location need to find is iData "<<data<<endl;

    //save first
    Link* temp = pfirst;
    
    int flag = 0, i = 0;
    
    //if list is not empty
    if(temp == NULL){
        cout<<"Empty list"<<endl;
    }else{
        
        while (temp != NULL) {
            
            if (temp->iData == data) {
                cout<<"iData found at location: "<<(i+1)<<endl;
                flag=0;
                
            } else {
                flag++;
                
            }
            i++;
            temp = temp -> pNext;
        }
        if(flag==data){ //If element is not present in the list
            cout<<"Item not found\n";
        }
    }
    
    
    return temp;
}

#endif /* LinkList_hpp */
