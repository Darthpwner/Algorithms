//
//  main.cpp
//  Sorting
//
//  Created by Matthew Allen Lin on 12/16/15.
//  Copyright © 2015 Matthew Allen Lin Software. All rights reserved.
//

#include <iostream>
#include "Heap.h"
using namespace std;

int runs = 0;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//Brute force method of comparing each
int* bubbleSort(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - 1; j++) {
            if(arr[j] > arr[j+1]) {
                runs++;
                swap(arr[j], arr[j+1]);
            }
        }
    }
    
    return arr;
}

//BUGGY DO LATER!
int* modifiedBubbleSort(int arr[], int size) {
    bool flag = false;
    
    //Same as above but uses flag
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - 1; j++) {
            runs++;
            if(flag) {
                return arr;
            }
            
            if(arr[j] > arr[j+1]) {
                runs++;
                swap(arr[j], arr[j+1]);
            }
            
            flag = true;
        }
    }
    
    return arr;
}

int* selectionSort(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        int indexOfMin = i;
        for(int j = i; j < size; j++) {
            runs++;
            if(arr[indexOfMin] > arr[j]) {
                indexOfMin = j;
            }
        }
        
        swap(arr[i], arr[indexOfMin]);
    }
    
    return arr;
}

int* insertionSort(int arr[], int size) {
    return arr;
}

int* heapSort(int arr[], int size) {
    Maxheap maxheap;
    
    for(int i = 0; i < size; i++) {
        runs++;
        maxheap.addNode(arr[i]);
    }
    
    for(int j = size - 1; j >= 0; j--) {
        runs++;
        arr[j] = maxheap.extractMax();
    }
    
    return arr;
}

//
/* Helper function for finding the max of two numbers */
int max(int x, int y)
{
    if(x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

/* left is the index of the leftmost element of the subarray; right is one
 * past the index of the rightmost element */
void merge_helper(int *input, int left, int right, int *scratch)
{
    /* base case: one element */
    if(right == left + 1)
    {
        return;
    }
    else
    {
        int i = 0;
        int length = right - left;
        int midpoint_distance = length/2;
        /* l and r are to the positions in the left and right subarrays */
        int l = left, r = left + midpoint_distance;
        
        /* sort each subarray */
        merge_helper(input, left, left + midpoint_distance, scratch);
        merge_helper(input, left + midpoint_distance, right, scratch);
        
        /* merge the arrays together using scratch for temporary storage */
        for(i = 0; i < length; i++)
        {
            /* Check to see if any elements remain in the left array; if so,
             * we check if there are any elements left in the right array; if
             * so, we compare them.  Otherwise, we know that the merge must
             * use take the element from the left array */
            if(l < left + midpoint_distance &&
               (r == right || max(input[l], input[r]) == input[l]))
            {
                scratch[i] = input[l];
                l++;
            }
            else
            {
                scratch[i] = input[r];
                r++;
            }
        }
        /* Copy the sorted subarray back to the input */
        for(i = left; i < right; i++)
        {
            input[i] = scratch[i - left];
        }
    }
}

/* mergesort returns true on success.  Note that in C++, you could also
 * replace malloc with new and if memory allocation fails, an exception will
 * be thrown.  If we don't allocate a scratch array here, what happens?
 *
 * Elements are sorted in reverse order -- greatest to least */

int mergesort(int *input, int size)
{
    int *scratch = (int *)malloc(size * sizeof(int));
    if(scratch != NULL)
    {
        merge_helper(input, 0, size, scratch);
        free(scratch);
        return 1;
    }
    else
    {
        return 0;
    }
}
//

//int* mergeSort(int arr[], int size) {
//    return arr;
//}

int* quickSort(int arr[], int size) {
    return arr;
}

void print(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "Runs: " << runs;
    runs = 0;
    
    cout << endl << endl;
}

int main(int argc, const char * argv[]) {
    int arr[5] = {1, 9, 2, 5, 20};
    print(bubbleSort(arr, 5), 5);
    
    int arr1[5] = {5, 4, 3, 2, 1};
    print(bubbleSort(arr1, 5), 5);
    
    int arr2[5] = {1, 9, 2, 5, 20};
    print(selectionSort(arr2, 5), 5);
    
    int arr3[5] = {5, 4, 3, 2, 1};
    print(selectionSort(arr3, 5), 5);
    
    int arr4[5] = {7, 3, 9, 1, 5};
    print(heapSort(arr4, 5), 5);
    
    int arr5[6] = {9, 3, 5, 1, 32, 5};
    mergesort(arr5, 6);
    
    print(arr5, 6);
    
    return 0;
}

