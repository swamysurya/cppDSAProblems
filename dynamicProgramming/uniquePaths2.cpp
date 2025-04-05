#include <iostream>
#include <vector>

using namespace std;


int uniquePathsRecurstion(int i, int j, vector<vector<int>>& grid){
    // boundary cases return 0 beacuse we are not cross the boundy of grid
    if (i < 0 || j < 0) return 0;
    if (grid[i][j] == -1) return 0;
    if (i == 0 && j == 0) return 1;
    // go in top direction posibilities
    int top = uniquePathsRecurstion(i-1, j, grid);
    // go in left direction posibilities
    int left = uniquePathsRecurstion(i,j-1,grid);
    // add all posibilities
    return top + left;
}

int uniquePathsMemorisation(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
    // boundary cases return 0 beacuse we are not cross the boundy of grid
    if (i < 0 || j < 0) return 0;
    if (grid[i][j] == -1) return 0;
    if (i == 0 && j == 0) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    // go in top direction posibilities
    int top = uniquePathsMemorisation(i-1, j, grid, dp);
    // go in left direction posibilities
    int left = uniquePathsMemorisation(i,j-1,grid, dp);
    // add all posibilities
    dp[i][j] = top + left;
    return dp[i][j];
}

int uniquePathsTabulation(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
    // initialise a dp withe values of 0 and in place of -1 (obstacles) replace it with 0 
    int left,top;
    // example
    // gird = [[0 0 -1], [-1 0 0], [-1 0 0]]
    // dp = [[1 _ 0], [0 _ _ ],[0 _ _ ]] 
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (i == 0 && j == 0){
                // base case
                dp[i][j] = 1;
            }else if(grid[i][j] == -1){
                // we set 0 to places were we can set values to 0
                dp[i][j] = 0;
            }else{
                // reamaining paths we find it by summing down and top
                top = 0;
                left = 0;
                // if i > 0 means we we should touch beyond boundry of gird
                if (i > 0) left = dp[i-1][j];
                // if j > 0 means we we should touch beyond boundry of gird
                // add both the posibilities 
                if (j > 0) top = dp[i][j-1];
                dp[i][j] = top + left;
            }
        }
    }
    return dp[m-1][n-1];
}

int uniquePathsTabulationOptimised(int m, int n, vector<vector<int>>& grid){
    int left,top;
    // as we observed above the dp[i][j] = dp[i-1][j] + dp[i][j-1]
    // means the current dp value is depends on prev row and currnt row
    // instead of creating dp we store prev row to compute current row 
    vector<int> prev(n); // for prev row values nothing but top rows 
    vector<int> curr(n); // for compute current row 
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            // starting cell should have one way if not blocked
            if (i == 0 && j == 0){
                // base case
                curr[0] = 1;
            }else if(grid[i][j] == -1){
                curr[j] = 0;
            }else{
                // reamaining paths we find it by summing down and top
                top = 0;
                left = 0;
                // if i > 0 means we we should touch beyond boundry of gird
                if (i > 0) top = prev[j];
                // if j > 0 means we we should touch beyond boundry of gird
                // add both the posibilities 
                if (j > 0) left = curr[j-1];
                curr[j] = top + left;
            }
        }
        prev = curr;
    }
    return curr[n-1];
}

int main(){
    int m = 3, n = 3;
    vector<vector<int>> grid = {{0,0,-1},{-1,0,0},{-1,0,0}};
    cout << "uniquePathsRecurstion: " << uniquePathsRecurstion(m-1, n-1, grid) << endl;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "uniquePathsMemorisation: " << uniquePathsMemorisation(m-1, n-1, grid, dp) << endl;
    vector<vector<int>> dp2(m, vector<int>(n, -1));
    cout << "uniquePathsTabulation: " << uniquePathsTabulation(m, n, grid, dp2) << endl;
    cout << "uniquePathsTabulationOptimised: " << uniquePathsTabulationOptimised(m, n, grid) << endl;
    
    return 0;
}
