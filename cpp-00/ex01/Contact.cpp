/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:32:08 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/01/07 20:03:37 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setFirstName(std::string &firstName)
{
    _firstName = firstName;
}

void Contact::setLastName(std::string &lastName)
{
    _lastName = lastName;
}

void Contact::setNickname(std::string &nickname)
{
    _nickname = nickname;
}

void Contact::setPhoneNumber(std::string &phoneNumber)
{
    _phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string &darkestSecret)
{
    _darkestSecret = darkestSecret;
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

