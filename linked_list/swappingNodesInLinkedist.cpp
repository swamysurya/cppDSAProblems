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

// three loop appraoch
Node* swapNodesThreeLoop(Node* head, int k) {
    Node* current = head;
    int length = 0;
    // Calculate the length of the linked list
    while (current != NULL) {
        length++;
        current = current->next;
    }
    // If k is greater than the length of the list, return the original list
    if (k > length) return head;
    // Find the kth node from the beginning
    Node* firstNode = head;
    for (int i = 1; i < k; i++)
        firstNode = firstNode->next;
    
    // Find the kth node from the end
    Node* secondNode = head;
    for (int i = 1; i < length - k + 1; i++)
        secondNode = secondNode->next;

    // Swap the data of the two nodes
    swap(firstNode->data, secondNode->data);

    return head;
}

// timee complexcity:O(2N) = O(N);
// space complexcity: O(1);

void printLinkedList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

Node* swapNodesTwoPass(Node* head, int k) {
    Node* front = head;
    Node* back = head;
    Node* frontNode;
    Node* backNode;
    // move front pointer to kth node
    for(int i=1; i < k && front->next != nullptr; ++i){
        front = front->next;
    }
    // if front is null means k is greater than length of linked list
    if(front == nullptr) return head;
    // store front node
    backNode = front;

    // move front pointer to end of linked list
    while(front->next != nullptr){
        front = front->next;
        back = back->next;
    }
    // store back node
    frontNode = back;

    // swap data of front and back node
    int temp = frontNode->data;
    frontNode->data = backNode->data;
    backNode->data = temp;
    // return head
    return head;
}

Node* swapNodesSinglePass(Node* head, int k) {
    Node* current = head;
    Node* firstNode = nullptr;
    Node* secondNode = nullptr;
    int length = 0; // length of linked list
    // iterate till end of linked list
    while (current != NULL) {
        // indicates the current position of the node
        length++;
        // second node not null measn we found first node
        // we need move till end of linked list

        if (secondNode != nullptr) {
            secondNode = secondNode->next;
        }
        // if position is equal to k means we need to store the first node
        // make second node to point to head
        if (length == k) {
            firstNode = current;
            secondNode = head;
        }
        // move current pointer to next node
        current = current->next;
    }
    // if loop terminated means we reached end of linked list
    // fisrt node data we aleary stored
    // second node is pointing to kth node from end of linked list
    swap(firstNode->data, secondNode->data);

    return head;
}

int main(){
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5,new Node(6))))));
    int k = 2;

    // Node* head1 = swapNodesThreeLoop(head, k);
    Node* head2 = swapNodesSinglePass(head, k);
    cout << "After swapping nodes at position " << k << " and " << (6 - k + 1) << ":" << endl;
    printLinkedList(head);
}