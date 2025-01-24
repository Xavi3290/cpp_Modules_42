/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavi <xavi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:06:21 by xavi              #+#    #+#             */
/*   Updated: 2025/01/24 20:16:15 by xavi             ###   ########.fr       */
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