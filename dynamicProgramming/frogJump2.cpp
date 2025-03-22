#include <iostream>
#include <vector>
#include <climits>
using namespace std;



// Recursive Approach (Exponential)
int minTotalSpend(vector<int> steps, int k, int i){
    if (i == 0) return 0;
    int minEnergy = INT_MAX;
    for (int j = 1; j <= k; j++){
        if (i-j >= 0){
            int energy = abs(steps[i] - steps[i-j]) + minTotalSpend(steps, k, i-j);
            minEnergy = min(minEnergy, energy);
        }
    }
    return minEnergy;
}

// Memoization (Top-Down DP)
int minTotalSpendMemoisationHelper(const vector<int>& steps, int k, int i, vector<int>& dp){
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];

    int minEnergy = INT_MAX;
    for (int j = 1; j <= k; j++){
        if (i - j >= 0){
            int energy = abs(steps[i] - steps[i - j]) + minTotalSpendMemoisationHelper(steps, k, i - j, dp);
            minEnergy = min(minEnergy, energy);
        }
    }
    return dp[i] = minEnergy;
}

int minTotalSpendMemoisation(const vector<int>& steps, int k, int n){
    vector<int> dp(n, -1);
    return minTotalSpendMemoisationHelper(steps, k, n - 1, dp);
}
// n levels each level k options means k function calls
// Time complexity = O(n * k)
// Space complexity = O(n) + O(n) = O(n) (dp array + recursive call stack)

// Tabulation (Bottom-Up DP)
int minTotalSpendTabulation(const vector<int>& steps, int k, int n){
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++){
        for (int j = 1; j <= k; j++){
            if (i - j >= 0){
                int energy = abs(steps[i] - steps[i - j]) + dp[i - j];
                dp[i] = min(dp[i], energy);
            }
        }
    }
    return dp[n - 1];
}

// Space-Optimized Tabulation (O(K) Space)
int minTotalSpendTabulationSpaceOptimised(const vector<int>& steps, int k, int n){
    if (n == 1) return 0;

    vector<int> prev(k, INT_MAX);
    prev[0] = 0;

    for (int i = 1; i < n; i++) {
        int curr = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0){
                int energy = abs(steps[i] - steps[i - j]) + prev[(i - j) % k];
                curr = min(curr, energy);
            }
        }
        prev[i % k] = curr;
    }
    return prev[(n - 1) % k];
}

// Main function to test all approaches
int main(){
    int n = 4;
    int k = 3; 
    vector<int> steps = {80, 140, 120, 100};

    cout << "Recursive: " << minTotalSpend(steps, k, n-1) << endl;
    cout << "Memoization: " << minTotalSpendMemoisation(steps, k, n) << endl;
    cout << "Tabulation: " << minTotalSpendTabulation(steps, k, n) << endl;
    cout << "Space Optimized Tabulation: " << minTotalSpendTabulationSpaceOptimised(steps, k, n) << endl;
    
    return 0;
}
