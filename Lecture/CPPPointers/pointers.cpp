#include <iostream>

using namespace std;

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

    return 0;
}