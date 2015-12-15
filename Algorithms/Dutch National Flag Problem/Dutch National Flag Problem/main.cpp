//
//  main.cpp
//  Dutch National Flag Problem
//
//  Created by Matthew Allen Lin on 12/15/15.
//  Copyright © 2015 Matthew Allen Lin Software. All rights reserved.
//

#include <iostream>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Utility function to print array arr[] */
void printArray(int arr[], int arr_size)
{
    printf("array after segregation ");
    int i;
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}

//Time Complexity: O(n) - Middle is your index that you run through. In the worst case, arr[middle] is never > key, so you run through all n elements
void dutchNationalFlag(int arr[], int size, int key) {
    int low = 0;
    int middle = 0;
    int high = size - 1;
    
    while(middle <= high) {
        if(arr[middle] < key) {
            swap(&arr[low], &arr[middle]);
            low++;
            middle++;
        } else if(arr[middle] > key) {
            swap(&arr[middle], &arr[high]);
            high--;
        } else {    //arr[middle] == key
            middle++;
        }
    }
    
    printf("Low: %d\n", low);
    printf("Medium: %d\n", middle); //Number of iterations through the array
    printf("High: %d\n", high);
    printArray(arr, size);
}

int main(int argc, const char * argv[]) {
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
//    int i;
    
    int arr1[] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
    int arr1_size = sizeof(arr1)/sizeof(arr1[0]);
    
    dutchNationalFlag(arr, arr_size, 1);
    dutchNationalFlag(arr1, arr1_size, 1);
    
    //printArray(arr, arr_size);
    //printArray(arr1, arr1_size);
    
    
    return 0;
}
