/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:26:39 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/11 09:53:18 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
    _type = "Dog";
    _brain = new Brain();
    std::cout << "Dog created. (Default)" << std::endl;
}

Dog::Dog(const Dog &dog): Animal(dog) {
    _brain = new Brain(*dog._brain);
    std::cout << "Dog copied." << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
    if (this != &dog) {
        Animal::operator=(dog);
        delete _brain;
        _brain = new Brain(*dog._brain);
    }
    std::cout << "Dog assigned." << std::endl;
    return *this;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Dog destroyed." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

Brain *Dog::getBrain() const {
    return _brain;
}
