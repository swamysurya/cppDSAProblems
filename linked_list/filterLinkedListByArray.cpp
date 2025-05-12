#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Node class to represent each element in the linked list
class Node{
    public:
        int data; // Data stored in the node
        Node* next; // Pointer to the next node

    public:
        // Constructor to initialize the node with a value
        Node(int value){
            data = value;
            next = nullptr;
        }
};

// Function to convert an array into a linked list
Node* arrayToLinkedList(vector<int> arr, int n){
    Node* head = new Node(arr[0]); // Initialize the head of the linked list
    Node* temp;
    Node* curr = head;
    for(int i = 1; i < n; i++){
        temp = new Node(arr[i]); // Create a new node for each element in the array
        curr->next = temp; // Link the current node to the new node
        curr = temp; // Move to the new node
    }
    return head; // Return the head of the linked list
}

// Function to delete nodes from the linked list that have values present in the array
Node* deleteNodes(Node* head, vector<int>& arr) {
    // Convert array to set for O(1) lookup
    if(head == nullptr) return head; // Return if the list is empty
    unordered_set<int> arrSet(arr.begin(), arr.end());
    
    // Remove nodes from the head that match values in the set
    while((arrSet.count(head->data) != 0) && head != nullptr){
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
    }
    
    Node* temp = head;
    Node* prevNode = nullptr;
    
    // Traverse the list and delete nodes with matching values
    while(temp != nullptr){
        if (arrSet.count(temp->data)){
            Node* deletedNode = temp;
            prevNode->next = temp->next; // Bypass the node to be deleted
            temp = temp->next; // Move to the next node
            delete deletedNode; // Delete the node
        }else{
            prevNode = temp; // Move prevNode to current node
            temp = temp->next; // Move to the next node
        }
    }
    return head; // Return the modified head of the list
}

// Function to print the linked list
void printLinkedList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> "; // Print the data of each node
        temp = temp->next; // Move to the next node
    }
    cout << "nullptr" << endl; // End of the list
}

int main(){
    int n = 5;
    vector<int> arr = {1,2,3,4,5}; // Initialize an array
    Node* head = arrayToLinkedList(arr, n); // Convert array to linked list
    int m = 3;
    vector<int> arr2 = {2,4,6}; // Array of values to be deleted from the list
    Node* filteredHead = deleteNodes(head, arr2); // Delete nodes from the list
    printLinkedList(filteredHead); // Print the modified list
    return 0;
}