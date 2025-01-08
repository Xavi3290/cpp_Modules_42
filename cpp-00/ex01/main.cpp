/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavi <xavi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:51:23 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/01/08 23:05:11 by xavi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void printMenu()
{
    std::cout << "\nAvailable commands:" << std::endl << std::endl;
    std::cout << "     ADD: Add a new contact" << std::endl;
    std::cout << "     SEARCH: Search and display contacts" << std::endl;
    std::cout << "     EXIT: Exit the program" << std::endl << std::endl;
    std::cout << "Enter your command: ";
}

int main()
{
    PhoneBook phonebook;
    std::string command;
    
    while (42)
    {
        printMenu();
        std::getline(std::cin, command);
        if (std::cin.eof())
        {
            std::cout << "\nEOF detected. Exiting program." << std::endl;
            break;
        }
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContacts();
        else if (command == "EXIT")
        {
            std::cout << "Exiting program. Goodbye!" << std::endl;
            break;
        }
        else
            std::cout << "Invalid command. Please enter ADD, SEARCH or EXIT." << std::endl;      
    }
    return 0;
}