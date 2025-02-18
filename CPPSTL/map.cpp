#include <iostream>
#include <map>
#include <string>
using namespace std;

// Function to demonstrate map initialization
void mapInitialization() {
    // 1. Empty map
    cout << "1. Empty Map Initialization:" << endl;
    map<int, string> emptyMap;
    cout << "Size of empty map: " << emptyMap.size() << endl;

    // 2. Initialization with initializer list
    cout << "\n2. Initialization with Initializer List:" << endl;
    map<int, string> studentsMap = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"}
    };
    for (const auto& student : studentsMap) {
        cout << "ID: " << student.first << ", Name: " << student.second << endl;
    }

    // 3. Copy constructor
    cout << "\n3. Copy Constructor:" << endl;
    map<int, string> copiedMap(studentsMap);
    for (const auto& student : copiedMap) {
        cout << "Copied - ID: " << student.first << ", Name: " << student.second << endl;
    }
}

// Function to demonstrate map insertion methods
void mapInsertion() {
    cout << "\nMap Insertion Methods:" << endl;
    map<string, int> ageMap;

    // 1. Using square bracket operator
    ageMap["Alice"] = 25;  // O(log n)
    
    // 2. Using insert method
    ageMap.insert({"Bob", 30});  // O(log n)
    
    // 3. Using pair
    ageMap.insert(pair<string, int>("Charlie", 35));  // O(log n)
    
    // 4. Checking insertion
    auto [iterator, wasInserted] = ageMap.insert({"David", 40});
    cout << "David insertion: " << (wasInserted ? "Successful" : "Failed") << endl;

    // Display map contents
    for (const auto& person : ageMap) {
        cout << person.first << " is " << person.second << " years old" << endl;
    }
}

// Function to demonstrate map access and modification
void mapAccessAndModification() {
    cout << "\nMap Access and Modification:" << endl;
    map<string, double> productPrices = {
        {"Apple", 0.50},
        {"Banana", 0.30},
        {"Orange", 0.60}
    };

    // 1. Accessing elements
    cout << "Apple price: $" << productPrices["Apple"] << endl;  // O(log n)
    
    // 2. Safe access with .at()
    try {
        cout << "Banana price: $" << productPrices.at("Banana") << endl;
    } catch (const out_of_range& e) {
        cout << "Key not found!" << endl;
    }

    // 3. Checking existence
    cout << "Is Grape in map? " << (productPrices.count("Grape") > 0 ? "Yes" : "No") << endl;

    // 4. Finding an element
    auto it = productPrices.find("Orange");
    if (it != productPrices.end()) {
        cout << "Orange found: $" << it->second << endl;
    }

    // 5. Modifying an existing element
    productPrices["Apple"] = 0.55;
    cout << "Updated Apple price: $" << productPrices["Apple"] << endl;
}

// Function to demonstrate map iteration and bounds
void mapIterationAndBounds() {
    cout << "\nMap Iteration and Bounds:" << endl;
    map<int, string> numberNames = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"}
    };

    // 1. Forward iteration
    cout << "Forward Iteration:" << endl;
    for (const auto& pair : numberNames) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 2. Reverse iteration
    cout << "\nReverse Iteration:" << endl;
    for (auto it = numberNames.rbegin(); it != numberNames.rend(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    // 3. Lower and Upper Bounds
    auto lowerBound = numberNames.lower_bound(3);
    auto upperBound = numberNames.upper_bound(3);
    cout << "\nLower Bound of 3: " << lowerBound->first << " = " << lowerBound->second << endl;
}

// Function to demonstrate map deletion
void mapDeletion() {
    cout << "\nMap Deletion:" << endl;
    map<string, int> scoreMap = {
        {"Alice", 95},
        {"Bob", 87},
        {"Charlie", 92}
    };

    // 1. Deleting a single element
    scoreMap.erase("Bob");  // O(log n)

    // 2. Deleting all elements
    // scoreMap.clear();  // O(n)

    // Display remaining elements
    for (const auto& score : scoreMap) {
        cout << score.first << ": " << score.second << endl;
    }
}

int main() {
    mapInitialization();
    mapInsertion();
    mapAccessAndModification();
    mapIterationAndBounds();
    mapDeletion();

    return 0;
} 