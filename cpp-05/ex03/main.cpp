/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:55:13 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/05/27 20:21:59 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
    Intern intern;
    AForm *form1, *form2, *form3;
    
    try {
        form1 = intern.makeForm("shrubbery creation", "Home");
        form2 = intern.makeForm("robotomy request", "Bender");
        form3 = intern.makeForm("presidential pardon", "Xavi");
    }
    catch (const std::exception &e) {
        std::cerr << "Intern error: " << e.what() << std::endl;
        return 1;
    }

    Bureaucrat low("Low", 150);
    Bureaucrat high("High", 1);

    std::cout << std::endl;
    
    low.signForm(*form1);
    low.executeForm(*form1);
    low.signForm(*form2);
    low.executeForm(*form2);
    low.signForm(*form3);
    low.executeForm(*form3);

    std::cout << std::endl;

    high.signForm(*form1);
    high.executeForm(*form1);
    high.signForm(*form2);
    high.executeForm(*form2);
    high.signForm(*form3);
    high.executeForm(*form3);

    std::cout << std::endl;

    try {
        AForm *unknownForm = intern.makeForm("unknown form", "Target");
        if (unknownForm)
            delete unknownForm;
    } catch (const Intern::UnknownFormException &e) {
        std::cerr << "Intern error: " << e.what() << std::endl;
    }

    if (form1) 
        delete form1;
    if (form2) 
        delete form2;
    if (form3) 
        delete form3;
    
    return 0;
}
