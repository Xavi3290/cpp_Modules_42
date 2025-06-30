/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:18:01 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/06/30 20:34:19 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    try {
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;
        
        Array<int> nums(5);
        std::cout << "Array size: " << nums.size() << std::endl;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            nums[i] = i * 10;
        }
        std::cout << "Array contents: ";
        for (unsigned int i = 0; i < nums.size(); ++i) {
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;

        Array<int> copy(nums);
        std::cout << "Copy array size: " << copy.size() << std::endl;
        std::cout << "Copy array contents: ";
        for (unsigned int i = 0; i < copy.size(); ++i) {
            std::cout << copy[i] << " ";
        }
        std::cout << std::endl;

        Array<int> assigned;
        assigned = nums;
        std::cout << "Assigned array size: " << assigned.size() << std::endl;
        std::cout << "Assigned array contents: ";
        for (unsigned int i = 0; i < assigned.size(); ++i) {
            std::cout << assigned[i] << " ";
        }
        std::cout << std::endl;
        
        nums[0] = 100;
        std::cout << "Modified original array contents: " << std::endl;
        std::cout << nums[0] << std::endl;
        std::cout << copy[0] << std::endl;

        std::cout << "Trying to access out of bounds index:" << std::endl;
        std::cout << nums[10] << std::endl;
    }
    catch (const Array<int>::OutOfBoundsException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
