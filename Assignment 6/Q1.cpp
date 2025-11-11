#include <iostream>
#include <cstdlib>

using namespace std;

// --- Doubly Linked List (DLL) Implementation ---

struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;
};

DLLNode* createDLLNode(int data) {
    DLLNode* newNode = new DLLNode;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void displayDLL(DLLNode* head) {
    if (head == NULL) {
        cout << "DLL is empty." << endl;
        return;
    }
    DLLNode* current = head;
    cout << "DLL: ";
    while (current != NULL) {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Q1(a): DLL Insertion
void insertDLL(DLLNode** head, int data, int position, int specificValue = -1) {
    DLLNode* newNode = createDLLNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if (position == 1) { // As a first node
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    } else if (position == 2) { // As a last node
        DLLNode* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    } else if (position == 3) { // After a specific node
        DLLNode* current = *head;
        while (current != NULL && current->data != specificValue) {
            current = current->next;
        }
        if (current != NULL) {
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != NULL) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        } else {
            cout << "Specific node " << specificValue << " not found." << endl;
            delete newNode;
        }
    } else if (position == 4) { // Before a specific node
        DLLNode* current = *head;
        while (current != NULL && current->data != specificValue) {
            current = current->next;
        }
        if (current != NULL) {
            newNode->prev = current->prev;
            newNode->next = current;
            if (current->prev != NULL) {
                current->prev->next = newNode;
            } else {
                *head = newNode; // New head
            }
            current->prev = newNode;
        } else {
            cout << "Specific node " << specificValue << " not found." << endl;
            delete newNode;
        }
    }
}

// Q1(b): DLL Deletion of a specific node
void deleteDLLNode(DLLNode** head, int key) {
    DLLNode* current = *head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Node " << key << " not found for deletion." << endl;
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next; // Deleted head node
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    delete current;
    cout << "Node " << key << " deleted successfully." << endl;
}

// Q1(c): DLL Search
void searchDLL(DLLNode* head, int key) {
    DLLNode* current = head;
    int pos = 1;
    while (current != NULL) {
        if (current->data == key) {
            cout << "Node " << key << " found at position " << pos << "." << endl;
            return;
        }
        current = current->next;
        pos++;
    }
    cout << "Node " << key << " not found." << endl;
}

// --- Circular Linked List (CLL) Implementation ---

struct CLLNode {
    int data;
    CLLNode* next;
};

CLLNode* createCLLNode(int data) {
    CLLNode* newNode = new CLLNode;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void displayCLL(CLLNode* head) {
    if (head == NULL) {
        cout << "CLL is empty." << endl;
        return;
    }
    CLLNode* current = head;
    cout << "CLL: ";
    do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != head);
    cout << "(Head " << head->data << ")" << endl;
}

Q1(a): CLL Insertion
void insertCLL(CLLNode** head, int data, int position, int specificValue = -1) {
    CLLNode* newNode = createCLLNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    CLLNode* last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    if (position == 1) { // As a first node
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
    } else if (position == 2) { // As a last node
        newNode->next = *head;
        last->next = newNode;
    } else if (position == 3) { // After a specific node
        CLLNode* current = *head;
        CLLNode* temp = NULL;
        do {
            if (current->data == specificValue) {
                temp = current;
                break;
            }
            current = current->next;
        } while (current != *head);

        if (temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            cout << "Specific node " << specificValue << " not found." << endl;
            delete newNode;
        }
    } else if (position == 4) { // Before a specific node (simplified by inserting after prev node)
        CLLNode* current = *head;
        CLLNode* prev = last;
        CLLNode* temp = NULL;
        do {
            if (current->data == specificValue) {
                temp = prev;
                break;
            }
            prev = current;
            current = current->next;
        } while (current != *head);

        if (temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
            if (current == *head) { // If inserting before head, new node becomes the head
                *head = newNode;
            }
        } else {
            cout << "Specific node " << specificValue << " not found." << endl;
            delete newNode;
        }
    }
}

// Q1(b): CLL Deletion of a specific node
void deleteCLLNode(CLLNode** head, int key) {
    if (*head == NULL) {
        cout << "CLL is empty. Cannot delete." << endl;
        return;
    }

    CLLNode* current = *head;
    CLLNode* prev = NULL;

    // Find the node to delete and its previous node
    do {
        if (current->data == key) {
            break;
        }
        prev = current;
        current = current->next;
    } while (current != *head);

    if (current->data != key) {
        cout << "Node " << key << " not found for deletion." << endl;
        return;
    }

    if (current == *head && current->next == *head) { // Single node case
        *head = NULL;
    } else if (current == *head) { // Head node deletion
        CLLNode* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        *head = current->next;
        last->next = *head;
    } else { // Deletion in between or last node
        prev->next = current->next;
    }

    delete current;
    cout << "Node " << key << " deleted successfully." << endl;
}

// Q1(c): CLL Search
void searchCLL(CLLNode* head, int key) {
    if (head == NULL) {
        cout << "CLL is empty. Node " << key << " not found." << endl;
        return;
    }
    CLLNode* current = head;
    int pos = 1;
    do {
        if (current->data == key) {
            cout << "Node " << key << " found at position " << pos << "." << endl;
            return;
        }
        current = current->next;
        pos++;
    } while (current != head);
    cout << "Node " << key << " not found." << endl;
}

void question1() {
    DLLNode* dllHead = NULL;
    CLLNode* cllHead = NULL;
    int choice, subChoice, data, specificVal;

    while (true) {
        cout << "\n--- Q1 Menu: DLL and CLL Operations ---" << endl;
        cout << "1. Doubly Linked List (DLL) Operations" << endl;
        cout << "2. Circular Linked List (CLL) Operations" << endl;
        cout << "3. Exit Q1" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 3) break;

        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Search" << endl;
        cout << "4. Display" << endl;
        cout << "Enter sub-choice: ";
        cin >> subChoice;

        if (choice == 1) { // DLL Operations
            if (subChoice == 1) {
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Insert: 1. As first 2. As last 3. After specific 4. Before specific: ";
                int pos;
                cin >> pos;
                specificVal = -1;
                if (pos == 3 || pos == 4) {
                    cout << "Enter specific value: ";
                    cin >> specificVal;
                }
                insertDLL(&dllHead, data, pos, specificVal);
            } else if (subChoice == 2) {
                cout << "Enter node data to delete: ";
                cin >> specificVal;
                deleteDLLNode(&dllHead, specificVal);
            } else if (subChoice == 3) {
                cout << "Enter node data to search: ";
                cin >> specificVal;
                searchDLL(dllHead, specificVal);
            } else if (subChoice == 4) {
                displayDLL(dllHead);
            }
        } else if (choice == 2) { // CLL Operations
            if (subChoice == 1) {
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Insert: 1. As first 2. As last 3. After specific 4. Before specific: ";
                int pos;
                cin >> pos;
                specificVal = -1;
                if (pos == 3 || pos == 4) {
                    cout << "Enter specific value: ";
                    cin >> specificVal;
                }
                insertCLL(&cllHead, data, pos, specificVal);
            } else if (subChoice == 2) {
                cout << "Enter node data to delete: ";
                cin >> specificVal;
                deleteCLLNode(&cllHead, specificVal);
            } else if (subChoice == 3) {
                cout << "Enter node data to search: ";
                cin >> specificVal;
                searchCLL(cllHead, specificVal);
            } else if (subChoice == 4) {
                displayCLL(cllHead);
            }
        }
    }
}
