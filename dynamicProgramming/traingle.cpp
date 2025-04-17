#include <iostream>
#include <vector>

using namespace std;

int minPathRecursionTabulationOptimisation(vector<vector<int>>& triangle, int n){
    vector<int> prev(n);
    for (int i = 0; i< n; i++) prev[i] = triangle[n-1][i];
    vector<int> curr(n);
    
    for(int i=n-2; i>=0; i--){
        for(int j=0; j <= i; j++){
            curr[j] = triangle[i][j] + min(prev[j], prev[j+1]);
        }
        prev = curr;
    }
   return prev[0]; 
}

// Time Complexity: O(n^2), because of the nested loops iterating over the triangle grid with n rows.
// Space Complexity:O(n) for the cur and prev arrays, where n is the number of rows in the triangle grid.

int minPathRecursionTabulation(vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
    for(int i = 0; i < n; i++){
        dp[n-1][i] = triangle[n-1][i];
    }
    
    for (int i = n-2; i >= 0; i--){
        for(int j = 0; j<= i; j++){
            dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    return dp[0][0];
}

// time complexcity : O(n^2), because it iterates through each cell of the n x n triangle grid once, where n is the number of rows in the triangle.
// space complexity =  O(n^2)  for the dp array, where n is the number of rows in the triangle 

int minPathRecursionMemo(vector<vector<int>>& triangle, int n, int i, int j, vector<vector<int>>& dp){
    if (i == n-1) return triangle[i][j];
    if (dp[i][j] != -1) return dp[i][j];
    
    int down = triangle[i][j] + minPathRecursionMemo(triangle, n, i+1, j, dp);
    int cross = triangle[i][j] + minPathRecursionMemo(triangle, n, i+1, j +1, dp);
    dp[i][j] = min(down, cross);
    return dp[i][j];
}
// time complexity = O(n^2)  where n is the number of rows in the triangle grid, as each cell is computed once and the function uses memoization to avoid redundant calculations.
// space complexity = O(n^2) + O(n) where  O(n^2) for the dp array, and O(n) for the recursive call stack, and n is the number of rows in the triangle grid.


int minPathRecursion(vector<vector<int>>& triangle, int n, int i, int j){
    if (i == n-1){
        return triangle[i][j];
    }
    int down = triangle[i][j] + minPathRecursion(triangle, n, i+1, j);
    int cross = triangle[i][j] + minPathRecursion(triangle, n, i+1, j +1);
    int res = min(down, cross);
    return res;
}

// time complexcity = O(2^n)
//because it explores all possible paths from the top to the bottom of the triangular grid, resulting in an exponential number of recursive calls.
// space complexity = O(n)
//where n is the number of rows in the triangle grid, as it requires space to store the recursive call stack for each row.

void minPath(vector<vector<int>>& triangle, int n){
    int i = 0, j = 0;
    cout << "Minimum Path Sum: " << minPathRecursion(triangle,n,i,j) << endl;

    // dp
    vector<vector<int>> dp1(n, vector<int>(n, -1));
    cout << "Minimum Path Sum: " << minPathRecursionMemo(triangle, n, i, j, dp1) << endl;
    vector<vector<int>> dp2(n, vector<int>(n, -1));
    cout << "Minimum Path Sum: " << minPathRecursionTabulation(triangle, n, dp2) << endl;
    cout << "Minimum Path Sum: " << minPathRecursionTabulationOptimisation(triangle, n) << endl;
    
}

int main(){
    vector<vector<int>> triangle = {{5}, {9,2}, {12,8,3}, {4,11,6,10}};
    minPath(triangle, triangle.size());
    return 0;
}