
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void kLeftRoatations(vector<int> &arr, int n, int noOfLeftRotations)
{
    auto itBegin = arr.begin();
    auto itEnd = arr.end();
    reverse(itBegin, itBegin + noOfLeftRotations); // time complexity = O(k)
    reverse(itBegin + noOfLeftRotations, itEnd);   // time complexity = O(n-k)
    reverse(itBegin, itEnd);                       // time complexity = O(n)
    // Time complexity = O(k) + O(n-k) + O(n) = O(n)
}

void kRightRoatations(vector<int> &arr, int n, int noOfRightRotations)
{
    auto itBegin = arr.begin();
    auto itEnd = arr.end();
    reverse(itEnd - noOfRightRotations, itEnd);   // time complexity = O(k)
    reverse(itBegin, itEnd - noOfRightRotations); // time complexity = O(n-k)
    reverse(itBegin, itEnd);                      // time complexity = O(n)
    // Time complexity = O(k) + O(n-k) + O(n) = O(n)
}

int findNoOfLeftRotations(int n, int x, int y)
{
    x = x % n; // roatations bounded by n
    y = y % n; // roatations bounded by n
    int rotations = 0;
    // if x is greater than y, then we need to find the no of right rotations
    // if y is greater than x, then we need to find the no of left rotations

    if (x > y)
    {
        rotations = x - y;
        // here convert right rotations to left rotations
        rotations = abs(rotations - n);
    }
    else
    {
        // its directly left rotations
        rotations = y - x;
    }
    return rotations;
}

void onlyLeftRoatationsApproach(int n, int x, int y, vector<int> &arr)
{
    // find no of left rotations
    int noOfLeftRoataions = findNoOfLeftRotations(n, x, y); // Time complexity = O(1)
    kLeftRoatations(arr, n, noOfLeftRoataions);             // Time complexity = O(n)
}

void bothRotationsApproach(int n, int x, int y, vector<int> &nums)
{
    x = x % n;
    y = y % n;

    int rotations;
    if (x > y)
    {                                         // right > left
        rotations = x - y;                    // right rotations
        kRightRoatations(nums, n, rotations); // Time complexity = O(n)
    }
    else
    {
        rotations = y - x;                   // left rotations
        kLeftRoatations(nums, n, rotations); // Time complexity = O(n)
    }
}

int main()
{
    const int n = 6;
    vector<int> arr = {7, 8, 9, 10, 11, 12};
    int x = 3; // no of right rotations
    int y = 2; // no of left rotations
    cout << "Original array: ";
    printArray(arr, n); // Time complexity = O(n)
    cout << "Array after left rotations: ";
    // onlyLeftRoatationsApproach(n,x,y,arr); //Time complexity = O(n)
    bothRotationsApproach(n, x, y, arr); // Time complexity = O(n)
    printArray(arr, n);                  // Time complexity = O(n)
}