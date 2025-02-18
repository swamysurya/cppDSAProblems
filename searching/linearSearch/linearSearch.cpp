#include <iostream>
using namespace std;

/**
 * Performs a linear search to find the target element in the array.
 *
 * @param arr The input array of integers.
 * @param n The number of elements in the input array.
 * @param target The element to search for in the array.
 * @return The index of the target element if found, -1 otherwise.
 */

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    const int n = 10;
    int arr[n] = {1,2,3,4,5,12,32,1,23,12};
    int target = 12;
    cout << linearSearch(arr,n,target) << endl;
}