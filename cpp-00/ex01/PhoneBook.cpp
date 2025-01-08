/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:51:23 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/01/08 19:14:00 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactCount(0), _oldestIndex(0) {}

PhoneBook::~PhoneBook() {}

bool isAlpha(const std::string &str) 
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isalpha(str[i]))
        {
            std::cout << "Invalid input. Please enter only alphabetic characters." << std::endl;
            return false;
        }
    }
    return true;
}

bool isDigit(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
        {
            std::cout << "Invalid input. Please enter only numeric characters." << std::endl;
            return false;
        }
    }
    return true;
}

void readVlaidatedInput(const std::string &prompt, std::string &input, bool (*validate)(const std::string &))
{
    
    while (42){
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof()) exit(0);
        if (input.empty())
        {
            std::cout << "Field cannot be empty." << std::endl;
            continue;
        }
        if (validate && !validate(input))
            continue;
        break;    
    }
}