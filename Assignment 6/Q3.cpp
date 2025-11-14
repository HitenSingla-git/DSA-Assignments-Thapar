int sizeDLL(DLLNode* head) {
    int count = 0;
    DLLNode* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}


int sizeCLL(CLLNode* head) {
    if (head == NULL) {
        return 0;
    }
    int count = 0;
    CLLNode* current = head;
    do {
        count++;
        current = current->next;
    } while (current != head);
    return count;
}

void question3() {
    cout << "\n--- Q3: Find Size of DLL and CLL ---" << endl;
    
    // Example DLL
    DLLNode* dllHead = createDLLNode(10);
    dllHead->next = createDLLNode(20);
    dllHead->next->prev = dllHead;
    dllHead->next->next = createDLLNode(30);
    dllHead->next->next->prev = dllHead->next;

    cout << "Example DLL (10 <-> 20 <-> 30): Size = " << sizeDLL(dllHead) << endl;

    // Example CLL
    CLLNode* cllHead = createCLLNode(1);
    CLLNode* n2 = createCLLNode(2);
    CLLNode* n3 = createCLLNode(3);
    cllHead->next = n2;
    n2->next = n3;
    n3->next = cllHead;

    cout << "Example CLL (1 -> 2 -> 3 -> 1): Size = " << sizeCLL(cllHead) << endl;
}

