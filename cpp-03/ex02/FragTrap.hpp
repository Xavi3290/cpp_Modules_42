/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:26:25 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/10 18:39:16 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap {
    public:
        FragTrap();
        FragTrap(const std::string &name);
        FragTrap(const FragTrap &fragTrap);
        FragTrap &operator=(const FragTrap &fragTrap);
        ~FragTrap();

        void highFivesGuys(void);       
};

#endif