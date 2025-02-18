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
