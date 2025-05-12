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

// delete element in linked list

// delete element at end
Node* deleteTailElement(Node* head){
    Node* temp = head;
    // if there is no linked list
    if (temp == nullptr) return nullptr;
    // if only one node is present 
    if (temp->next == nullptr){
        delete temp;
        return nullptr;
    }
    // more than one node is presnet iterate it

    while(temp->next->next != nullptr) temp = temp->next;
    Node* delNode = temp->next;
    delete delNode;
    temp->next = nullptr;

    return head;
}

// time complexcity : O(N);
// space complexcity: O(1);

// delete head element
Node* deleteHead(Node* head){
    if (head == nullptr) return nullptr;

    Node* temp = head;
    head = head ->next;
    delete temp;
    return head;
}

// time complecity : O(1)
// space complexcity : O(1)

// delete kth element (index based )
// means of u delete k = 3 means index 3 value should be deleted 4 the element in the linked list

Node* deleteKthElement(Node* head, int k){
    // head is empty
    if (head == nullptr) return nullptr;
    // it means k = 0 is head element
    if (k == 0){
        Node* temp = head;
        head = head ->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    int count = 0;
    while(temp->next != nullptr){
        if (count == k-1){
            Node* deletedNode = temp->next;
            temp ->next = temp ->next->next;
            delete deletedNode;
            break;
        }
        temp = temp->next;
        count++;
    }
    return head;
}

// time complexcity: O(N);
// space complexcity: O(1);

Node* deleteValue(Node* head, int x){
    // head is empty
    if (head == nullptr) return nullptr;
    // it means k = 0 is head element
    if (x == head->data){
        Node* temp = head;
        head = head ->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    int count = 0;
    while(temp->next != nullptr){
        if (x == temp->next->data){
            Node* deletedNode = temp->next;
            temp ->next = temp ->next->next;
            delete deletedNode;
            break;
        }
        temp = temp->next;
        count++;
    }
    return head;
}

// time complexcity: O(N);
// space complexcity: O(1);

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