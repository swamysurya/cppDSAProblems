#include <iostream>
#include <vector>
using namespace std;


int fibinacci(int n){
    if (n == 0 || n == 1) return n;
    return fibinacci(n-1) + fibinacci(n-2);
}

// time complexity = O(2ⁿ)
// space complexity = O(n) because of recursive call stack

int fibinacciMemorization(int n, vector<int> &dp){
    if (n == 0 || n == 1) return n;
    if (dp[n] != -1) return dp[n];
    dp[n] = fibinacciMemorization(n-1, dp) + fibinacciMemorization(n-2, dp);
    return dp[n];
}

// time complexity = O(n)
// space complexity = O(n) because of recursive call stack

/*
memorization: Memoization is a technique in DP where we store the results of 
expensive function calls and reuse them when the same inputs occur again.
This optimization avoids redundant calculations and significantly improves performance, 
especially for problems with overlapping subproblems.
*/

int fibinacciTabulation(int n, vector<int> &dp){
    if (n == 0 || n == 1) return n;

    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// time complexity = O(n)
// space complexity = O(n)

int fibinacciTabulationSpaceOptimised(int n){
    if (n == 0 || n == 1) return n;
    int prior1 = 1, prior2 = 0;

    for (int i = 2; i <= n; i++){
        int current = prior1 + prior2;
        prior2 = prior1;
        prior1 = current;
    }
    return prior1;
}

// time complexity = O(n)
// space complexity = O(1)


int main(){
    int n = 8;
    int res = fibinacci(n);// function which returns the n'th fibinacci number
    cout << "Fibinacci number at position " << n << ": " << res << endl;

    int n2 = 8;
    vector<int> dp(n2+1, -1);
    int res2 = fibinacciMemorization(n2,dp);
    cout << "Fibinacci number at position " << n2 << ": " << res2 << endl;

    int n3 = 8;
    vector<int> dp2(2);
    dp2[0] = 0;
    dp2[1] = 1;
    int res3 = fibinacciTabulation(n3,dp2);
    cout << "Fibinacci number at position " << n3 << ": " << res3 << endl;

    int n4 = 8;
    int res4 = fibinacciTabulationSpaceOptimised(n4);
    cout << "Fibinacci number at position " << n4 << ": " << res4 << endl;
    return 0;
}


/*
f(n) => 0,1,1,2,3,5,8,13,21...
n    => 0,1,2,3,4,5,6,7, 8

dp[]
*/