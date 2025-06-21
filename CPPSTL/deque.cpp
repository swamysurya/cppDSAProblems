#include <iostream>
#include <deque>

using namespace std;

// here we are 
int main(){
    // different ways to initialize deque
    deque<int> d;
    deque<int> d1(5, 10); // 5 elements all initialized to 10
    deque<int> d2(d1); // copy constructor
    deque<int> d3(d1.begin(), d1.end()); // range constructor
    deque<int> d4 = {1, 2, 3, 4, 5}; // initializer list

    // add element to front
    d4.push_front(0);
    // add element to back
    d4.push_back(6);

    // remove element from front
    d4.pop_front();
    // if i remove if deque is empty it will give garbage value
    // remove element from back
    d4.pop_back();
    // if i remove if deque is empty it will give garbage value

    // get front element
    cout << "Front element: " << d4.front() << endl;
    // if i remove if deque is empty it will give garbage value
    // get back element
    cout << "Back element: " << d4.back() << endl;
    // if i remove if deque is empty it will give garbage value

    // size of deque
    cout << "Size of deque: " << d4.size() << endl;
    // check if deque is empty
    cout << "Is deque empty: " << d4.empty() << endl;
    // if deque is empty it will return 1 else 0

    // print deque
    for (int i : d4) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}




// list of all methods and properties of deque and time complexity
// addFront - O(1) 
// addBack - O(1)
// removeFront - O(1)
// removeBack - O(1)
// getFront - O(1)
// getBack - O(1)
// size - O(1)
// isEmpty - O(1)

