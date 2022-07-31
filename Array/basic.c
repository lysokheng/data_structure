//
//  main.c
//  Data Structer
//
//  Created by LySokHeng Huot on 12/20/21.
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

/*-------------------------------- deleteAllElements Function ------------------------------------*/
void deleteAllElements(int arr[MAX_SIZE], int qty){
    // Initialize variable.
    int i;
    
    printf("\n\n------------------- Result -----------------\n\n");
    
    // Delete all elements process.
    for(i=0; i<qty; i++)
    {
        arr[i]=0;
    }
    
    // Print array after all deletion.
    printf("\nElements of array after all delete are :\t");
    for(i=0; i<qty; i++)
    {
        printf("%d\t", arr[i]);
    }
}

/*-------------------------------- search Function ------------------------------------*/
void search(int arr[MAX_SIZE], int qty){
    // Initialize variable.
    int toSearch, j = 0, i, count = 0, found = 0;
        
    // Ask user what number want to search.
    printf("\nSearch :\t");
    scanf("%d", &toSearch);
    
    printf("\n\n------------------- Result -----------------\n\n");
    
    // Find Non-duplicate number of array element.
    for(i=0; i<qty; i++){
        if (toSearch == arr[i]) {
            if (toSearch / arr[i] == 1) {
                j++;
                if (j >= 2) {
                    found = 1;
                }
            }
        }
        else{
            printf("Invalid number! This number can not be found in our array\n");
            break;
        }
    }
    
    // If found print below.
    if (found == 1) {
        printf("\nNon-Duplicate are Found !\n");
    }
    else{
        // If not found print below.
        printf("\nNon-Duplicate are not Found !\n");
    }
    
    // Find duplicate number of array element.
    for(i=0; i<qty; i++){
        if (toSearch == arr[i]) {
            if (toSearch / arr[i] == 1) {
                count++;
            }
        }
    }
    
    // Print, how many duplicate number have?
    printf("\n\nDuplicate are found %d times", count);
}

/*-------------------------------- Main Function ------------------------------------*/
int main(){
    // Initialize variable of array and other
    int arr[MAX_SIZE], qty, i, choice;
    char ch;
    
    // Repeat if user agree permission below
REPEAT:
    
    printf("\n\n");
    printf("---------------------------------------------\n");
    printf("*                                           *\n");
    printf("*                                           *\n");
    printf("*                20/12/2021                 *\n");
    printf("*              Array Operation              *\n");
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
        printf("Input your data into array element %d :\t", i+1);
        scanf("%d", &arr[i]);
    }
    
    // Menu
    printf("\n\n------------------- Menu -----------------\n\n");
    printf("1. Show element of array\n");
    printf("2. Insert an element to array to the position\n");
    printf("3. Delete element\n");
    printf("4. Delete all elements with value\n");
    printf("5. Search element(s) in array by value\n");
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
            
            // Goto function displayArray
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
            
            // Goto function displayArray
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
            
            // Goto function displayArray
            deleteAllElements(arr, qty);
            
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
        case 5:
            
            // Goto function displayArray
            search(arr, qty);
            
            // Ask user, Did they want repeat or not?
        again5:
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
                goto again5;
            }
            break;
    }
    return 0;
}
