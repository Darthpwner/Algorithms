//
//  main.cpp
//  Dynamic Programming
//
//  Created by Matthew Allen Lin on 12/16/15.
//  Copyright © 2015 Matthew Allen Lin Software. All rights reserved.
//

#include <iostream>
using namespace std;

#define N 1000

int runs = 0;

/*Utils*/
int findFactorial(int n) {
    if (n == 0)
        return 1;
    else
        return (n * findFactorial(n-1));
}
/**/

//9.1
int nthStaircase(int n) {
    //My solution: Do not use for cases where you can take many steps i.e. 4 or more because it's hardcoded
//    if(n <= 0) {
//        return 0;
//    } else if(n == 1) {
//        return 1;   //1
//    } else if(n == 2) {
//        return 2;   //1 + 1; 2
//    } else if(n == 3) {
//        return 4;   //1 + 1 + 1; 1 + 2; 2 + 1; 3
//    }
    
    runs++;
    
    //Official solution
    if(n < 0) {
        return 0;
    } else if(n == 0) {
        return 1;
    }
    
    return nthStaircase(n - 1) + nthStaircase(n - 2) + nthStaircase(n - 3);
}

int nthStaircaseWithDP(int n, int map[]) {
    runs++;
    
    //Official solution
    if(n < 0) {
        return 0;
    } else if(n == 0) {
        return 1;   //1
    } else if(map[n] > -1) {
        return map[n];
    } else {
        map[n] = nthStaircaseWithDP(n - 1, map) +
                 nthStaircaseWithDP(n - 2, map) +
                 nthStaircaseWithDP(n - 3, map);
        return map[n];
    }
}

void print(int n) {
    cout << n << endl;
    cout << "Runs: " << runs << endl << endl;
    runs = 0;
}

//9.2
int robotOnGridProblem(int grid[][N], int x, int y) {
    runs++;
    if(x > N || y > N) {
        return -1;
    }
    
    return (findFactorial(x + y)) / (findFactorial(x) * findFactorial(y));
}

int main(int argc, const char * argv[]) {
    //9.1: Upper bound is ~33
    int map[N];
    fill_n(map, N, -1);

    print(nthStaircaseWithDP(33, map));
    print(nthStaircase(33));
    
    //9.2
    int grid[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            grid[i][j] = 0;
        }
    }

    print(robotOnGridProblem(grid, 1, 1));
    return 0;
}
