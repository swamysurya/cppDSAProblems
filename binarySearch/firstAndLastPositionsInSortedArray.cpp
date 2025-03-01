// file : firstAndLastPositionsInSortedArray.cpp
#include <iostream>
#include <vector>
using namespace std;
#include "functions.h"


// brute force apporach
vector<int> firstAndLastPosition(vector<int> &arr, int target) {
    int first = -1;
    int last = -1;
    // itereate over the vector
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) { // if target found
            if (first == -1) first = i; // update the first only if not found
            last = i; // keep updating the last till the target matches
        }
    }
    return {first, last};
}

//time complexity = O(n)
//space complexity = O(1)

// function to find the first position of the target
int findFirstOccurence(vector<int> &arr, int target) {
    int first = -1;
    int low = 0;
    int high = arr.size() - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == target) { 
            // if target found there will be a posibility of first occurence of target will be in left side
            // to check that we will move high to mid - 1
            first = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            // if target is greater than mid search space will move to right
            low = mid + 1;
        } else {
            // if target is less than mid search space will move to left
            high = mid - 1;
        }
    }
    return first;
}

//time complexity = O(log n)
//space complexity = O(1)

int findLastOccurence(vector<int> &arr, int target) {
    int last = -1;
    int low = 0;
    int high = arr.size() - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            // if target found there will be a posibility of last occurence of target will be in right side
            // to check that we will move low to mid + 1
            last = mid;
            low = mid + 1;
        } else if (arr[mid] < target) {
            // if target is greater than mid search space will move to right
            low = mid + 1;
        } else {
            // if target is less than mid search space will move to left
            high = mid - 1;
        }
    }
    return last;
}   

//time complexity = O(log n)
//space complexity = O(1)

// optimal approach
vector<int> firstAndLastPositionOptimal(vector<int> &arr, int target) {
    // to find the first position of the target
    int first = findFirstOccurence(arr, target);
    int last = findLastOccurence(arr, target);
    return {first, last};
}

// by using lower bound concept we can also find the first and last position in O(log n) time complexity
vector<int> firstAndLastPositionUsingLowerBound(vector<int> &arr, int target) {
    int first = lower_bound_builtIn(arr, target);
    int last = lower_bound_builtIn(arr, target+1) - 1;
    if (first < arr.size() && arr[first] == target) {
        return {first, last};
    }
    return {-1, -1};
}

// int main() {
//     vector<int> arr = {5, 7, 7, 8, 8, 10};
//     int target = 8;
//     vector<int> result = firstAndLastPosition(arr, target);
//     cout << "first occurence " <<result[0] << endl;
//     cout << "last occurence " <<result[1] << endl;

//     vector<int> result2 = firstAndLastPositionOptimal(arr, target);
//     cout << "first occurence " <<result2[0] << endl;
//     cout << "last occurence " <<result2[1] << endl;
//     return 0;
// }


