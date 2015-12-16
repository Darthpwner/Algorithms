//
//  Heap.h
//  Sorting
//
//  Created by Matthew Allen Lin on 12/16/15.
//  Copyright © 2015 Matthew Allen Lin Software. All rights reserved.
//

#ifndef Heap_h
#define Heap_h

#define N 1000

class Heap {
public:
    Heap();
    int getRootIndex();
    int leftChildLocator(int i);
    int rightChildLocator(int i);
    int parentLocator(int i);
    void printVal(int i);
    void printHeap();
    void addNode(int v);
    void swap(int& a, int& b);
protected:
    int m_count = 0;
    int m_heap[N];
};

class Minheap: public Heap {
public:
    Minheap();
    virtual void addNode(int v);
    int extractMin();
};

class Maxheap: public Heap {
public:
    Maxheap();
    virtual void addNode(int v);
    int extractMax();
};

#endif /* Heap_h */
