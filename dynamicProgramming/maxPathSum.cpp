#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int maxPathRecursionTabulationOptimisation(vector<vector<int>> &grid, int m, int n){
    vector<int> prev(n);
    for(int j = 0; j < n; j++) prev[j] = grid[m-1][j];
    vector<int> curr(n);
    
    for(int i=m-2; i>=0; i--){
        for(int j=0; j < n; j++){
            int diagLeft = (j-1 < 0) ? INT_MIN : prev[j-1];
            int down = prev[j];
            int diagRight = (j+1 >= n) ? INT_MIN : prev[j+1];
            
            curr[j] = grid[i][j] + max({diagLeft, down, diagRight});
        }
        prev = curr;
    }
    return *max_element(prev.begin(),prev.end());
}

/*
Time Complexity: O(m * n)

The nested loops iterate through each cell in the grid exactly once.

Each cell's value is computed in constant time.

Space Complexity: O(n)

The additional space required for the prev and cur arrays is proportional to the number of columns in the grid.
*/


int maxPathRecursionTabulation(vector<vector<int>> &grid, int m, int n){
    vector<vector<int>> dp(m, vector<int>(n,-1));
    for(int j=0; j < n; j++) dp[m-1][j] = grid[m-1][j];
    for(int i = m-2; i >= 0; i--){
        for(int j = 0; j < n; j++){
            int diagLeft = (j-1 < 0) ? INT_MIN : dp[i+1][j-1];
            int down = dp[i+1][j];
            int diagRight = (j+1 >= n) ? INT_MIN : dp[i+1][j+1];
            
            dp[i][j] = grid[i][j] + max({diagLeft, down, diagRight});
        }
    }
    int maxSum = *max_element(dp[0].begin(), dp[0].end());
    return maxSum;
}

/*
Time Complexity: O(m * n)

The nested loops iterate through each cell in the grid exactly once.

Each cell's value is computed in constant time.

Space Complexity: O(m * n)

The additional space required for the dp array is proportional to the number of cells in the grid.

*/

int maxPathRecursionMemo(vector<vector<int>> &grid, int i,int j,int m,int n, vector<vector<int>>& dp){
    if(i >= m || j >= n) return INT_MIN;
    if (i == m-1) return grid[i][j];
    if (dp[i][j] != -1) return dp[i][j];
    
    int diagLeft = maxPathRecursionMemo(grid,i+1, j-1, m,n, dp);
    int down = maxPathRecursionMemo(grid,i+1,j,m,n, dp);
    int diagRight = maxPathRecursionMemo(grid,i+1,j+1,m,n,dp);
    
    dp[i][j] = grid[i][j] + max({diagLeft, down, diagRight});
    return dp[i][j];
}

/*
Time Complexity: O(m * n)

The function maxPathRecursionMemo makes recursive calls, and each call involves exploring three possible directions (left diagonal, down, right diagonal) and is called for each cell in the first row in the max_path_sum function.

The recursive calls memoized by the dp array reduce redundant computations.

Space Complexity: O(m * n) + O(m)

The space complexity is determined by the dp array, which is a memoization table used to store intermediate results to avoid redundant computations -> O(m * n).

Each recursive call consumes space on the call stack until it reaches the base case. The maximum depth of the recursion is the number of rows (m) since we start from the top and move down -> O(m).

*/

int maxPathRecursion(vector<vector<int>> &grid, int i,int j,int m,int n){
    if(i >= m || j >= n) return INT_MIN;
    if (i == m-1) return grid[i][j];
    
    int diagLeft = maxPathRecursion(grid,i+1, j-1, m,n);
    int down = maxPathRecursion(grid,i+1,j,m,n);
    int diagRight = maxPathRecursion(grid,i+1,j+1,m,n);
    
    int res = grid[i][j] + max({diagLeft, down, diagRight});
    return res;
}

// time complexity =O(n * 3^m)
// The function maxPathRecursion(i, j, grid) makes three recursive calls (left, down, right diagonally) for each cell in the grid. In the worst case, it explores all possible paths through the grid, resulting in a time complexity of 3^m.

// The function maxPathRecursion(m, n, grid) calls maxPathRecursion function for each cell in the first row.
// space complexity = O(m)
// The space complexity is determined by the depth of the recursion, which is equal to the number of rows 'm' in the grid.

void maxPath(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();

    int maxSum = INT_MIN;
    for(int j = 0; j < n; j++){
        maxSum = max(maxSum,maxPathRecursion(grid, 0, j, m, n));
    }
    cout << "using Recursion: " << maxSum << endl;

    vector<vector<int>> dp1(m, vector<int>(n,-1));
    for(int j = 0; j < n; j++){
        maxSum = max(maxSum,maxPathRecursionMemo(grid, 0, j, m, n, dp1));
    }
    cout << "using Memoisation: " << maxSum << endl;

    maxSum = maxPathRecursionTabulation(grid, m, n);
    cout << "using Tabulation: " << maxSum << endl;

    maxSum = maxPathRecursionTabulationOptimisation(grid, m, n);
    cout << "using Tabulation Optimisation: " << maxSum << endl;
}

int main(){
    vector<vector<int>> grid = {{10,40,50},{30,30,20},{30,20,20}};
    maxPath(grid);
    return 0;
}