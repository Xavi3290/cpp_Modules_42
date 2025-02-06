/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:39:11 by xavi              #+#    #+#             */
/*   Updated: 2025/02/06 18:06:55 by xroca-pe         ###   ########.fr       */
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