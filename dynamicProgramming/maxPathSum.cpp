#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int minimumPathRecursion(int i, int j, vector<vector<int>> &grid){
    if ( i == 0 && j == 0) return grid[i][j];
    // before doing recursive call we ensure i > 0 and j > 0 beacuse
    // if i > 0 -> i - 1 is valid index
    // if j > 0 -> j - 1 is valid index
    
    // if add base case like if (i < 0 || j < 0) return INT_MAX 
    // which return value of base case INT_MAX value add to grid[i][j] causes overflow so
    // we check i and j are greater than 0 
    int top = (i > 0) ? grid[i][j] + minimumPathRecursion(i-1, j, grid) : INT_MAX;
    int left = (j > 0) ? grid[i][j] + minimumPathRecursion(i, j-1, grid) : INT_MAX;
    // we need min sum from left and right posibilties
    int res = min(top,left);
    // return the posibility for prev call 
    return res;
}

int minimumPathMemorisation(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i == 0 && j == 0) return grid[i][j];
    if (dp[i][j] != -1) return dp[i][j];
    
    int top = (i > 0) ? grid[i][j] + minimumPathMemorisation(i-1, j, grid, dp) : INT_MAX;
    int left = (j > 0) ? grid[i][j] + minimumPathMemorisation(i, j-1, grid,dp) : INT_MAX;
    
    dp[i][j] = min(top,left);
    return dp[i][j];
}

int minimumPathTabulation(int m, int n, vector<vector<int>> &grid){
    vector<vector<int>> dp(m, vector<int> (n,0));
    
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            }else{
                int right = (j > 0) ? grid[i][j] + dp[i][j-1] : INT_MAX;
                int top = (i > 0) ? grid[i][j] + dp[i-1][j] : INT_MAX;
                dp[i][j] = min(top, right);
            }
        }
    }
    return dp[m-1][n-1];
}

int minimumPathTabulationOptimisation(int m, int n, vector<vector<int>> &grid){
    // this array hold prev row values
    vector<int> prev(n,0);
    // this array holds current row values
    vector<int> curr(n,0);
    
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            // starting element store in currnt array starting value
            if (i == 0 && j == 0) {
                curr[j] = grid[0][0];
            }else{
                // current value depends on left value curr[j-1] and prev value prev[j]
                int right = (j > 0) ? grid[i][j] + curr[j-1]: INT_MAX;
                int top = (i > 0) ? grid[i][j] + prev[j] : INT_MAX;
                curr[j] = min(top, right);
            }
        }
        // update prev value to currnt value for next iteration
        prev = curr;
    }
    // return last value in curr or prev array 
    return curr[n-1];
}

int main(){
    int m = 3, n = 3;
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}}; // output: 21
    cout <<"Recursion: " << minimumPathRecursion(2,2,grid) << endl;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout <<"Memorisation: " << minimumPathMemorisation(2,2,grid,dp) << endl;

    cout <<"Tabulation: " << minimumPathTabulation(3,3,grid) << endl;
    cout <<"Tabulation Optimisation: " << minimumPathTabulationOptimisation(3,3,grid) << endl;
    return 0;
}