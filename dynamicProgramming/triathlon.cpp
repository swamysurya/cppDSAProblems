#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxValRecursion(int day, vector<vector<int>> &points, int sport, int n){
    if (day < 0) return 0;
    int otherSport1 = maxValRecursion(day-1,points,(sport + 1)%3,n);
    int otherSport2 = maxValRecursion(day-1,points,(sport + 2)%3,n);
    return points[day][sport] +  max( otherSport1,otherSport2  );
}


int maxValMemorisation(int day, vector<vector<int>> &points, int sport, int n, vector<vector<int>> &dp){
    if (day < 0) return 0;
    if (dp[day][sport] != -1) return dp[day][sport];
    int otherSport1 = maxValMemorisation(day-1,points,(sport + 1)%3,n, dp);
    int otherSport2 = maxValMemorisation(day-1,points,(sport + 2)%3,n, dp);
    dp[day][sport] = points[day][sport] +  max( otherSport1,otherSport2  );
    return dp[day][sport];
}

int maxValTabulation(vector<vector<int>> &points){
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];
    
    for(int day = 1; day < n; day++){
        dp[day][0] = points[day][0] + max(dp[day-1][1], dp[day-1][2]);
        dp[day][1] = points[day][1] + max(dp[day-1][0], dp[day-1][2]);
        dp[day][2] = points[day][2] + max(dp[day-1][0], dp[day-1][1]);
    }
    return max(dp[n-1][0],max(dp[n-1][1], dp[n-1][2]));
}

// Time complexity = O(n * 3) = O(n)
// Space complexity = O(n * 3) = O(n) (dp array)

int maxValTabulationOptimised(vector<vector<int>> &points){
    int n = points.size();
    vector<int> prev(3);
    prev[0] = points[0][0];
    prev[1] = points[0][1];
    prev[2] = points[0][2];
    
    for(int day = 1; day < n; day++){
        vector<int> curr(3,0);
        curr[0] = points[day][0] + max(prev[1],prev[2]);
        curr[1] = points[day][1] + max(prev[0],prev[2]);
        curr[2] = points[day][2] + max(prev[1],prev[0]);
        prev = curr;
    }
    return max(prev[0], max(prev[1], prev[2]));
}

// Time complexity = O(n * 3) = O(n)
// Space complexity = O(3) = O(1) (dp array)    

int trainingRecurstion(int n, vector<vector<int>> &points){
    int a = maxValRecursion(n-1, points, 0, n);
    int b = maxValRecursion(n-1, points, 1, n);
    int c = maxValRecursion(n-1, points, 2, n);

    return max(a, max(b,c));
}

// Time complexity = O(2^n)
// Space complexity = O(n) because of recursive call stack

int trainingMemorisation(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int>(3, -1));
    int a = maxValMemorisation(n-1, points, 0, n, dp);
    int b = maxValMemorisation(n-1, points, 1, n, dp);
    int c = maxValMemorisation(n-1, points, 2, n, dp);
    return max(a, max(b,c));
}

// Time complexity = O(n * 3) = O(n)
// Space complexity = O(n) + O(n * 3) = O(n) (dp array + recursive call stack)

int main(){
    vector<vector<int>> points = {{1, 2, 3},
                                  {2, 3, 4},
                                  {3, 4, 5}};
    int n = points.size(); // output should be 11
    vector<vector<int>> dp(n, vector<int>(3, -1));
    cout << "Recursion: " << trainingRecurstion(n, points) << endl;
    cout << "Memorisation: " << trainingMemorisation(n, points) << endl;
    cout << "Tabulation: " << maxValTabulation(points) << endl;
    cout << "Tabulation Optimised: " << maxValTabulationOptimised(points) << endl;
    return 0;
}