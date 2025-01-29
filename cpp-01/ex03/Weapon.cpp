/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavi <xavi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:31:07 by xavi              #+#    #+#             */
/*   Updated: 2025/01/29 19:58:19 by xavi             ###   ########.fr       */
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
