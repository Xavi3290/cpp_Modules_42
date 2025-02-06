/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:39:26 by xavi              #+#    #+#             */
/*   Updated: 2025/02/06 18:06:20 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() const {
    std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}
