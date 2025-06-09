#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
    public:
        Node(int value, Node* address){
            data = value;
            next = address;
        }
    public:
        Node(int value){
            data = value;
            next = nullptr;
        }
    public:
        Node(){
            data = 0;
            next = nullptr;
        }
};

// brute force approach
Node* reverse_LL(Node* head){
    Node* temp = head;
    stack<int> s;
    while(temp != nullptr){
        s.push(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    while(temp != nullptr){
        temp->data = s.top();
        s.pop();
        temp = temp->next;
    }
    return head;
}

// time complexity O(n)
// space complexity O(n)

void printLinkedList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

// optimised using 3 pointers
Node* reverse_LL_3Pointer(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// time complexity O(n)
// space complexity O(1)



int main(){
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
    Node* res = reverse_LL(head);
    printLinkedList(res);
    
    return 0;
}
