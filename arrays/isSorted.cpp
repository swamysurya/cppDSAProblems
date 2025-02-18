#include<iostream>
using namespace std;

/**
 * Returns 1 if the array is sorted in ascending order, 0 if not.
 * @param arr the array to check
 * @param n the number of elements in the array
 */

int isSorted(int arr[], int n){
    // iterate through the array and check if the current element is greater than the next element
    for (int i = 0; i < n-1; i++){
        // if the current element is greater than the next element, the array is not sorted
        if (arr[i] > arr[i+1]) return 0;
    }
    return 1;
}

// Time Complexity = O(n)
// Space Complexity = O(1)




int main(){
    int n = 9;
    int arr[] = {1,2,3,4,5,7,6,8,9};
    cout << isSorted(arr,n) << endl;

}