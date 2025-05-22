/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:54:41 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/12 18:52:32 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CPP
#define CHARACTER_CPP

#include "ICharacter.hpp"

class Character : public ICharacter {
    private:
        std::string _name;
        AMateria *_inventory[4];
        AMateria* _unequipped[4];

    public:
        Character();
        Character(std::string name);
        Character(const Character &character);
        Character &operator=(const Character &character);
        virtual ~Character();

        std::string const &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};

#endif
