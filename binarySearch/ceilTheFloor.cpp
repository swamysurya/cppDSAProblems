#include <iostream>
using namespace std;

int ceilOfTarget(int arr[], int n, int target){
    int low,high,mid;
    low = 0;
    high = n-1;
    int ans = -1;
    while(low<=high){
        mid = low + (high - low)/2;
        if (arr[mid] <= target){
            low = mid + 1;
        }
        else{
            ans = arr[mid];
            high = mid - 1;
        }
    }
    return ans;
}

int floorOfTarget(int arr[], int n, int target){
    int low,high,mid;
    low = 0;
    high = n-1;
    int ans = -1;
    while(low<=high){
        mid = low + (high - low)/2;
        if (arr[mid] <= target){
            ans = arr[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
            
        }
    }
    return ans;
}




int main(){
    const int n = 5;
    int target = 12;
    int arr[n] = {5, 10, 15, 20, 25};
    int ciel = ceilOfTarget(arr, n, target);
    int floor = floorOfTarget(arr, n, target);
    cout << "Floor of " << target << " is " << floor << endl;
    cout << "Ceil of " << target << " is " << ciel << endl;
    cout << endl;
}