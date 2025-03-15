#include <iostream>
#include <vector>

using namespace std;

void printSubsequence(vector<int> &v, int arr[], int index, int n, int k, vector<vector<int>> &res, int currentSum){
    // base case
    if (index == n){
        if (currentSum == k){
            res.push_back(v);
        }
        return;
    }
    // either we can pick the element
    v.push_back(arr[index]);
    // add the current element to the current sum this ensures that we keep track of the sum of the current subsequence for each recursive call
    printSubsequence(v, arr, index+1, n, k, res, currentSum + arr[index]);
    // or we can not pick the element
    v.pop_back();
    // remove the current element from the current sum this ensures that we keep track of the sum of the current subsequence for each recursive call
    printSubsequence(v, arr, index+1, n, k, res, currentSum);
}

int main(){
    int arr[] = {4,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v; // for current subsequence
    int k = 5;
    vector<vector<int>> res; // to store the subsequences with sum k
    int currentSum = 0; // to keep track of the sum of the current subsequence for each recursive call
    printSubsequence(v,arr, 0, n, k, res, currentSum);
    cout << "Subsequences with sum " << k << ":" << endl;
    for(auto v: res){
        for(auto i: v){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

// Time Complexity: O(2ⁿ * n)
// Space Complexity: O(2ⁿ * n)
// space complexity = auxilary space + space used by the input
// auxilary space = O(n)
// space used by the input = O(n)


// LeetCode Problem #560.

