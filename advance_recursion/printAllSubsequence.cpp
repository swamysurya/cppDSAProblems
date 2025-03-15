#include <iostream>
#include <vector>
using namespace std;

// function to print subarray
void printArray(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void printSubsequence(vector<int> &v, int arr[], int index, int n){
   // base case
   // we print the array when the we form subarray
   if (index == n){
        printArray(v);
        return;
   }

   // either we can pick the element
   v.push_back(arr[index]);
   printSubsequence(v, arr, index+1, n);
   // or we can not pick the element
   v.pop_back();
   printSubsequence(v, arr, index+1, n);


} 

//Time Complexity: O(2ⁿ * n)    // 2^n for tree and n for print array
//Space Complexity: O(n) (auxilary space)       // n for array

int main(){
    int arr[] = {4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    printSubsequence(v,arr, 0, n);
}

// subsequcne are the sequence which are ordered and need not continous
// subset are the sequence which are ordered and continous

/*
left side is pick and right side is not pick

                            []
                          /    \
                      [1]        []
                    /    \       /    \
                [1,2]    [1]   [2]    []
               /    \    /   \  /   \   /   \
         [1,2,3]  [1,2] [1,3] [1] [2,3] [2] [3] []

*/