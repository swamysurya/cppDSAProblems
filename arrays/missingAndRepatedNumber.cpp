#include<iostream>
#include<vector>
using namespace std;

/**
 * Finds the repeating and missing numbers in an array of size n.
 *
 * @param arr The input array of size n.
 * @param n The size of the input array.
 * @return A vector containing the repeating and missing numbers.
 */

// Brute Force Approach

vector<int> missingAndRepeatingNumberBruteForce(vector<int> arr, int n) {
    int repeated = -1 , missing = -1;
    vector<int> checked(n+1, false); // [false] * n+1 
    
    for (int i = 0; i < n; i++){
        // each number in array consider as index of checked array and updated it
        if (checked[arr[i]]){
            // if already checked means that is repeated number
            repeated = arr[i];
        }else{
            // if its not checked updated with true
            checked[arr[i]] = true;
        }
    }
    // if any number is not checked means that is missing number
    for(int i = 1; i < n; i++){
        if (! checked[i]){
            missing = i;
            break;
        }
    }
    return {repeated, missing};
}

// time complexity = O(n)
// space complexity = O(n)

// optimized approach
vector<int> missingAndRepeatingNumberOptimized(vector<int> arr, int n) {
    int missing = -1;
    int repeating = -1;

    //store the frequency of each element in the array
    vector<int> freq(n+1, 0);
    for (int k: arr) {
        freq[k]++;
    }
    // find the repeating and missing number
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 2) repeating = i;
        if (freq[i] == 0) missing = i;
        
    }
    return {repeating, missing};
}



int main(){
    int n = 10;
    vector<int> arr = {3,1,5,2,2,4,7,9,8,10};
    vector<int> result = missingAndRepeatingNumberBruteForce(arr,n);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " "; 
    }
    cout << endl;
}