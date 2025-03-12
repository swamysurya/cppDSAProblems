#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void printSubsequence(vector<int> &v, int arr[], int index, int n){
   if (index >= n){
        printArray(v);
        return;
   }

   // pick here
   v.push_back(arr[index]);
   printSubsequence(v, arr, index+1, n);
   v.pop_back();
   printSubsequence(v, arr, index+1, n);


}   

int main(){
    int arr[] = {4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    printSubsequence(v,arr, 0, n);
}