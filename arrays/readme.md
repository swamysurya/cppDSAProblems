### 1. Function: `rotateArrayKtimes`

**Question Name:** Rotate Array K Times

**Description:** Rotate the given array by `k` times to the left.

**Test Cases:**

- **Input:** `arr = [1, 2, 3, 4, 5], k = 2`  
  **Output:** `[3, 4, 5, 1, 2]`
- **Input:** `arr = [1, 2, 3], k = 4`  
  **Output:** `[2, 3, 1]`

**Detailed Algorithm:**

1. If `k` is greater than `n`, set `k = k % n`.
2. Create a temporary array of size `k`.
3. Store the first `k` elements in the temporary array.
4. Shift the remaining elements of the original array to the left by `k` positions.
5. Copy the elements from the temporary array back to the original array starting from index `n-k`.

**Time Complexity:** O(n)  
**Space Complexity:** O(k)

---

### 2. Function: `countSubarrays`

**Question Name:** Count Subarrays with Bounded Maximum

**Description:** Count the number of subarrays where the maximum value is within the range `[minK, maxK]`.

**Test Cases:**

- **Input:** `nums = [3, 2, 5, 4], minK = 3, maxK = 4`  
  **Output:** `3`
- **Input:** `nums = [1, 2, 3], minK = 1, maxK = 3`  
  **Output:** `6`

**Detailed Algorithm:**

1. Initialize `count`, `left`, and `right` pointers.
2. Iterate through the array using the `right` pointer.
3. If the current element is within `[minK, maxK]`, calculate the number of valid subarrays ending at `right`.
4. If the current element is greater than `maxK`, reset `left` to `right + 1`.
5. Return the total count of valid subarrays.

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

### 3. Function: `findDuplicate`

**Question Name:** Find Duplicate Element

**Description:** Find the duplicate element in a vector of integers.

**Test Cases:**

- **Input:** `nums = [1, 2, 3, 2]`  
  **Output:** `2`
- **Input:** `nums = [1, 2, 3, 4]`  
  **Output:** `-1`

**Detailed Algorithm:**

1. Sort the array in ascending order.
2. Iterate through the sorted array and compare each element with the next one.
3. If two consecutive elements are equal, return that element as the duplicate.
4. If no duplicates are found, return -1.

**Time Complexity:** O(n log n)  
**Space Complexity:** O(1)

---

### 4. Function: `duplicateZeros`

**Question Name:** Duplicate Zeros

**Description:** Move all zeros in the given array to the end while preserving the order of non-zero elements.

**Test Cases:**

- **Input:** `arr = [1, 0, 2, 3, 0, 4, 5, 0]`  
  **Output:** `[1, 0, 0, 2, 3, 0, 0, 4]`
- **Input:** `arr = [0, 1, 0, 2]`  
  **Output:** `[0, 0, 1, 2]`

**Detailed Algorithm:**

1. Create a new array to store the result.
2. Iterate through the original array and for each zero found, add two zeros to the new array.
3. Copy remaining elements to the new array.
4. Copy the new array back to the original.

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

---

### 5. Function: `findMissingNumber`

**Question Name:** Find Missing Number

**Description:** Find the first missing number in an array from 1 to maxElement.

**Test Cases:**

- **Input:** `arr = [1, 2, 3, 5], maxElement = 5`  
  **Output:** `4`
- **Input:** `arr = [2, 3, 4]`  
  **Output:** `1`

**Detailed Algorithm:**

1. Sort the array in ascending order.
2. Iterate through the sorted array, comparing each element with the expected value (starting from 1).
3. If an element does not match the expected value, return the expected value as the missing number.
4. If all elements are present, return `maxElement + 1`.

**Time Complexity:** O(n log n)  
**Space Complexity:** O(1)

---

### 6. Function: `findSingleElement`

**Question Name:** Find Single Element

**Description:** Find the single element in an array where every other element appears twice.

**Test Cases:**

- **Input:** `arr = [1, 2, 2, 3, 3]`  
  **Output:** `1`
- **Input:** `arr = [4, 5, 4, 5, 6]`  
  **Output:** `6`

**Detailed Algorithm:**

1. Sort the array in ascending order.
2. Iterate through the sorted array in pairs.
3. If a pair is not equal, return the first element of the pair as the single element.
4. If all pairs are equal, return -1.

**Time Complexity:** O(n log n)  
**Space Complexity:** O(1)

---

### 7. Function: `intersection`

**Question Name:** Intersection of Three Sorted Arrays

**Description:** Find the intersection of three sorted arrays.

**Test Cases:**

- **Input:** `nums1 = [1, 2, 3], nums2 = [2, 3, 4], nums3 = [3, 4, 5]`  
  **Output:** `[3]`
- **Input:** `nums1 = [1, 2], nums2 = [1, 2], nums3 = [1, 2]`  
  **Output:** `[1, 2]`

