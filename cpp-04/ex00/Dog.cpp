/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:26:39 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/11 08:49:00 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
    _type = "Dog";
    std::cout << "Dog created. (Default)" << std::endl;
}

Dog::Dog(const Dog &dog): Animal(dog) {
    std::cout << "Dog copied." << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
    if (this != &dog)
        Animal::operator=(dog);
    std::cout << "Dog assigned." << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destroyed." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
