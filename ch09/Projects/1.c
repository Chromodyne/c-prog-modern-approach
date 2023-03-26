#include<stdio.h>

//Max number of integers.
#define N 50

//Prototypes
void selection_sort(int a[], int n);

int main(void) {

    //user_input stores the user's integers input. Length stores the actual number of integers input by user.
    int user_input[N], length = 0;
    char c;

    printf("Enter up to %d integers: ", N);

    
    for (int i = 0; i < N; i++) {
        
        scanf(" %d", &user_input[i]);

        //Increment to determine how many integers were actually input into the array.
        length++;

        //Check if the user presses the enter key. Break out of loop if so.
        if ((c = getchar()) == '\n') {
            break;
        }
        
    }

    selection_sort(user_input, length);

    printf("Sorted: ");

    //Print out the sorted array.
    for(int i = 0; i < length; i++) {
        printf(" %d", user_input[i]);
    }

    printf("\n");

    return 0;

}

void selection_sort(int a[], int n) {
 
    int store, largest = 0;
    
    if (n == 0) {
        printf("Returned.");
        return;
    }
    
    //Searches the array for the largest integer and then stores it in the 'largest' variable.
    for(int i = 0; i < n; i++) {
        
        if (a[i] > a[largest]) {
            largest = i;
        }

    }

    //Setup a storage location that won't get overwritten during recursion
    store = a[largest];

    a[largest] = a[n - 1];

    a[n - 1] = store;

    //A return statement with a ternary operator is not feasible here due to the fact that
    //there's nothing other than returning we want to do if a condition was true and return
    //is a statement which cannot be used in ternary operations.
    selection_sort(a, (n - 1));

}