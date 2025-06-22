#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::applyOperator(char op, int a, int b) const {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0)
            throw std::runtime_error("Error: division by zero");
        return a / b;
    }
    throw std::runtime_error("Error: unknown operator");
}

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        if (token.length() == 1 && isdigit(token[0])) {
            _stack.push(token[0] - '0');
        }
        else if (token.length() == 1 && isOperator(token[0])) {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            int result = applyOperator(token[0], a, b);
            _stack.push(result);
        }
        else {
            throw std::runtime_error("Error");
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    return _stack.top();
}