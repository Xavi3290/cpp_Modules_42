/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:51:23 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/06 18:04:29 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactCount(0), _oldestIndex(0) {}

PhoneBook::~PhoneBook() {}

static bool isAlpha(const std::string &str) 
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

static bool isDigit(const std::string &str)
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

int stringToInt(const std::string &str) {
    std::istringstream iss(str);
    int num;
    iss >> num;
    return num;
}

static void readValidatedInput(const std::string &prompt, std::string &input, bool (*validate)(const std::string &))
{
    
    while (42){
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cout << "\nEOF detected. Exiting program." << std::endl;
            exit(0);
        }
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

void PhoneBook::addContact() 
{
    Contact newContact;
    std::string input;

    readValidatedInput("Enter first name: ", input, isAlpha);
    newContact.setFirstName(input);
    readValidatedInput("Enter last name: ", input, isAlpha);
    newContact.setLastName(input);
    readValidatedInput("Enter nickname: ", input, NULL);
    newContact.setNickname(input);
    readValidatedInput("Enter phone number: ", input, isDigit);
    newContact.setPhoneNumber(input);
    readValidatedInput("Enter darkest secret: ", input, NULL);
    newContact.setDarkestSecret(input);

    if (_contactCount < MAX_CONTACTS)
    {
        _contacts[_contactCount++] = newContact;
    }
    else
    {
        _contacts[_oldestIndex] = newContact;
        _oldestIndex = (_oldestIndex + 1) % MAX_CONTACTS;
    }
    std::cout << "Contact added successfully." << std::endl;
}

void PhoneBook::printColumn(const std::string &str) const
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << str;
}

void PhoneBook::printContact(int index) const
{
    std::cout << "FirstName: " << _contacts[index].getFirstName() << std::endl;
    std::cout << "LastName: " << _contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
    std::cout << "PhoneNumber: " << _contacts[index].getPhoneNumber() << std::endl;
    std::cout << "DarkestSecret: " << _contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::searchContacts() const
{
    if (_contactCount == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    
    for (int i = 0; i < _contactCount; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        printColumn(_contacts[i].getFirstName());
        std::cout << "|";
        printColumn(_contacts[i].getLastName());
        std::cout << "|";
        printColumn(_contacts[i].getNickname());
        std::cout << std::endl;
    }

    std::string index;
    while (42)
    {
        readValidatedInput("Enter index of the contact you want to display: ", index, isDigit);
        std::ostringstream oss;
        oss << (_contactCount);
        if (index.length() == 1 && index[0] >= '1' && index[0] <= oss.str()[0])
            break;
		std::cout << "Invalid index. Please enter a number between 1 and " << _contactCount << "." << std::endl;
    }
    std::istringstream iss(index);
    printContact(stringToInt(index) - 1);
}
