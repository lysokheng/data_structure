//
//  main.cpp
//  Link Connection
//
//  Created by LySokHeng Huot on 5/12/22.
//

#include <iostream>

using namespace std;

/**
 Create Link class to create a linked list
 */
class Link{
    public:
        int Value;
        Link *Next;
        Link();
};

/**
 constructure
 */
Link::Link(){
    Value = 1;
    Next = NULL;
};

/**
 Driver code
 */
int main(int argc, char** argv) {
    
    //Create 10 links and make it connect from one to one
    Link Link1;
    Link1.Value = 1;
    
    Link Link2;
    Link2.Next = &Link1;
    Link2.Value = 2;
    
    Link Link3;
    Link3.Next = &Link2;
    Link3.Value = 3;
    
    Link Link4;
    Link4.Next = &Link3;
    Link4.Value = 4;
    
    Link Link5;
    Link5.Next = &Link4;
    Link5.Value = 5;
    
    Link Link6;
    Link6.Next = &Link5;
    Link6.Value = 6;
    
    Link Link7;
    Link7.Next = &Link6;
    Link7.Value = 7;
    
    Link Link8;
    Link8.Next = &Link7;
    Link8.Value = 8;
    
    Link Link9;
    Link9.Next = &Link8;
    Link9.Value = 9;
    
    Link Link10;
    Link10.Next = &Link9;
    Link10.Value = 10;
    
    Link *tmp = new Link();
    tmp = &Link10;
    
    
    //Print value of each link and address of next, also its own address
    for (int i = sizeof(Link); i > 0; i--) {
        cout<< "Value: " << tmp->Value <<endl;
        cout<< "Own address: " << tmp <<endl;
        cout<< "Address of next: " << tmp->Next <<endl<<endl;
        tmp = tmp->Next;
    }
    return 0;
}

