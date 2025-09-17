#include <iostream>
#include <vector>
#include <string>

class Queue {
private:
    std::vector<int> data;
    int max_size;

public:
    Queue(int size) {
        max_size = size;
    }

    bool isEmpty() {
        return data.empty();
    }

    bool isFull() {
        return data.size() >= max_size;
    }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Error: The queue is full. Cannot enqueue " << item << "." << std::endl;
        } else {
            data.push_back(item);
            std::cout << "Enqueued item: " << item << std::endl;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Error: The queue is empty. Cannot dequeue." << std::endl;
            return -1;
        } else {
            int item = data.front();
            data.erase(data.begin());
            std::cout << "Dequeued item: " << item << std::endl;
            return item;
        }
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Error: The queue is empty. No item to peek." << std::endl;
            return -1;
        } else {
            int item = data.front();
            std::cout << "Peeked item: " << item << std::endl;
            return item;
        }
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue: [] (The queue is empty)" << std::endl;
        } else {
            std::cout << "Queue: ";
            for (int item : data) {
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int max_size;
    std::cout << "Enter the maximum size of the queue: ";
    std::cin >> max_size;

    Queue my_queue(max_size);

    int choice;
    int item;

    do {
        std::cout << "\n--- Queue Operations Menu ---" << std::endl;
        std::cout << "1. Enqueue (Add an item)" << std::endl;
        std::cout << "2. Dequeue (Remove an item)" << std::endl;
        std::cout << "3. Peek (View the first item)" << std::endl;
        std::cout << "4. Check if Empty" << std::endl;
        std::cout << "5. Check if Full" << std::endl;
        std::cout << "6. Display the queue" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice (1-7): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the item to enqueue: ";
                std::cin >> item;
                my_queue.enqueue(item);
                break;
            case 2:
                my_queue.dequeue();
                break;
            case 3:
                my_queue.peek();
                break;
            case 4:
                if (my_queue.isEmpty()) {
                    std::cout << "The queue is empty." << std::endl;
                } else {
                    std::cout << "The queue is not empty. " << std::endl;
                }
                break;
            case 5:
                if (my_queue.isFull()) {
                    std::cout << "The queue is full." << std::endl;
                } else {
                    std::cout << "The queue is not full. " << std::endl;
                }
                break;
            case 6:
                my_queue.display();
                break;
            case 7:
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number from 1 to 7." << std::endl;
                break;
        }
    } while (choice != 7);

    return 0;
}
