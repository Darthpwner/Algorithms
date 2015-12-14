/****************************************************************
 Write a program to print all the permutations of a given string.
 
 Example:
 
 Given String: ABC
 Output: ABC, ACB, BAC, BCA, CAB, CBA
 
 ****************************************************************/

//C++
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int time_complexity = 0;

/*Swap*/
void swap(char* x, char* y) {
    char temp;
    temp = *x; 
    *x = *y;    //Note: I am having a BAD_ACCESS bug over here if I use a character pointer
    *y = temp;
}

void permutation(char* input, int start, unsigned long end) {
    time_complexity++;
    
    if(start == end) {    //Base case
        cout << input << endl;
    } else {    //
        for(int i = start; i <= end; i++) {  //Problem is starting this at 0
            time_complexity++;
            swap(input + start, input + i);
            permutation(input, start + 1, end);    //Simplifying step
            swap(input + start, input + i);    //Used to backtrack and get remaining permutations
        }
    }
}

int main() {
    char input[] = "ABC";   //Cannot use a char pointer because I get a bad access error
    unsigned long n = strlen(input);    /*Converting to an int loses precision, so I just made it an unsigned long
                                         for very small string sizes like "ABC", it won't matter (it just takes up more bytes)*/
    permutation(input, 0, n - 1);
    cout << "The number of runs is " << time_complexity << endl;    //10 <- 3 * 3
    return 0;
}

//Prints ABC, ACB, BAC, BCA, CBA, CAB
/*Notes: Needs input + start as first argument because it will double count the original permutations
 For testing in main, you need to use a character array because I am getting a bad access error if I use a character pointer
 */

/*Algorithm: 1. Internally swaps the last two characters in a 3 character string via backtracking
            2. Then it swaps the first character and performs the same swapping mechanism
            Time Complexity is O(n*n!): The factor of n means you have to run through the entire string at least once, and you multiply by n! because n! is the amount of times you have to swap to account for all possible permutations
*/