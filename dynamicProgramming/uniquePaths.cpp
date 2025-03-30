#include <iostream>
#include <vector>
using namespace std;


// f(i,j) = no of unique paths form (0,0) to (i,j);
// f(i,0) = no of unique paths from (0,0) to (i, 0) is one only
// f(0, j) = no of unique paths from (0,0) to (0, j) is one only

int uniquePathsRecursive(int i, int j){
    if (i == 0 || j == 0) return 1;
    int down = uniquePathsRecursive(i-1,j);
    int right = uniquePathsRecursive(i, j-1);
    int res = down + right;
    return res;
}

// T.C = O(2 ^ m + n)
// S.C = O(m + n)

int uniquePathsMemorisation(int i, int j, vector<vector<int>> &dp){
    if (i == 0 || j == 0) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    int down = uniquePathsMemorisation(i-1,j, dp);
    int right = uniquePathsMemorisation(i,j-1, dp);
    dp[i][j] = down + right;
    return dp[i][j];
}

// T.C = O(m * n)
// S.C = O(m + n)(stack space) + O(m*n) additional dp space

int uniquePathsTabluation(int m, int n){
    vector<vector<int>> dp(m, vector<int> (n, 0));
    for(int i = 0; i < m; i++){
        dp[i][0] = 1;
    }
    for(int j = 0; j < n; j++){
        dp[0][j] = 1;
    }
    for(int i = 1; i < m; i++){
        for(int j = 1;  j < n; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

// T.C = O(m * n)
// S.C = O(m * n) of dp size

int uniquePathsTabluationOptimisation(int m, int n){
    // vector<int> prev(n, 1);
    // vector<int> curr(n,0);
    // instead of prev and curr intialised withe size n we can initlise withe min(m,n) 
    // why beause cuur[j] valuse depends on curr[j-1] value and prev[j] value 
    // so the array sizees need not be n
    vector<int> prev(n, 1);
    vector<int> curr(n,0);
    curr[0] = 1; // no need
    for(int i = 1; i < m; i++){
        // curr[0] = 1 // IF YO WANT TO U CAN SET CURR[0] = 1 explicitLY THERE IS NO USE OF THAT
        // BEACUSE CURR[0]  ALWAYS HOLDES 1
        for (int j = 1; j < n; j++){
            curr[j] = curr[j-1] + prev[j];
        }
        prev = curr;
    }
    return prev[n-1];
}

// T.C = O(m * n);
// S.C = O(n) //  column size


int main() {
    int m = 5;
    int n = 5;
    vector<vector<int>> dp(m, vector<int> (n, -1));
    int res1 = uniquePathsRecursive(m-1,n-1);
    int res2 = uniquePathsMemorisation(m-1,n-1,dp); 
    int res3 = uniquePathsTabluation(m,n);
    int res4 = uniquePathsTabluationOptimisation(m,n);
    cout << "Recursive: " << res1 << endl;
    cout << "Memorisation: " << res2 << endl;
    cout << "Tabulation: " << res3 << endl;
    cout << "Tabulation Optimisation: " << res4 << endl;
    return 0;
}

