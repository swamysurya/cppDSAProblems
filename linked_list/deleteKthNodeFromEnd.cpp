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

Node* deleteKthNodeFromEnd(Node* head, int k){
    int count = 0;
    Node* temp = head;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    cout << "count is " << count << endl;

    int deletePos = count - k;

    if (deletePos < 0) return head;
    
    int pos = 1;
    temp = head;
    while(temp != nullptr){
        if (pos == deletePos){
            Node* deletedNode = temp->next;
            temp->next = temp->next->next;
            delete deletedNode;
            break;
        }
        temp = temp->next;
        pos++;
    }
    return head;
}

void printLinedList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}


int main(){
    // create a linked list of values 8 4 5 7 2
    Node* head = new Node(8, new Node(4, new Node(5, new Node(7, new Node(2)))));

    deleteKthNodeFromEnd(head, 2);
    printLinedList(head);
    return 0;
}