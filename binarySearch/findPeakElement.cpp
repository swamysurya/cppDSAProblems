#include <iostream>
#include <vector>

using namespace std;

// Function to find a peak element in an array
// A peak element is an element which is greater than or equal to its neighbors.
// This function uses a binary search approach to find a peak element efficiently.

int findPeakElement(vector<int> arr, int n){
    // Initialize the search space to the entire array
    int low = 1, high = n - 2;
    int mid;

    // check start and end elements are peack elements
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n-1] > arr[n-2]) return n-1;

    // Perform binary search to find the peak element
    while (low <= high){
        // Calculate the middle index
        mid = low + (high - low)/2;

        // Check if the middle element is a peak
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) return mid;

        // If the middle element is greater than its left neighbor, 
        // then the peak must be on the right side
        if (arr[mid] > arr[mid - 1]) 
            low = mid + 1; 
        else 
            // Otherwise, the peak is on the left side (including mid)
            high = mid - 1;
    }
    return 0;
}

int main(){
    vector <int> arr = {1,2,3,4,5,6,2,1};
    int n = arr.size();

    int res = findPeakElement(arr,n);
    cout << "peak element of array: " << res << endl;
}

/*
Why does arr[mid] > arr[mid - 1] mean the peak is on the right?

If arr[mid] > arr[mid - 1], it means the slope is increasing.

This suggests that there might be a peak ahead (to the right).
Even if arr[mid] is not the peak, there's a chance that the sequence keeps rising to a peak further right.
*/

/*
Why Can We Use Binary Search in [1, 3, 5, 7, 6, 4, 2]?

The array first increases (1 → 3 → 5 → 7) and then decreases (7 → 6 → 4 → 2).
This structure ensures that at least one peak exists (a peak is an element greater than its neighbors).
Even though the entire array is not fully sorted, we can still apply binary search by looking at the relationship between arr[mid] and its neighbors.

*/