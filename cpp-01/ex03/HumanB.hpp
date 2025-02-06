/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:39:17 by xavi              #+#    #+#             */
/*   Updated: 2025/02/06 18:06:34 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB {
    private:
        std::string _name;
        Weapon *_weapon;
    
    public:
        HumanB(const std::string &name);
        ~HumanB();
        
        void setWeapon(Weapon &weapon);
        void attack() const;
};

#endif