## 🧩 Problem Statement

Given an array of integers `arr` and an integer `k`, **find the number of contiguous subarrays** whose sum equals `k`.

### 🔢 Example

```text
Input:
arr = [1, 2, 3, -3, 1, 1, 1, 4, 2, -3]
k = 3

Output:
8
```

### ✅ Subarrays with sum = 3:

1. [1, 2]
2. [3]
3. [1, 2, 3, -3]
4. [2, 3, -3, 1]
5. [3, -3, 1, 1, 1]
6. [-3, 1, 1, 1, 4, 2, -3]
7. [1, 1, 1]
8. [4, 2, -3]

---

## ⚙️ Approach 1: Brute Force

- Use two pointers `i` and `j`
- For every pair `(i, j)`, calculate the sum of elements from `i` to `j`
- If the sum equals `k`, increment `count`

**Time Complexity:** O(n²)  
**Space Complexity:** O(1)

---

## ⚡️ Approach 2: Prefix Sum + Hash Map (Efficient)

- Maintain a running prefix sum
- Use a hash map to store frequencies of prefix sums seen so far
- If `prefixSum - k` is in the map, it means a subarray ending at current index has sum `k`

**explanation :**

<pre>
   s-k    k  
|^^^^^^^|^^^|
|___________|
            ^
            s
s -  prefix sum 
till prefix sum count of k equal to count of s-k
</pre>

if currentPrefix sum - k is found in map means we exclude numbers before the that prefix to from a sub array where sum = k

### 🧮 Pseudocode

```
PROCEDURE subarraySumK(arr, k)
    SET count = 0
    SET prefixSum = 0
    INITIALIZE map as empty
    SET map[0] = 1

    FOR index FROM 0 TO size of arr - 1
        SET prefixSum = prefixSum + arr[index]
        IF (prefixSum - k) EXISTS IN map
            count = count + map[prefixSum - k]
        INCREMENT map[prefixSum] by 1
    END FOR

    RETURN count
END PROCEDURE
```

---

## ✅ Time and Space Complexity (Corrected)

| Type             | Value    |
| ---------------- | -------- |
| Time Complexity  | **O(n)** |
| Space Complexity | **O(n)** |
