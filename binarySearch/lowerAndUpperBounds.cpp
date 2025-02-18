#include <iostream>
#include <algorithm>
using namespace std;

// implementation of upper bound in c++ using binary search
int upper_bound_builtIn(vector<int>& arr, int x) {
    int low = 0, high = arr.size();
    int ans = arr.size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x){
            low = mid + 1;
        }else{
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;  // Index where the first element > x is found
}

// implementation of lower bound in c++ using binary search
int lower_bound_builtIn(vector<int>& arr, int x) {
    int low = 0, high = arr.size();
    int n = arr.size();
    int ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}



int main(){

    int arr[] = {1,2,3,6,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 7;
    int target2 = 4;

    // calculate lower bound
    // lower_bound function takes (arr, arr+n, target) as arguments
    // The function returns an iterator pointing to this position where the element is greater than or equal to the target
    // After getting the iterator from lower_bound, you subtract arr from it. This operation calculates the index of the element pointed to by the iterator.
    // Essentially, lower_bound returns a pointer to the found position, and by subtracting arr, you get the index of that position in the original array.
    int lower = lower_bound(arr,arr+n, target) - arr;
    cout << "lower bound: " << lower << endl;
    // if element is greater than last element, it will return n

    // upper_bound function takes (arr, arr+n, target) as arguments
    // The function returns an iterator pointing to this position where the element is greater than the target
    // After getting the iterator from upper_bound, you subtract arr from it. This operation calculates the index of the element pointed to by the iterator.
    // Essentially, upper_bound returns a pointer to the found position, and by subtracting arr, you get the index of that position in the original array.
    int upper = upper_bound(arr,arr+n, target2) - arr;
    cout << "upper bound: " << upper << endl;

    
    // for vectors
    vector<int> arr2 = {1,2,3,6,8,9};
    int target3 = 7;
    int target4 = 4;
    int lower2 = lower_bound(arr2.begin(),arr2.end(), target3) - arr2.begin(); // time complexity is O(log n) 
    cout << "lower bound: " << lower2 << endl;
    int upper2 = upper_bound(arr2.begin(),arr2.end(), target4) - arr2.begin(); // time complexity is O(log n) 
    cout << "upper bound: " << upper2 << endl;

    // checkeing builtin functions
    int lower3 = lower_bound_builtIn(arr2, target3);
    cout << "lower bound: " << lower3 << endl;
    int upper3 = upper_bound_builtIn(arr2, target4);
    cout << "upper bound: " << upper3 << endl;


    /*
    Use of lower_bound Function
    The lower_bound function is primarily used in sorted arrays or sorted containers to efficiently 
    find the first element greater than or equal to a given value. It is useful in various scenarios, such as:
    */

    return 0;

}


/*
Use Case	Example
Finding the first element strictly greater than x	-> upper_bound(arr, x) returns the next larger element
Finding the count of occurrences of x	            -> upper_bound() - lower_bound()
Finding the next higher element in range queries	-> Used in competitive programming 
Finding first occurrence	                        -> Works faster than std::find() in sorted arrays
*/