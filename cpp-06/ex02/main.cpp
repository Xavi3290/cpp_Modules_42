/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:18:44 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/09/20 12:43:08 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base *generate() {
    int random = std::rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base *p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else 
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p) {
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e) {
        //std::cerr << "Not A" << std::endl;
    }
    try {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
    }
    catch (std::exception &e) {
        //std::cerr << "Not B" << std::endl;
    }
    try {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
    }
    catch (std::exception &e) {
        //std::cerr << "Not C" << std::endl;
    }    
}

int main() {
    std::cout << "Identifying randomly generated Base objects:" << std::endl;
    std::srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < 10; ++i) {
        Base *base = generate();
        identify(base);
        identify(*base);
        delete base;
        std::cout << std::endl;
    }
    
    std::cout << "Identifying null Base pointer and reference:" << std::endl;
    identify(NULL);
    std::cout << std::endl;
    std::cout << "Identifying wrong Base reference:" << std::endl;
    Base z;
    identify(z);
    
    return 0;
}
