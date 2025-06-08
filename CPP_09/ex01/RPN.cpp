#include "RPN.hpp"

RPN::RPN() : _input("8 9 * 9 - 9 - 9 - 4 - 1 +") {
}

RPN::RPN(const std::string &inputStr) : _input(inputStr) {
}

RPN::RPN(const RPN &other) : _input(other._input) {
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->_input = other._input;
    }
    return *this;
}

RPN::~RPN() {
}

int RPN::count_rpn()
{
    std::istringstream iss(_input);
    std::stack<int> stack;
    std::string token;

    while (iss >> token)
    {
        if (isdigit(token[0]) && token.size() == 1)
            stack.push(token[0] - '0');
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
                throw ErrorFormat();
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            if (token == "+")
                stack.push(a + b);
            else if (token == "-")
                stack.push(a - b);
            else if (token == "*")
                stack.push(a * b);
            else if (token == "/")
            {
                if (b == 0)
                    throw ErrorFormat();
                stack.push(a / b);
            }
        }
        else
            throw ErrorFormat();
    }

    if (stack.size() != 1)
        throw ErrorFormat();
    return stack.top();
}