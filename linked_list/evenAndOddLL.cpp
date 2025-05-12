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

Node* evenAndOdd(Node* head) {
    Node* even = head;
    Node* odd = head->next;
    Node* oddHead = odd;
    
    while(odd != nullptr && odd->next != nullptr){
        even->next = even->next->next;
        odd->next = odd->next->next;
        even = even->next;
        odd = odd->next;
    }
    even->next = oddHead;
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
    Node* res = evenAndOdd(head);
    printLinkedList(res);
    return 0;
}
