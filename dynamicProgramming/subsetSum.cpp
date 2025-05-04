#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool subsetSumRecursion(int i, int total, int arr[]){
    if (total == 0) return true;
    if (i == 0) {
        if (arr[i] == total) return true;
        else return false;
    }
    
    bool not_pick, pick;
    not_pick = subsetSumRecursion(i-1, total, arr);
    if(arr[i] > total) pick = false;
    else pick = subsetSumRecursion(i-1, total - arr[i], arr);
    
    return pick || not_pick;
}

// Time Complexity: O(2^n),  since the algorithm explores all possible subsets of the input array, resulting in an exponential increase in the number of recursive calls as the input size (n) grows.
// Space Complexity: O(n), due to the recursive call stack, which can go as deep as the number of elements in the array (n) before reaching the base cases.



bool subsetSumMemo(int i, int total, int arr[], vector<vector<int>>& dp){
    if (total == 0) return true;
    if (i == 0) {
        if (arr[i] == total) return true;
        else return false;
    }
    if (dp[i][total] != -1) return dp[i][total];
    bool pick, not_pick;
    not_pick = subsetSumMemo(i-1, total, arr, dp);
    if(arr[i] > total) pick = false;
    else pick = subsetSumMemo(i-1, total - arr[i], arr, dp);
    dp[i][total] =  pick || not_pick;
    return dp[i][total];
}

// Time Complexity: O(n*k), since the algorithm explores all possible combinations of elements and sums, and the DP table has dimensions n x k, where n is the number of elements and k is the target sum.
// Space Complexity: O(n*k) + O(n), due to the 2D dp array with dimensions n and k, and O(n) for the recursive call stack.



bool subsetSumTabulation(int n,int k, int arr[]){
    // initialise the vector row is (i) and column is (total) 
    vector<vector<int>> dp(n, vector<int>(k+1));
    // i range from 0->n-1 
    // total range from 0->k
    // base case where total = 0 return total 
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    for(int total=1; total <= k; total++){
        if (total == arr[0]) dp[0][total] = 1;
        else dp[0][total] = 0;
    }
    bool pick, not_pick;
    for(int i = 1; i < n; i++){
        for(int total = 1; total <= k; total++){
            not_pick = dp[i-1][total];
            if(arr[i] > total) pick = 0;
            else  pick = dp[i-1][total - arr[i]];
            dp[i][total] = pick || not_pick;
        }
    }
    return dp[n-1][k];
}

// Time Complexity: O(n * k), since it involves nested loops iterating over n elements and up to k possible sums, performing constant-time operations inside the loops.
// Space Complexity: O(n * k),  due to the 2D dp array with dimensions n and k.



bool subsetSumTabulationOptimised(int n, int k, int arr[]){
    vector<int> curr(k+1);
    vector<int> prev(k+1);
    prev[0] = 1;
    curr[0] = 1;
    
    for(int total = 1; total <= k; total++) {
        if(total == arr[0]) prev[total] = 1;
        else prev[total] = 0;
    }
    bool pick, not_pick;
    for(int i=1; i < n; i++){
        for(int total = 1; total <= k; total++){
            not_pick = prev[total];
            if(arr[i] > total) pick = 0;
            else pick = prev[total-arr[i]];
            curr[total] = pick || not_pick;
        }
        prev = curr;
    }
    return prev[k];
}

// Time Complexity: O(n * k), due to the nested loops iterating over n elements and k possible sums, and the operations within those loops are constant time.
// Space Complexity: O(k), since it uses two arrays of size k+1, prev and cur, to store states for achieving various sums, and no additional data structures are used.



int main(){
    int n = 4;
    int arr[] = {4,5,2,2};
    int k = 7;
    
    cout << "using Recursion: " << (subsetSumRecursion(n-1, k, arr) ? "true" : "false" )<< endl;
    vector<vector<int>> dp(n, vector<int>(k+1,-1));
    cout << "using Memoisation: " << (subsetSumMemo(n-1, k, arr, dp) ? "true" : "false" )<< endl;
    cout << "using Tabulation: " << (subsetSumTabulation(n, k, arr) ? "true" : "false" )<< endl;
    cout << "using Tabulation Optimisation: " << (subsetSumTabulationOptimised(n, k, arr) ? "true" : "false" )<< endl;
}