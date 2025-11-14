void displayCLLHeadRepeat(CLLNode* head) {
    if (head == NULL) {
        cout << "CLL is empty." << endl;
        return;
    }
    CLLNode* current = head;
    cout << "Output: ";
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);

    // Repeat value of head node at the end
    cout << head->data << "." << endl;
}

void question2() {
    cout << "\n--- Q2: Display CLL with Head Repeated ---" << endl;
    // Input: 20->100->40->80->60. [cite: 12]
    CLLNode* head = createCLLNode(20);
    CLLNode* n2 = createCLLNode(100);
    CLLNode* n3 = createCLLNode(40);
    CLLNode* n4 = createCLLNode(80);
    CLLNode* n5 = createCLLNode(60);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = head; // Make it circular

    cout << "Input: 20 -> 100 -> 40 -> 80 -> 60." << endl;
    displayCLLHeadRepeat(head);
}
