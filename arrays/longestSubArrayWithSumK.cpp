#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;


// brute force solution
/**
 * Finds the length of the longest subarray with sum k in the given array.
 *
 * The brute force solution has a time complexity of O(n^2) and a space complexity of O(1).
 * The optimal solution has a time complexity of O(n) and a space complexity of O(n).
 *
 * @param arr The input array of integers.
 * @param n The number of elements in the input array.
 * @param k The sum of the subarray to be found.
 * @return The length of the longest subarray with sum k.
 */
int longestSubarrayWithSumKBruteForce(int arr[], int n, int k){
    int maxLen = INT_MIN;
    // take each element as the starting point
    // and find the longest subarray with sum k

    for(int i = 0; i < n; i++){
        int sum = 0;
        // j keep of increment till end of the array
        // and check if the sum is equal to k
        // if the sum is equal to k then update the maxLen
        for(int j = i; j < n; j++){
            sum += arr[j];
            if (sum == k){
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

// time complexity = O(n^2)
// space complexity = O(1)

// two pointer solution

int longestSubarrayWithSumKTwoPointer(int arr[], int n, int k){
    int i = 0, j = 0;
    int sum = 0;
    int maxLen = 0;
    // i keep of increment till end of the array
    // and check if the sum is equal to k
    // if the sum is equal to k then update the maxLen
    // and decrement i
    while(j < n){
        // add the current element to the sum
        sum += arr[j];
        // if the sum is greater than k then decrement i
        // until the sum is less than k
        // and make sure i is less than j
        while(sum > k && i < j){
            sum -= arr[i];
            i++;
        }
        // if the sum is equal to k then update the maxLen
        // and increment i
        if (sum == k){
            maxLen = max(maxLen, j - i + 1);
            i++;
        }
        // increment j
        j++;
    }
    return maxLen;
}

// time complexity = O(n)
// space complexity = O(1)

// optimal solution
int longestSubarrayWithSumK(int arr[], int n, int k){
    int sum = 0, maxLen = 0;
    unordered_map<int, int> preFixSum;
    // store the prefix sum and its index means
    // [ 0,  1,  2,  3] // indexes
    // [-1, -2, -3, -4] => { -1: 0, -3: 1, -7: 2, -10: 3}
    //   |   |   |   | 
    //  -1  -3  -7  -10    // prefix sum
    for(int i = 0; i < n; i++){
        sum += arr[i];
        // if sum is equal to k then update the maxLen
        if (sum == k){
            maxLen = i + 1;
        }
        // if sum - k is present in the map then update the maxLen
        // why sum - k ?
        // if sum - k is present in the map then it means that the subarray from preFixSum[sum - k] to i with sum k has been formed
        if(preFixSum.find(sum - k) != preFixSum.end()){
            maxLen = max(maxLen, i - preFixSum[sum - k]);
        }

        // store the prefix sum and its index if it doesn't exist
        if (preFixSum.find(sum) == preFixSum.end()){
            preFixSum[sum] = i; 
        }
    }
    return maxLen;
}

// time complexity = O(n * log n)
// space complexity = O(n)

int main() {
    int n = 4, k = -5;
    int arr[n] =  {-1, -2, -3, -4};
    // cout << longestSubarrayWithSumK(arr, n, k) << endl;
    // cout << longestSubarrayWithSumKBruteForce(arr, n, k) << endl;
    int k2 = 5;
    int n2 = 5;
    int arr2[n] = {1,2,1,1,1};
    cout << longestSubarrayWithSumKTwoPointer(arr2, n2, k2) << endl;
    // cout << longestSubarrayWithSumKTwoPointer(arr, n, k) << endl;
    return 0;
}