/*******************************************************************************
 * Name        : inversioncounter.cpp
 * Author      : Jerry Cheng
 * Version     : 1.0
 * Date        : 10/21/2019
 * Description : Counts the number of inversions in an array.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

// Function prototype.
static long mergesort(int array[], int scratch[], int low, int high);

/**
 * Counts the number of inversions in an array in theta(n^2) time.
 */
long count_inversions_slow(int array[], int length) {
    long inversions = 0;
    for(int i = 0; i < length - 1; i++){
        for(int j = i + 1; j < length; j++){
            if(array[i] > array[j])
                inversions++;
        }
    }
    return inversions;
}

/**
 * Counts the number of inversions in an array in theta(n lg n) time.
 */
long count_inversions_fast(int array[], int length) {
    int *scratch = new int[length];
    long inversions = mergesort(array, scratch, 0, length - 1);
    delete[] scratch;
    return inversions;
}

static long mergesort(int array[], int scratch[], int low, int high) {
    long inversions = 0;
    if(low < high){
        int mid = low + (high - low)/2;
        int temp_low = low;
        int temp_high = mid + 1;
        
        inversions += mergesort(array, scratch, low, mid);
        inversions += mergesort(array, scratch, mid + 1, high);

        for(int i = low; i <= high; i++){
            if(temp_low <= mid && (temp_high > high || array[temp_low] <= array[temp_high])){
                scratch[i] = array[temp_low];
                temp_low++;
            }
            else{
                scratch[i] = array[temp_high];
                inversions += mid - temp_low + 1;
                temp_high++;
            }
        }

        for(int j = low; j <= high; j++){
            array[j] = scratch[j];
        }
    }
    return inversions;
}

int main(int argc, char *argv[]) {

    if(argc > 2){
        cerr << "Usage: ./inversioncounter [slow]" << endl;
        return 1;
    }
    else if((argc == 2) && (strcmp(argv[1], "slow") != 0)){
        cerr << "Error: Unrecognized option '" << argv[1] << "'." << endl;
        return 1;
    }

    cout << "Enter sequence of integers, each followed by a space: " << flush;

    istringstream iss;
    int value, index = 0;
    vector<int> values;
    string str;
    str.reserve(11);
    char c;
    while (true) {
        c = getchar();
        const bool eoln = c == '\r' || c == '\n';
        if (isspace(c) || eoln) {
            if (str.length() > 0) {
                iss.str(str);
                if (iss >> value) {
                    values.push_back(value);
                } else {
                    cerr << "Error: Non-integer value '" << str
                         << "' received at index " << index << "." << endl;
                    return 1;
                }
                iss.clear();
                ++index;
            }
            if (eoln) {
                break;
            }
            str.clear();
        } else {
            str += c;
        }
    }

    if(values.size() > 0){
        if(argc == 2){
            cout << "Number of inversions: " << count_inversions_slow(&values[0], values.size()) << endl;
            return 0;
        }
        else{
            cout << "Number of inversions: " << count_inversions_fast(&values[0], values.size()) << endl;
            return 0;
        }
    }
    else{
        cerr << "Error: Sequence of integers not received." << endl;
        return 1;
    }
}
