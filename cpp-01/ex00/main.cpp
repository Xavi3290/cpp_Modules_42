/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:14:32 by xavi              #+#    #+#             */
/*   Updated: 2025/02/06 18:03:07 by xroca-pe         ###   ########.fr       */
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