**Detailed Algorithm:**

1. Initialize pointers `i`, `j`, and `k` for the three arrays.
2. Iterate through the arrays and compare the elements.
3. If all three elements are equal, add to the result and increment all pointers.
4. If not, increment the pointer pointing to the smallest element.
5. Return the result vector.

**Time Complexity:** O(m + n + p)  
**Space Complexity:** O(1)

---

### 8. Function: `intersectionOfTwoSortedArray`

**Question Name:** Intersection of Two Sorted Arrays

**Description:** Find the intersection of two sorted arrays.

**Test Cases:**

- **Input:** `arr1 = [1, 2, 3], arr2 = [2, 3, 4]`  
  **Output:** `[2, 3]`
- **Input:** `arr1 = [1, 1, 2], arr2 = [1, 2, 2]`  
  **Output:** `[1, 2]`

**Detailed Algorithm:**

1. Initialize pointers `i` and `j` for the two arrays.
2. Iterate through both arrays until one is exhausted.
3. If elements are equal, add to the result and increment both pointers.
4. If one element is smaller, increment the corresponding pointer.
5. Return the result vector.

**Time Complexity:** O(m + n)  
**Space Complexity:** O(min(m, n))

---

### 9. Function: `isSorted`

**Question Name:** Check if Array is Sorted

**Description:** Check if the array is sorted in ascending order.

**Test Cases:**

- **Input:** `arr = [1, 2, 3, 4]`  
  **Output:** `1` (true)
- **Input:** `arr = [1, 3, 2]`  
  **Output:** `0` (false)

**Detailed Algorithm:**

1. Iterate through the array from index `0` to `n-2`.
2. Compare each element with the next.
3. If any element is greater than the next, return `0`.
4. If the loop completes, return `1`.

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

### 10. Function: `longestSubarrayWithSumK`

**Question Name:** Longest Subarray with Sum K

**Description:** Find the length of the longest subarray with sum `k`.

**Test Cases:**

- **Input:** `arr = [1, -1, 5, -2, 3], k = 3`  
  **Output:** `4`
- **Input:** `arr = [-2, -1, 2, 1], k = 1`  
  **Output:** `2`

**Detailed Algorithm:**

1. Initialize variables for `sum`, `minLen`, and a hashmap for prefix sums.
2. Iterate through the array, adding elements to `sum`.
3. If `sum` equals `k`, update `minLen`.
4. If `sum - k` exists in the hashmap, update `minLen` with the difference of indices.
5. Store the current sum and its index in the hashmap.
6. Return the length of the longest subarray found.

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

---

### 11. Function: `maxConsecutiveOnes`

**Question Name:** Maximum Consecutive Ones

**Description:** Find the maximum number of consecutive 1's in a binary array.

**Test Cases:**

- **Input:** `arr = [1, 1, 0, 1, 1, 1]`  
  **Output:** `3`
- **Input:** `arr = [0, 0, 0]`  
  **Output:** `0`

**Detailed Algorithm:**

1. Initialize pointers `i` and `j` for the current sequence.
2. Use a while loop to traverse the array.
3. If a `0` is found, move `i` to the next index.
4. If a `1` is found, extend the sequence until a `0` is encountered.
5. Update the maximum count of consecutive 1's found.
6. Return the maximum count.

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

### 12. Function: `missingAndRepeatingNumber`

**Question Name:** Missing and Repeating Number

**Description:** Find the missing and repeating numbers in an array.

**Test Cases:**

- **Input:** `arr = [3, 1, 2, 5, 3], n = 5`  
  **Output:** `[3, 4]`
- **Input:** `arr = [1, 2, 2, 3, 5], n = 5`  
  **Output:** `[2, 4]`

**Detailed Algorithm:**

1. Initialize variables for `repeated` and `missing`.
2. Create a frequency array to track occurrences.
3. Iterate through the array and update the frequency array.
4. Identify the repeating number from the frequency array.
5. Find the missing number by checking which index in the frequency array is still `0`.
6. Return both numbers.

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

---

### 13. Function: `movingZerosToEnd`

**Question Name:** Move Zeros to End

**Description:** Move all zeros in the given array to the end while preserving the order of non-zero elements.

**Test Cases:**

- **Input:** `arr = [0, 1, 0, 3, 12]`  
  **Output:** `[1, 3, 12, 0, 0]`
- **Input:** `arr = [1, 2, 0]`  
  **Output:** `[1, 2, 0]`

**Detailed Algorithm:**

1. Create a new array to store non-zero elements.
2. Iterate through the original array, adding non-zero elements to the new array.
3. Fill the rest of the new array with zeros.
4. Copy the new array back to the original.

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

---

### 14. Function: `removeDuplicates`

**Question Name:** Remove Duplicates

**Description:** Remove duplicates from the array and return the count of unique elements.

