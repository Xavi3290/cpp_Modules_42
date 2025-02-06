/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:31:07 by xavi              #+#    #+#             */
/*   Updated: 2025/02/06 18:06:51 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : _type("default") {}

Weapon::Weapon(const std::string &type) : _type(type) {}

Weapon::~Weapon() {}

const std::string &Weapon::getType() const {
    return this->_type;
}

void Weapon::setType(const std::string &type) {
    this->_type = type;
}
