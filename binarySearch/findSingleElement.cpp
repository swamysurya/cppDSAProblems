#include <iostream>
#include <vector>

using namespace std;


int findSingleElement(vector<int> arr, int n){
    int low = 0, high = n - 1;
    int mid;

    while (low <= high){
        mid = low + (high - low)/2;
        // if mid not equal to left and right then that means its unique
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid -1]) return arr[mid];
        // if mid is even and its equal to its left our unique number is on right side
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) low = mid + 1;
        // if mid is odd and its equal to its right our unique number is on left side
        else high = mid - 1;
    }
    return -1;
}

// time complexity O(log n)
// space complexity O(1)

// this will work if no ubique elemetns are there
int findSingleElement2(vector<int> arr, int n){
    int low = 0, high = n - 1;
    int mid;

    while (low < high){
        mid = low + (high - low)/2;
        // we making mid is always even
        if (mid % 2 == 1){
            mid = mid - 1;
        };
        // so for the even index if mid value equals to its right then that means unique element is on the right side
        // (reson beacuse if mid value equal to to right means the left part before mid is not distribed (not distrubed means its not contains single element))
        // and if mid value equals to its left then that means unique element is on the left side
        if (arr[mid] == arr[mid + 1]){
            low = mid + 2;
        }else{
            high = mid;
        }
    }
    // This checks whether arr[low] is truly a unique element
    // If low == 0, arr[low] has no left neighbor → It's valid
    // Otherwise, it ensures arr[low] isn't equal to arr[low - 1] (i.e., it's not part of a pair)
    // if low == n - 1, arr[low] has no right neighbor → It's valid.
    // Otherwise, it ensures arr[low] isn't equal to arr[low + 1] (i.e., it's not part of a pair).
    if ((low == 0 || arr[low] != arr[low - 1]) && (low == n - 1 || arr[low] != arr[low + 1])) { 
        return arr[low];  // Valid single element
    }

    return -1;  // No single element found
}

// time complexity O(log n)
// space complexity O(1)


int main(){
    
    vector<int> arr= {1,1,2,2,3,3,4,4,5,5,7};
    int n = arr.size();
    int result = findSingleElement2(arr,n);
    cout << "Single element: " << result << endl;
    
}