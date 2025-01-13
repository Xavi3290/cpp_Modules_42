/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavi <xavi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:51:20 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/01/10 09:04:14 by xavi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>     //setw(10)
#include <string>
#include <sstream>     //std::stringstream
#include <cstdlib>     //exit(0)

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
        void searchContacts() const;
        void printContact(int index) const;
        
    private:
        void printColumn(const std::string &str) const;
};

#endif
