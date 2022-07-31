//
//  main.c
//  ite_hw4_huot_lysokheng
//
//  Created by LySokHeng Huot on 1/19/22.
//

#include <stdio.h> // call header file stdio.h to use print()
#include <stdbool.h> // call header file stdbool.h to use boolean variable

#define MAX_SIZE 100 // define size of array is 100


void swap(int *xp, int *yp) // swap() function with xp and yp as parameter
{ // start swap() function
    int temp = *xp; // declare temp in integer and assign value of pointer to temp
    *xp = *yp; // assign value pointer of yp to pointer of xp
    *yp = temp; // assign temp to pointer of yp
} // end swap() function

void Ascending(int arr[MAX_SIZE], int qty) // Ascending() function with arr and n as parameter
{ // start Ascending() function
    int i, j; // decalre variable i and j in integer
    bool swapped; // decalare bool as swapped
    for (i = 0; i < qty-1; i++) // use for-loop to find count i
    { // start i circle
        swapped = false; // swapped = false to keep compare until the swapped below is not eqaul ture anymore
        for (j = 0; j < qty-i-1; j++) // use j in for-loop to compare between previous and next value
        { // start j circle
            if (arr[j] > arr[j+1]) // if arr at previous is bigger than the next
            { // start compare between previous and next value circle
                swap(&arr[j], &arr[j+1]); // So, the swap() function is perform
                swapped = true; // then the swap is true when compare
            } // end compare between previous and next value circle
        } // end i circle

     if (swapped == false) // if no two elements were swapped by inner loop, then break
         break; // break statement
    } // end i circle
} // end Ascending() function

void Descending(int arr[MAX_SIZE], int qty) // Descending() function with arr and n as parameter
{ // start Descending() function
   int i, j; // decalre variable i and j in integer
   bool swapped; // decalare bool as swapped
   for (i = 0; i < qty-1; i++) // use for-loop to find count i
   { // start i circle
    swapped = false; // swapped = false to keep compare until the swapped below is not eqaul ture anymore
    for (j = 0; j < qty-i-1; j++) // use j in for-loop to compare between previous and next value
    { // start j circle
        if (arr[j] < arr[j+1]) // if arr at previous is smaller than the next
        { // start compare between previous and next value circle
            swap(&arr[j], &arr[j+1]); // So, the swap() function is perform
            swapped = true; // then the swap is true when compare
        } // end compare between previous and next value circle
     } // end i circle

     if (swapped == false) // if no two elements were swapped by inner loop, then break
        break; // break statement
   } // end i circle
} // end Ascending() function

void printArray(int arr[MAX_SIZE], int size) // function to print array with arr and size as parameter
{ // start printArray() function
    int i; // declare variable i in integer
    for (i=0; i < size; i++) // use for-loop to display all index in array
        printf("%d ", arr[i]); // display array
    printf("\n"); // new line
} // end printArray() function

int main() // main() function
{ // start main() function
    int arr[MAX_SIZE], qty, i = 0, choice; // declare variable arr as array, qty, i, choice
AGAIN: // if user want to go back at the beginning of program
    printf("\n\nEnter your element : "); // Create size to store array element.
    scanf("%d", &qty); // input by user
    printf("\n"); // new line
    
    for(i=0; i<qty; i++) // use for-loop to input data in seveal index of array
    { // start i circle
        printf("Input your data into index number %d :\t", i+1); // tell user how many index that they input
        scanf("%d", &arr[i]); // input data by user in several index
    } // end i cirlce
    
    do { //
        printf("\n\n------------------- Menu -----------------\n\n"); // Menu decoration
        printf("1. Ascending\n"); // 1st option to perform Ascending
        printf("2. Descending\n"); // 2nd option to perform Descending
        printf("3. Back\n"); // 3rd option to get back at the beginning program
        printf("4. Exit\n"); // 4th option to exit this program
        printf("\n------------------------------------------\n\n"); // End Menu decoration
        
        printf("Your order is number :\t"); // Choose your choice
        scanf("%d", &choice); // input choice by user
        
        switch (choice) // use switch statement to process menu
        { // start switch statement
            case 1: // 1st option to perform Ascending
                Ascending(arr, qty); // goto Ascending() function to perform
                printf("Ascending array: \n"); // display array after ascending
                printArray(arr, qty); // goto printArray() function to perform to display array
                break; // break statement
                    
            case 2: // 2nd option to perform Ascending
                Descending(arr, qty); // goto Descending() function to perform
                printf("Ascending array: \n"); // display array after ascending
                printArray(arr, qty); // goto printArray() function to perform to display array
                break; // break statement
                
            case 3: // 3rd option to get back at the beginning program
                goto AGAIN; // goto AGAIN at above
                break; // break statement
                
            case 4: // 4th option to exit this program before execute
                printf("Exiting...!\n"); // display Exiting...! to the user on console
                break; // break statement
                
            default: // defualt option is user input out of number
                printf("Input invalid!\n"); // display to the user
                break; // break statement
        } // end switch statement
    } while (choice != 4); // if user input number 4 is go skip to execute the program
    return 0; // execute the program
}
