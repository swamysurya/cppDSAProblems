#include<iostream>
#include<set>
using namespace std;

/**
 * Removes duplicate elements from the array and returns the count of unique elements.
 * The unique elements are moved to the beginning of the array.
 *
 * @param arr The input array of integers.
 * @param n The number of elements in the input array.
 * @return The count of unique elements in the array.
 */

int removeDuplicates(int arr[], int n){
    // set is used to store unique elements
    set<int> s;
    // insert all elements in set
    for(int i = 0; i < n; i++){ //Time complexity = O(n)
        s.insert(arr[i]); // Time complexity = O(logn)
    }
    // copy all elements from set to array
    int j = 0;
    for(int k: s) arr[j++] = k; // Time complexity = O(n)
    // return the size of set
    return s.size();
}

// Time complexity = O(nlogn) (inserting n elements in set)+ O(n) (copying n elements from set to array) = O(nlogn)

// Space complexity = O(n)

// optimal solution

int removeDuplicatesOptimal(int arr[], int n){
    // if array is empty return 0
    if (n == 0) return 0;
    // intialize i to 0
    int i = 0;
    // iterate from second element to last element
    
    for (int j = 1; j < n; j++){
        // if ith element is not equal to jth element
        // increment i and copy jth element to ith element
        // beacuse the ith element is hold place for unique elements
        // if ith element is not equal to jth element, then jth element is unique
        if (arr[i] != arr[j]){
            arr[++i] = arr[j];
        }
    }
    return i+1;
}

// Time complexity = O(n) (iterating through n elements) = O(n)
// Space complexity = O(1) (no extra space is used)

int main(){
    int n = 10;
    int arr[] = {3,1,5,2,2,4,7,9,8,10};
    int uniqueListEndIndex = removeDuplicatesOptimal(arr,n);\
    cout << uniqueListEndIndex << endl;
    for(int i = 0; i < uniqueListEndIndex; i++){
        cout << arr[i] << " "; 
    }
    cout << endl;
}