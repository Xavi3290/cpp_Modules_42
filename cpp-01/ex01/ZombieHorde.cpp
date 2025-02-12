/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:01:10 by xavi              #+#    #+#             */
/*   Updated: 2025/02/12 18:39:18 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) {
        std::cout << "Error: Number of zombies must be grater than 0." << std::endl;
        return NULL;
    }
    Zombie *zombie = new Zombie[N];
    for (int i = 0; i < N; i++) {
        zombie[i].setName(name);
    }
    return zombie;
}
