#include <iostream>
using namespace std;

struct SLLNode {
    int data;
    SLLNode* next;
};


bool isCircular(SLLNode* head) {
    if (head == NULL) {
        return false; 
    }

    SLLNode* current = head->next;
    while (current != NULL && current != head) {
        current = current->next;
    }

    return (current == head);
}


SLLNode* createSLLNode(int data) {
    SLLNode* newNode = new SLLNode;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


SLLNode* createExampleCLL() {
    SLLNode* head = createSLLNode(2);
    SLLNode* n2 = createSLLNode(4);
    SLLNode* n3 = createSLLNode(6);
    SLLNode* n4 = createSLLNode(7);
    SLLNode* n5 = createSLLNode(5);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = head;
    return head;
}

SLLNode* createExampleSLL() {
    SLLNode* head = createSLLNode(1);
    head->next = createSLLNode(2);
    head->next->next = createSLLNode(3);
    return head;
}

void question5() {
    cout << "\n--- Q5: Check if Linked List is Circular ---" << endl;
    
   
    SLLNode* cllExample = createExampleCLL();
    cout << "LinkedList: 2->4->6->7->5 (Circular check)" << endl;
    cout << "Output: " << (isCircular(cllExample) ? "True" : "False") << endl;

   
    SLLNode* sllExample = createExampleSLL();
    cout << "LinkedList: 1->2->3 (Circular check)" << endl;
    cout << "Output: " << (isCircular(sllExample) ? "True" : "False") << endl;
}
