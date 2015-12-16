//
//  Heap.cpp
//  Sorting
//
//  Created by Matthew Allen Lin on 12/16/15.
//  Copyright © 2015 Matthew Allen Lin Software. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Heap.h"
using namespace std;

#define N 1000

Heap::Heap() {
    
}

int Heap::getRootIndex() {
    return 0;
}

int Heap::leftChildLocator(int i) {
    if(i < m_count) {
        return (2 * i + 1);
    } else {
        return -1;
    }
}

int Heap::rightChildLocator(int i) {
    if(i < m_count) {
        return (2 * i + 2);
    } else {
        return -1;
    }
}

int Heap::parentLocator(int i) {
    return ((i - 1)/2);
}

void Heap::printVal(int i) {
    cout << m_heap[i] << endl;
}

void Heap::printHeap() {
    for(int i = 0; i < m_count; i++) {
        cout << m_heap[i] << " ";
    }
    cout << endl;
}

void Heap::addNode(int v) {
    m_heap[m_count] = v;
    m_count++;
}

void Heap::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/*Minheap********/
Minheap::Minheap() {
    for(int i = 0; i < N; i++) {
        m_heap[i] = numeric_limits<int>::max();
    }
}

void Minheap::addNode(int v) {
    m_heap[m_count] = v;
    
    int i = m_count;
    while(m_heap[i] < m_heap[parentLocator(i)]) {
        swap(m_heap[i], m_heap[parentLocator(i)]);
        i = parentLocator(i);
    }
    
    m_count++;
}

int Minheap::extractMin() {
    //Extract root
    int extract = m_heap[0];
    
    //Copy bottom-most right-most to root
    m_heap[0] = m_heap[m_count - 1];
    m_heap[m_count - 1] = -1;
    m_count--;
    
    //Compare with children
    int i = 0;
    
    bool compareLeft = m_heap[i] > m_heap[leftChildLocator(i)];
    bool compareRight =  m_heap[i] > m_heap[rightChildLocator(i)];
    
    int left = m_heap[leftChildLocator(i)];
    int right = m_heap[rightChildLocator(i)];
    
    while((compareLeft || compareRight)) {  //FIX THIS SHIT IN THE MORNING
        if(left < right) {
            swap(m_heap[i], m_heap[leftChildLocator(i)]);
            i = leftChildLocator(i);
        } else {    //right < left
            swap(m_heap[i], m_heap[rightChildLocator(i)]);
            i = rightChildLocator(i);
        }
        
        compareLeft = m_heap[i] > m_heap[leftChildLocator(i)];
        compareRight =  m_heap[i] > m_heap[rightChildLocator(i)];
        
        left = m_heap[leftChildLocator(i)];
        right = m_heap[rightChildLocator(i)];
    }
    
    return extract;
}
/****************/

/*Maxheap********/
Maxheap::Maxheap() {
    for(int i = 0; i < N; i++) {
        m_heap[i] = numeric_limits<int>::min();
    }
}

void Maxheap::addNode(int v) {
    m_heap[m_count] = v;
    
    int i = m_count;
    while(m_heap[i] > m_heap[parentLocator(i)]) {
        swap(m_heap[i], m_heap[parentLocator(i)]);
        i = parentLocator(i);
    }
    
    m_count++;
}

int Maxheap::extractMax() {
    //Extract root
    int extract = m_heap[0];
    
    //Copy bottom-most right-most to root
    m_heap[0] = m_heap[m_count - 1];
    m_heap[m_count - 1] = -1;
    m_count--;
    
    //Compare with children
    int i = 0;
    
    bool compareLeft = m_heap[i] < m_heap[leftChildLocator(i)];
    bool compareRight =  m_heap[i] < m_heap[rightChildLocator(i)];
    
    int left = m_heap[leftChildLocator(i)];
    int right = m_heap[rightChildLocator(i)];
    
    while(compareLeft || compareRight) {    //FIX THIS SHIT IN THE MORNING
        if(left > right) {
            swap(m_heap[i], m_heap[leftChildLocator(i)]);
            i = leftChildLocator(i);
        } else {    //right > left
            swap(m_heap[i], m_heap[rightChildLocator(i)]);
            i = rightChildLocator(i);
        }
        
        compareLeft = m_heap[i] < m_heap[leftChildLocator(i)];
        compareRight =  m_heap[i] < m_heap[rightChildLocator(i)];
        
        left = m_heap[leftChildLocator(i)];
        right = m_heap[rightChildLocator(i)];
    }
    
    return extract;
}
/****************/