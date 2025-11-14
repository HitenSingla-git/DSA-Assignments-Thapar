#include <iostream>
using namespace std;

bool isPalindromeDLL(DLLNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

   
    DLLNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }


    DLLNode* start = head;
    DLLNode* end = tail;

    while (start != end && start->prev != end) {
        if (start->data != end->data) {
            return false;
        }
        start = start->next;
        end = end->prev;
    }
    return true;
}


DLLNode* createCharDLL(const char* s) {
    DLLNode* head = NULL;
    DLLNode* tail = NULL;
    for (int i = 0; s[i] != '\0'; ++i) {
        DLLNode* newNode = createDLLNode(s[i]);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}

void question4() {
    cout << "\n--- Q4: Check DLL Palindrome ---" << endl;
    
 
    DLLNode* dll1 = createCharDLL("LEVEL");
    cout << "Input: L E V E L (Palindrome check)" << endl;
    cout << "Output: " << (isPalindromeDLL(dll1) ? "True" : "False") << endl;

    DLLNode* dll2 = createCharDLL("NOT");
    cout << "Input: N O T (Palindrome check)" << endl;
    cout << "Output: " << (isPalindromeDLL(dll2) ? "True" : "False") << endl;
}
