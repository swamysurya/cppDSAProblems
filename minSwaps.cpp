#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int minSwaps(vector<int>& arr) {
    vector<int> v = arr; // clone the array 
    // sort the array 
    sort(v.begin(), v.end());
    // uses introsort (quick merge and insertion sort)
    
    unordered_map<int, int> map;
    for(int i = 0; i < v.size(); i++) {
        map[v[i]] = i; // first is index, second is value
    }
    
    int i = 0;
    int swapCount = 0;
    
    while (i < v.size()) {
        if (map[arr[i]] == i) {
            i++;
        } else { 
            swap(arr[i], arr[map[arr[i]]]);
            swapCount++;
        }
    }
    return swapCount;
}

int main() {
    vector<int> arr = {4, 5, 1, 2, 3};
    cout << "Original array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;
    
    int swaps = minSwaps(arr);
    
    cout << "Minimum swaps needed: " << swaps << endl;
    cout << "Array after swaps: ";
    for(int x : arr) cout << x << " ";
    cout << endl;
    
    return 0;
}