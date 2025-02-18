#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*************  ✨ Codeium Command ⭐  *************/
/**
 * Finds the duplicate element in a vector of integers.
 *
 * The function first sorts the vector in ascending order and then iterates through it to find any consecutive
 * elements that are equal. If such a pair is found, the function returns the duplicate element. If no duplicate
 * is found, it returns -1.
 *
 * @param nums A reference to a vector of integers in which to find a duplicate.
 * @return The duplicate element if found, otherwise -1.
 */

/******  affe7760-3346-4c0c-99b3-0f794f1d8c4c  *******/
int findDuplicate(vector<int> &nums){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = 0;
    while (i < n - 1)
    {
        if (nums[i] == nums[i + 1])
            return nums[i];
        i++;
    }
    return -1;
}

// Time complexity = O(n)
// Space complexity = O(n)


// optimized solution
// storing the count of each element
// if count > 1 return the element
int findDuplicateOptimized(vector<int> &nums){
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++){ // Time complexity = O(n)
        map[nums[i]]++; // Time complexity = O(1)
        if(map[nums[i]] > 1) return nums[i];
    }
    return -1;
}

// Time complexity = O(n)
// Space complexity = O(n)

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 5, 6, 7, 8};
    // int res = findDuplicate(nums);
    int res = findDuplicateOptimized(nums);
    cout << "duplicate element is: " << res << endl;
}