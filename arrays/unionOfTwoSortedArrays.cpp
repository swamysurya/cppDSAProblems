#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    /**
     * Computes the union of two sorted arrays without duplicates.
     *
     * This function takes two sorted vectors `a` and `b` as input and returns a new vector containing the union of 
     * the elements from both vectors. The resulting vector is sorted and contains no duplicate elements.
     *
     * @param a The first sorted vector.
     * @param b The second sorted vector.
     * @return A sorted vector containing the union of elements from both `a` and `b` without duplicates.
     */

    vector<int> unionOfTwoSortedArrays(vector<int> a, vector<int> b){
        // a = {3,5,5,6,6} b = {1,2,3,5}
        int i = 0, j = 0;
        int m = a.size(); // 5
        int n = b.size(); // 4
        vector<int> c; 
        // i and j are pointers to a and b
        // m and n are sizes of a and b
        // c is the resultant vector
        // iterate throght both array till one of them is exhausted 
        while(i < m && j < n){ // Time complexity = O(m+n)
            // if ith element of a is less than jth element of b
            // then copy ith element of a to c
            // and check if c is empty or c.back() is not equal to a[i] beacuse we need to remove duplicates
            // increment i
            if(a[i] < b[j]){
                if (c.empty() || c.back() != a[i]) c.push_back(a[i]);
                i++;
            // if jth element of b is less than ith element of a
            // then copy jth element of b to c
            // and check if c is empty or c.back() is not equal to b[j] beacuse we need to remove duplicates
            // increment j
            }else if (a[i] > b[j]){
                if (c.empty() || c.back() != b[j]) c.push_back(b[j]);
                j++;  
            // if ith element of a is equal to jth element of b
            // then copy any of them to c (here we copy ith element of a)
            // and check if c is empty or c.back() is not equal to a[i] beacuse we need to remove duplicates
            // increment both i and j
            }else{
                if (c.empty() || c.back() != a[i]) c.push_back(a[i]);
                i++;
                j++;
            }
        }
        // if a is not exhausted
        // then copy all remaining elements of a to c
        while (i < m){ // Time complexity = O(m)
            if (c.back() != a[i]) c.push_back(a[i]);
            i++;
        }
        // if b is not exhausted
        // then copy all remaining elements of b to c
        while (j < n){ // Time complexity = O(n)
            if (c.back() != b[j]) c.push_back(b[j]);
            j++;
        }
        cout << "final " << endl;
        return c;
        // Time complexity = O(m+n) + O(m) + O(n) = O(m+n)
    }

    // algorithm:
    // 1. Initialize two pointers i and j to 0.
    // 2. Iterate through both arrays until one of them is exhausted.
    // 3. If the i-th element of the first array is less than the j-th element of the second array, copy the i-th element to the result vector.
    // 4. If the j-th element of the second array is less than the i-th element of the first array, copy the j-th element to the result vector.
    // 5. If the i-th element of the first array is equal to the j-th element of the second array, copy any of them to the result vector.
    // 6. Increment the pointers i and j accordingly.
    // 7. If the first array is not exhausted, copy the remaining elements to the result vector.
    // 8. If the second array is not exhausted, copy the remaining elements to the result vector.
    // 9. Return the result vector containing the union of the two arrays without duplicates.

    //time complexity = O(m+n) + O(m) + O(n) = O(m+n)
    //space complexity = O(m+n) (resultant vector)
    

    /**
     * Computes the union of two sorted arrays using a brute force approach.
     *
     * This function takes two sorted vectors `a` and `b` as input and returns a new vector containing the union of 
     * the elements from both vectors. The resulting vector is sorted and contains no duplicate elements.
     * 
     * The function uses a set to store unique elements from both vectors and then constructs the result vector from the set.
     *
     * @param a The first sorted vector.
     * @param b The second sorted vector.
     * @return A sorted vector containing the union of elements from both `a` and `b` without duplicates.
     */

    vector<int> unionOfTwoSortedArraysBruteForce(vector<int> a, vector<int> b){
        // a = {3,5,5,6,6} b = {1,2,3,5}
        set<int> s;
        for(int i = 0; i < a.size(); i++){ // Time complexity = O(m)
            s.insert(a[i]); // Time complexity = O(log x)
        }
        // time complexity = O(m log x)
        for(int i = 0; i < b.size(); i++){ // Time complexity = O(n)
            s.insert(b[i]); // Time complexity = O(log x) 
        }
        // time complexity = O(n log x)
        // time complexity = O(m log x) + O(n log x) = O((m+n) log x)
        vector<int> c;
        for(auto i: s){ // Time complexity = O(x)
            c.push_back(i); // Time complexity = O(1)
        }
        return c;
        // Time complexity = O((m+n) log x + x)
        // In the worst case, x = m + n
        // Therefore, time complexity = O((m+n) log (m+n))
        // Space complexity = O(x) for the set and O(x) for the result vector
        // In the worst case, space complexity = O(m + n)
    }
    //time complexity = O((m+n) log (m+n))
    //space complexity = O(m + n) (set to store unique elements and result vector)
};



int main(){
    vector<int> a = {3,5,5,6,6};
    vector<int> b = {1,2,3,5};
    solution s;
    vector<int> c = s.unionOfTwoSortedArraysBruteForce(a,b);
    // expected output: 1 2 3 5 6
    for(int i = 0; i < c.size(); i++){
        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}