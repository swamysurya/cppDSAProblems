#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// another way of writing code
int minimumPathRecursionNormal(int i, int j, vector<vector<int>> &grid){
    // boundary cases return INT_MAX beacuse we are not cross the boundy of grid
    if (i < 0 || j < 0) return INT_MAX;
    // base case return grid value
    if ( i == 0 && j == 0) return grid[i][j];
    // we need min sum from left and right posibilties
    int top =  minimumPathRecursionNormal(i-1, j, grid);
    int left = minimumPathRecursionNormal(i, j-1, grid);
    // we need min sum from left and right posibilties
    int res = grid[i][j] + min(top,left);
    // return the posibility for prev call 
    return res;
}

// time complexity = O(2 ^ (m + n))
//  since each cell is computed recursively with two possible moves (right and down) for (m) rows and (n) columns.
// space complexity = O(m + n) 
// as it depends on the depth of the recursive call stack, which is limited to the sum of rows (m) and columns (n) in the grid.



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


// time complexity = O(2 ^ (m + n))
//  since each cell is computed recursively with two possible moves (right and down) for (m) rows and (n) columns.
// space complexity = O(m + n) 
// as it depends on the depth of the recursive call stack, which is limited to the sum of rows (m) and columns (n) in the grid.


int minimumPathMemorisation(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i == 0 && j == 0) return grid[i][j];
    if (dp[i][j] != -1) return dp[i][j];
    
    int top = (i > 0) ? grid[i][j] + minimumPathMemorisation(i-1, j, grid, dp) : INT_MAX;
    int left = (j > 0) ? grid[i][j] + minimumPathMemorisation(i, j-1, grid,dp) : INT_MAX;
    
    dp[i][j] = min(top,left);
    return dp[i][j];
}

// time complexity = O(m * n)
//  because each cell in the m×n grid is computed once, and memoization ensures that previously computed values are reused.
// space complexity = O(m + n) + O(m * n)
// where space complexity is O(m+n) for the memoization table (DP table) plus O(mxn) for the recursive call stack.


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

// time complexity = O(m * n)
//  because the algorithm iterates through all  m rows and n columns of the grid once to fill the DP table.
// space complexity = O(m * n)
//   due to the usage of a 2D DP table of size  m×n to store intermediate values for each cell in the grid.

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

// time complexity = O(m * n)
//  due to the nested iteration over the grid.
// space complexity = O(n) (prev array) + O(n) (curr array) = O(n)
//  due to the usage of two 1D arrays of size n (prev and curr) to store intermediate values.

int main(){
    int m = 3, n = 3;
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}}; // output: 21
    cout << "RecursionNoraml: " << minimumPathRecursionNormal(2,2,grid) << endl;
    cout <<"Recursion: " << minimumPathRecursion(2,2,grid) << endl;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout <<"Memorisation: " << minimumPathMemorisation(2,2,grid,dp) << endl;

    cout <<"Tabulation: " << minimumPathTabulation(3,3,grid) << endl;
    cout <<"Tabulation Optimisation: " << minimumPathTabulationOptimisation(3,3,grid) << endl;
    return 0;
}