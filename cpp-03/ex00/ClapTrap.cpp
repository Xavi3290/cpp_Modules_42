/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:17:20 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/06 21:30:25 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " has been created. (default constructor)" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
   std::cout << "ClapTrap " << _name << " has been created." << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
    *this = clapTrap;
    std::cout << "ClapTrap " << _name << " has been copied." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
    if (this != &clapTrap) {
        _name = clapTrap._name;
        _hitPoints = clapTrap._hitPoints;
        _energyPoints = clapTrap._energyPoints;
        _attackDamage = clapTrap._attackDamage;
    }
    std::cout << "ClapTrap " << _name << " has been assigned." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " has been destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << 
            _attackDamage << " points of damage!" << std::endl; 
    } else {
        std::cout << "ClapTrap " << _name << " has no energy or is already down!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints > 0) {
        _hitPoints -= amount;
        if (_hitPoints < 0)
            _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount << " ponts of damage! Remaining HP: "
            << _hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " is already down!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points! Total HP: "
            << _hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " has no energy or is already down!" << std::endl;
    }
}
