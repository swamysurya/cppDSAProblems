#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer array nums and two integers minK and maxK,
return the number of subarrays if maxvalue in the subarray is in the range [minK, maxK].
A subarray is a contiguous part of an array.

example:
Input: nums = [3,2,5,4], minK = 3, maxK = 4
Output: 3
total subarrays = 
[3] = valid
[3,2] = valid
[3,2,5]
[3,2,5,4]
[2] 
[2,5]
[2,5,4]
[5]
[5,4]
[4] = valid
valid subarrays = [3] [3,2] [4].
*/

int countSubarrays(vector<int>& nums, int minK, int maxK) {
    int count = 0; // count of valid subarrays
    int left = 0; // Tracks the last index where arr[left] > maxBound (invalid reset point).
    int right = 0; // Tracks the last index where arr[i] >= minBound (valid boundary).
    int preCount = 0; 
    // iterate till end of array
    while(right < nums.size()){
        // if current element is in range [minK, maxK] 
        // calculate the number of valid subarrays ending at index right [read below description]
        if (minK <= nums[right] && nums[right] <= maxK){
            // how right - left + 1 gives no of subarrays at index right
            preCount = right - left + 1;
        // if current element is greater than maxK reset the count and left pointer
        }else if (nums[right] > maxK){
            preCount = 0;
            left = right+1;
        }   
        // add the no of valid subarrays at index right to count
        // precount give no of sub arrays till index right
        // count calculate the total no of pre count(valid subarrays) 
        // the preCount set to zero when current element is greater than maxK means the with includes that number we unable to form valid subarray
        count += preCount;
        right++;
    }
    return count;
}

// time complexity = O(n) (iterating through n elements) = O(n)
// space complexity = O(1) (no extra space is used)

int main(){
    vector<int> nums = {3,2,5,4};
    int minK = 3;
    int maxK = 4;
    cout << countSubarrays(nums, minK, maxK) << endl;
    return 0;
}


/*
This is How j - i + 1 give no of subarrays at index j
example:
nums = [3,2,5,4]
        i
        j
i = 0 j = 0
no of subarrays ending at index 0 = j - i + 1 = 0 - 0 + 1 = 1  => [3]   total = 1

nums = [3,2,5,4]
        i j
i = 0 j = 1
no of subarrays ending at index 1 = j - i + 1 = 1 - 0 + 1 = 2  => [3] [2] [3,2] total = 3

nums = [3,2,5,4]
        i   j
i = 0 j = 2
no of subarrays ending at index 2 = j - i + 1 = 2 - 0 + 1 = 3  => [3] [2] [3,2] [2,5] [3,2,5] [5] total = 6

nums = [3,2,5,4]
        i     j
i = 0 j = 3
no of subarrays ending at index 3 = j - i + 1 = 3 - 0 + 1 = 4  => [3] [2] [3,2] [2,5] [3,2,5] [5] [4] [5,4] [2,5,4] [3,2,5,4] total = 10

*/