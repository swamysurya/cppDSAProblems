#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cowsCanPlace(vector<int> arr, int n, int c, int distance){
    int cowCount = 1; // already placed one cow
    int lastPosition = arr[0]; // last position of the cow
    for (int i = 1; i < n; i++){ // try to place the next cow from second position
        // if distance between current and previous stall is greater than or equal to the distance
        // then place the cow here and update the last position
        if (arr[i] - lastPosition >= distance){ 
            cowCount++; // increment the cow count
            lastPosition = arr[i]; // update the last position
        }
        if (cowCount >= c) return true; // if we placed all the cows then return true
    }
    return false; // if we cannot place all the cows then return false
}

int minimumDistanceBruteForce(vector<int> arr, int n, int c){
    sort(arr.begin(), arr.end());
    // the maximum possible distance is highest and lowest stall postions
    int ans = arr[n-1] - arr[0];
    for (int i = 1; i < n; i++){
        // if we cannot place all cows with this distance
        // then we need to return the previous distance
        if (cowsCanPlace(arr, n, c, i) == false){
            return (i-1);
        }
    }
    // else return the maximum distance
    return ans;
}

int minimumDistance(vector<int> arr, int n, int c){
    sort(arr.begin(), arr.end());
    int low = 1, high = arr[n-1] - arr[0];
    int mid;
    int ans = high; // the maximum possible distance is highest and lowest stall postions
    while (low <= high){
        mid = low + (high - low)/2; 
        // if we can place all cows with this distance
        // then we can try for a larger distance
        if (cowsCanPlace(arr, n, c, mid)) { 
            ans = mid;
            low = mid + 1;
        // if we cannot place all cows with this distance
        // then we need to try a smaller distance
        }else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n = 5;
    vector<int> arr = {5,8,3,9,6};
    int c = 3;

    int n2 = 10;
    vector<int> arr2 = {0, 4, 7, 8, 3, 5, 9,1,6,2};
    int c2 = 6;
    cout << "minimum distance: " << minimumDistanceBruteForce(arr,n,c) << endl;
    cout << "minimum distance: " << minimumDistance(arr,n,c) << endl;
    cout << "minimum distance: " << minimumDistance(arr2,n2,c2) << endl;
    return 0;
}

/*
n = 10, c = 6
arr = [0, 4, 7, 8, 3, 5, 9,1,6,2]

*/