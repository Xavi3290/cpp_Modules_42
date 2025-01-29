/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavi <xavi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:39:17 by xavi              #+#    #+#             */
/*   Updated: 2025/01/29 20:27:32 by xavi             ###   ########.fr       */
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