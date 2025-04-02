
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;

int countStudents(vector<int>& arr, int maxPageCount){
    int n = arr.size();
    int pages = 0, studentCount = 1;
    for(int i = 0; i < n; i++){
        if (pages + arr[i] <= maxPageCount){
            pages += arr[i];
        }else{
            studentCount++;
            pages = arr[i];
        }
    }
    return studentCount;
}
int bookAllocation(vector<int>& arr, int k) {
    int ans,low,high,mid;
    low = *max_element(arr.begin(),arr.end());
    high = accumulate(arr.begin(), arr.end(),0);
    ans = low;
    while(low <= high){
        mid = low + (high - low)/2;
        if(countStudents(arr,mid) <= k){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n = 5;
    int k = 3;

    vector<int> arr = {50, 38, 23, 89, 76};
    int res = bookAllocation(arr, k);
    cout << "Minimum pages: " << res << endl;
    return 0;
}