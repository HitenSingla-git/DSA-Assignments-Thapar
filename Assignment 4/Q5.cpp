#include <iostream>
#include <queue>

class StackWithTwoQueues {
private:
    std::queue<int> q1;
    std::queue<int> q2;

public:
    void push(int x) {
        q1.push(x);
        std::cout << "Pushed " << x << " to the stack." << std::endl;
    }

    int pop() {
        if (q1.empty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        int popped = q1.front();
        q1.pop();
        
        std::queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        std::cout << "Popped " << popped << " from the stack." << std::endl;
        return popped;
    }

    int top() {
        if (q1.empty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        int topElement = q1.front();
        q2.push(q1.front());
        q1.pop();
        
        std::queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return topElement;
    }

    bool empty() {
        return q1.empty();
    }
};

void runStackWithTwoQueues() {
    StackWithTwoQueues s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();
    s.pop();

    s.push(40);
    s.pop();
}

int main() {
    runStackWithTwoQueues();
    return 0;
}
