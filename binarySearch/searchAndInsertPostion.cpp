#include <iostream>
using namespace std;

int findIndexAndInsert(int arr[], int n, int target){
    int low = 0;
    int high = n-1;
    int index = -1;
    int mid;
    
    while(low <= high){
        mid = low + (high - low)/2;
        if (arr[mid] >= target){
            index = mid;
            low = mid - 1;
        }else{
            high = mid + 1;
        }
    }
    return index;
}

int main(){
    const int n = 4;
    int target = 7;
    int arr[] = {4,5,6,9};
    cout << "index to insert postion" << findIndexAndInsert(arr,n,target) << endl;
}