// file : countNoOfOccuranceOfaElement.cpp
#include <iostream>
#include <vector>
using namespace std;
#include "functions.h"


int countNoOfOccuranceOfaElement(vector<int>& arr, int target) {
    int first = findFirstOccurence(arr, target);
    int last = findLastOccurence(arr, target);
    
    if (first == -1) return 0;
    return (last - first + 1);
}

// time complexity : O(log n) + O(log n) = O(log n)
// space complexity : O(1)

int main(){
    vector<int> arr = {5,7,7,8,8,10};
    int target = 8;
    cout << "no of occurence " <<countNoOfOccuranceOfaElement(arr,target) << endl;
    return 0;
}