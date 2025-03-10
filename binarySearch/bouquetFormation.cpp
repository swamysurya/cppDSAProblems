#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Statement:
 * ------------------
 * Given an array `arr` where `arr[i]` represents the day on which the ith flower blooms, 
 * you need to determine the minimum number of days required to form `m` bouquets.
 * Each bouquet requires exactly `k` **consecutive** bloomed flowers.
 *
 * If it is impossible to form `m` bouquets, return `-1`.
 *
 * Constraints:
 * ------------
 * - 1 ≤ n ≤ 10^5 (size of the array)
 * - 1 ≤ arr[i] ≤ 10^9 (bloom days)
 * - 1 ≤ m, k ≤ 10^5
 *
 * Example Test Cases:
 * -------------------
 * Test Case 1:
 * Input: arr = [5, 3, 3, 7, 2, 4, 6], m = 2, k = 3
 * Output: 4
 *
 * Test Case 2:
 * Input: arr = [1, 10, 3, 10, 2], m = 3, k = 1
 * Output: 3
 */

/**
 * Function to check if it is possible to form `m` bouquets 
 * with `k` consecutive flowers within `mid` days.
 * 
 * @param arr Blooming days of flowers
 * @param m Number of bouquets required
 * @param k Number of consecutive flowers needed for a bouquet
 * @param mid The maximum day allowed for picking flowers
 * @return true if `m` bouquets can be formed within `mid` days, false otherwise
 */
bool possibleToGetBouquet(vector<int> arr, int m, int k, int mid) {
    int flowers = 0, bouquet = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // If the flower blooms on or before `mid` days, we can pick it
        if (arr[i] <= mid) {
            flowers++;  // Pick the flower
            
            // If we have `k` consecutive flowers, we can form a bouquet
            if (flowers == k) {
                bouquet++;  // Bouquet prepared
                flowers = 0;  // Reset flower count for the next bouquet
            }
        } else {
            // If a flower is not ready, reset consecutive flower count
            flowers = 0;
        }
    }
    
    // Check if we can make at least `m` bouquets
    return bouquet >= m;
}



int main() {
    vector<int> arr = {5, 3, 3, 7, 2, 4, 6}; // Blooming days of flowers
    int m = 2;  // Number of bouquets required
    int k = 3;  // Number of consecutive flowers per bouquet

    // Edge case: If total flowers available are less than required
    if (m * k > arr.size()) {
        cout << "-1" << endl; // Not enough flowers to form `m` bouquets
        return 0;
    }

    // The lowest possible day to start picking flowers
    int low = *min_element(arr.begin(), arr.end());

    // The highest possible day, where all flowers have bloomed
    int high = *max_element(arr.begin(), arr.end());

    int ans = -1;  // Variable to store the minimum number of days required
    int mid;

    // Perform Binary Search to find the minimum possible days
    while (low <= high) {
        mid = low + (high - low) / 2;

        // If it's possible to form `m` bouquets within `mid` days
        if (possibleToGetBouquet(arr, m, k, mid)) { // time complexity: O(n)
            ans = mid;  // Store the current answer
            high = mid - 1;  // Move left to find a smaller valid day
        } else {
            low = mid + 1;  // Move right as we need more days
        }
    }

    cout << "Minimum days required to form " << m << " bouquets: " << ans << endl;
    return 0;
}

// Time Complexity: O(n⋅log max(bloomDay))
// Space Complexity: O(1)

// LeetCode Problem #1482.