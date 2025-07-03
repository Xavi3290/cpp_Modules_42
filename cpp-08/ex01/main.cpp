/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:23:36 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/07/03 15:37:28 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main() {

    std::cout << "Exception adding number to full span:" << std::endl;
    Span sp(5);
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        sp.addNumber(42);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nAdding numbers to span with addNumbers:" << std::endl;

    Span rangeSp(10);
    std::vector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i * 2);
    }
    try {
        rangeSp.addNumbers(v.begin(), v.end());
        std::cout << "Shortest span in range: " << rangeSp.shortestSpan() << std::endl;
        std::cout << "Longest span in range: " << rangeSp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTesting shortestSpan and longestSpan with less than two numbers:" << std::endl;

    Span shortSp(2);
    try {
        shortSp.addNumber(1);
        shortSp.shortestSpan();
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    try {
        shortSp.longestSpan();
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTesting longestSpan:" << std::endl;

    const int N = 10000;
    Span largeSp(N);
    srand(time(0));
    for (int i = 0; i < N; ++i) {
        largeSp.addNumber(rand() % 100000);
    }
    try {
        std::cout << "Shortest span in large span: " << largeSp.shortestSpan() << std::endl;
        std::cout << "Longest span in large span: " << largeSp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}