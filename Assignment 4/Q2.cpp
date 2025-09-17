#include <iostream>

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Error: The queue is full. Cannot enqueue more items." << std::endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
        std::cout << "Enqueued item: " << item << std::endl;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Error: The queue is empty. Cannot dequeue." << std::endl;
            return -1;
        }
        int item = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        std::cout << "Dequeued item: " << item << std::endl;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Error: The queue is empty. No item to peek." << std::endl;
            return -1;
        }
        std::cout << "Peeked item: " << arr[front] << std::endl;
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "Current Queue: ";
        int i = front;
        do {
            std::cout << arr[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
        std::cout << std::endl;
    }
};

int main() {
    int cap;
    std::cout << "Enter the capacity of the circular queue: ";
    std::cin >> cap;

    CircularQueue cq(cap);
    int choice;
    int item;

    do {
        std::cout << "\n--- Circular Queue Menu ---" << std::endl;
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Peek" << std::endl;
        std::cout << "4. Check if Empty" << std::endl;
        std::cout << "5. Check if Full" << std::endl;
        std::cout << "6. Display" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter item to enqueue: ";
                std::cin >> item;
                cq.enqueue(item);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.peek();
                break;
            case 4:
                if (cq.isEmpty()) {
                    std::cout << "The queue is empty." << std::endl;
                } else {
                    std::cout << "The queue is not empty." << std::endl;
                }
                break;
            case 5:
                if (cq.isFull()) {
                    std::cout << "The queue is full." << std::endl;
                } else {
                    std::cout << "The queue is not full." << std::endl;
                }
                break;
            case 6:
                cq.display();
                break;
            case 7:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 7);

    return 0;
}
