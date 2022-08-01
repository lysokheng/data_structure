//
//  main.cpp
//  Priority-Queue
//
//  Created by LySokHeng Huot on 5/5/22.
//

// Standard Template Library (STL)
#include <iostream>
#include <queue>

using namespace std;

// Print the Priority-Queue
void display(priority_queue<int> data)
{
    priority_queue<int> quiz = data;
    //keep popping and printing the front until the
    //Priority-Queue become empty
    while (!quiz.empty()) {
        cout << '\t' << quiz.top();
        quiz.pop();
    }
}

// Driver Code
int main()
{
    priority_queue<int> quiz; //declare Priority-Queue as quiz variable
    
    //inserts an element at the end of the queue
    quiz.push(10);
    quiz.push(20);
    quiz.push(30);
    quiz.push(40);
    quiz.push(50);
    
    //display element after push in
    cout << "The Priority-Queue quiz is : ";
    display(quiz);

    //Returns the size of the queue.
    cout << "\nquiz.size() : " << quiz.size();
    
    //Returns a reference to the first element of the queue.
    cout << "\nquiz.top() : " << quiz.top();

    //Deletes the first element of the queue.
    cout << "\nquiz.pop() : ";
    quiz.pop();
    //to display a present elements in queue
    display(quiz);
    
    //Returns whether the queue is empty.
    cout << "\nquiz.empty() : ";
    quiz.empty();
    
    //after modify
    cout << "\nAfter modify: ";
    display(quiz);

    cout << '\n';

    return 0;
}


