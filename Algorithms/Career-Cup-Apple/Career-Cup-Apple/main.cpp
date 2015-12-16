//
//  main.cpp
//  Career-Cup-Apple
//
//  Created by Matthew Allen Lin on 12/16/15.
//  Copyright © 2015 Matthew Allen Lin Software. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

/*Utils*/
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
/**/

//Returns the sum without using a + b
int sum(int a, int b) {
    if(abs(a) < abs(b)) {
        swap(a, b);
    }
    
    while(b > 0) {
        a++;
        b--;
    } while (b < 0) {
        a--;
        b++;
    }
    
    return a;
}

//Returns the square without using * or ^
int square(int num) {
//    int absNum = abs(num);
    int absNum = abs(num);
    int square = 0, odd = 1;
    while(absNum > 0) {
        square += odd;
        odd += 2;
        absNum--;
    }
    
    return square;
}

void print(int n) {
    cout << n << endl << endl;
}

int main(int argc, const char * argv[]) {
    print(sum(-10000, -1));
    
    print(sum(8, 6));
    print(sum(-8, -6));
    print(sum(-8, 6));
    print(sum(-6, 8));
    
    print(square(-5));
    
    return 0;
}
