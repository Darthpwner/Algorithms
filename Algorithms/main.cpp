//
//  main.cpp
//  Algorithms
//
//  Created by Matthew Allen Lin on 11/16/15.
//  Copyright © 2015 Matthew Allen Lin Software. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <iostream>

#include "Combinations.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string x = "ABCD";
    Combinations c;
    
    c.combinations(x, 4);
    
    return 0;
}
