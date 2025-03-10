#include <iostream>
using namespace std;

// Function to find the ceiling of a target value in a sorted array
int ceilOfTarget(int arr[], int n, int target) {
    int low, high, mid;
    low = 0; // Initialize the lower bound
    high = n - 1; // Initialize the upper bound
    int ans = -1; // Variable to store the ceiling value

    // Perform binary search
    while (low <= high) {
        mid = low + (high - low) / 2; // Calculate mid index
        if (arr[mid] >= target) { // If mid element is greater than or equal to target
            ans = arr[mid]; // Update the ceiling value
            high = mid - 1; // Move the upper bound down
        } else {
            low = mid + 1; // Move the lower bound up
        }
    }
    return ans; // Return the ceiling value
}

// Function to find the floor of a target value in a sorted array
int floorOfTarget(int arr[], int n, int target) {
    int low, high, mid;
    low = 0; // Initialize the lower bound
    high = n - 1; // Initialize the upper bound
    int ans = -1; // Variable to store the floor value

    // Perform binary search
    while (low <= high) {
        mid = low + (high - low) / 2; // Calculate mid index
        if (arr[mid] <= target) { // If mid element is less than or equal to target
            ans = arr[mid]; // Update the floor value
            low = mid + 1; // Move the lower bound up
        } else {
            high = mid - 1; // Move the upper bound down
        }
    }
    return ans; // Return the floor value
}
    
// Main function to demonstrate the ceiling and floor functionalities
int main() {
    const int n = 5; // Size of the array
    int target = 12; // Target value to find the ceiling and floor for
    int arr[n] = {5, 10, 15, 20, 25}; // Sorted array

    // ceil : find index of first element >= target (lower bound)
    //floor : find index of first element <= target 

    // Find the ceiling and floor of the target
    int ciel = ceilOfTarget(arr, n, target); // Function to find the ceiling of a target value in a sorted array : output : 10
    int floor = floorOfTarget(arr, n, target); // Function to find the floor of a target value in a sorted array : output : 15

    // Output the results
    cout << "Floor of " << target << " is " << floor << endl;
    cout << "Ceil of " << target << " is " << ciel << endl;

    return 0; // Return success
}