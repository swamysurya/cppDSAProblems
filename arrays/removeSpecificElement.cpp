#include <iostream>
using namespace std;

int removeSpecificElement(int arr[], int n, int target){
    int i = 0;
    for (int j = 0; j< n; j++){
        if (arr[j] != target){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    return i;
}

int main(){
    int n = 11;
    int arr[] = {7,2,3,7,5,7,7,2,1,2,7};
    int target = 7;
    int remainingListEndIndex = removeSpecificElement(arr,n,target);
    for (int i = 0; i < remainingListEndIndex ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}