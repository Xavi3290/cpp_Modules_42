/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:33:50 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/10 20:40:59 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    std::cout << "Cat created. (Default)" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat) {
    std::cout << "Cat copied." << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
    if (this != &cat)
        Animal::operator=(cat);
    std::cout << "Cat assigned." << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}
