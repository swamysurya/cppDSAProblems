#include <iostream>
#include <vector>

using namespace std;


vector<int> printOnlyOneSubSeqenceWithSumK(vector<int> arr, int n,int k,int i, vector<int> &v, int currentSum){
    vector<int> res;
    if ( i == n){
        if (currentSum == k){
            return v;
        }
        return {};
    }

    v.push_back(arr[i]);
    res = printOnlyOneSubSeqenceWithSumK(arr, n, k,i+1,v, currentSum+arr[i]);
    // if res is not empty we will return vector that we found no need to to go right part of tree
    if (!res.empty()) return res;
    // if res is empty we will search on right and return the result
    v.pop_back();
    res = printOnlyOneSubSeqenceWithSumK(arr, n, k,i+1,v, currentSum);
    return res;
}

int main(){
    int n = 3, k = 9, i = 0, currentSum = 0;
    vector<int> arr = {4,5,9}, v;
    vector<int> res = printOnlyOneSubSeqenceWithSumK(arr, n,k, i,v, currentSum);    
    for(int k : res){
        cout << k << " ";
    };
    cout << endl;
}

// time complexcity = best case O(n), worst case O(2ⁿ)
// space complexcity = O(n);
