#include <iostream>
#include<cmath>
#include <numeric> // for acumulate
#include <vector>
#include <algorithm>

using namespace std;

bool isItMinCapacityToTransportAllParcels(vector <int> arr, int n, int minCapacity, int minDays){
    int countDays = 1;
    int weight = 0;
    for(int i = 0; i < n; i++){
        // if you add curent weight which exeeds the minCapacity we move the package to next day
        if (weight + arr[i] > minCapacity){
            countDays+= 1;
            weight = arr[i];
        }else{
            // otherwise we keep on adding the weights
            weight += arr[i];
        }
    }
    return countDays <= minDays;
}




int minCapacityToTransport(vector <int> arr, int n, int days){
    //ship’s minimum possible capacity must be at least the weight of the heaviest package.
    int low = *min_element(arr.begin(),arr.end()); // time complexcity = O(n)
    int mid;
    //If we had just one day (D = 1), we would need to ship all packages at once.
    int high = accumulate(arr.begin(),arr.end(),0); // time complexcity = O(n)
    int ans = high;
    while (low <= high){
        mid = low + (high - low)/2;
        // if countDays is less means there is possible minWeight of the left of mid;
        if(isItMinCapacityToTransportAllParcels(arr,n,mid,days)){ // // time complexcity = O(n)
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

// time complexcity: O(Nlog(sum(weights)))
// space complexcity: O(1)

int main(){
    vector <int> arr = {2, 6, 9, 7, 8, 3, 5,6,10,9};
    int n = arr.size();
    int days = 8;
    int res = minCapacityToTransport(arr,n,days);
    cout << "Minimum capacity: " << res << endl;
}



/*
imp observations
Why is low = *max_element(weights.begin(), weights.end())?
The ship’s minimum possible capacity must be at least the weight of the heaviest package.
If we choose a lower capacity than the heaviest package, it would be impossible to transport that package in any number of days.

Why is high = accumulate(weights.begin(), weights.end(), 0)?
The maximum possible capacity is the sum of all package weights.
If we had just one day (D = 1), we would need to ship all packages at once.

Initialize requiredDays = 1 because shipping starts on day 1

*/