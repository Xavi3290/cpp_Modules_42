/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavi <xavi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:59:04 by xavi              #+#    #+#             */
/*   Updated: 2025/01/24 19:20:32 by xavi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "Zombie " << _name << " is created." << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << _name << " is destroyed." << std::endl;
}

void Zombie::announce(void) {
    std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}