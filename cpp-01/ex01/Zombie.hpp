/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:52:34 by xavi              #+#    #+#             */
/*   Updated: 2025/02/06 18:05:30 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    private:
        std::string _name;

    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        
        void announce(void);
        void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif