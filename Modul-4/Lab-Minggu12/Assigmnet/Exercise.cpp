#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int evaluatePostfix(const std::string& expr) {
    std::stack<int> s;
    std::stringstream ss(expr);
    std::string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
            else if (token == "/") s.push(a / b);
        }
        else {
            s.push(std::stoi(token));
        }
    }
    return s.top();
}

int main() {
    std::string expr1 = "3 4 + 5 *";
    std::string expr2 = "10 2 8 * + 3 -";

    std::cout << "--- Pengujian Postfix Evaluator ---\n";
    std::cout << "Ekspresi: '" << expr1 << "' -> Hasil: " << evaluatePostfix(expr1) << "\n";
    std::cout << "Ekspresi: '" << expr2 << "' -> Hasil: " << evaluatePostfix(expr2) << "\n";

    return 0;
}

