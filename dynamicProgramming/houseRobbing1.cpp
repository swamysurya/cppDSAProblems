#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Recursive approach (Brute force)
     * Time Complexity: O(2^n) -> Exponential due to overlapping subproblems
     * Space Complexity: O(n) -> Recursion stack
     */
    int maxAmountRecursive(int arr[], int n, int i) {
        // Base cases
        if (i == 0) return arr[i];
        if (i == 1) return max(arr[i], arr[i - 1]);
        
        // Either pick current house and move to i-2 OR skip to i-1
        int pick = arr[i] + maxAmountRecursive(arr, n, i - 2);
        int notPick = maxAmountRecursive(arr, n, i - 1);
        
        return max(pick, notPick);
    }

    /**
     * Memoization approach (Top-down DP)
     * Time Complexity: O(n) -> Each state is computed once
     * Space Complexity: O(n) -> DP array + Recursion stack
     */
    int maxAmountMemoization(int arr[], int n, int i, vector<int> &dp) {
        // Base cases
        if (i == 0) return arr[i];
        if (i == 1) return max(arr[i], arr[i - 1]);
        
        // Return precomputed result
        if (dp[i] != -1) return dp[i];
        
        // Compute result and store it in dp array
        int pick = arr[i] + maxAmountMemoization(arr, n, i - 2, dp);
        int notPick = maxAmountMemoization(arr, n, i - 1, dp);
        
        return dp[i] = max(pick, notPick);
    }

    /**
     * Tabulation approach (Bottom-up DP)
     * Time Complexity: O(n) -> Iterative computation
     * Space Complexity: O(n) -> DP array
     */
    int maxAmountTabulation(int arr[], int n) {
        if (n == 1) return arr[0];
        
        vector<int> dp(n, 0);
        
        // Base cases
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        
        // Fill the DP table iteratively
        for (int i = 2; i < n; i++) {
            int pick = arr[i] + dp[i - 2];
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        
        return dp[n - 1];
    }

    /**
     * Space-Optimized Tabulation (Bottom-up DP with O(1) space)
     * Time Complexity: O(n) -> Iterative computation
     * Space Complexity: O(1) -> Only two variables are used
     */
    int maxAmountTabulationOptimized(int arr[], int n) {
        if (n == 1) return arr[0];
        
        int prev2 = arr[0]; // dp[i-2]
        int prev1 = max(arr[0], arr[1]); // dp[i-1]
        
        for (int i = 2; i < n; i++) {
            int pick = arr[i] + prev2;
            int notPick = prev1;
            int curr = max(pick, notPick);
            
            prev2 = prev1; // Update previous values
            prev1 = curr;
        }
        
        return prev1;
    }

    /**
     * Function to compute the maximum stolen amount
     * Calls all implementations for testing
     */
    void testAllApproaches(int n, int arr[]) {
        vector<int> dp(n, -1);
        cout << "Recursive Approach: " << maxAmountRecursive(arr, n, n-1) << endl;
        cout << "Memoization Approach: " << maxAmountMemoization(arr, n, n-1, dp) << endl;
        cout << "Tabulation Approach: " << maxAmountTabulation(arr, n) << endl;
        cout << "Optimized Tabulation Approach: " << maxAmountTabulationOptimized(arr, n) << endl;
    }
};

// Driver code
int main() {
    Solution sol;
    int arr[] = {30,40,10,50};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    sol.testAllApproaches(n, arr);
    
    return 0;
}
