#include <iostream>
#include <vector>
using namespace std;

/**
 * Moves all the zeros in the given array to the end of the array in order.
 * The relative order of the non-zero elements is preserved.
 *
 * @param arr The input array of integers.
 * @param n The number of elements in the input array.
 */
void movingZerosToEnd(int arr[], int n){
    vector<int> nonZeroElements;
    for(int i = 0; i < n; i++){ //Time complexity = O(n)
        if (arr[i] != 0){
            nonZeroElements.push_back(arr[i]);
        }
    }
    for(int i = 0; i < nonZeroElements.size(); i++){ //Time complexity = O(n)
        arr[i] = nonZeroElements[i];
    }
    for(int i = nonZeroElements.size(); i < n; i++){ //Time complexity = O(n)
        arr[i] = 0;
    }
}

// Time complexity = O(n) + O(n) + O(n) = O(n) (iterating through n elements)
// Space complexity = O(1) (no extra space is used)



/**
 * Moves all the zeros in the given array to the end of the array in order.
 * The relative order of the non-zero elements is preserved using an optimal approach.
 *
 * This function efficiently rearranges the array in-place, minimizing the number of swaps.
 *
 * @param arr The input array of integers.
 * @param n The number of elements in the input array.
 */

void movingZerosToEnd2optimal(int arr[], int n){
    int i = 0;
    for(int j = 1; j < n; j++){ //Time complexity = O(n)
        if (arr[j] != 0){
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

// Algorithm:
// 1. Initialize two pointers: i and j.
// 2. Iterate through the array from index 1 to n-1.
// 3. If the j-th element is non-zero, swap it with the i-th element and increment i.
// 4. The i-th element is the first zero element encountered, and the j-th element is the first non-zero element after that.
// 5. Continue the loop until j reaches the end of the array.
// 6. The array is rearranged such that all zeros are moved to the end while preserving the relative order of the non-zero elements.

// Time complexity = O(n) (iterating through n elements) = O(n)
// Space complexity = O(1) (no extra space is used)

/**
 * Moves all the zeros in the given array to the beginning of the array in order.
 * The relative order of the non-zero elements is preserved using an optimal approach.
 *
 * This function efficiently rearranges the array in-place, minimizing the number of swaps.
 *
 * @param arr The input array of integers.
 * @param n The number of elements in the input array.
 */
void movingZerosToStartWithOrder(int arr[], int n){
    // starting from the end of the array i and j are set to n-1
    // if jth element is not zero, swap it with ith element and decrement i
    // continue the loop until j reaches the start of the array
    int i = n-1;
    for(int j = n-1; j >= 0; j--){
        if (arr[j] != 0){
            swap(arr[i], arr[j]);
            i--;
        }
    }
}

// Algorithm:
// 1. Initialize two pointers: i and j.
// 2. Iterate through the array from index n-1 to 0.
// 3. If the j-th element is non-zero, swap it with the i-th element and decrement i.
// 4. The i-th element is the last zero element encountered, and the j-th element is the last non-zero element before that.
// 5. Continue the loop until j reaches the start of the array.

// Time complexity = O(n) (iterating through n elements) = O(n)
// Space complexity = O(1) (no extra space is used)


int main(){
    int n = 12;
    int arr[] = {0,1,0,2,0,4,0,0,0,8,9,0};
    movingZerosToStartWithOrder(arr,n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}