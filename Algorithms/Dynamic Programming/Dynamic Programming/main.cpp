//
//  main.cpp
//  Dynamic Programming
//
//  Created by Matthew Allen Lin on 12/16/15.
//  Copyright © 2015 Matthew Allen Lin Software. All rights reserved.
//

#include <iostream>
using namespace std;

//9.1
int nthStaircase(int n) {
    if(n <= 0) {
        return 0;
    } else if(n == 1) {
        return 1;   //1
    } else if(n == 2) {
        return 2;   //1 + 1; 2
    } else if(n == 3) {
        return 4;   //1 + 1 + 1; 1 + 2; 2 + 1; 3
    }
    
    return nthStaircase(n - 1) + nthStaircase(n - 2) + nthStaircase(n - 3);
}

int nthStaircaseWithDP(int n, int map[]) {
    if(n <= 0) {
        return 0;
    } else if(n == 1) {
        return 1;   //1
    } else if(map[n] > -1) {
        return map[n];
    } else {
        //map[n] = nth
    }
    
    return -9;
}

void printNthStaircase(int n) {
    cout << nthStaircase(n) << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printNthStaircase(4);
    return 0;
}
