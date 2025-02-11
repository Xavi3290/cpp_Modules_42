/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:37:37 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/11 13:11:44 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &aMateria) {
    *this = aMateria;
}

AMateria &AMateria::operator=(const AMateria &aMateria) {
    if (this != &aMateria)
        _type = aMateria._type;
    return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter &target) {
    std::cout << "* uses AMateria on " << target.getName() << " *" << std::endl;
}
