/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavi <xavi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:39:23 by xavi              #+#    #+#             */
/*   Updated: 2025/01/29 20:17:31 by xavi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA {
    private:
        std::string _name;
        Weapon &_weapon;

    public:
        HumanA(const std::string &name, Weapon &weapon);
        ~HumanA();

        void attack() const;
};

#endif