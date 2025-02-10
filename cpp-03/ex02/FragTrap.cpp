/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:26:28 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/10 18:46:30 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap") {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " has been created. (default constructor)" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " has been created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap) {
    std::cout << "FragTrap " << _name << " has been copied." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap) {
    if (this != &fragTrap) {
        ClapTrap::operator=(fragTrap);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " has been destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
}
