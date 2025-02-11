/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:24:06 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/11 18:28:48 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASORUCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    private:
        AMateria *_materias[4];
    
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &materiaSource);
        MateriaSource &operator=(const MateriaSource &materiaSource);
        virtual ~MateriaSource();

        void learnMateria(AMateria *m);
        AMateria *createMateria(std::string const &type);
};

#endif