//
//  main.c
//  Data Structer 1
//
//  Created by LySokHeng Huot on 12/27/21.
//

#include <stdio.h>

#define MAX_SIZE 100

/*-------------------------------- displayArray Function ------------------------------------*/
void displayArray(int arr[MAX_SIZE], int qty){
    // Initialize variable.
    int i = 0;
    
    printf("\n\n------------------- Result -----------------\n\n");

    // Display array after input from user.
    printf("Displaying:\t\t");
    for (i=0; i<qty; i++) {
        printf("%d\t", arr[i]);
    }
}

/*-------------------------------- insert Function ------------------------------------*/
void insert(int arr[MAX_SIZE], int qty){
    // Initialize variable.
    int i, num, pos;
    
    // Input new array element.
    printf("\nEnter element to insert : ");
    scanf("%d", &num);
    
    // Choose position want to input.
    printf("\nEnter the element position : ");
    scanf("%d", &pos);
    
    printf("\n\n------------------- Result -----------------\n\n");

    // If position of element is not valid
    if(pos > qty+1 || pos <= 0)
    {
        printf("Invalid position! Please enter position between 1 to %d", qty+1);
    }
    else
    {
        // Make room for new array element by shifting to right
        for(i=qty; i>=pos; i--)
        {
            arr[i] = arr[i-1];
        }
        
        // Insert new element at given position and increment size
        arr[pos-1] = num;
        qty++;
        
        // Print array after insert operation
        printf("Array elements after insertion :\t");
        for(i=0; i<qty; i++)
        {
            printf("%d\t", arr[i]);
        }
    }
}

/*-------------------------------- delete Function ------------------------------------*/
void delete(int arr[MAX_SIZE], int qty){
    // Initialize variable.
    int i, pos;
    
    // Input element position to delete
    printf("\nEnter the element position to delete : ");
    scanf("%d", &pos);
    
    printf("\n\n------------------- Result -----------------\n\n");

    // Invalid delete position
    if(pos < 0 || pos > qty)
    {
        printf("Invalid position! Please enter position between 1 to %d", qty);
    }
    else
    {
        // Copy next element value to current element
        for(i=pos-1; i<qty-1; i++)
        {
            arr[i] = arr[i+1];
        }

        // Decrement array size by 1
        qty--;

        // Print array after deletion
        printf("\nElements of array after delete are :\t");
        for(i=0; i<qty; i++)
        {
            printf("%d\t", arr[i]);
        }
    }
}

/*-------------------------------- binarySearch Function ------------------------------------*/
int binarySearch(int arr[], int qty) {
    // Initialize variable.
    int mid, low = 0, high = qty-1, toSearch;
    
    // Input number to find.
    printf("Enter your number:\t");
    scanf("%d", &toSearch);
    
    // Repeat until the pointers low and high meet each other
    while (low <= high) {
        mid = (high + low) / 2;

        if (arr[mid] == toSearch){
            return mid;
        }
        else if (low > high){
            return toSearch;
        }
        else if (arr[mid] < toSearch){
            if (arr[mid] < toSearch) {
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
    }

    // If user input invalid.
    return -1;
}
/*-------------------------------- Main Function ------------------------------------*/
int main(){
    // Initialize variable of array and other
    int arr[MAX_SIZE], qty, i, choice, result;
    char ch;
    
    // Repeat if user agree permission below
REPEAT:
    
    printf("\n\n");
    printf("---------------------------------------------\n");
    printf("*                                           *\n");
    printf("*                                           *\n");
    printf("*                20/12/2021                 *\n");
    printf("*               Ordered Array               *\n");
    printf("*          Credit: Huot Lysokheng           *\n");
    printf("*                                           *\n");
    printf("*                                           *\n");
    printf("---------------------------------------------\n");
    
    // Create size to store array element.
    printf("\n\nEnter your element to display : ");
    scanf(" %d", &qty);
    printf("\n");
    
    // Input data by user.
    for(i=0; i<qty; i++){
        printf("Input your data into array in index %d :\t", i);
        scanf("%d", &arr[i]);
    }
    
    // Menu
    printf("\n\n------------------- Menu -----------------\n\n");
    printf("1. Show element of array\n");
    printf("2. Insert an element to array to the position\n");
    printf("3. Delete element\n");
    printf("4. Search element(s) in array by value (Binary Search)\n");
    printf("\n------------------- Menu -----------------\n\n");

    // Choose your choice
    printf("Your order is number :\t");
    scanf("%d", &choice);
    
    // The processing of menu.
    switch(choice){
        case 1:
            
            // Goto function displayArray
            displayArray(arr, qty);
            
            // Ask user, Did they want repeat or not?
        again1:
            printf ("\n\nDo you want to repeat the operation(Y/N): ");
            fflush(stdin);
            scanf ("%c", &ch);

            // If say yes press y or Y.
            if(ch == 'y' || ch == 'Y'){
                goto REPEAT;
            }
            // If say no press n or N.
            else if(ch == 'n' || ch == 'N'){
                return 0;
            }
            else{
                // If user input invalid letter of above.
                printf("\nPlease enter Yes or NO.\n");
                goto again1;
            }
            break;
        case 2:
            
            // Goto function insert
            insert(arr, qty);
            
            // Ask user, Did they want repeat or not?
        again2:
            printf ("\n\nDo you want to repeat the operation(Y/N): ");
            fflush(stdin);
            scanf ("%c", &ch);

            // If say yes press y or Y.
            if(ch == 'y' || ch == 'Y'){
                goto REPEAT;
            }
            // If say no press n or N.
            else if(ch == 'n' || ch == 'N'){
                return 0;
            }
            else{
                // If user input invalid letter of above.
                printf("\nPlease enter Yes or NO.\n");
                goto again2;
            }
            break;
        case 3:
            
            // Goto function delete
            delete(arr, qty);
            
            // Ask user, Did they want repeat or not?
        again3:
            printf ("\n\nDo you want to repeat the operation(Y/N): ");
            fflush(stdin);
            scanf ("%c", &ch);

            // If say yes press y or Y.
            if(ch == 'y' || ch == 'Y'){
                goto REPEAT;
            }
            // If say no press n or N.
            else if(ch == 'n' || ch == 'N'){
                return 0;
            }
            else{
                // If user input invalid letter of above.
                printf("\nPlease enter Yes or NO.\n");
                goto again3;
            }
            break;
        case 4:
            
            result = binarySearch(arr, qty);
            
            // Display result "binarySearch"
            if (result == -1){
              printf("Not found");
            }
            else{
              printf("Element is found at index %d", result);
          }
            
            // Ask user, Did they want repeat or not?
        again4:
            printf ("\n\nDo you want to repeat the operation(Y/N): ");
            fflush(stdin);
            scanf ("%c", &ch);

            // If say yes press y or Y.
            if(ch == 'y' || ch == 'Y'){
                goto REPEAT;
            }
            // If say no press n or N.
            else if(ch == 'n' || ch == 'N'){
                return 0;
            }
            else{
                // If user input invalid letter of above.
                printf("\nPlease enter Yes or NO.\n");
                goto again4;
            }
            break;
    }
    return 0;
}
