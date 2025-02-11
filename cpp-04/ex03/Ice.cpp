/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:54:10 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/11 19:38:34 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &ice) : AMateria(ice) {}

Ice &Ice::operator=(const Ice &ice) {
    if (this != &ice)
        AMateria::operator=(ice);
    return *this;
}

Ice::~Ice() {}

AMateria *Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}