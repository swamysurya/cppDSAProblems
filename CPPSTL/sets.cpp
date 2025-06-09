#include <iostream>
#include <set>

#include <iterator>

using namespace std;


int main() {
    // Create a set of integers
    set<int> mySet;

    // Insert elements into the set
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    // insert multiple elements at once
    mySet.insert({40, 50, 60});

    // check a number is present in set or not
    int num = 20;
    if (mySet.find(num) != mySet.end()) {
        cout << num << " is present in the set." << endl;
    } else {
        cout << num << " is not present in the set." << endl;
    }
    // Check the size of the set
    cout << "Size of the set: " << mySet.size() << endl;

    // Display the elements in the set
    cout << "Elements in the set: ";
    for (const int& element : mySet) {
        cout << element << " ";
    }
    cout << endl;

    // Check if an element exists in the set
    int searchElement = 20;
    if (mySet.find(searchElement) != mySet.end()) {
        cout << searchElement << " is found in the set." << endl;
    } else {
        cout << searchElement << " is not found in the set." << endl;
    }

    // Remove an element from the set
    mySet.erase(20);
    cout << "After removing 20, elements in the set: ";
    for (const int& element : mySet) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}