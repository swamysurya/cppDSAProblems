#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> sortedSquares(vector<int>& arr, int n) {
    int left = 0;
    int right = n-1;
    vector<int> result(n);
    for (int i = n-1; i >= 0; i--){
        if (abs(arr[left]) > abs(arr[right])){
            result[i] = arr[left] * arr[left];
            left++;
        }else{
            result[i] = arr[right] * arr[right];
            right--;
        }
    }
    return result;
}


int main(){
    const int n = 6;
    vector<int> arr = {-5,-1,0,2,3,6};
    vector<int> result = sortedSquares(arr,n);
    // expected output: 0 1 4 9 25 36
    for (int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    cout << endl;

}