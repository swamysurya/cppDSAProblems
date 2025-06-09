#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node* next) : data(data), next(next) {}
};

Node* deleteMiddle(Node* head) {
    if(!head) return nullptr;
    if(!head->next){
        delete head;
        return nullptr;
    }
    Node* slow = head;
    Node* fast = head;
    Node* slowPrev;
    while(fast && fast->next){
        slowPrev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* deletedNode = slow;
    slowPrev->next = slow->next;
    delete deletedNode;
    return head;
    
}

// time complexity: O(n)
// space complexity: O(1)

void printLinkedList(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main(){
    Node* head = new Node(10, new Node(20, new Node(30, new Node(40, new Node(50)))));
    Node* res = deleteMiddle(head);
    printLinkedList(res);
    return 0;
}
