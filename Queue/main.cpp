//
//  main.cpp
//  Stack, Queue, Priority-Queue
//
//  Created by LySokHeng Huot on 5/5/22.
//

// Standard Template Library (STL)
#include <iostream>
#include <queue>

using namespace std;

// Print the queue
void display(queue<int> data)
{
    queue<int> quiz = data;
    //keep popping and printing the front until the
    //queue become empty
    while (!quiz.empty()) {
        cout << '\t' << quiz.front();
        quiz.pop();
    }
}

// Driver Code
int main()
{
    queue<int> quiz; //declare queue as quiz variable
    
    //inserts an element at the end of the queue
    quiz.push(10);
    quiz.push(20);
    quiz.push(30);
    quiz.push(40);
    quiz.push(50);
    
    //display element after push in
    cout << "The queue quiz is : ";
    display(quiz);

    //Returns the size of the queue.
    cout << "\nquiz.size() : " << quiz.size();
    
    //Returns a reference to the first element of the queue.
    cout << "\nquiz.front() : " << quiz.front();
    
    //Returns a reference to the last element of the queue.
    cout << "\nquiz.back() : " << quiz.back();

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

