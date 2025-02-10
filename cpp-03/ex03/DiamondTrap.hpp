/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:03:24 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/10 19:09:59 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    private:
        std::string _name;
        
    public:
        DiamondTrap();
        DiamondTrap(const std::string name);
        DiamondTrap(const DiamondTrap &diamondTrap);
        DiamondTrap &operator=(const DiamondTrap &diamondTrap);
        ~DiamondTrap();
        
        void whoAmI();
        using ScavTrap::attack;
};

#endif 
