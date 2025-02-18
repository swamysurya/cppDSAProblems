#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    // 1. Static Arrays
    int staticArray[5] = {1, 2, 3, 4, 5}; // Initialization
    cout << "Static Array: ";
    for (int i = 0; i < 5; i++) {
        cout << staticArray[i] << " ";
    }
    cout << endl;
    // array iterations using for each loop
    cout << "Static Array using for each loop: ";
    for (int i : staticArray) {
        cout << i << " ";
    }
    cout << endl;
    // sort the array
    sort(staticArray, staticArray + 5); // Sorting the array
    cout << "Sorted Array: ";
    for (int i = 0; i < 5; i++) {
        cout << staticArray[i] << " ";
    }
    cout << endl;

    // 2. Dynamic Arrays
    int* dynamicArray = new int[5]; // Allocation
    for (int i = 0; i < 5; i++) {
        dynamicArray[i] = i + 1; // Initialization
    }
    cout << "Dynamic Array: ";
    for (int i = 0; i < 5; i++) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;
    // iterate using for each loop
    cout << "Dynamic Array using for each loop: ";
    // for (int i : dynamicArray) { //The issue in your code is that you're trying to use a range-based for loop on a dynamically allocated array, which is not valid in C++.
    //     cout << i << " ";
    // }
    // cout << endl;
    /*
    dynamicArray is a pointer (int*), not an array
    When you allocate an array dynamically:
    dynamicArray is just a pointer to the first element.
    Unlike C-style static arrays, the compiler cannot infer its size.
    Range-Based Loops Require an Iterable Object
    A pointer (int*) is not an iterable container (like std::vector or std::array).
    When you use for (int i : dynamicArray), the compiler does not know how many elements to iterate over, leading to compilation errors.
    */
    delete[] dynamicArray; // Deallocation
    
    // sort the dynamic array is same as static array
    sort(dynamicArray, dynamicArray + 5); // Sorting the array

    // 3. STL Arrays
    array<int, 5> stlArray = {1, 2, 3, 4, 5}; // Initialization
    cout << "STL Array: ";
    for (int i = 0; i < stlArray.size(); i++) {
        cout << stlArray[i] << " ";
    }
    cout << endl;

    // 4. Array Iterators
    array<int, 5> arr = {1, 2, 3, 4, 5};
    cout << "Array Iterators: ";
    for (auto it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // 5. Array Operations
    array<int, 5> arr1 = {1, 2, 3, 4, 5};
    array<int, 5> arr2 = {5, 4, 3, 2, 1};
    arr1.swap(arr2); // Swapping two arrays

    cout << "Array 1 after swapping: ";
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Array 2 after swapping: ";
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // all stl array operations are same as vector operations
    // 6. Array Size
    cout << "Size of STL Array: " << arr1.size() << endl;

    // 7. Array Element Access
    cout << "Element at index 2: " << arr1.at(2) << endl;

    // 8. Array Front and Back
    cout << "First element: " << arr1.front() << endl;
    cout << "Last element: " << arr1.back() << endl;

    // 9. Array Fill
    array<int, 5> arr3;
    arr3.fill(10); // Fill all elements with 10
    cout << "Array after fill: ";
    for (int i = 0; i < arr3.size(); i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    // 10. Array Comparison
    array<int, 5> arr4 = {1, 2, 3, 4, 5};
    array<int, 5> arr5 = {1, 2, 3, 4, 5};
    if (arr4 == arr5) {
        cout << "Arrays are equal" << endl;
    } else {
        cout << "Arrays are not equal" << endl;
    }

    // 11. Array Sorting
    array<int, 5> arr6 = {5, 4, 3, 2, 1};
    sort(arr6.begin(), arr6.end()); // Sorting the array
    cout << "Sorted Array: ";
    for (int i = 0; i < arr6.size(); i++) {
        cout << arr6[i] << " ";
    }
    cout << endl;



    

    return 0;
}
