#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& expr) {
    std::stack<char> s;

    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) return false;

            char open = s.top();
            s.pop();

            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) {
                return false;
                }
        }
    }
    return s.empty();
}

int main() {
    std::string testCases[] = {
        "({[]})",
        "({[})",
        "((()))",
        "(()",
        "]]()["
    };

    std::cout << "--- Pengujian Parentheses Checker ---\n";
    for (const auto& expr : testCases) {
        std::cout << "Ekspresi: " << expr << " -> "
                  << (isBalanced(expr) ? "Balanced" : "Not Balanced") << "\n";
    }

    return 0;
}