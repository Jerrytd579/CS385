#include <iostream>

using namespace std;

void display_array(int array[], const int length){
    cout << "[";
    if(length > 0) {
        cout << array[0];
    }

    for(int i = 1; i < length; i++){
        // if(i != 0) {
        //     cout <<", ";
        // }
        cout << ", " << array[i];
    }
    cout << "]" << endl;
}

void display_array_ptr(int array[], const int length) {
    cout << "[";
    for(int *ptr = array, *end = array + length; ptr < end; ++ptr){
        if (ptr != array) {
            cout <<", ";
        }
        cout << *ptr;
    }
    cout << "]";
}

void pass_by_value(int x) {
    x = 10;
}

void pass_by_pointer(int *x) {
    *x = 10;
}

void pass_by_reference(int &x) {
    x = 10;
}

int main() {

    int x = 5, y = 6, *z = &x;
    // * is used to declare a pointer, as well as dereferences a pointer
    // & is the address of operator

    cout << z << endl;
    // Points to the address of x
    cout << *z << endl;
    // The star gets rid of the indirection and gives us what z points to, which is 5
    cout << "x = " << x << ", y = " << y << endl;
    
    
    *z = 7;
    // This changes the value of x
    cout << "x = " << x << ", y = " << y << endl;
    
    z = &y;
    *z = 7;
    // The value of changes from this cause we first change the pointer to where y is
    cout << "x = " << x << ", y = " << y << endl;

    // cout << ++z << endl;
    // // This modifies the memory address, bad idea. We're not sure what z points to now.
    // cout<< *z << endl; // We may or may not know where this points. Note that later doing --z will return us.

    // z += 30000;     // Terrible idea: z points outside the address space of this process
    // *z = 30;
    // cout<< *z << endl;  // Asigning a new value to the place z points will cause a segmentation fault.

    // // gdp ./pointers will help you debug stuff

    int *values = new int[y]; // Whenever you allocate anything with new you free up your memory when done
    for(int i = 0; i < y; i++) {
        values[i] = i;
    }
    // valgrind allows us to memory debug
    // valgrind will be used to test our code in the future
    //delete [] values;

    display_array(values, y);
    display_array_ptr(values, y);
    delete [] values;

    x = 5;
    pass_by_value(x);
    cout <<""<< endl;
    cout << "x = " << x << endl;

    x = 5;
    pass_by_pointer(&x); // C style way
    cout << "x = " << x << endl;

    x = 5;
    pass_by_reference(x);
    cout << "x = " << x << endl;

    return 0;
}