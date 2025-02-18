#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;

// Function declarations from minSwaps.cpp
void radixSort(int arr[], int n);
void printArray(int arr[], int n);

// Helper function to check if array is sorted
bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) return false;
    }
    return true;
}

// Helper function to compare arrays
bool areArraysEqual(int arr1[], int arr2[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

void runTest(const char* testName, int arr[], int n) {
    cout << "\nRunning test: " << testName << endl;
    
    // Create a copy for std::sort comparison
    int* sortedArr = new int[n];
    std::copy(arr, arr + n, sortedArr);
    std::sort(sortedArr, sortedArr + n);
    
    // Create a copy for radix sort
    int* testArr = new int[n];
    std::copy(arr, arr + n, testArr);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    radixSort(testArr, n);
    
    cout << "After radix sort: ";
    printArray(testArr, n);
    
    // Verify sorting
    bool sortedCorrectly = isSorted(testArr, n);
    bool matchesStdSort = areArraysEqual(testArr, sortedArr, n);
    
    assert(sortedCorrectly && "Array is not sorted correctly!");
    assert(matchesStdSort && "Radix sort result doesn't match std::sort!");
    
    cout << "✓ Test passed!" << endl;
    
    delete[] sortedArr;
    delete[] testArr;
}

int main() {
    // Test 1: Basic test with small numbers
    {
        int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
        int n = sizeof(arr)/sizeof(arr[0]);
        runTest("Basic test with small numbers", arr, n);
    }
    
    // Test 2: Array with duplicates
    {
        int arr[] = {5, 2, 8, 5, 1, 9, 2, 8, 1, 3};
        int n = sizeof(arr)/sizeof(arr[0]);
        runTest("Array with duplicates", arr, n);
    }
    
    // Test 3: Already sorted array
    {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int n = sizeof(arr)/sizeof(arr[0]);
        runTest("Already sorted array", arr, n);
    }
    
    // Test 4: Reverse sorted array
    {
        int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        int n = sizeof(arr)/sizeof(arr[0]);
        runTest("Reverse sorted array", arr, n);
    }
    
    // Test 5: Array with all same elements
    {
        int arr[] = {4, 4, 4, 4, 4, 4, 4};
        int n = sizeof(arr)/sizeof(arr[0]);
        runTest("Array with all same elements", arr, n);
    }
    
    // Test 6: Large numbers
    {
        int arr[] = {999999, 888888, 777777, 666666, 555555};
        int n = sizeof(arr)/sizeof(arr[0]);
        runTest("Large numbers", arr, n);
    }
    
    // Test 7: Single element array
    {
        int arr[] = {42};
        int n = sizeof(arr)/sizeof(arr[0]);
        runTest("Single element array", arr, n);
    }
    
    // Test 8: Empty array
    {
        int arr[] = {};
        int n = 0;
        runTest("Empty array", arr, n);
    }
    
    // Test 9: Random large array
    {
        const int n = 1000;
        int* arr = new int[n];
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000000);
        
        for(int i = 0; i < n; i++) {
            arr[i] = dis(gen);
        }
        
        runTest("Random large array", arr, n);
        delete[] arr;
    }

    cout << "\nAll tests passed successfully!" << endl;
    return 0;
}
