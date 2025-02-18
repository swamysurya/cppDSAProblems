# Learning Notes on C++ Techniques

## 1. Longest Subarray with Sum K

### Function: [longestSubarrayWithSumK](cci:1://file:///c:/GIT/cPlusPLus/arrays/longestSubArrayWithSumK.cpp:4:0-31:1)
- **Purpose**: Finds the length of the longest subarray whose sum equals `k`.
- **Approach**: Uses a hashmap to track cumulative sums and their indices.
- **Time Complexity**: O(n).

## 2. Shortest Subarray with Sum K

### Function: [shortestSubarrayWithSumK](cci:1://file:///c:/GIT/cPlusPLus/arrays/shortestSubArrayWIthSumK.cpp:5:0-22:1)
- **Purpose**: Finds the length of the shortest subarray whose sum equals `k`.
- **Approach**: Similar to the longest subarray, but minimizes the length.
- **Time Complexity**: O(n).

## 3. Sorted Squares of a Sorted Array

### Function: [sortedSquares](cci:1://file:///c:/GIT/cPlusPLus/arrays/squaredOfSortedArray.cpp:6:0-20:1)
- **Purpose**: Returns a sorted array of squares from the input array.
- **Approach**: Two-pointer technique to compare absolute values.
- **Time Complexity**: O(n).

## 4. Vectors in C++

### File: `vectors.cpp`
- **Key Concepts**:
  - Initialization of vectors.
  - Accessing elements using indexing and methods like `front()` and `back()`.
  - Modifying elements and adding new ones using `push_back()`.
  
## 5. Static and Dynamic Arrays

### File: `arrays.cpp`
- **Key Concepts**:
  - Initialization and iteration over static arrays.
  - Dynamic array allocation using `new`.
  - Sorting static arrays using [sort()](cci:1://file:///c:/GIT/cPlusPLus/arrays/squaredOfSortedArray.cpp:6:0-20:1).

## 6. Union of Two Sorted Arrays

### File: `unionOfTwoSortedArrays.cpp`
- **Purpose**: Merges two sorted arrays into one sorted array without duplicates.
- **Approach**: Uses a solution class method to implement the logic.
- **Expected Output**: Merged array.

## 7. Check if Array is Sorted

### File: `isSorted.cpp`
- **Purpose**: Checks if a given array is sorted.
- **Approach**: Iterates through the array to verify order.
- **Time Complexity**: O(n).
- **Space Complexity**: O(1).

## 8. Additional Techniques and Algorithms
- Further techniques may include searching algorithms, sorting methods, and data structure manipulations.
- Each algorithm typically has a specific time and space complexity that is essential for understanding its efficiency.

## Conclusion
These notes summarize various techniques and approaches used in C++ programming, particularly focusing on array and vector manipulations. Mastering these concepts can greatly enhance your problem-solving abilities in coding interviews and algorithm challenges.