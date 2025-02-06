/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:59:04 by xavi              #+#    #+#             */
/*   Updated: 2025/02/06 18:05:24 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
    this->_name = "Default";
    std::cout << "Zombie " << this->_name << " is created." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "Zombie " << this->_name << " is created." << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << this->_name << " is destroyed." << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    this->_name = name;
}