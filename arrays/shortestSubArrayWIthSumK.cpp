#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

// brute force solution
int shortestSubarrayWithSumKbruteForce(int arr[], int n, int k){
    int maxLen = INT_MAX;
    // take each element as the starting point
    // and find the shortest subarray with sum k

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if (sum == k){
                maxLen = min(maxLen, j - i + 1);
            }
        }
    }

    return maxLen;
}   

// Time complexity = O(n^2)
// Space complexity = O(n)


/**
 * Finds the length of the shortet subarray with sum k in the given array.
 *
 * @param arr The input array of integers.
 * @param n The number of elements in the input array.
 * @param k The sum of the subarray to be found.
 * @return The length of the shortest subarray with sum k.
 */

int shortestSubarrayWithSumK(int arr[], int n, int k){
    int sum = 0, minLen = 999999;
    unordered_map<int, int> preFixSum;
    // store the prefix sum and its index
    // [ 0,  1,  2,  3] // indexes
    // [-1, -2, -3, -4] => { -1: 0, -3: 1, -7: 2, -10: 3}
    //   |   |   |   | 
    //  -1  -3  -7  -10    // prefix sum

    for (int i = 0; i < n; i++){
        sum += arr[i];
        if (sum == k){
            minLen = i + 1;
        }
        // if sum - k is present in the map
        // why sum - k ?
        // if sum - k is present in the map then it means that the subarray from preFixSum[sum - k] to i with sum k has been formed
        if (preFixSum.find(sum - k) != preFixSum.end()){
            minLen = min(minLen, i - preFixSum[sum - k]);
        }
        // if sum is not present in the map then it means that the subarray from preFixSum[sum] to i with sum k has not been formed
        // so we need to store the index of the current sum in the map
        if (preFixSum.find(sum) == preFixSum.end()){
            preFixSum[sum] = i;
        }
    }
    return minLen;
}

// Time complexity = O(n * log n)
// Space complexity = O(n)

int main(){
    int n = 4, k = -5;
    int arr[n] =  {-1, -2, -3, -4};
    cout << shortestSubarrayWithSumK(arr, n, k) << endl;
    cout << shortestSubarrayWithSumKbruteForce(arr, n, k) << endl;
    return 0;
}