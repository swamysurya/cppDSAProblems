#include <bits/stdc++.h> // Includes all standard C++ libraries with a single directive
using namespace std; // Allows usage of standard library components without the std:: prefix

// Definition of a Node in a linked list
class Node {
    public:
        int data; // Data stored in the node
        Node* next; // Pointer to the next node in the list
        
        Node(): data(0), next(nullptr) {} // Default constructor initializing data to 0 and next to nullptr
        Node(int data) : data(data), next(nullptr) {} // Constructor initializing data with a given value and next to nullptr
        Node(int data, Node* next) : data(data), next(next) {} // Constructor initializing data and next with given values
};

// Solution class encapsulating methods to work with linked lists
class solution {
public:

    // Method to calculate the length of a linked list
    int getLength(Node* head){
        int count = 0; // Initialize count of nodes
        while(head != nullptr) { // Traverse until the end of the list
            count++; // Increment count for each node
            head = head->next; // Move to the next node
        }
        return count; // Return the total count of nodes
    }
    
    // Method to add zero padding to a linked list
    Node* zeroPadding(Node* head, int paddingLen){
        while(paddingLen--){ // Loop until padding length is exhausted
            Node* newNode = new Node(0); // Create a new node with data 0
            newNode->next = head; // Link the new node to the current head
            head = newNode; // Update head to the new node
        }
        return head; // Return the new head of the padded list
    }
    
    // Recursive method to add two numbers represented by linked lists
    void addToLinkedList(Node* a, Node* b, int sum, int& carry, Node*& dummy){
        if(a == nullptr && b == nullptr) return; // Base case: if both lists are exhausted, return
        
        Node* nextA = (a->next != nullptr) ? a->next : nullptr; // Get the next node of list a
        Node* nextB = (b->next != nullptr) ? b->next : nullptr; // Get the next node of list b
        
        addToLinkedList(nextA, nextB, sum, carry, dummy); // Recursive call for the next nodes
        
        int aVal = (a != nullptr) ? a->data : 0; // Get data from node a or 0 if null
        int bVal = (b != nullptr) ? b->data : 0; // Get data from node b or 0 if null
        
        sum = aVal + bVal + carry; // Calculate the sum of both nodes and carry
        carry = sum / 10; // Update carry for the next iteration
        Node* temp = new Node(sum % 10); // Create a new node with the digit part of the sum
        temp->next = dummy; // Link the new node to the result list
        dummy = temp; // Update dummy to the new node
    }

    // Method to add two numbers represented by linked lists
    Node* addTwoNumbers(Node* a, Node* b){
        int lenA = getLength(a); // Get the length of list a
        int lenB = getLength(b); // Get the length of list b
        
        if(lenA < lenB) a = zeroPadding(a, lenB - lenA); // Pad list a if it's shorter
        else b = zeroPadding(b, lenA - lenB); // Pad list b if it's shorter
        
        Node* dummy = nullptr; // Initialize dummy node for result
        int carry = 0; // Initialize carry to 0
        addToLinkedList(a, b, 0, carry, dummy); // Add the two lists
        
        if(carry) { // If there's a remaining carry
            Node* temp = new Node(carry); // Create a new node with the carry
            temp->next = dummy; // Link it to the result list
            dummy = temp; // Update dummy to the new node
        }
        
        return dummy; // Return the head of the result list
    }
    

    
    // method to reverse the linked list
    // utility function 
    Node* reverseLinkedList(Node* head){
        Node* prev = nullptr;
        while(head != nullptr){
            Node* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    // method 2 
    Node* addTwoNumbersByReverse(Node* a, Node* b){
        // reverse the linked list to make it easy to add the numbers
        a = reverseLinkedList(a);
        b = reverseLinkedList(b);
        
        Node* dummy = nullptr;
        int carry = 0;

        // loop till a or b is not null or carry is not zero
        while(a != nullptr || b != nullptr || carry != 0){
            // extract only if a or b is not null
            int aVal = (a != nullptr) ? a->data : 0;
            int bVal = (b != nullptr) ? b->data : 0;
            // get the sum and update the carry
            int sum = aVal + bVal + carry;
            carry = sum / 10;
            // create a node for store in result linked list
            Node* temp = new Node(sum % 10);
            // this two add new node moves head pointer to next
            temp->next = dummy;
            dummy = temp;
            // move to next node
            if(a != nullptr) a = a->next;
            if(b != nullptr) b = b->next;
        }
        return dummy;
    }

    // method 3 
    // using stack 
    Node* addTwoNumbersByStack(Node* a, Node* b){
        stack<int> s1;
        stack<int> s2;
        
        while(a != nullptr){
            s1.push(a->data);
            a = a->next;
        }
        while(b != nullptr){
            s2.push(b->data);
            b = b->next;
        }
        
        Node* dummy = nullptr;
        int carry = 0;
        while(!s1.empty() || !s2.empty() || carry != 0){
            int aVal = (s1.empty()) ? 0 : s1.top();
            int bVal = (s2.empty()) ? 0 : s2.top();
            int sum = aVal + bVal + carry;
            carry = sum / 10;
            Node* temp = new Node(sum % 10);
            temp->next = dummy;
            dummy = temp;
            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
        }
        return dummy;
    }

};

// Function to print the linked list
void printLinkedList(Node* head){
    Node* temp = head; // Start from the head
    while(temp != nullptr){ // Traverse until the end of the list
        cout << temp->data << " -> "; // Print the data of each node
        temp = temp->next; // Move to the next node
    }
    cout << "nullptr" << endl; // Print the end of the list
}

int main(){
    Node* a = new Node(9, new Node(9, new Node(9, new Node(9)))); // Create first linked list representing 9999
    Node* b = new Node(1); // Create second linked list representing 1
    solution s; // Create an instance of solution
    Node* res = s.addTwoNumbers(a,b); // Add the two numbers
    printLinkedList(res); // Print the result
    

    // // method two testing
    // coomnet th
    Node* res2 = s.addTwoNumbersByReverse(a,b);  // This reverses 'a' and 'b' in-place
    // printLinkedList(res2);

    Node* res3 = s.addTwoNumbersByStack(a,b);
    printLinkedList(res3);
    return 0;
}

// for example i have elements 1 2 3 4 5 = arr
// create a linked list in reverse orderby

/*
Node* dummy = nullptr;
int i = 0;

while(i < n){
    Node* temp = new Node(arr[i]);
    temp->next = dummy;
    dummy = temp;
    i++;
}

res => 5 -> 4 -> 3 -> 2 -> 1 -> nullptr


*/