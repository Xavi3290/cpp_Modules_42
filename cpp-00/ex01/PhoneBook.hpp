/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:51:20 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/01/08 18:34:21 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>     //draw table
#include <string>
#include <limits>

#define MAX_CONTACTS 8

class PhoneBook
{
    private:
        Contact _contacts[MAX_CONTACTS];
        int _contactCount;
        int _oldestIndex;
    
    public:
        PhoneBook();
        ~PhoneBook();
        
        void addContact();
        void searchContact();
        void displayContact(int index) const;
        
    private:
        void printColumn(const std::string &str) const;
};

#endif