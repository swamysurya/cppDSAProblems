#include <iostream>
#include <unordered_map>
using namespace std;

/*
1. what is hash map?
- A hash map is a data structure that stores key-value pairs. It is also known as an associative array, a hash table, or a dictionary.
- The key is used to uniquely identify the value and is used to access the value associated with it.
- The key is hashed to generate a unique hash code, which is used to store the key-value pair in the hash map.
- The hash map provides constant-time complexity O(1) for insertion, deletion, and lookup operations on average.
- The hash map is implemented using an array of linked lists, where each element in the array is a linked list of key-value pairs.

2. When to use hash map?
- When you need to store key-value pairs and quickly access the value associated with a key.
- When you need to check if a key exists in the data structure efficiently.
- When you need to insert, delete, or update key-value pairs with constant-time complexity O(1) on average.

3. time and space complexity of functions in hash map?
- insertion - O(1) on average
- deletion - O(1) on average
- lookup - O(1) on average
- space complexity - O(n), where n is the number of key-value pairs stored in the hash map.

4. internal implementation of hash map?
- The hash map is implemented using an array of linked lists.
- Each element in the array is a linked list of key-value pairs.
*/



int main() {
    // 1. Initialization
    unordered_map<int, string> hashMap; // Empty hash map
    unordered_map<int, string> hashMap2 = {{1, "one"}, {2, "two"}, {3, "three"}}; // Initialization with values

    // 2. Inserting elements
    hashMap[1] = "one";
    hashMap[2] = "two";
    hashMap[3] = "three";

    // 3. Accessing elements
    cout << "Element with key 1: " << hashMap[1] << endl;
    cout << "Element with key 2: " << hashMap[2] << endl;

    // 4. Checking if a key exists
    // hashmap.end() specifies the end of the hashmap which points to the next location after the last element
    // hashmap.find() returns the iterator to the element if found, otherwise returns hashmap.end()
    if (hashMap.find(4) != hashMap.end()) {
        cout << "Key 4 exists in the hash map." << endl;
    } else {
        cout << "Key 4 does not exist in the hash map." << endl;
    }

    // 5. Iterating over elements
    cout << "Hash map elements:" << endl;
    // iterating over the hashmap return a pair of key and value with first and second respectively.
    for (const auto& pair : hashMap) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    // 6. Erasing elements
    hashMap.erase(2); // Erase element with key 2
    cout << "After erasing key 2:" << endl;
    for (const auto& pair : hashMap) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    // 7. Size of the hash map
    cout << "Size of hash map: " << hashMap.size() << endl;

    // 8. Clearing the hash map
    hashMap.clear();
    cout << "Size of hash map after clearing: " << hashMap.size() << endl;

    return 0;
}

// hash map
/*

{
    1: "one",  // key: 1, value: "one"
    2: "two",
    3: "three"
}


*/