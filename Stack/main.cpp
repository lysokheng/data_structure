//
//  main.cpp
//  Stack
//
//  Created by LySokHeng Huot on 5/5/22.
//

// Standard Template Library (STL)
#include <iostream>
#include <stack>

using namespace std;

// Print the stack
void display(stack<int> data)
{
    stack<int> quiz = data;
    //keep popping and printing the front until the
    //stack become empty
    while (!quiz.empty()) {
        cout << '\t' << quiz.top();
        quiz.pop();
    }
}

// Driver Code
int main()
{
    stack<int> quiz; //declare stack as quiz variable
    
    //inserts an element at the end of the stack
    quiz.push(10);
    quiz.push(20);
    quiz.push(30);
    quiz.push(40);
    quiz.push(50);
    
    //display element after push in
    cout << "The stack quiz is : ";
    display(quiz);

    //Returns the size of the stack.
    cout << "\nquiz.size() : " << quiz.size();
    
    //Returns a reference to the first element of the stack.
    cout << "\nquiz.top() : " << quiz.top();

    //Deletes the first element of the stack.
    cout << "\nquiz.pop() : ";
    quiz.pop();
    //to display a present elements in stack
    display(quiz);
    
    //Returns whether the stack is empty.
    cout << "\nquiz.empty() : ";
    quiz.empty();
    
    //after modify
    cout << "\nAfter modify: ";
    display(quiz);

    cout << '\n';

    return 0;
}


