#include <iostream>
using namespace std;    


/**
 * Removes all but two of each duplicate element from the array and returns the count of unique elements.
 * The unique elements are moved to the beginning of the array.
 *
 * @param arr The input array of integers.
 * @param n The number of elements in the input array.
 * @return The count of unique elements in the array.
 */
int removeDupliates2(int arr[], int n) {
    // if array is empty return 0
    if (n == 0) return 0;
    // intialize i to 0
    int i = 1;
    // iterate from second element to last element
    int count = 1;
    
    for (int j = 1; j < n; j++) {
        // if jth element is equal to j-1th element increment count
        // else count is 1
        if (arr[j] == arr[j-1]) count++;
        else count = 1;
        // if count is less than or equal to 2, copy jth element to ith element
        if (count <= 2) arr[i++] = arr[j];
    }
    return i;
}   
/*

Algorithm for removeDuplicates2:
1. If the array is empty, return 0.
2. iterate through the array from the second element to the last element.
use a count variable to keep track of the number of times the current element has occurred.
3. If the current element is equal to the previous element, increment the count.
4. If the count is less than or equal to 2, copy the current element to the ith position in the array.
5. Return the value of i, which is the index of the last unique element in the array.

*/

// Time complexity = O(n) (iterating through n elements) = O(n)
// Space complexity = O(1) (no extra space is used)


int main() {
    const int n = 17;
    cout << "Original array: ";
    int arr[n] = {1,1,1,2,2,2,3,3,3,3,3,5,5,5,8,9,9};

    int endIndexOfUniqueList = removeDupliates2(arr,n);
    // print the unique list
    cout << "End index of unique list: " << endIndexOfUniqueList << endl;
    for (int i = 0; i < endIndexOfUniqueList; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}