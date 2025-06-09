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


Node* reverseBetween(Node* head, int left, int right) {
    if(!head || left == right) return head;
    
    Node* leftPrev = nullptr;
    Node* leftNode = head;
    for(int i = 1; i < left && leftNode != nullptr; ++i){
        leftPrev = leftNode;
        leftNode = leftNode->next;
    }
    // safety chek this wont get executed any way left < right
    if (leftNode == nullptr) return head;
    
    // starting from left node
    Node* rightNode = leftNode;
    for(int j = left; j < right && rightNode->next != nullptr; ++j){
        rightNode = rightNode->next;
    }
    Node* rightNext = rightNode->next;
    
    Node* prev = rightNext;
    Node* curr = leftNode;
    Node* temp;
    
    while(curr != rightNext){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    
    if (leftPrev != nullptr){
        leftPrev->next = rightNode;
    }else{
        head = rightNode;
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

int main(){
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
    Node* res = reverseBetween(head, 2, 4);
    printLinkedList(res);
    return 0;
}

// example
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

