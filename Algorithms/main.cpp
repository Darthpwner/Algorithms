//
//  main.cpp
//  Algorithms
//
//  Created by Matthew Allen Lin on 11/16/15.
//  Copyright © 2015 Matthew Allen Lin Software. All rights reserved.
//

#include <iostream>

#include <iostream>
#include <string.h>
#include <iostream>
using namespace std;

void combinations(string x, int size) {
    string str = "";
    int base = 0;
    for(int i = 0; i < size; i++) {
        for(int j = base; j < size; j++) {
            cout << str << x[j] << endl;
        }
        str += x[i];
        base++;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string x = "ABCD";
    
    combinations(x, 4);
    
    return 0;
}
