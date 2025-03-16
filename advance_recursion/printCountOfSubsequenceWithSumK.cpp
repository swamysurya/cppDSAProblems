#include <iostream>
#include <vector>

using namespace std;


int findSubSequencesWithSumKRecursion(int arr[],int n, int k, int i, int currentSum){
    if (i == n){
        return (currentSum == k) ? 1 : 0;
    }
    int include = findSubSequencesWithSumKRecursion(arr, n, k, i+1, currentSum + arr[i]);
    int exclude = findSubSequencesWithSumKRecursion(arr, n, k, i+1,currentSum);
    
    return include + exclude;
}


int main(){
    int n = 3, k = 9, i = 0, currentSum = 0;
    int arr[] = {4,5,9};
    int res = findSubSequencesWithSumKRecursion(arr, n, k, i, currentSum);
    cout << "Number of subsequence with sum " << k << ": " << res << endl;
    return 0;
}

// subsequence with sum k =[4,5], [9]

// time complexcity = O(2ⁿ)
// space complexcity = O(n) bacause of recursive call stack
