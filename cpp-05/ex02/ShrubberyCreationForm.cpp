/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:56:11 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/05/26 19:52:30 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : AForm(form), _target(form._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form) {
    AForm::operator=(form);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    checkExecutable(executor);
    std::ofstream ofs((_target + "_shrubbery").c_str());
    ofs << 
    "    ccee88oo\n"
    "  C8O8O8Q8PoOb o8oo\n"
    " dOB69QO8PdUOpugoO9bD\n"
    "CgggbU8OU qOp qOdoUOdcb\n"
    "    6OuU  /p u gcoUodpP\n"
    "      \\\\\\\\//  /douUP\n"
    "        \\\\\\\\////\n"
    "         |||/\\\n"
    "         |||\\/\n"
    "         |||||\n"
    "   .....//||||\\....\n";
    ofs.close();
}
