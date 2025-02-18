#include <iostream>
#include <algorithm>
using namespace std;


/**
 * Rotate the given array by k times to the left.
 * The elements of the array are rotated k times towards the left.
 * The relative order of the elements is preserved.
 *
 * @param arr The input array of integers.
 * @param n The number of elements in the input array.
 * @param k The number of positions to shift the array to the left.
 */
void rotateArrayKtimes(int arr[], int n, int k){
    // if k is greater than n, reduce it to the smallest equivalent rotation
    k = k % n;
    // create a temp array to store the first k elements
    int* temp = new int[k];
    for(int i = 0; i < k; i++){ //Time complexity = O(k)
        temp[i] = arr[i];
    }
    // shift the remaining elements to the left by k positions
    for(int i = k; i < n; i++){ //Time complexity = O(n)
        arr[i-k] = arr[i];
    }
    // copy the temp array elements to the end of the array
    for(int i = 0; i < k; i++){ //Time complexity = O(k)
        arr[n-k+i] = temp[i];
    }
    delete[] temp;
}

// Time complexity = O(k) + O(n) + O(k) = O(n) (iterating through n elements)
// Space complexity = O(k) (using an additional array of size k)
// algorithm:
// 1. Create a temporary array of size k to store the first k elements of the input array.
// 2. Shift the remaining elements of the input array to the left by k positions.
// 3. Copy the elements from the temporary array to the end of the input array.


/**
 * Rotate the given array by k times to the left using an optimal approach.
 * The elements of the array are rotated k times towards the left.
 * This function uses the reversal algorithm to achieve the rotation in-place.
 *
 * @param arr The input array of integers.
 * @param n The number of elements in the input array.
 * @param k The number of positions to shift the array to the left.
 */

void rotateArrayKtimesOptimal(int arr[], int n, int k){
    k = k % n;
    reverse(arr, arr+k); //Time complexity = O(k)
    reverse(arr+k, arr+n); //Time complexity = O(n-k)
    reverse(arr, arr+n); //Time complexity = O(n)
}

// Time complexity = O(k) + O(n-k) + O(n) = O(n) (iterating through n elements)
// Space complexity = O(1) (no extra space is used)
// algorithm: example: [1,2,3,4,5,6,7,8,9] k = 3
// 1. Reverse the first k elements of the input array. [3,2,1,4,5,6,7,8,9]
// 2. reverse the remaining elementts from k to n. [3,2,1,9,8,7,6,5,4]
// 3. reverse the whole array. [4,5,6,7,8,9,1,2,3]
// 4. The array is rotated k times towards the left using the reversal algorithm.



int main(){
    int n = 9;
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int k = 12;
    
    rotateArrayKtimesOptimal(arr,n,k);
    cout << "Array after rotating " << k << " times: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}






































































































