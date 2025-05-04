#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    public:

        Node(int value, Node* adress){
            data = value;
            next = adress;
        }

        Node(int value){
            data = value;
            next = nullptr;
        }

        Node(){
            data = 0;
            next = nullptr;
        }
};


Node* arrayToLinkedList(int arr[], int n){
    Node* head = new Node(arr[0]);
    Node* temp;
    Node* curr;
    curr = head;
    for(int i = 1; i < n; i++){
        temp = new Node(arr[i]);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

void printLinkedList(Node* head){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

bool searchElementInLinedList(Node* head, int target){
    Node* temp = head;

    while(temp != nullptr){
        if (target == temp->data) return true;
        temp = temp->next;
    }
    return false;
}


int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;
    // here head is pointer 
    Node* head = arrayToLinkedList(arr, n);
   printLinkedList(head);
   cout << (searchElementInLinedList(head, 12) ? "found" : "Not found") << endl;
    
    // dot notation usage
    Node head2 = Node(3); // node is a object
    cout << head2.data << endl;

    return 0;


}

// what is differnce between NULL and nullptr in c/c++ ?
//✔ In modern C++ (C++11 and later), always prefer nullptr.
// ✔ Only use NULL when you are working in old C/C++ code that doesn’t support nullptr.

/*
NULL
It’s a macro (usually defined as #define NULL 0 in C/C++ headers).

Used historically in C and old C++ to represent a null pointer.

Example:

Node* next = NULL;
Limitations / problems:

It’s just 0, so it can sometimes cause ambiguous behavior when overloaded functions exist.

Example:


void func(int);
void func(Node*);

func(NULL);  // Which one is called? Ambiguous, because NULL == 0
✅ nullptr (introduced in C++11)
It’s a keyword that represents a null pointer.

Type-safe: it has its own type std::nullptr_t.

Eliminates ambiguity between pointers and integers.

Example:

Node* next = nullptr;
Advantage:

Clear, type-safe, and avoids overload ambiguity.

Works only with pointers — won’t accidentally match integer overloads.


In C++, you actually can define multiple functions with the same name, as long as their parameter types (signatures) are different.

This feature is called → function overloading.

example :
void func(int x) {
    cout << "int version called\n";
}

void func(Node* ptr) {
    cout << "Node* version called\n";
}

func(10);            // calls func(int)
Node* n = nullptr;
func(n);             // calls func(Node*)

func(NULL);          // ⚠ ambiguous if NULL == 0, because it matches both

*/