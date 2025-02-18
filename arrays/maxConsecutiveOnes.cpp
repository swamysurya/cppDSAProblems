#include<iostream>
using namespace std;

/**
 * Finds the maximum number of consecutive 1's in the given array.
 *
 * The approach is to maintain a sliding window and keep track of the maximum
 * number of consecutive 1's seen so far. When a 0 is encountered, it is skipped and
 * the window is moved to the right. When a sequence of 1's is encountered, it is
 * extended as long as possible and its length is compared with the maximum
 * seen so far.
 *
 * @param arr The input array of binary integers.
 * @param n The number of elements in the input array.
 * @return The maximum number of consecutive 1's in the array.
 */
int maxConsecutiveOnes(int arr[], int n){
    int i = 0, j = 0;
    int current_max;
    int prev_max = 0;
    // sliding window approach 
    // i and j are pointers to arr
    
    while (j < n){
        // if you found 0, skip it and move the window to right
        if(arr[i] == 0){
            i++;
            j++;
        }
        // if you found 1, extend the window as long as possible
        else{
            // j+1 < n is used to avoid array out of bounds
            while (arr[j+1] == 1 && j+1 < n){
                j++;
            }
            // calculate the length of the current sequence of 1's
            current_max = (j-i)+1;
            // compare the length with the maximum seen so far
            if (prev_max < current_max){
                prev_max = current_max;
            }
            // move the window to right
            i = j;
            i++;j++;
        }
    }
    return prev_max;
}

// Time complexity = O(n)
// Space complexity = O(1)


// brute force approach
int maxConsecutiveOnesBruteForce(int arr[], int n){
    int max = 0;
    int curr = 0;
    for (int i = 0; i < n; i++){ // Time complexity = O(n)
        if (arr[i] == 0){
            curr = 0;
        }else{
            curr++;
            if (curr > max){
                max = curr;
            }
        }
    }
    return max;
}
// Time complexity = O(n)
// Space complexity = O(1)

int main(){
    const int n = 10;
    int arr[n] = {1,1,0,1,1,1,1,0,1,1};
    // cout << "Maximum consecutive ones: " << maxConsecutiveOnes(arr,n) << endl;
    cout << "Maximum consecutive ones: " << maxConsecutiveOnesBruteForce(arr,n) << endl;
}