#include <iostream>
#include <vector>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    vector<int> result;
    int i = 0, j = 0, k = 0;
    int m = nums1.size();
    int n = nums2.size();
    int p = nums3.size();
    // iterate through all three arrays
    while (i < m && j < n && k < p) { // Time complexity = O(m+n+p)
        // if all three elements are equal then add to result
        if (nums1[i] == nums2[j] && nums2[j] == nums3[k]) {
            result.push_back(nums1[i]);
            i++;
            j++;
            k++;
        // if nums1[i] is less than nums2[j] then increment i
        } else if (nums1[i] < nums2[j]) {
            i++;
        // if nums2[j] is less than nums3[k] then increment j
        } else if (nums2[j] < nums3[k]) {
            j++;
        // if nums3[k] is less than nums1[i] then increment k
        } else { // because if i > j and j > k then i > k
            k++;
        }

        // there no comapration between nums3[k] and nums1[i] 
        // because if i > j and j > k then i > k
    }

    return result;  
}

// Time complexity = O(m+n+p) (iterating through m+n+p elements)
// Space complexity = O(1) (no extra space is used)



int main(){
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {2,3,5,7,8,9};
    vector<int> nums3 = {3,5,6,7,8,9};
    vector<int> result = intersection(nums1,nums2,nums3);
    // expected output: 3 5
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
}