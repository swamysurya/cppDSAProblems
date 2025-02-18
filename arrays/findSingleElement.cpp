#include <iostream>
#include <algorithm>
#include <map>
using namespace std;    

/**
 * Finds the single element in an array of size n which is present only once.
 * The input array is expected to contain pairs of duplicate elements, except for the single element.
 * The function returns the single element if found, -1 otherwise.
 *
 * The function iterates through the array, comparing each pair of elements. If the pair is not equal, then the first element of the pair is the single element and is returned. If all pairs are equal, then the function returns -1.
 *
 * @param arr The input array of integers.
 * @param n The number of elements in the input array.
 * @return The single element if found, -1 otherwise.
 */

int findSingleElement(int arr[], int n){
    sort(arr,arr+n);
    int i = 0, j = 1;
    while (j < n){
        if (arr[i] != arr[j]){
            return arr[i];
        }
        i += 2;
        j += 2;
    }
    return -1;
}

// Time complexity = O(nlogn) + O(n) = O(nlogn)
// Space complexity = O(1) (no extra space is used)

// using hashmap
int findSingleElementUsingHashMap(int arr[], int n){
    unordered_map<int, int> hashmap;
    for (int i = 0; i < n; i++){ // Time complexity = O(n)
        hashmap[arr[i]]++; 
    }
    for (int i = 0; i < n; i++){ // Time complexity = O(n)
        if (hashmap[arr[i]] == 1){
            return arr[i];
        }
    }
    return -1;
}   

// Time complexity = O(n)
// Space complexity = O(n)

int findSingleElementUsingMap(int arr[], int n){
    map<int, int> hashmap; // here map is used
    for (int i = 0; i < n; i++){ // Time complexity = O(n)
        hashmap[arr[i]]++; 
    }
    for (int i = 0; i < n; i++){ // Time complexity = O(n)
        if (hashmap[arr[i]] == 1){
            return arr[i];
        }
    }
    return -1;
}   

// Time complexity = O(n * log n)
// Space complexity = O(n)


//optimized approach
int findSingleElementOptimized(int arr[], int n){
    int unique = 0;
    for (int i = 0; i < n; i++){
        unique ^= arr[i];
    }
    return unique;
}
// Time complexity = O(n)
// Space complexity = O(1) (no extra space is used)

/*
We XOR all elements step by step:

Step	XOR Computation	Result
Start	unique = 0	0
1st XOR	0 ^ 2	2
2nd XOR	2 ^ 3	1
3rd XOR	1 ^ 5	4
4th XOR	4 ^ 3	7
5th XOR	7 ^ 2	5
*/



int main(){
    const int n = 9;
    int arr[n] = {1,2,3,4,5,5,1,2,3};
    // int result = findSingleElement(arr,n);
    int result = findSingleElementUsingMap(arr,n);
    cout << "Single element: " << result << endl;
    
}