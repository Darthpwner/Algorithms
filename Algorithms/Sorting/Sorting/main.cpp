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

int* mergeSort(int arr[], int size) {
    return arr;
}

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
    
    return 0;
}

