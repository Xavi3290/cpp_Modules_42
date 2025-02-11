/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:33:50 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/11 09:53:57 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
    _type = "Cat";
    _brain = new Brain();
    std::cout << "Cat created. (Default)" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat) {
    _brain = new Brain(*cat._brain);
    std::cout << "Cat copied." << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
    if (this != &cat) {
        Animal::operator=(cat);
        delete _brain;
        _brain = new Brain(*cat._brain);
    }
    std::cout << "Cat assigned." << std::endl;
    return *this;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

Brain *Cat::getBrain() const {
    return _brain;
}
