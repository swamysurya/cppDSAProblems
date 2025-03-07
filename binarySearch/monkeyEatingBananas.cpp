#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
// Brute Force approach
int minimumHoursToFinishBruteForce(vector<int> arr, int n, int h){
    // max value nothing but max possible speed of monkey(read below)
    int max = *max_element(arr.begin(), arr.end());
    // loop calculate hours take by monkey for each speed
    for (int m = 1; m < max; m++){
        long long currHours = 0;
        for(int i = 0;i < n; i++){
            currHours += (arr[i] + m -1)/m ;// which is similar to ceil((double)arr[i]/(double)i)
        }
        // if total hours taken by monkey for all bananas is less than given hours then return that speed
        if (currHours <= h){
            return m;
        }
    }
    return -1;
}

// time complexcity = O(n max(arr))
// space complexcity = O(1)

int minimumHoursToFinishBinarySearch(vector<int> arr, int n, int h){
    int low = 1, high = *max_element(arr.begin(), arr.end());
    int mid, ans = high;

    while (low <= high){
        mid = low + (high - low)/2;

        long long currHours = 0;
        // calculate currHours based on mid 
        for(int i = 0; i < n; i++){
            currHours += (arr[i] + mid - 1)/mid; // which is similar to ceil((double)arr[i]/(double)i)
        }

        // if total hours taken by monkey for all bananas is less than given hours store the speed 
        // and there is posbile speed on left side so adjust the high 
        if (currHours <= h){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

// time complexcity = O(n log max(arr))
// space complexcity = O(1)

int main(){
    int n = 4, h = 10;
    vector<int> arr = {2,8,4,6};
    int res = minimumHoursToFinishBinarySearch(arr,n,h);
    cout << " minimum 'm': " << res << endl;
}


/*
Why Choose high = max_element(arr, arr + n)?
What does high represent?

high represents the maximum possible speed Koko can eat at.
The fastest she could ever eat is if she eats an entire pile in 1 hour.
Since the largest pile contains max_element(arr, arr + n) bananas, if she eats at this speed, she will finish that pile in exactly 1 hour.
What happens if high is greater than max_element(arr, arr + n)?

Any speed greater than the largest pile size is unnecessary.
Suppose the largest pile has 7 bananas. If Koko eats at speed 8, she still finishes it in 1 hour, just like speed 7. So, checking values greater than 7 is pointless.

*/