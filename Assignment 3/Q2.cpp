#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str) {
    stack<char> s;

    
    for (char ch : str) {
        s.push(ch);
    }


    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string reversed = reverseString(input);
    cout << "Reversed string: " << reversed << endl;

    return 0;
}
