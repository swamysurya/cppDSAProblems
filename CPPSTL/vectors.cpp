#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 1. Initialization
    vector<int> vec1; // Empty vector
    vector<int> vec2(5, 10); // Vector of size 5, all elements initialized to 10
    vector<int> vec3 = {1, 2, 3, 4, 5}; // Vector with initializer list
    vector<int> vec4(4); // Vector of size 4, all elements initialized to 0

    // 2. Accessing elements
    cout << "Element at index 2 in vec3: " << vec3[2] << endl;
    cout << "First element in vec3: " << vec3.front() << endl;
    cout << "Last element in vec3: " << vec3.back() << endl;

    // 3. Modifying elements
    vec3[2] = 10; // Direct access
    vec3.at(3) = 20; // Using at() method

    // 4. Adding elements
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);

    //accessing front and back element
    cout << "Front element in vec1: " << vec1.front() << endl; // if vec1 is empty, it will give garbage value;
    cout << "Back element in vec1: " << vec1.back() << endl; // if vec1 is empty, it will give garbage value;
    

    // 5. Removing elements
    vec1.pop_back(); // Removes the last element

    // 6. Iterating over elements
    cout << "Elements in vec1: ";
    for (int i : vec1) {
        cout << i << " ";
    }
    cout << endl;

    // 7. Inserting elements
    vec1.insert(vec1.begin(), 0); // Insert 0 at the beginning
    vec1.insert(vec1.end(), 4); // Insert 4 at the end

    // insert element at front 
    vec1.insert(vec1.begin(), 100);

    // insert element in array using index
    vec1.insert(vec1.begin() + 2, 100); // Insert 100 at index 2

    // 8. Erasing elements
    vec1.erase(vec1.begin()); // Erase the first element
    vec1.erase(vec1.begin(), vec1.begin() + 2); // Erase the first two elements

    // 9. Resizing the vector
    vec1.resize(5, 100); // Resize to 5 elements, new elements initialized to 100

    // 10. Clearing the vector
    vec1.clear(); // Remove all elements

    // 11. Checking size and capacity
    cout << "Size of vec2: " << vec2.size() << endl;
    cout << "Capacity of vec2: " << vec2.capacity() << endl;

    // 12. Using algorithms
    sort(vec3.begin(), vec3.end()); // Sort the vector
    // sort the vector in reverse ordere
    reverse(vec3.begin(), vec3.end()); // Reverse the vector

    //check vec1 is empty or not
    if (vec1.empty()) {
        cout << "vec1 is empty" << endl;
    } else {
        cout << "vec1 is not empty" << endl;
    }

    cout << "Sorted and reversed vec3: ";
    for (int i : vec3) {
        cout << i << " ";
    }
    cout << endl;

    //concat two vectors
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    cout << "Concatenated vec1 and vec2: ";
    for (int i : vec1) {
        cout << i << " ";
    }
    cout << endl;

    // use of map function to sqare each element in vector
    vector<int> vec4 = {1,2,3,4,5};
    transform(vec4.begin(), vec4.end(), vec4.begin(), [](int x){return x*x;});
    cout << "Squared vec4: ";
    for (int i : vec4) {
        cout << i << " ";
    }
    cout << endl;
    

    

    return 0;
}

/*
.size() - Returns the number of elements in the vector.
.capacity() - Returns the number of elements that can be stored in the vector without reallocation.
.push_back(val) - Adds an element with value val to the end of the vector.
.pop_back() - Removes the last element from the vector.
.front() - Returns a reference to the first element in the vector.
.back() - Returns a reference to the last element in the vector.
.at(index) - Returns a reference to the element at the specified index, with bounds checking.
.insert(pos, val) - Inserts an element with value val at the specified position pos.
.erase(pos) - Removes the element at the specified position pos.
.erase(start, end) - Removes elements in the range [start, end).
.resize(new_size, val) - Resizes the vector to contain new_size elements, with new elements initialized to val.
.clear() - Removes all elements from the vector.
.begin() - Returns an iterator pointing to the first element in the vector.
.end() - Returns an iterator pointing to the position just after the last element in the vector.
.sort(start, end) - Sorts the elements in the range [start, end) in ascending order.
.reverse(start, end) - Reverses the order of elements in the range [start, end).
*/