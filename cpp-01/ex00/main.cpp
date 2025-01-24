/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavi <xavi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:14:32 by xavi              #+#    #+#             */
/*   Updated: 2025/01/24 19:21:59 by xavi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    Zombie *zombie;
    
    zombie = Zombie::newZombie("Paco");
    zombie->announce();
    delete zombie;
    std::cout << std::endl;
    Zombie::randomChump("Pepe");
    std::cout << std::endl;
    zombie = Zombie::newZombie("Juan");
    zombie->announce();
    Zombie::randomChump("Luis");
    zombie->announce();
    delete zombie;
    
    return 0;
}