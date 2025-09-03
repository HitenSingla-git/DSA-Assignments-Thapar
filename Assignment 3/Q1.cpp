#include <iostream>
using namespace std;

#define MAX 5  

int stack[MAX];
int top = -1;

bool isFull() {
    return top == MAX - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(int val) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push " << val << endl;
    } else {
        stack[++top] = val;
        cout << val << " pushed into stack." << endl;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Nothing to pop." << endl;
    } else {
        cout << stack[top--] << " popped from stack." << endl;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty. No top element." << endl;
    } else {
        cout << "Top element is: " << stack[top] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Stack Operations Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                if (isEmpty()) cout << "Stack is empty." << endl;
                else cout << "Stack is not empty." << endl;
                break;
            case 5:
                if (isFull()) cout << "Stack is full." << endl;
                else cout << "Stack is not full." << endl;
                break;
            case 6:
                display();
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
