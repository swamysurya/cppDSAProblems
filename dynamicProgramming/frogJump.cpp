#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minTotalSpend(vector<int> steps, int i){
    // base case
    // if frog jump from 0th step to 0th step energy spend = 0
    if (i == 0) return 0;
    // if frog jump from 1st step to 0th step energy spend = |steps[1] - steps[0]|
    if (i == 1) return abs(steps[i] - steps[i-1]);

    // if frog jump only one step current energy spend = |steps[i] - steps[i-1]| + minTotalSpend(steps, i-1) (next step)
    int left = abs(steps[i] - steps[i-1]) + minTotalSpend(steps, i-1);
    // if frog jump two steps current energy spend = |steps[i] - steps[i-2]| + minTotalSpend(steps, i-2) (next step)
    int right = abs(steps[i] - steps[i-2]) + minTotalSpend(steps, i-2);

    // return minimum energy spend out of two options
    return min(left, right);
}

// Time complexity = O(2ⁿ)
// Space complexity = O(n) because of recursive call stack

int minTotalSpendMemoisationHelper(vector<int> steps, int i, vector<int> &dp){
    // base case
    // if frog jump from 0th step to 0th step energy spend = 0
    if (i == 0) return 0;
    // if frog jump from 1st step to 0th step energy spend = |steps[1] - steps[0]|
    if (i == 1) return abs(steps[i] - steps[i-1]);

    // if dp[i] is already computed return it 
    if (dp[i] != -1) return dp[i];

    // if frog jump only one step current energy spend = |steps[i] - steps[i-1]| + minTotalSpend(steps, i-1) (next step)
    int s1 = abs(steps[i] - steps[i-1]) + minTotalSpendMemoisationHelper(steps, i-1, dp);
    // if frog jump two steps current energy spend = |steps[i] - steps[i-2]| + minTotalSpend(steps, i-2) (next step)
    int s2 = abs(steps[i] - steps[i-2]) + minTotalSpendMemoisationHelper(steps, i-2, dp);

    // return minimum energy spend out of two options
    return dp[i] = min(s1, s2);
}

int minTotalSpendMemoisation(vector<int> steps, int n){
    vector<int> dp(n, -1);
    return minTotalSpendMemoisationHelper(steps, n-1, dp);
}

// Time complexity = O(n)
// Space complexity = O(n) + O(n) = O(n) (dp array + recursive call stack)

int minTotalSpendTabulation(vector<int> steps, int n){
    // base case
    if (n == 0) return 0;
    if (n == 1) return abs(steps[1] - steps[0]);

    vector<int> dp(n, -1);
    dp[0] = 0;
    dp[1] = abs(steps[1] - steps[0]);
    for (int i = 2; i < n; i++){
        int s1 = abs(steps[i] - steps[i-1]) + dp[i-1];
        int s2 = abs(steps[i] - steps[i-2]) + dp[i-2];
        dp[i] = min(s1, s2);
    }
    // // print dp
    // for (int i = 0; i < n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    return dp[n-1];

    
}

/*
dp array => [-1, -1, -1, -1, -1, -1]
dp array = [0, 20, _, _, _, _]
dp[2] = min(abs(80 - 30) + dp[1], abs(80 - 50) + dp[0]) => min(50 + 20, 30 + 0) => 30

dp array = [0, 20, 30, _, _, _]

dp[3] = min(abs(30 - 80) + dp[2], abs(30 - 30) + dp[1]) => min(50 + 30, 0 + 20) => 20

dp array = [0, 20, 30, 20, _, _]

dp[4] = min(abs(80 - 30) + dp[3], abs(80 - 80) + dp[2]) => min(50 + 20, 0 + 30) => 30

dp array = [0, 20, 30, 20, 30, _]

dp[5] = min(abs(70 - 80) + dp[4], abs(70 - 30) + dp[3]) => min(10 + 30, 40 + 20) => 40

dp array = [0, 20, 30, 20, 30, 40]

return dp[n-1] = 40

*/

// Time complexity = O(n)
// Space complexity = O(n)


int minTotalSpendTabulationOptimised(vector<int> steps, int n){
    if (n == 0) return 0;
    if (n == 1) return abs(steps[1] - steps[0]);

    int prev1 = 0;
    int prev2 = abs(steps[1] - steps[0]);
    int curr;
    for (int i = 2; i < n; i++){
        int s1 = abs(steps[i] - steps[i-1]) + prev1;
        int s2 = abs(steps[i] - steps[i-2]) + prev2;
        curr = min(s1, s2);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

// Time complexity = O(n)
// Space complexity = O(1)

/*
[0,      20]
 |        |
prev2    prev1    curr

i = 2   
curr = min(abs(80 - 30) + prev1, abs(80 - 50) + prev2) => min(50 + 20, 30 + 0) => 30

[0,      20,         30]
          |           |
        prev2       prev1       curr

i = 3

curr = min(abs(30 - 80) + prev1, abs(30 - 30) + prev2) => min(50 + 30, 0 + 20) => 20

[0,      20,         30        20]
                     |          |        
                   prev2      prev1      curr

i = 4

curr = min(abs(80 - 30) + prev1, abs(80 - 80) + prev2) => min(50 + 20, 0 + 30) => 30

[0,      20,         30        20        30]
                                |         |        
                              prev2    prev1    curr

i = 5

curr = min(abs(70 - 80) + prev1, abs(70 - 30) + prev2) => min(10 + 30, 40 + 20) => 40

[0,      20,         30        20       30       40]
                                        |         |        
                                        prev2     prev1    curr

*/

int main(){
    
int n = 4;
vector<int> steps = {80,90,120,100};
    // started at last step we followed top-down approach that us why we are passing n-1
    cout << "Minimum total spend: " <<  minTotalSpend(steps,n-1) << endl;
    cout << "Minimum total spend: " <<  minTotalSpendMemoisation(steps, n) << endl;
    cout << "Minimum total spend: " <<  minTotalSpendTabulation(steps,n) << endl;
    return 0;
}

/*
int n = 6
vector<int> steps = {50, 30, 80, 30, 80, 70}
answer = 40 

int n = 4;
vector<int> steps = {80,90,120,100};
answer = 20

*/



/*

index => 0  1  2  3  4  5
steps => 50,30,80,30,80,70

                     f(5)
                     /   \
                 f(4)    f(3)
                 /   \    / \
             f(3)     f(2)   f(1)
             /   \   /   \ 
         f(2)    f(1)   f(0)
         /   \
     f(1)    f(0)
*/