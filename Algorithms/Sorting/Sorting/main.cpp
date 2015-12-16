//
//  main.cpp
//  Sorting
//
//  Created by Matthew Allen Lin on 12/16/15.
//  Copyright © 2015 Matthew Allen Lin Software. All rights reserved.
//

#include <iostream>
using namespace std;

int runs = 0;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

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

int* modifiedBubbleSort(int arr[], int size) {
    return arr;
}

int* selectionSort(int arr[], int size) {
    return arr;
}

int* insertionSort(int arr[], int size) {
    return arr;
}

int* heapSort(int arr[], int size) {
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
    
    
    return 0;
}

