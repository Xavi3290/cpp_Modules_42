/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavi <xavi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:39:11 by xavi              #+#    #+#             */
/*   Updated: 2025/01/29 19:42:45 by xavi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
    private:
        std::string _type;

    public:
        Weapon();
        Weapon(const std::string &type);
        ~Weapon();
            
        const std::string &getType() const;
        void setType(const std::string &type);
};

#endif