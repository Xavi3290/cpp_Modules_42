/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:06:21 by xavi              #+#    #+#             */
/*   Updated: 2025/02/06 18:05:13 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    Zombie *zombie;
    int numZombies = 5;
    
    zombie = new Zombie();
    zombie->announce();
    zombie->setName("Paco");
    zombie->announce();
    delete zombie;

    Zombie *horde = zombieHorde(numZombies, "Pepes");
    if (horde) {
        for (int i = 0;i < numZombies; i++) {
            horde[i].announce();
        }
        delete[] horde;
    }
    return 0;
}