/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:17:45 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/02/11 09:32:56 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain created. (Default)" << std::endl;
}

Brain::Brain(const Brain &brain) {
    *this = brain;
    std::cout << "Brain copied." << std::endl;
}

Brain &Brain::operator=(const Brain &brain) {
    if (this != &brain) {
        for (int i = 0; i < 100; i++) {
            _ideas[i] = brain._ideas[i];
        }
    }
    std::cout << "Brain assigned." << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destroyed." << std::endl;
}

void Brain::setIdea(int index, const std::string &idea) {
    if (index >= 0 && index < 100)
        _ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return _ideas[index];
    return "Invalid index";
}