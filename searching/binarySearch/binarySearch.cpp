#include <iostream>

using namespace std;


int binarySearchRecursive(int arr[], int target, int low, int high){
    if (low > high){
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] > target) return binarySearchRecursive(arr, target, mid+1, high);
    else return binarySearchRecursive(arr, target, low, mid-1);
}

// time complexity = O(log n)
// space complexity = O(1)


int binarySearch(int arr[], int n, int target){
    int low = 0;
    int high = n-1;

    while (low <= high){
        // int mid = (low + high)/2 ;
        // to avoid overflow we can modify the calculation of mid
        int mid = low + (high - low) / 2; // this for contrtol overflow
        if (arr[mid] == target){
            return mid;
        }else if (arr[mid] > target){
            low = mid + 1;
            
        }else{
            high = mid - 1;
        }
    }
    return -1;
}

// time complexity = O(log n)
// space complexity = O(1)

int main(){
    int n = 7;
    int arr[n] = {4,2,1,9,1,3,8};
    int targetIndex = binarySearchRecursive(arr, 3, 0, n-1);
    // int targetIndex2 = binarySearch(arr,n,3);
    cout << targetIndex << endl;
}



/*
1. what is overflow in binary search ?
ans: If low and high are both large values, their sum (low + high)
may exceed the maximum limit of the integer type, causing an integer overflow.
In 32-bit signed integers (maximum value = 2^31 - 1),

int low = 2,000,000,000; 
int high = 2,100,000,000;
int mid = (low + high) / 2; // Potential overflow

Here, low + high = 4,100,000,000, which exceeds the maximum signed 32-bit integer limit (2,147,483,647), causing overflow and resulting in an incorrect mid value.

Instead of (low + high) / 2, use:

int mid = low + (high - low) / 2;
Since high - low is always positive and smaller than high + low, adding low after dividing by 2 keeps the result within the valid range.

This is a safer and recommended approach in all programming languages that deal with fixed-width integers.


​2. how to calculate time complexcity ?
ans: 
1. each step reduces the search space by half
 n -> n/2 -> n/4 -> n/8 -> ... -> 1
2. after k steps the search space will be 1
        n/(2^k) - 1
3. solving k
    n = 2^k
    log n = k
    k = log n

*/