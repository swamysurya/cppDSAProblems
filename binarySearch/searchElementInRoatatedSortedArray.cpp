#include <iostream>
#include <vector>

using namespace std;

// this wont work for array which contains duplicates
int findElementInRoatedSortedArray(vector<int> arr, int n, int target){
    int res = -1;

    int low = 0;
    int high = n - 1;
    int mid;

    while(low <= high){
        mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        // find which list is sorted one
        // first if states left space before mid is sorted one
        if(arr[low] <= arr[mid]){
            // if the target within the left space range search only left space
            if(arr[low] <= target && target <= arr[mid]){
                high = mid - 1;
            // of find the right space
            }else{
                low = mid + 1;
            }
        // the if states the right space is sorted one
        }else if (arr[mid] <= arr[high]){
            // if target is found in the range search in right spaces
            if (arr[mid] <= target && target <= arr[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return res;
}

//this will work for array that contains duplicates
// [5,5,5,5,1,2,3,4,5] 
int findElementInRoatedSortedArray2(vector<int> arr, int n, int target){
    int low = 0, high = n-1;
    int mid;

    while (low <= high){
        mid = low + (high - low)/2;
        if (arr[mid] ==  target) return mid;
        // if the high low and mid values are same then redue search space on both end till if one of element not equal to other elements
        if (arr[mid] == arr[low] && arr[mid] == arr[high]){
            low = low + 1;
            high = high - 1;
        // if left part is sorted
        }else if (arr[low] <= arr[mid]){
            if (arr[low] <= target && target <= arr[mid]) high = mid - 1;
            else low = mid + 1;
        }else if (arr[mid] <= arr[high]){
            if (arr[mid] <= target && target <= arr[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}



int main(){
    vector<int> arr = {5,5,6,7,1,2,3,4,5,5,5,5};
    int n = arr.size();
    int target = 41;
    int indexOfTarget = findElementInRoatedSortedArray2(arr,n,target);
    cout << "Index of element " << indexOfTarget << endl;
}