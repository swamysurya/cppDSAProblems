#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    int maxChocolatesRecursion(vector<vector<int>>& grid, int m, int n, int i, int j1, int j2){
        // base cases where the jack and charlie goes beyond the box
        if (j1 < 0 || j2 < 0 || j1 > n-1 || j2 > n-1) return INT_MIN;
        int gridValue;
        // when both reach bottom means based on the postion get the cholclates
        if (i == m-1){
            if (j1 == j2){
                return grid[i][j1];
            }else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        // while in travel any one collide grid value should picked based on condition
        if (j1 == j2){
            gridValue = grid[i][j1];
        }else{
            gridValue = grid[i][j1] + grid[i][j2];
        }
        
        vector<int> posibilities(9);
        // charlie moves left and jack moves left
        posibilities[0] = maxChocolatesRecursion(grid,m,n,i+1,j1-1,j2-1);
        // charlie moves left and jack movies down
        posibilities[1] = maxChocolatesRecursion(grid,m,n,i+1,j1-1,j2);
        // charlie moves left and jack moves right
        posibilities[2] = maxChocolatesRecursion(grid,m,n,i+1,j1-1,j2+1);
        // charlie moves down with 3 different posibilties of jack 
        posibilities[3] = maxChocolatesRecursion(grid,m,n,i+1,j1,j2-1);
        posibilities[4] = maxChocolatesRecursion(grid,m,n,i+1,j1,j2);
        posibilities[5] = maxChocolatesRecursion(grid,m,n,i+1,j1,j2+1);
        // charlie moves right with 3 different posibilties of jack
        posibilities[6] = maxChocolatesRecursion(grid,m,n,i+1,j1+1,j2-1);
        posibilities[7] = maxChocolatesRecursion(grid,m,n,i+1,j1+1,j2);
        posibilities[8] = maxChocolatesRecursion(grid,m,n,i+1,j1+1,j2+1);
        
        return gridValue + *max_element(posibilities.begin(), posibilities.end());
        
    }

    // Time Complexity: O(9^m)
    // The function explores 9 different positions for each cell in the grid (3 choices for each of the two columns).
    // The recursion depth is equal to the number of rows (m).
    // The total number of recursive calls is exponential.
    // Space Complexity: O(m)
    // The space complexity is determined by the depth of the recursion, which is equal to the number of rows (m).
    
    int maxChocolatesMemo(vector<vector<int>>& grid,int m,int n,int i, int j1, int j2, vector<vector<vector<int>>> &dp){
        // base cases where the jack and charlie goes beyond the box
        if (j1 < 0 || j2 < 0 || j1 > n-1 || j2 > n-1) return INT_MIN;
        int gridValue;
        // when both reach bottom means based on the postion get the cholclates
        if (i == m-1){
            if (j1 == j2){
                return grid[i][j1];
            }else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        // while in travel any one collide grid value should picked based on condition
        if (j1 == j2){
            gridValue = grid[i][j1];
        }else{
            gridValue = grid[i][j1] + grid[i][j2];
        }
        // expore all the possbiel ways charie(left, down, right) and jack(left, down, right)
        // total 9 posibilities
        vector<int> posibilities(9);
        // charlie moves left and jack moves left
        posibilities[0] = maxChocolatesMemo(grid,m,n,i+1,j1-1,j2-1,dp);
        // charlie moves left and jack movies down
        posibilities[1] = maxChocolatesMemo(grid,m,n,i+1,j1-1,j2,dp);
        // charlie moves left and jack moves right
        posibilities[2] = maxChocolatesMemo(grid,m,n,i+1,j1-1,j2+1,dp);
        // charlie moves down with 3 different posibilties of jack 
        posibilities[3] = maxChocolatesMemo(grid,m,n,i+1,j1,j2-1,dp);
        posibilities[4] = maxChocolatesMemo(grid,m,n,i+1,j1,j2,dp);
        posibilities[5] = maxChocolatesMemo(grid,m,n,i+1,j1,j2+1,dp);
        // charlie moves right with 3 different posibilties of jack
        posibilities[6] = maxChocolatesMemo(grid,m,n,i+1,j1+1,j2-1,dp);
        posibilities[7] = maxChocolatesMemo(grid,m,n,i+1,j1+1,j2,dp);
        posibilities[8] = maxChocolatesMemo(grid,m,n,i+1,j1+1,j2+1,dp);
        
        dp[i][j1][j2] = gridValue + *max_element(posibilities.begin(), posibilities.end());
        return dp[i][j1][j2];
    }

    // Time Complexity: O(m * (n^2))
    // The function explores 9 different positions for each cell in the grid (3 choices for each of the two columns).
    // The recursion depth is equal to the number of rows (m).
    // For each cell in the grid, there are two column indices (j1 and j2), resulting in a total of n^2 subproblems.
    // With memoization, each subproblem is solved only once, leading to a time complexity of O(m * (n^2)).
    // Space Complexity: O(m * (n^2)) + O(m)
    // The space complexity is determined by the memoization table dp, which is a three-dimensional vector with dimensions m * n * n.
    // Each cell in the memoization table stores the result of a subproblem.
    // The space complexity of the recursion stack, which is equal to the number of rows (m) -> O(m)
    
    int maxChocolatesTabulation(int m, int n,vector<vector<int>>& grid){
        // intialise 3d dp for store all values
        // dp[i][j1][j2] -> maximum chocolates collected starting from row i,
        // where palyer 1 is at column j1 and player 2 at column j2
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n,vector<int>(n)));
        int gridVal;
        // porcess the grid from the last row up to the first row 
        for (int i = m-1; i >=0; i--){
            for(int j1 = 0; j1 <= n-1; j1++){ // player 1 column
                for(int j2 = 0; j2 <= n-1; j2++){ // player 2 column
                    // base case : last row -> just collect chocolates
                    if (i == m-1){
                        // if they are in same cell
                        if (j1 == j2){
                            dp[i][j1][j2] = grid[i][j1];
                        }else{
                        // differnet cell
                            dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
                        }
                    }else{
                        // for other rows take curret cell value based on j1 j2 postion
                        if (j1 == j2){
                            gridVal = grid[i][j1];
                        }else{
                            gridVal = grid[i][j1] + grid[i][j2];
                        }
                        // after taking explore all possible values 
                        // intiliased all posibilties withe out of boundry
                        // if any valid move get from prev computed values which is dp
                        vector<int> posibilities(9,INT_MIN);
                        
                        // all 9 move combinations
                        // player 1 -> j1-1,j1,j1+1;
                        //player 2 -> j1-1,j2,j2+1;
                        
                        if (j1-1 >= 0 && j2-1 >= 0) posibilities[0] = dp[i+1][j1-1][j2-1];
                        if (j1-1 >= 0) posibilities[1] = dp[i+1][j1-1][j2];
                        if (j1-1 >= 0 && j2+1 <= n-1) posibilities[2] = dp[i+1][j1-1][j2+1];
                        
                        if (j2-1 >= 0) posibilities[3] = dp[i+1][j1][j2-1];
                        posibilities[4] = dp[i+1][j1][j2];
                        if (j2 + 1 <= n-1) posibilities[5] = dp[i+1][j1][j2+1];
                        
                        if (j1+1 <= n-1 && j2-1 >= 0) posibilities[6] = dp[i+1][j1+1][j2-1];
                        if (j1+1 <= n-1) posibilities[7] = dp[i+1][j1+1][j2];
                        if (j1 + 1 <= n-1 && j2 +1 <= n-1) posibilities[8] = dp[i+1][j1+1][j2+1];
                        // take the best (maximum ) of all 9 posible next moves
                        dp[i][j1][j2] = gridVal + *max_element(posibilities.begin(), posibilities.end());
                    }
                }
            }
        }
        // final answer
        // start from row 0 withe player 1 at col 0 and player 2 at col n-1
        return dp[0][0][n-1];
    }
    
    // Time Complexity: O(m * (n^2))
    // The three nested loops iterate through all cells in the 3D dp table, resulting in O(m * (n^2)) operations.
    // Space Complexity: O(m * (n^2))
    // The space complexity is determined by the 3D dp table, which has dimensions m * n * n.
    // Each cell in the dp table stores the result of a subproblem.

    int maxChocolatesTabulationOptmisiation(int m, int n, vector<vector<int>>& grid){
        vector<vector<int>> curr(n, vector<int>(n));
        vector<vector<int>> prev(n, vector<int>(n));
        int gridValue;
        for (int i = m-1; i >= 0; i--){
            for (int j1 = 0; j1 < n; j1++){
                for(int j2 = 0; j2 < n; j2++){
                    // base case fill all grid values
                    if (i == m-1){
                        if (j1 == j2) curr[j1][j2] = grid[i][j1];
                        else curr[j1][j2] = grid[i][j1] + grid[i][j2];
                    }else{
                        if (j1 == j2) gridValue = grid[i][j1];
                        else gridValue = grid[i][j1] + grid[i][j2];
                        
                        vector<int> posibilities(9, INT_MIN);
                        if(j1 -1 >= 0 && j2-1 >= 0) posibilities[0] = prev[j1-1][j2-1];
                        if(j1-1 >=0) posibilities[1] = prev[j1-1][j2];
                        if(j1-1 >=0 && j2+1 <= n-1) posibilities[2] = prev[j1-1][j2+1];
                        
                        if(j2-1 >=0) posibilities[3] = prev[j1][j2-1];
                        posibilities[4] = prev[j1][j2];
                        if(j2 +1 <= n-1) posibilities[5] = prev[j1][j2+1];
                        
                        if(j1 + 1 <= n-1 && j2 -1 >= 0) posibilities[6] = prev[j1+1][j2-1];
                        if(j1+1 <= n-1) posibilities[7] = prev[j1+1][j2];
                        if(j1+1 <= n-1 && j2+1 <= n-1) posibilities[8] = prev[j1+1][j2+1];
                        
                        curr[j1][j2] = gridValue + *max_element(posibilities.begin(), posibilities.end());
                    }
                }
            }
            prev = curr;
        }
        return prev[0][n-1];
    }

    // Time Complexity: O(m * (n^2))
    // The three nested loops iterate through all cells in the 3D dp table, resulting in O(m * (n^2)) operations.
    // Space Complexity: O(n^2)
    // The space complexity is determined by the 2D dp table, which has dimensions n * n.
    // Each cell in the dp table stores the result of a subproblem.
    
    int maxChocolates(int m, int n, vector<vector<int>>& grid){
        // create a 3 dimentional gird to store function calls
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n,-1)));
        // return maxChocolatesRecursion(grid, m, n, 0,0, n-1);
        // return maxChocolatesMemo(grid,m,n,0,0,n-1,dp);
        // return maxChocolatesTabulation(m,n,grid);
        return maxChocolatesTabulationOptmisiation(m,n,grid);
    }
};

// main code

//test case 2
// 2 2
// 50 40
// 40 50

int main(){
    int m = 3, n = 3;
    vector<vector<int>> grid = {{10,20,10},{30,20,10},{10,15,30}}; // output: 115
    // int m = 2, n = 2;
    // vector<vector<int>> grid = {{50,40},{40,50}}; // output: 180
    solution sol;
    // recursion approach
    cout << "Recursion: " << sol.maxChocolatesRecursion(grid, m, n, 0,0, n-1) << endl;
    
    // memoisation approach
    vector<vector<vector<int>>> dp1(m, vector<vector<int>>(n, vector<int>(n,-1)));
    cout << "Memoisation: " << sol.maxChocolatesMemo(grid,m,n,0,0,n-1,dp1) << endl;

    // tabulation approach
    cout << "Tabulation: " << sol.maxChocolatesTabulation(m,n,grid) << endl;

    // tabulation optimisation approach
    cout << "Tabulation Optimisation: " << sol.maxChocolatesTabulationOptmisiation(m,n,grid) << endl;
    
    return 0;
}