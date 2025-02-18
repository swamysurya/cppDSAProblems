#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



/**
 * Finds the first missing number in an array of size n which is in the range from 1 to maxElement.
 *
 * The function first sorts the array in ascending order, then iterates through the sorted array to find the first missing number.
 *
 * @param arr The input array of integers.
 * @param maxElement The maximum possible element in the array.
 * @param arrSize The number of elements in the input array.
 * @return The first missing number in the array.
 */
int findMissingNumber(int arr[], int maxElement, int arrSize){
    sort(arr,arr+arrSize);
    int currentVal = arr[0];    
    for(int i = 0; i < arrSize; i++){ // Time complexity = O(n)
        if(arr[i] != currentVal){
            return currentVal;
        }
        currentVal++;
    }
    return currentVal;
}

// Time complexity = O(n)
// Space complexity = O(1)

//optimized approach
int findMissingNumberByXor(int arr[], int maxElement){
    int xor1 = arr[0];
    int xor2 = 0;
    // beacause the array starts from 1
    // the end index is < maxElement-1 why becuase the one number is missing
    // if not missing the end index will be maxElement-1
    for (int i = 1; i < maxElement-1; i++){ // Time complexity = O(n)
        xor1 = xor1 ^ arr[i];
    }
    // xor2 is the xor of all the numbers from 1 to maxElement
    for (int i = 1; i <= maxElement; i++){ // Time complexity = O(n)
        xor2 = xor2 ^ i;
    }
    // xor1 ^ xor2 will give the missing number
    return xor1 ^ xor2;
 }

// Time complexity = O(n)
// Space complexity = O(1)


//brute force approach
int findMissingNumberBruteForce(int arr[],int maxElement){
    // iterate through all the numbers from 1 to maxElement
    for(int i = 1; i <= maxElement; i++){ // Time complexity = O(n)
        int present = 0;
        // check if the number is present in the array
        // if present then return the number
        for (int j = 0; j < maxElement-1; j++){ // Time complexity = O(n)
            if (arr[j] == i){
                present = 1;
                break;
            }
        }
        // if the number is not present in the array
        // return the number
        if (present == 0){
            return i;
        }
    }
    // if all the numbers are present in the array
    return -1;
    
}
// Time complexity = O(n^2)
// Space complexity = O(1)

int findMissingNumberByIndexingStoring(int arr[],int maxElement){
    // create a temp array of size maxElement+1
    int* temp = new int[maxElement]();
    // Remember to delete the allocated memory
    for(int i = 0; i < maxElement-1; i++){ // Time complexity = O(n)
        // mark the index of the number as 1
        temp[arr[i]] = 1;
    }
    // iterate through all the numbers from 1 to maxElement
    for(int i = 1; i <= maxElement; i++){ // Time complexity = O(n)
        // if the number is not present in the array
        // return the number
        if (temp[i] == 0){
            delete[] temp;
            return i;
        }
    }
    delete[] temp;
    return -1;
}

// Time complexity = O(n)
// Space complexity = O(n)

int findMissingNumberBySummation(int arr[],int maxElement){
    int sum1 = maxElement*(maxElement+1)/2;
    int sum2 = 0;
    for(int i = 0; i < maxElement-1; i++){ // Time complexity = O(n)
        sum2 += arr[i];
    }
    return sum1 - sum2;
}

int main(){
    int maxElement = 11; // max number in array
    // here the array always starts from 1 to n
    const int arraySize = 10;
    int arr[arraySize] = {1,2,3,5,6,7,8,9,10,11};
    // here one number is missing
    // this method works only if the array contains unique elements
    // Fails when duplicates are present.
    cout << "The missing number is: " << findMissingNumber(arr,maxElement,arraySize) << endl;
    // this method not works if the array contains duplicates
    //Fails when duplicates are present.
    //If duplicates exist, the XOR calculation is thrown off because the missing number gets lost in the extra duplicate values.
    cout << "The missing number is: " << findMissingNumberByXor(arr,maxElement) << endl;
    // if the array contains duplicates then use the brute force approach
    cout << "The missing number is: " << findMissingNumberBruteForce(arr,maxElement) << endl;
    // works for duplicates
    cout << "The missing number is: " << findMissingNumberByIndexingStoring(arr,maxElement) << endl;
    // fails when duplicates are present.
    cout << "The missing number is: " << findMissingNumberBySummation(arr,maxElement) << endl;
    return 0;
}
