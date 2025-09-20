/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:52:54 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/09/20 15:15:19 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <cctype>
#include <iostream>

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    (void)other;
}

RPN &RPN::operator=(const RPN &other) {
    (void)other;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::applyOp(int lOperand, int rOperand, const std::string &op) {
    if (op == "+") 
        return lOperand + rOperand;
    if (op == "-") 
        return lOperand - rOperand;
    if (op == "*") 
        return lOperand * rOperand;
    if (op == "/") {
        if (rOperand == 0) {
            throw std::runtime_error("Division by zero");
        }
        return lOperand / rOperand;
    }
    throw std::invalid_argument("Unknown operator: " + op);
}

void RPN::evaluate(const std::string &expression) const {
    std::istringstream ss(expression);
    std::stack<int> stack;
    std::string token;

    while (ss >> token) {
        if (isOperator(token)) {
            if (stack.size() < 2) {
                throw std::runtime_error("Error");
            }
            int rOperand = stack.top();
            stack.pop();
            int lOperand = stack.top();
            stack.pop();
            int result = applyOp(lOperand, rOperand, token);
            stack.push(result);
        } else if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0]))) {
            stack.push(token[0] - '0');
        } else {
            throw std::invalid_argument("Error");
        }
    }
    if (stack.size() != 1) {
        throw std::runtime_error("Error");
    }
    std::cout << stack.top() << std::endl;
}

