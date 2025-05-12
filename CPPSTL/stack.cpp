#include <stack>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    // different ways of creating stack
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    // using copy constructor
    stack<int> s1(s);

    // using vector (since stack doesn't support array initialization directly)
    vector<int> vec = {1, 2, 3, 4, 5};

    stack<int, vector<int>> s2(vec);

    // using list
    list<int> l = {1, 2, 3, 4, 5};
    stack<int, list<int>> s3(l);
    // push element to stack
    s3.push(6);

    // size of stack
    cout << "Size of stack: " << s.size() << endl;
    // check if stack is empty
    cout << "Is stack empty: " << s.empty() << endl;
    // top element of stack
    cout << "Top element of stack: " << s.top() << endl;
    // pop element from stack
    int res = s.top();
    s.pop();
    cout << "Popped element: " << res << endl;
    cout << "Top element of stack after pop: " << s.top() << endl;

    // print stack
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}