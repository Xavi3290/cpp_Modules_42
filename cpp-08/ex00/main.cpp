/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:14:08 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/09/20 15:09:28 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    std::list<int> lst;
    for (int i = 1; i <= 10; ++i) {
        vec.push_back(i);
        lst.push_back(i);
    }
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found " << *it << " in vector at position " << std::distance(vec.begin(), it) << std::endl;
    }
    catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 7);
        std::cout << "Found " << *it << " in list at position " << std::distance(lst.begin(), it) << std::endl;
    }
    catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }

    try{
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Found " << *it << " in vector at position " << std::distance(vec.begin(), it) << std::endl;
    }
    catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }

    try{
        std::list<int>::iterator it = easyfind(lst, 42);
        std::cout << "Found " << *it << " in list at position " << std::distance(lst.begin(), it) << std::endl;
    }
    catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;    
}

