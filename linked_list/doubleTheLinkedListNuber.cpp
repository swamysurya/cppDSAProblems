#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
        Node(): data(0), next(nullptr) {}
        Node(int data) : data(data), next(nullptr) {}
        Node(int data, Node* next) : data(data), next(next) {}
};

int carry = 0;
void doubleLinkedListRecursive(Node* head){
    if (head == nullptr) return;
    doubleLinkedListRecursive(head->next);
    
    int newVal = (head->data * 2) + carry;
    head->data = newVal % 10;
    carry = newVal / 10;
}

Node* doubleLinkedList(Node* head) {
    // Write your code here...
    doubleLinkedListRecursive(head);
    if(carry > 0){
        Node* newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// time complexcity: O(n)
// space complexcity: O(n) (stack space)
    
void printLinkedList(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(1, new Node(2, new Node(3)));
    Node* res = doubleLinkedList(head);
    printLinkedList(res);
    return 0;
}