/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavi <xavi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:32:08 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/01/13 20:16:35 by xavi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setFirstName(std::string &firstName)
{
    this->_firstName = firstName;
}

void Contact::setLastName(std::string &lastName)
{
    this->_lastName = lastName;
}

void Contact::setNickname(std::string &nickname)
{
    this->_nickname = nickname;
}

void Contact::setPhoneNumber(std::string &phoneNumber)
{
    this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string &darkestSecret)
{
    this->_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const 
{
    return this->_firstName;   
}

std::string Contact::getLastName() const
{
    return this->_lastName;
}

std::string Contact::getNickname() const
{
    return this->_nickname;
}

std::string Contact::getPhoneNumber() const
{
    return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return this->_darkestSecret;
}
