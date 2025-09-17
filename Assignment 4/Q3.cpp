#include <iostream>
#include <queue>
#include <stack>

void interleaveQueue(std::queue<int>& q) {
    if (q.empty() || q.size() % 2 != 0) {
        return;
    }

    int halfSize = q.size() / 2;
    std::stack<int> s;

    for (int i = 0; i < halfSize; ++i) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < halfSize; ++i) {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < halfSize; ++i) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        q.push(q.front());
        q.pop();
        s.pop();
    }
}

void printQueue(std::queue<int> q) {
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    std::cout << "Original Queue: ";
    printQueue(q);

    interleaveQueue(q);

    std::cout << "Interleaved Queue: ";
    printQueue(q);

    return 0;
}
