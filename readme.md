# **Problem Statement: Efficient Array Rotations**

## **Problem Description**

Given an array of size `n`, perform a series of rotations based on the given values of `x` and `y`:

- `x` represents the number of **right rotations**.
- `y` represents the number of **left rotations**.

Your task is to determine the **minimum** number of left rotations needed to bring the array to its final rotated position after applying both `x` right rotations and `y` left rotations. Implement an efficient approach to achieve this in `O(n)` time complexity.

## **Input Format**

- An integer `n` (size of the array).
- An array of `n` integers.
- Two integers `x` (number of right rotations) and `y` (number of left rotations).

## **Output Format**

- Print the modified array after applying the optimal rotations.

## **Constraints**

- `1 <= n <= 10^5`
- `1 <= arr[i] <= 10^9`
- `0 <= x, y <= 10^9`

## **Examples**

### **Example 1**

**Input:**

```
6
7 8 9 10 11 12
3 2
```

**Output:**

```
10 11 12 7 8 9
```

**Explanation:**

- 3 right rotations: `[10, 11, 12, 7, 8, 9]`
- 2 left rotations: `[10, 11, 12, 7, 8, 9]` (same as above, so only left rotations needed)

### **Example 2**

**Input:**

```
5
1 2 3 4 5
2 3
```

**Output:**

```
4 5 1 2 3
```

**Explanation:**

- 2 right rotations: `[4, 5, 1, 2, 3]`
- 3 left rotations: `[4, 5, 1, 2, 3]` (same as above, so only left rotations needed)

## Comparison of Functionality

### lowerAndUpperBounds.cpp

- **Purpose**: Implements functions to find the **lower bound** and **upper bound** of a target value in a sorted array.
  - **Lower Bound**: The index of the first element that is **greater than or equal to** the target.
  - **Upper Bound**: The index of the first element that is **greater than** the target.

### ceilTheFloor.cpp

- **Purpose**: Implements functions to find the **ceiling** and **floor** of a target value in a sorted array.
  - **Ceiling**: The smallest element that is **greater than or equal to** the target.
  - **Floor**: The largest element that is **less than or equal to** the target.

### Key Differences

1. **Implementation**: Both files use binary search, but they serve different purposes and return different types of results (indices vs. values).
2. **Return Values**:
   - Functions in [lowerAndUpperBounds.cpp](cci:7://file:///home/manikanta/Desktop/GIT/cPlusPLus/binarySearch/lowerAndUpperBounds.cpp:0:0-0:0) return indices.
   - Functions in [ceilTheFloor.cpp](cci:7://file:///home/manikanta/Desktop/GIT/cPlusPLus/binarySearch/ceilTheFloor.cpp:0:0-0:0) return actual values from the array.

### Summary

While both files utilize binary search techniques and deal with sorted arrays, they focus on different aspects of searching:

- [lowerAndUpperBounds.cpp](cci:7://file:///home/manikanta/Desktop/GIT/cPlusPLus/binarySearch/lowerAndUpperBounds.cpp:0:0-0:0) is concerned with finding indices (bounds).
- [ceilTheFloor.cpp](cci:7://file:///home/manikanta/Desktop/GIT/cPlusPLus/binarySearch/ceilTheFloor.cpp:0:0-0:0) is focused on finding the actual values (ceiling and floor).
