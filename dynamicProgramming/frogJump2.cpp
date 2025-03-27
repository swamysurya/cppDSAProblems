#include <iostream>
#include <vector>
#include <climits>
using namespace std;



// Recursive Approach (Exponential)
int minTotalSpend(vector<int> steps, int k, int i){
    // base case
    // if frog jump from 0th step to 0th step energy spend = 0
    if (i == 0) return 0;
    // bacause of k (1 step or 2 steps or 3 steps and so on till k steps)
    // we need to check all possible options
    // 
    int minEnergy = INT_MAX;
    for (int j = 1; j <= k; j++){
        // The condition if (i - j >= 0) ensures that the frog does not attempt to jump beyond the first step (out of bounds).
        if (i-j >= 0){
            // if frog jump j steps current energy spend = |steps[i] - steps[i-j]| + minTotalSpend(steps, k, i-j) (next step)
            int energy = abs(steps[i] - steps[i-j]) + minTotalSpend(steps, k, i-j);
            // store minimum enegy on each step
            minEnergy = min(minEnergy, energy);
        }
    }
    // return minimum energy
    return minEnergy;
}

// Time complexity = O(k^n)
// Space complexity = O(n) because of recursive call stack

// Memoization (Top-Down DP)
int minTotalSpendMemoisationHelper(const vector<int>& steps, int k, int i, vector<int>& dp){
    // Base case: If the frog is at the first step (0th index), no energy is required
    if (i == 0) return 0;

    // If the result for this step has already been computed, return the cached value
    if (dp[i] != -1) return dp[i];

    int minEnergy = INT_MAX; // Initialize minEnergy to a large value to find the minimum
    for (int j = 1; j <= k; j++){ // Try all possible jumps up to 'k' steps
        if (i - j >= 0){ // Ensure we do not go out of bounds (negative index)
            // Calculate energy spent if the frog jumps from (i - j) to i
            int energy = abs(steps[i] - steps[i - j]) + minTotalSpendMemoisationHelper(steps, k, i - j, dp);
            // Update minEnergy to store the minimum energy required to reach step 'i'
            minEnergy = min(minEnergy, energy);
        }
    }
    // Store the computed minimum energy for step 'i' in the DP array and return it
    return dp[i] = minEnergy;
}

int minTotalSpendMemoisation(const vector<int>& steps, int k, int n){
    vector<int> dp(n, -1);
    return minTotalSpendMemoisationHelper(steps, k, n - 1, dp);
}
// n levels each level k options means k function calls
// Time complexity = O(n * k)
// Space complexity = O(n) + O(n) = O(n) (dp array + recursive call stack)

int minTotalSpendTabulation(const vector<int>& steps, int k, int n){
    // Create a DP array of size 'n' initialized with INT_MAX (large value)
    // This represents the minimum energy required to reach each step
    vector<int> dp(n, INT_MAX);

    // Base case: No energy is required to stay at the first step (0th index)
    dp[0] = 0;

    // Iterate through each step from 1 to n-1
    // reason why i  started from 1 is because the first stone (i = 0) is the starting point, and the frog does not need to spend any energy to stay there.
    for (int i = 1; i < n; i++){
        // Try all possible jumps from 1 to 'k' steps
        for (int j = 1; j <= k; j++){
            // Ensure we do not access an out-of-bounds index (negative index)
            if (i - j >= 0){
                // Calculate the energy spent if the frog jumps from (i - j) to i
                int energy = abs(steps[i] - steps[i - j]) + dp[i - j];

                // Update dp[i] to store the minimum energy required to reach step 'i'
                dp[i] = min(dp[i], energy);
            }
        }
    }
    // Return the minimum energy required to reach the last step (n-1)
    return dp[n - 1];
}

// Time complexity = O(n * k)
// Space complexity = O(n)


// Space-Optimized Tabulation (O(K) Space)
int minTotalSpendTabulationSpaceOptimised(const vector<int>& steps, int k, int n){
    // If there's only one step, no energy is required
    if (n == 1) return 0;

    // Use a vector of size 'k' to store only the last 'k' computed values
    vector<int> prev(k, INT_MAX);

    // Base case: No energy required at the first step (0th index)
    prev[0] = 0;

    // Iterate through each step from 1 to n-1
    for (int i = 1; i < n; i++) {
        int curr = INT_MAX; // Stores the minimum energy for the current step

        // Try all possible jumps from 1 to 'k' steps
        for (int j = 1; j <= k; j++) {
            // Ensure we do not access an out-of-bounds index (negative index)
            if (i - j >= 0){
                // Calculate energy spent when jumping from (i - j) to i
                int energy = abs(steps[i] - steps[i - j]) + prev[(i - j) % k];

                // Update the minimum energy required to reach step 'i'
                curr = min(curr, energy);
            }
        }
        // Store the computed minimum energy in a circular manner
        prev[i % k] = curr;
    }

    // Return the minimum energy required to reach the last step (n-1)
    return prev[(n - 1) % k];
}

// time complexity = O(n * k)
// space complexity = O(k)

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






