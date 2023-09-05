#include <iostream>
#include <stack>
#include <string>

bool CheckParenthesis(const std::string& s) {
    std::stack<char> stack;
    for (char i : s) {
        if (i == '(' || i == '{' || i == '[') {
            stack.push(i);
        } else if (i == ')' || i == '}' || i == ']') {
            if (stack.empty()) {
                std::cout << "No" << std::endl;
                return false;
            } else if (i == ')' && stack.top() == '(') {
                stack.pop();
            } else if (i == '}' && stack.top() == '{') {
                stack.pop();
            } else if (i == ']' && stack.top() == '[') {
                stack.pop();
            } else {
                std::cout << "No" << std::endl;
                return false;
            }
        }
    }

    if (stack.empty()) {
        std::cout << "Yes" << std::endl;
        return true;
    } else {
        std::cout << "No" << std::endl;
        return false;
    }
}

int main() {
    int testCases;
    std::cin >> testCases;
    std::cin.ignore(); // Ignore the newline character

    for (int i = 0; i < testCases; ++i) {
        std::string s;
        std::getline(std::cin, s);
        if (CheckParenthesis(s)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}