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

long long sum_division(int arr[], int n, int x){
    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum += ceil( (double)arr[i] / (double) x);
    }
    return sum;
}
int minimum_positive_divisor (int arr[], int n, int limit){
    int max = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    for(int i = 1; i <= max; i++){
        if(sum_division(arr, n, i) <= limit){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {9, 35, 19,17,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int limit = 11;
    cout << "Minimum positive divisor: " << minimum_positive_divisor(arr, n, limit) << endl;
    return 0;
}


/*
Why is low set to 1?
The divisor must be positive (>= 1), as division by 0 is undefined.
The smallest possible divisor is 1, which would result in the highest possible sum (i.e., the sum of all elements in the array).
Why is high set to max_element(nums)?
The largest possible divisor that makes sense is the largest number in the array.
If we choose a divisor greater than the largest number, every element will round down to 1 (since ceil(x/x) = 1), and the sum of divisions will be exactly n (size of the array).
Setting high = max_element(nums) ensures that we consider the smallest divisor that achieves the required threshold.

*/