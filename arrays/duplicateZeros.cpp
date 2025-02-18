
#include<iostream>
#include<vector>
using namespace std;

// brute force 
void duplicateZeros_bruteForce(vector<int> &arr){
    int i = 0;
    vector<int> newArr;
    for(int j = 0; j < arr.size(); j++){
        if(arr[j] == 0){
            newArr.push_back(0);
            newArr.push_back(0);
        }else{
            newArr.push_back(arr[j]);
        }
    }
    
    for(int i = 0; i < arr.size(); i++){
        arr[i] = newArr[i];
    }
}
// time complexity = O(n)
// space complexity = O(n)

// optimal solution
void duplicateZeros(vector<int> &arr){
    int i = 0;
    int n = arr.size();
    while(i < n){
        // if you found zero insert 0 at the position and pop last element
        if(arr[i] == 0){
            arr.insert(arr.begin() + i + 1, 0);
            arr.pop_back();
            i++; // increment i because we inserted 0 at the position
        }
        i++; // increment i because we are moving to the next element
    }
}
// time complexity = O(n)
// space complexity = O(n)

int main(){
    vector<int> arr = {1,0,2,3,0,4,5,0};
    duplicateZeros_bruteForce(arr);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}