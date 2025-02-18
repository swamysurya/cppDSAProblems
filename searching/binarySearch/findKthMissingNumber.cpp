#include <iostream>
using namespace std;


/**
 * Finds the k-th missing positive integer in a sorted array of unique positive integers.
 *
 * The function uses binary search to efficiently determine the k-th missing number.
 * 
 * @param arr A sorted array of unique positive integers.
 * @param n The number of elements in the array.
 * @param k The order of the missing positive integer to find.
 * @return The k-th missing positive integer.
 */

int findKthMissingNumber(int arr[], int n, int k) {
    int low = 0;
    int high = n-1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - mid - 1;
        if (missing >= k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low + k;
}

// Algorithm:
// 1. Initialize low to 0 and high to n.
// 2. Perform binary search:
//    a. Calculate mid as (low + high) / 2.
//    b. If missing numbers up to mid are greater than or equal to k, move high to mid.
//    c. Otherwise, move low to mid + 1.
// 3. Return low + k as the k-th missing number.

// Note: the index in arry tells the number of missing numbers before that index by arr[i] - i - 1

/*
Why does left + k give the correct missing number?

1. left is the number of elements that exist in arr before the k-th missing number.
2. If there were no missing numbers, the k-th missing number would have been at position k in the complete sequence.
3. However, because arr already contains left numbers before the k-th missing number, the correct position is:
left+𝑘

the left will tell all real numbers before the kth missing number
the k tells the no of missing numbers
if you add both you will get the kth missing number
beacuse the missing termns and present terms if you combine you get sequence of all natural numbers where index itself is the number;
*/

/*
Why Does This Work?
Because in a perfect natural number sequence, each index is the number itself:

Index:    1  2  3  4  5  6  7  8  9  10  11  12 ...
Numbers:  1  2  3  4  5  6  7  8  9  10  11  12 ...
When we remove numbers, we create gaps. But the combined count of missing + present numbers always reconstructs the natural sequence.
*/

int main(){
    int n = 5;
    int arr[] = {2,3,4,7,11};
    //[1,5,6,8,9,10,12,13,14,15]
    int k = 5;
    cout << findKthMissingNumber(arr,n,k) << endl;
}