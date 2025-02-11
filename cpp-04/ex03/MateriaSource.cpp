/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:24:09 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/11 18:47:52 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
    for (int i = 0; i < 4; i++) {
        if (materiaSource._materias[i])
            _materias[i] = materiaSource._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource) {
    if (this != &materiaSource) {
        for (int i = 0; i < 4; i++) {
            if (_materias[i])
                delete _materias[i];
            if (materiaSource._materias[i])
                _materias[i] = materiaSource._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (_materias[i])
            delete _materias[i];
    }
}

void MateriaSource::learnMateria(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (!_materias[i]) {
            _materias[i] = m;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return NULL;
}
