/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:29:19 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/09/20 15:06:27 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const &x) {
    std::cout << x << std::endl;
}

template <typename T>
void sum(T const &x) {
    std::cout << x + x << std::endl;
}

int main() {
    int tabInt[] = {0 , 1, 2, 3, 4, 5};
    unsigned int lenInt = sizeof(tabInt) / sizeof(*tabInt);
    
    char tabChar[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned int lenChar = sizeof(tabChar) / sizeof(*tabChar);

    std::string tabStr[] = {"Hello", "World", "42", "Barcelona"};
    unsigned int lenStr = sizeof(tabStr) / sizeof(*tabStr);

    std::cout << "Printing int array:" << std::endl;
    iter(tabInt, lenInt, print);

    std::cout << "\nPrinting char array:" << std::endl;
    iter(tabChar, lenChar, print);
    
    std::cout << "\nPrinting string array:" << std::endl;
    iter(tabStr, lenStr, print);

    std::cout << "\nSum int array:" << std::endl;
    iter(tabInt, lenInt, sum);

    std::cout << "\nSum char array (ASCII values):" << std::endl;
    iter(tabChar, lenChar, sum);

    std::cout << "\nSum string array (concat):" << std::endl;
    iter(tabStr, lenStr, sum);

    return 0;
}

