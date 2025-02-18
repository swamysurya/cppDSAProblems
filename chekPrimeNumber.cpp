#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i < num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}


