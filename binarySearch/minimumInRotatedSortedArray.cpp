#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Function to find the minimum element in a rotated sorted array
int minimumInRoatedSortedArray(vector<int> arr) {
    // Get the size of the array
    int n = arr.size();
    
    // Initialize pointers for binary search
    int low = 0, high = n - 1;
    
    // Variable to store the minimum value found
    int minValue = INT_MAX;

    // Perform binary search
    while (low <= high) {
        // Calculate the middle index
        int mid = low + (high - low) / 2;
        
        // Check if the left half is sorted
        if (arr[low] <= arr[mid]) {
            // If left half is sorted, the minimum value must be in the right half or at low
            minValue = min(minValue, arr[low]);  // Update minValue if arr[low] is smaller
            low = mid + 1;  // Search in the right half
        }
        // Check if the right half is sorted
        else if (arr[mid] <= arr[high]) {
            // If right half is sorted, the minimum value must be in the left half or at mid
            minValue = min(minValue, arr[mid]);  // Update minValue if arr[mid] is smaller
            high = mid - 1;  // Search in the left half
        }
    }
    
    // Return the smallest value found
    return minValue;
}

// time complexity : O(log n)
// space complexity : O(1)

// note : The smallest element will always be in the unsorted half of the array
int minimumInRoatedSortedArrayOptimised(vector<int> nums){
    int left = 0, right = nums.size() - 1;
    int mid;
    while (left < right) {
        // Calculate mid-point to avoid integer overflow
        int mid = left + (right - left) / 2;

        // If the middle element is greater than the rightmost element,
        // it means the minimum element must be in the right half
        if (nums[mid] > nums[right]) {
            left = mid + 1; // Move left pointer to the right of mid
        } else {
            // Otherwise, the minimum element is in the left half or could be 'mid' itself
            right = mid;
        }
    }
    
    // At the end, 'left' and 'right' will point to the minimum element
    return nums[left];
}

// time complexity : O(log n)
// space complexity : O(1)



int main() {
    // Example array (rotated sorted array)
    vector<int> arr = {7, 3, 4, 5, 6};
    
    // Call the function to find the minimum element
    int res = minimumInRoatedSortedArray(arr);
    int res2 = minimumInRoatedSortedArrayOptimised(arr);
    // Output the result
    cout << "Minimum in array: " << res << endl;  // Expected output: 3
    cout << "Minimum in array: " << res2 << endl;  // Expected output: 3
}
