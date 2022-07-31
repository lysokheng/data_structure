//
//  Link.hpp
//  LinkedList
//
//  Created by LySokHeng Huot on 5/30/22.
//

#ifndef Link_hpp
#define Link_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

//Link Class
class Link{
public:
    int iData; //Data Item
    string sName; //Data Item
    Link* pNext; // Pointer to the next link in list
    
    void InitLink(int id, string sn); //Initiation Function to class attributes
    void DisplayLink(); //Display value of Items
};

//InitLink
void Link::InitLink(int id, string sn){
    iData = id;
    sName = sn;
    pNext = NULL;
};

//DisplayLink
void Link::DisplayLink(){
    cout<<"{iData: "<<iData;
    cout<<" sName: "<<sName<<"}"<<endl;
}
#endif /* Link_hpp */
