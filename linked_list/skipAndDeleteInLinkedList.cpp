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

Node* deleteNAfterMNodes(Node* head, int m, int n) {
    // initialise cur to head 
    Node* curr = head;
    // iterate till end 
    while(curr != nullptr){
        // loop for skip m nodes by starting from head to pos where the next points to be deleted
        // while iterating we not fall into segemnation error
        for(int i = 1; i < m && curr != nullptr; ++i) curr = curr->next;
        // if curr null means we skiped all ll nodes so no need of deletion
        if (curr == nullptr) break;
        // if from next node to curret node we need to start delete till n nodes
        // so moved till where temp holds a node where we need to connect to prev curre node 
        // while iterating we not fall into segemnation error
        Node* temp = curr->next;
        for(int j = 0; j < n && temp != nullptr; ++j){
            Node* deleteNode = temp;
            temp = temp->next;
            delete deleteNode;
        }
        // attach it
        curr->next = temp;
        // make curr is temp to repeat the process
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
// time complexcity: O(N);
// space complexcity: O(1);

int main(){
    // Create linked list of 2 4 6 8 10 12 14 16 18 
    Node* head = new Node(2, new Node(4, new Node(6, new Node(8, new Node(10, new Node(12, new Node(14, new Node(16, new Node(18)))))))));
    int m = 2, n = 3;
    head = deleteNAfterMNodes(head, m, n);
    Node* temp = head;
    printLinkedList(temp);

}