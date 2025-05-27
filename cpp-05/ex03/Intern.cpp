/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:22:51 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/05/27 20:04:23 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &intern) {
    (void)intern;
}

Intern &Intern::operator=(const Intern &intern) {
    (void)intern;
    return *this;
}

Intern::~Intern() {}

typedef AForm *(*FormFactoryFn)(const std::string &target);

static AForm *makeShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

static AForm *makeRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm *makePresidential(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
    struct FormEntry { 
        const char* name; 
        FormFactoryFn fn; 
    };
    const size_t tableSize = 3;
    static const FormEntry table[] = {
        {"shrubbery creation", makeShrubbery},
        {"robotomy request", makeRobotomy},
        {"presidential pardon", makePresidential}
    };
    for (size_t i = 0; i < tableSize; ++i) {
        if (formName == table[i].name) {
            AForm *form = table[i].fn(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    throw UnknownFormException();
}
