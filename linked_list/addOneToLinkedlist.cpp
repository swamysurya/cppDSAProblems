#include <iostream>
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
};


int carry = 1;
void AddOneToLLRecursively(Node* head){
    if (head == nullptr) return;
    AddOneToLLRecursively(head->next);
    if (carry == 1){
        int val = head->data + carry;
        head->data = val % 10;
        carry = val / 10;
    }
}

Node* add1ToLL(Node* head) {
    AddOneToLLRecursively(head);
    if (carry > 0){
        Node* newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// time complexcity: O(n)
// space complexcity: O(1) + O(n) (stack space) = O(n)
            
void printLinkedList(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(9, new Node(9, new Node(9)));
    Node* res = add1ToLL(head);
    printLinkedList(res);
    return 0;
}