**Test Cases:**

- **Input:** `arr = [1, 1, 2]`  
  **Output:** `2`
- **Input:** `arr = [0, 0, 1, 1, 2]`  
  **Output:** `3`

**Detailed Algorithm:**

1. Use a set to store unique elements.
2. Iterate through the array and insert each element into the set.
3. Copy the unique elements back to the original array.
4. Return the size of the set.

**Time Complexity:** O(n log n)  
**Space Complexity:** O(n)

---

### 15. Function: `removeDuplicates2`

**Question Name:** Remove Duplicates (Allow Two)

**Description:** Remove all but two of each duplicate element from the array.

**Test Cases:**

- **Input:** `arr = [1, 1, 1, 2, 2, 2, 3]`  
  **Output:** `[1, 1, 2, 2, 3]`
- **Input:** `arr = [0, 0, 0, 1, 1, 1, 2]`  
  **Output:** `[0, 0, 1, 1, 2]`

**Detailed Algorithm:**

1. Initialize a count variable to track occurrences.
2. Iterate through the array, comparing each element with the previous one.
3. If the count is less than or equal to 2, copy the current element to the result.
4. Return the length of the modified array.

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

### 16. Function: [removeSpecificElement](cci:1://file:///home/manikanta/Desktop/GIT/cPlusPLus/arrays/removeSpecificElement.cpp:3:0-12:1)

**Question Name:** Remove Specific Element

**Description:** Remove all occurrences of a specific element from the array.

**Test Cases:**

- **Input:** `arr = [3, 2, 2, 3, 4], target = 3`  
  **Output:** `[2, 2, 4]`
- **Input:** `arr = [1, 2, 3], target = 4`  
  **Output:** `[1, 2, 3]`

**Detailed Algorithm:**

1. Initialize a pointer to track the position for non-target elements.
2. Iterate through the array and swap non-target elements to the front.
3. Return the new length of the array.

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

### 17. Function: `rotateArrayLeftAndRight`

**Question Name:** Rotate Array Left and Right

**Description:** Rotate the array left and right by `k` positions.

**Test Cases:**

- **Input:** `arr = [1, 2, 3, 4, 5], k = 2`  
  **Output:** `[3, 4, 5, 1, 2]`
- **Input:** `arr = [1, 2, 3], k = 1`  
  **Output:** `[2, 3, 1]`

**Detailed Algorithm:**

1. Use reversal algorithm to achieve rotation in-place.
2. Reverse the first `k` elements.
3. Reverse the remaining elements.
4. Reverse the entire array.

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

### 18. Function: `shortestSubArrayWIthSumK`

**Question Name:** Shortest Subarray with Sum K

**Description:** Find the length of the shortest subarray with sum `k`.

**Test Cases:**

- **Input:** `arr = [1, 2, 3, 4], k = 5`  
  **Output:** `2`
- **Input:** `arr = [2, -1, 2, 3], k = 4`  
  **Output:** `3`

**Detailed Algorithm:**

1. Use a hashmap to store prefix sums and their indices.
2. Iterate through the array, updating the cumulative sum.
3. If the cumulative sum equals `k`, update the shortest length.
4. If `sum - k` exists in the hashmap, calculate the length and update if it's shorter.
5. Return the length of the shortest subarray found.

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

---

### 19. Function: `squaredOfSortedArray`

**Question Name:** Sorted Squares of Array

**Description:** Return a sorted array of the squares of the elements.

**Test Cases:**

- **Input:** `arr = [-4, -1, 0, 3, 10]`  
  **Output:** `[0, 1, 9, 16, 100]`
- **Input:** `arr = [-2, -1]`  
  **Output:** `[1, 4]`

**Detailed Algorithm:**

1. Initialize two pointers for the start and end of the array.
2. Create a result array of the same size.
3. Compare absolute values of elements at the two pointers.
4. Fill the result array from the back based on which absolute value is larger.
5. Return the result array.

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

---

### 20. Function: [unionOfTwoSortedArrays](cci:1://file:///home/manikanta/Desktop/GIT/cPlusPLus/arrays/unionOfTwoSortedArrays.cpp:16:4-66:5)

**Question Name:** Union of Two Sorted Arrays

**Description:** Compute the union of two sorted arrays without duplicates.

**Test Cases:**

- **Input:** `a = [1, 2, 3], b = [2, 3, 4]`  
  **Output:** `[1, 2, 3, 4]`
- **Input:** `a = [1, 1, 2], b = [2, 3]`  
  **Output:** `[1, 2, 3]`

**Detailed Algorithm:**

1. Initialize pointers for both arrays and a result vector.
2. Iterate through both arrays until one is exhausted.
3. Compare elements and add unique elements to the result.
4. Return the result vector.

**Time Complexity:** O(m + n)  
**Space Complexity:** O(min(m, n))
