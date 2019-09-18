/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Jerry Cheng
 * Date        : 9/18/2019
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <cctype>

using namespace std;

bool is_all_lowercase(const string &s) {
    // Returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.
    for(unsigned int i = 0; i < s.length(); i++){
        if(isupper(s[i]) || !isalpha(s[i]))
            return false;
    }

    return true;
}

bool all_unique_letters(const string &s) {
    // You may use only a single int for storage and work with bitwise
    // and bitshifting operators.
    // No credit will be given for other solutions.
    if(s.length() == 0){
        return true;
    }
    unsigned int storage = 0;
    for(unsigned int i = 0; i < s.length(); i++){
        int ascii_value = s[i] - 97;
        if((storage & (1 << ascii_value)) > 0)
            return false;
        storage |= (1 << ascii_value);
    }
    return true;
}

int main(int argc, char * const argv[]) {
    // Calls other functions to produce correct output.
    if(argc != 2){
        cerr << "Usage: " << argv[0] << " <string>" << endl;
        return 1;
    }
    if(!is_all_lowercase(argv[1])){
        cerr << "Error: String must contain only lowercase letters." << endl;
        return 1;
    }
    if(!all_unique_letters(argv[1])){
        cerr << "Duplicate letters found." << endl;
        return 1;
    }
    if(all_unique_letters(argv[1])){
        cout << "All letters are unique." << endl;
    }
}
