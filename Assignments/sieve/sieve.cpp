/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Jerry Cheng
 * Date        : 9/9/2019
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
// Test with valgrind and large inputs
using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit);

    ~PrimesSieve() {
        delete [] is_prime_;
    }

    int num_primes() const {
        return num_primes_;
    }

    void display_primes() const;

private:
    // Instance variables
    bool * const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;

    // Method declarations
    int count_num_primes() const;
    void sieve();
    static int num_digits(int num);
};

PrimesSieve::PrimesSieve(int limit) :
        is_prime_{new bool[limit + 1]}, limit_{limit} {
    sieve();
}

void PrimesSieve::display_primes() const {
    // TODO: write code to display the primes in the format specified in the
    // requirements document.
    cout << "\nNumber of primes found: " << num_primes() << endl;
    cout << "Primes up to " << limit_ << ":" << endl;

    // If all the primes cannot fit on one line, wrap around to the next line.
    // This will find the width of the maximum prime value and how many primes
    // can fit on one row.

    const int max_prime_width = num_digits(max_prime_),
        primes_per_row = 80/(max_prime_width + 1);

    // If the number of primes will fit onto one row
    if(num_primes_ <= primes_per_row){
        for(int i = 0; i <= limit_; i++) {
            if(is_prime_[i]) {
                if(i == max_prime_) {
                    cout << i;
                }
                else{
                    cout << i << " ";
                }
            }
        }
    }
    // If the number of primes will not fit onto one row
    else{
        for (int i = 0, count = 1; i <= limit_; i++){
            if (is_prime_[i] == true){
                if(count != primes_per_row){
                    if (i != max_prime_){
                        cout << setw(max_prime_width) << i << " ";
                        count++;
                    }
                    else{
                        cout << setw(max_prime_width) << i;
                        count++;
                    }
                }
                else{
                    cout << setw(max_prime_width) << i << endl;
                    count = 1;
                }
            }
        }
    }
}

int PrimesSieve::count_num_primes() const {
    int count = num_primes_;

    for(int i = 2; i <= limit_; i++) {
        if(is_prime_[i]) {
            count++;
        }
    }
    return count;
}

void PrimesSieve::sieve() {
    // Initializes an array of bool values, indexed by integers 2 to the limit, initially all set to true
    for(int i = 2; i <= limit_; i++) {
        is_prime_[i] = true;
    }

    // Sieve algorithm
    for(int i = 2; i <= sqrt(limit_); i++) {
        if(is_prime_[i]) {
            for(int j = pow(i, 2); j <= limit_; j = j + i){
                is_prime_[j] = false;
            }
        }
    }

    num_primes_ = count_num_primes();

    for(int k = limit_; k >= 2; k--){
        if(is_prime_[k]){
            max_prime_ = k;
            break;
        }
    }
}

int PrimesSieve::num_digits(int num) {
    // Hint: No strings are needed. Keep dividing by 10.
    int digits = 0;
    while(num != 0) {
        num /= 10;
        digits++;
    }
    return digits;
}

int main() {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;

    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }

    // TODO: write code that uses your class to produce the desired output.
    PrimesSieve ps(limit);
    ps.display_primes();

    return 0;
}
