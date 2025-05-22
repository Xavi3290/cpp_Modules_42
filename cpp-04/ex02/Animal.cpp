/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:03:50 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/12 18:51:43 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Unknown") {
    std::cout << "Animal created. (Default)" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type) {
    std::cout << "Animal of type " << _type << " created." << std::endl;
}

Animal::Animal(const Animal &animal) {
    *this = animal;
    std::cout << "Animal copied." << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {
    if (this != &animal)
        _type = animal._type;
    std::cout << "Animal assigned." << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destroyed." << std::endl;
}

std::string Animal::getType() const {
    return _type;
}
