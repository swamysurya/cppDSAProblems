#include <iostream>
#include <vector>

using namespace std;


// time complexity: O(2^n) space complexity: O(n)
int maxAmountRecursiveOldFunction(vector<int> arr, int i){
    if (i == 0) return arr[0];
    if (i == 1) return max(arr[0], arr[1]);
    
    int pick = arr[i] + maxAmountRecursiveOldFunction(arr, i-2);
    int notPick = maxAmountRecursiveOldFunction(arr,i-1);
    
    int res = max(pick, notPick);
    return res;
}

// time complexity: O(n) space complexity: O(n)
int maxAmountMemoOldFunction(vector<int> arr, int n, int i, vector<int> &dp){
    if (i == 0) return arr[0];
    if (i == 1) return max(arr[0], arr[1]);
    if (dp[i] != -1) return dp[i];
    int pick = arr[i] + maxAmountMemoOldFunction(arr,n, i-2,dp);
    int notPick = maxAmountMemoOldFunction(arr,n,i-1,dp);
    
    dp[i] = max(pick, notPick);
    return dp[i];
}

// time complexity: O(n) space complexity: O(n)
int maxAmountTabulationOldFunction(vector<int> arr, int n){
    if (n == 1) return arr[0];
    
    vector<int> dp(n,0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for(int i = 2; i < n; i++){
        int pick = arr[i] + dp[i-2];
        int notPick = dp[i-1];
        dp[i] = max(pick, notPick);
    }
    return dp[n-1];
}

// time complexity: O(n) space complexity: O(1)
int maxAmountTabulationOptimisedOldFunction(vector<int> arr, int n){
    if (n == 1) return arr[0];
    
    int prev2 = arr[0];
    int prev1 = max(arr[0], arr[1]);
    for(int i = 2; i < n; i++){
        int pick = arr[i] + prev2;
        int notPick = prev1;
        int curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}



int main(){
    int arr[] = {50,20,10,70};
    int n = sizeof(arr) / sizeof(arr[0]);

    // for circular array
    vector<int> arr1 (arr, arr + (n-1));
    vector<int> arr2 (arr + 1, arr + n);

    int res1 = maxAmountRecursiveOldFunction(arr1, n-1);
    int res2 = maxAmountRecursiveOldFunction(arr2, n-1);
    int res = max(res1, res2);
    cout << "Recursive Approach: " << res << endl;

    vector<int> dp1(n-1, -1);
    vector<int> dp2(n-1, -1);

    int res3 = maxAmountMemoOldFunction(arr1, n-1, n-2, dp1);
    int res4 = maxAmountMemoOldFunction(arr2, n-1, n-2, dp2);
    int res5 = max(res3, res4);
    cout << "Memoization Approach: " << res5 << endl;

    int res6 = maxAmountTabulationOldFunction(arr1, n-1);
    int res7 = maxAmountTabulationOldFunction(arr2, n-1);

    int res8 = max(res6, res7);
    cout << "Tabulation Approach: " << res8 << endl;

    int res9 = maxAmountTabulationOptimisedOldFunction(arr1, n-1);
    int res10 = maxAmountTabulationOptimisedOldFunction(arr2, n-1);

    int res11 = max(res9, res10);
    cout << "Optimized Tabulation Approach: " << res11 << endl; 

    return 0;
}