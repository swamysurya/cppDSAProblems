#include <iostream>
#include <vector>

using namespace std;

// using recursion
int noOfWaysToClimb(int i){
    if (i == 0 || i == 1) return 1;
    int left = noOfWaysToClimb(i-1);
    int right = noOfWaysToClimb(i-2);
    return left + right;
}

// time complexity = O(2ⁿ)
// space complexity = O(n) because of recursive call stack


int noOfWaysToClimbMemoisationHelper(int n, vector<int> &dp){
    if (n == 0 || n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    int left = noOfWaysToClimbMemoisationHelper(n-1, dp);
    int right = noOfWaysToClimbMemoisationHelper(n-2, dp);
    dp[n] = left + right ;
    return dp[n];
}

// time complexity = O(n)
// space complexity = O(n) + O(n) = O(n) (dp array + recursive call stack)


int noOfWaysToClimbMemoisation(int n){
    vector<int> dp(n+1, -1);
    return noOfWaysToClimbMemoisationHelper(n, dp);
}

int noOfWaysToClimbTabulation(int n){
    vector<int> dp(n+1, -1);
    dp[0] = 1; // There's 1 way to stay at the ground (doing nothing)
    dp[1] = 1; // There's only 1 way to climb 1 step.
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

/*
n = 5
dp[]:  [1, 1, _, _, _, _]  // Base cases
dp[]:  [1, 1, 2, _, _, _]  // dp[2] = dp[1] + dp[0] = 1 + 1 = 2
dp[]:  [1, 1, 2, 3, _, _]  // dp[3] = dp[2] + dp[1] = 2 + 1 = 3
dp[]:  [1, 1, 2, 3, 5, _]  // dp[4] = dp[3] + dp[2] = 3 + 2 = 5
dp[]:  [1, 1, 2, 3, 5, 8]  // dp[5] = dp[4] + dp[3] = 5 + 3 = 8

Time complexity = O(n)
space complexity = O(n)

*/

int noOfWaysToClimbTabulationOptimised(int n){
    if (n == 0 || n == 1) return 1;
    int prev1 = 1;
    int prev2 = 1;
    int curr;
    for (int i = 2; i <= n; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}


/*

prev1 = 1, prev2 = 1
i = 2 -> curr = 1 + 1 = 2  → prev2 = 1, prev1 = 2
i = 3 -> curr = 2 + 1 = 3  → prev2 = 2, prev1 = 3
i = 4 -> curr = 3 + 2 = 5  → prev2 = 3, prev1 = 5
i = 5 -> curr = 5 + 3 = 8  → prev2 = 5, prev1 = 8


    Time complexity = O(n)
    Space complexity = O(1)
*/


int main(){
    int noOfStairs = 3;
    cout << "Number of ways to climb " << noOfWaysToClimb(noOfStairs) << endl;
    cout << "Number of ways to climb " << noOfWaysToClimbMemoisation(noOfStairs) << endl;
    cout << "Number of ways to climb " << noOfWaysToClimbTabulation(noOfStairs) << endl;
    cout << "Number of ways to climb " << noOfWaysToClimbTabulationOptimised(noOfStairs) << endl;
    return 0;
}

/*
 no of stairs = 3
 1 1 1
 1 2
 2 1
ans = 3

Time complexity = O(2ⁿ)
Space complexity = O(n) because of recursive call stack
*/
