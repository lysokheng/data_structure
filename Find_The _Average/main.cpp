//
//  main.cpp
//  Find_The _Average
//
//  Created by LySokHeng Huot on 5/5/22.
//

#include<iostream>

using namespace std;

int main()
{
   // declare variables
   int subject1, subject2, subject3;
   int total;
   double average;

   // take input for marks of 3 subjects
   cout << "Enter Marks of 3 Subjects: ";
   cin >> subject1 >> subject2 >> subject3;
  
   // calculate total marks
   total = subject1 + subject2 + subject3;

   // calculate average mark
   average = total/3;
  
   // display result
   cout << "Total Mark = " << total << endl;
   cout << "Average Mark = " << average << endl;

   return 0;
}
