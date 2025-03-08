#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int sumOfDivisions(int mid, int arr[], int n, int limit){
    long long divSum= 0;
    for(int i =0; i< n; i++){
        divSum += ceil((double)arr[i] /(double) mid);
        if (divSum > limit){
            return -1;
        }
    }
    return 1;
}

int minimumPositiveDivisor (int arr[], int n, int limit){
    int low = 1;
    int high = *max_element(arr,arr+n);
    int mid;
    // cout << low << " " << high << endl;
    
    while (low <= high){
        mid = low + (high - low)/2;
        int DivisionsSum = sumOfDivisions(mid, arr, n, limit);
        if (DivisionsSum == 1) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

int main(){
    int arr[] = {9, 35, 19,17,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int limit = 11;
    cout << "Minimum positive divisor: " << minimumPositiveDivisor(arr, n, limit) << endl;
    return 0;
}