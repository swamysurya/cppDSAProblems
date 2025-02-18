#include <iostream>
#include <vector>
using namespace std;


/**
 * Computes the intersection of two sorted arrays.
 *
 * This function takes two sorted arrays `arr1` and `arr2` along with their sizes `n1` and `n2` as input,
 * and returns a vector containing the common elements in both arrays. The resulting vector is sorted and 
 * does not contain duplicate elements.
 *
 * @param arr1 The first sorted array.
 * @param arr2 The second sorted array.
 * @param n1 The number of elements in the first sorted array.
 * @param n2 The number of elements in the second sorted array.
 * @return A sorted vector containing the intersection of elements from both `arr1` and `arr2`.
 */

vector<int> intersectionOfTwoSortedArray(int arr1[], int arr2[], int n1, int n2) {
    int i = 0;
    int j = 0;
    // i and j are pointers to arr1 and arr2
    // n1 and n2 are sizes of arr1 and arr2
    // result is the resultant vector
    vector<int> result;
    // iterate through both arrays until one of them is exhausted
    while (i < n1 && j < n2) {
        // if the i-th element of the first array is equal to the j-th element of the second array
        // then copy the i-th element to the result vector
        if (arr1[i] == arr2[j]) {
            result.push_back(arr1[i]);
            i++;
            j++;
        // if the i-th element of the first array is less than the j-th element of the second array
        // then increment i
        } else if (arr1[i] < arr2[j]) {
            i++;
        // if the j-th element of the second array is less than the i-th element of the first array
        // then increment j
        } else {
            j++;
        }
    }
    return result;
}

// Time complexity = O(m+n) (iterating through m+n elements)
// Space complexity = O(min(m,n)) (using a vector to store the intersection elements)

// brute force approach
vector<int> intersectionOfTwoSortedArrayBruteForce(int arr1[], int arr2[], int n1, int n2) {
    vector<int> result;
    // create a temporary array to store the elements of the second array
    vector<int> temp(n2, 0);
    // iterate through the first array
    for (int i = 0; i < n1; i++) {
        // iterate through the second array
        for (int j = 0; j < n2; j++) {
            // if both elements are equal and the element is not already added to the result
            // then add the element to the result and mark it as added in the temporary array
            // reason for using temp array is to avoid adding duplicate elements to the result
            //The temp[j] = 0 is used to keep track of the elements in arr2 that have already been found in arr1
            if (arr1[i] == arr2[j] && temp[j] == 0) {
                result.push_back(arr1[i]);
                temp[j] = 1;
                break;
            }
            // if the element in the first array is less than the element in the second array
            // why break here?
            // because the array is sorted and if the element in the first array is less than the element in the second array
            // then the element in the second array must be greater than or equal to the element in the first array
            // so there is no need to check the remaining elements in the second array
            // because they are greater than the element in the first array
            // so we can break out of the loop and move to the next element in the first array
            if (arr1[i] < arr2[j]) break;
        }
    }
    return result;
}

// Time complexity = O(m*n) (iterating through m*n elements)
// Space complexity = O(2n) (using a vector to store the intersection elements and a temporary array)

int main(){
    int n1 = 5;
    int n2 = 6;
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {2,3,5,7,8,9};
    // vector<int> result = intersectionOfTwoSortedArray(arr1,arr2,n1,n2);
    vector<int> result = intersectionOfTwoSortedArrayBruteForce(arr1,arr2,n1,n2);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
}