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


Node* SortLL(Node* head) {
    // initilaise three node pointers for 0,1,2 these points to heads of each list 
    Node* zerosHead = nullptr;
    Node* onesHead = nullptr;
    Node* twosHead = nullptr;
    
    // for iterating take 3 pointers at final these iterator have end value as ends of each respective list
    Node* zerosIt = nullptr;
    Node* onesIt = nullptr;
    Node* twosIt = nullptr;
    
    Node* temp = head; // temp for iterating linked list 
    // to ensure all element in linked list is completed 
    while(temp != nullptr){
        int nodeVal = temp->data;
        // case 1 where value equal to zeros 
        if(nodeVal == 0){
            // if that was the first node make it as 0s head
            if(zerosHead == nullptr) zerosHead = temp;
            else zerosIt->next = temp;
            // move iterator to forward
            zerosIt = temp;
        }
        if(nodeVal == 1){
            // if that was first node make it as 1s head 
            if(onesHead == nullptr) onesHead = temp;
            else onesIt->next = temp;
            onesIt = temp;
        }
        if (nodeVal == 2){
            // if that was first node make it as 2s head 
            if(twosHead == nullptr) twosHead = temp;
            else twosIt->next = temp;
            twosIt = temp;
        }
        temp = temp->next;
    }
    
    // these three if statements are for conncetion purpose 
    // connect the zeros end end eaither ones head of zeros head 
    if(zerosIt != nullptr){ //if true means we can easy coonect the either ones or twos head 
        if(onesHead != nullptr) zerosIt->next = onesHead;
        else zerosIt->next = twosHead;
    }
    // if onesIt not null means we can conncet twos head to end of onesIt end 
    if(onesIt != nullptr) onesIt->next = twosHead;
    if(twosIt != nullptr) twosIt->next = nullptr;
    
    // based on list availability return list 
    if(zerosHead != nullptr) return zerosHead;
    if(onesHead != nullptr) return onesHead;
    return twosHead;
}

Node* sortBasedOnCount(Node* head){
    int zerosCount = 0;
    int onesCount = 0;
    int twosCount = 0;

    Node* temp = head;
    // count the number of 0s, 1s and 2s
    while(temp != nullptr){
        if(temp->data == 0) zerosCount++;
        else if(temp->data == 1) onesCount++;
        else twosCount++;
        temp = temp->next;
    }

    // update the linked list based on the count
    temp = head;
    while(temp != nullptr){
        // update the node value based on the count
        if(zerosCount-- > 0) temp->data = 0;
        else if(onesCount-- > 0) temp->data = 1;
        else temp->data = 2;
        // move to next node
        temp = temp->next;
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
    Node* head = new Node(0, new Node(1, new Node(2, new Node(0, new Node(1, new Node(2))))));
    // Node* res = SortLL(head);
    Node* res = sortBasedOnCount(head);
    printLinkedList(res);
    return 0;
}