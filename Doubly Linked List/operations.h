//
//  operations.h
//  Doubly Linked List
//
//  Created by LySokHeng Huot on 7/25/22.
//

#include <iostream>
#include "node.h"

#ifndef operations_h
#define operations_h

using namespace std;

void Size(node *node)
{
  // Initialize variable count for size
  int count = 0;

  // loop all nodes
  while (node != NULL)
  {
    // if node not NULL then increment count
    count++;
    node = node->next;
  }
  // print count total size
  cout << count << endl;
}

void InsertFirst(node *&head, int value)
{
  // create object to store data
  node *n = new node(value);

  // assign head to next node
  n->next = head;

  // assign node to previous head
  if (head != NULL)
  {
    head->prev = n;
  }
  // if head == NULL, we need to assign n to head
  head = n;
}

void InsertTail(node *&head, int value)
{
  // head == NULL, we use InsertFirst() instead
  if (head == NULL)
  {
    InsertFirst(head, value);
    return;
  }

  // create a new node
  node *n = new node(value);

  // assign head to the temp node
  node *temp = head;

  // make sure the next head is not NULL
  while (temp->next != NULL)
  {

    //assign the next head to the head
    temp = temp->next;
  }

  //assign a new node to the next head of the list
  temp->next = n;

  //assign the head to prev new node
  n->prev = temp;
}

void Display(node *head) {
  //assign head to the temp node
  node *temp = head;

  //make sure our node is not NULL
  while (temp != NULL) {
    
    //print data in the temp nodes
    cout << temp->data << " --> ";

    //the next temp node is assigned to the temp node
    temp = temp->next;
  }

  //else print NULL
  cout << "NULL" << endl;
}

void InsertInThePosition(node *head, int newElement, int position) {

  //allocate node to new element
  node *newNode = new node(newElement);
  newNode->data = newElement;
  newNode->next = NULL;
  newNode->prev = NULL;

  //check if the position is > 0
  if (position < 1) {
    cout << "\nposition should be >= 1.";

  } else if (position == 1) {

    //if the position is 1, make new node as head
    newNode->next = head;
    head->prev = newNode;
    head = newNode;

  } else {

    //Else, make a temp node and traverse to the
    //node previous to the position
    node *temp = head;
    for (int i = 1; i < position - 1; i++) {

      if (temp != NULL) {
        temp = temp->next;
      }
    }

    //If the previous node is not null, adjust the links
    if (temp != NULL) {
      newNode->next = temp->next;
      newNode->prev = temp;
      temp->next = newNode;

      if (newNode->next != NULL)
        newNode->next->prev = newNode;

    } else {

      //When the previous node is null
      cout << "\nThe previous node is null.";
    }
  }
}

void DeleteNode(node **head_ref, node *del) {
  //base case
  if (*head_ref == NULL || del == NULL)
    return;

  //If node to be deleted is head node
  if (*head_ref == del)
    *head_ref = del->next;

  //Change next only if node to be deleted is NOT the last node
  if (del->next != NULL)
    del->next->prev = del->prev;

  //Change prev only if node to be deleted is NOT the first node
  if (del->prev != NULL)
    del->prev->next = del->next;

  //Finally, free the memory occupied by del
  free(del);
  return;
}

void RemoveLinkInPosition(node **head_ref, int n) {
  //if list in NULL or invalid position is given
  if (*head_ref == NULL || n <= 0)
    return;

  node *current = *head_ref;

  //traverse up to the node at position 'n' from the beginning
  for (int i = 1; current != NULL && i < n; i++)
    current = current->next;

  //if 'n' is greater than the number of nodes in the doubly linked list
  if (current == NULL)
    return;

  //delete the node pointed to by 'current'
  DeleteNode(head_ref, current);
}

void RemoveTail(node *head) {
  //make sure head is not NULL
  if (head != NULL) {

    //if head in not null and next of head
    //is null, release the head
    if (head->next == NULL) {
      head = NULL;

    } else {

      //Else, traverse to the second last
      //element of the list
      node *temp = head;
      while (temp->next->next != NULL)
        temp = temp->next;

      //Change the next of the second
      //last node to null and delete the
      //last node
      node *lastNode = temp->next;
      temp->next = NULL;
      free(lastNode);
    }
  }
}

bool isEmpty(node *head) {
  //check if the next head is equal to the head and those head contains empty data
  if (head->next == head && head->data == 0)
    return true;

  //else
  return false;
}

#endif /* operations_h */
