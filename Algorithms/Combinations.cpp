//
//  Combinations.cpp
//  Algorithms
//
//  Created by Matthew Allen Lin on 11/16/15.
//  Copyright © 2015 Matthew Allen Lin Software. All rights reserved.
//

#include "Combinations.hpp"
#include <iostream>
#include <string.h>
using namespace std;

void Combinations::combinations(string x, int size) {
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

