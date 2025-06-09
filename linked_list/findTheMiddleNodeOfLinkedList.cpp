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

Node* findKthFromMiddle(Node* head, int k) {
    if (!head) return nullptr;
    
    Node* kthPrevNode = nullptr;
    Node* kthNode = head;
    Node* slowPointerPrevNode = nullptr;
    Node* slowPointer = head;
    Node* fastPointer = head;
    int count = 0;
    while(fastPointer && fastPointer->next){
        slowPointerPrevNode = slowPointer;
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
        count++;
        
        if (count > k) {
            kthPrevNode = kthNode;
            kthNode = kthNode->next;
        };
        
    }
    return kthNode;
};


int main(){
    // 10 -> 20 -> 30 -> 40 -> 50 -> 60, k = 2
    Node* head = new Node(10, new Node(20, new Node(40, new Node(30, new Node(50, new Node(60))))));
    Node* res = findKthFromMiddle(head, 2);
    cout << res->data << endl;
    return 0;
    
}