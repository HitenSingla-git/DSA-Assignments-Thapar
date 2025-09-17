#include <iostream>
#include <queue>
#include <unordered_map>

void findFirstNonRepeating(const std::string& str) {
    std::queue<char> q;
    std::unordered_map<char, int> charCount;

    std::cout << "First non-repeating characters: ";

    for (char ch : str) {
        charCount[ch]++;
        if (charCount[ch] == 1) {
            q.push(ch);
        }

        while (!q.empty() && charCount[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) {
            std::cout << "-1 ";
        } else {
            std::cout << q.front() << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::string input;
    std::cout << "Enter a string of characters (e.g., a b c): ";
    std::getline(std::cin, input);
    
    // Remove spaces from the input string
    std::string s;
    for (char c : input) {
        if (c != ' ') {
            s += c;
        }
    }

    findFirstNonRepeating(s);

    return 0;
}
