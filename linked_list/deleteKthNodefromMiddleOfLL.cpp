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

Node* deleteKthFromMiddle(Node* head, int k) {
    Node* slow = head;
    Node* fast = head;
    Node* kthNode = nullptr;
    Node* kthPrev = nullptr;
    
    if(!head) return nullptr;
    int count = 1;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        count++;
        
        if(count > k){
            if (!kthNode) {
                kthNode = head;
            }else{
                kthPrev = kthNode;
                kthNode = kthNode->next;
            }
        }
    }
    Node* deletedNode;
    if(kthNode && !kthPrev){
        deletedNode = head;
        head = head->next;
    }else{
        deletedNode = kthNode;
        kthPrev->next = kthPrev->next->next;
    }
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
    Node* head = new Node(10, new Node(20, new Node(30, new Node(40, new Node(50, new Node(60))))));
    Node* res = deleteKthFromMiddle(head, 2);
    printLinkedList(res);
    return 0;
}