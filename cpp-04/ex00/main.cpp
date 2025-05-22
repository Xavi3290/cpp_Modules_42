/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:03:52 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/12 18:50:29 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* genericAnimal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Type of genericAnimal: " << genericAnimal->getType() << std::endl;
    std::cout << "Type of dog: " << dog->getType() << std::endl;
    std::cout << "Type of cat: " << cat->getType() << std::endl;


    std::cout << std::endl;
    
    genericAnimal->makeSound();
    dog->makeSound();
    cat->makeSound();
   

    std::cout << std::endl;

    delete genericAnimal;
    delete dog;
    delete cat;

    std::cout << std::endl;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "Type of wrongAnimal: " << wrongAnimal->getType() << std::endl;
    std::cout << "Type of wrongCat: " << wrongCat->getType() << std::endl;

    std::cout << std::endl;
    
    wrongAnimal->makeSound();
    wrongCat->makeSound();

    std::cout << std::endl;

    delete wrongAnimal;
    delete wrongCat;

    std::cout << std::endl;

    Animal genericAnimal2;
    Dog dog2;
    Cat cat2;

    std::cout << "Type of genericAnimal: " << genericAnimal2.getType() << std::endl;
    std::cout << "Type of dog: " << dog2.getType() << std::endl;
    std::cout << "Type of cat: " << cat2.getType() << std::endl;
    
    genericAnimal2.makeSound();
    dog2.makeSound();
    cat2.makeSound();

    std::cout << std::endl;

    return 0;
}
