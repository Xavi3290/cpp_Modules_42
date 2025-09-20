/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:55:13 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/09/20 12:03:47 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main() {
    std::cout << "Shrubbery Creation Form Test\n" << std::endl;

    Bureaucrat low("Low", 150);
    Bureaucrat mid("Mid", 130);
    ShrubberyCreationForm shrubbery("Home");
    std::cout << shrubbery << std::endl;
        
    low.signForm(shrubbery);
    mid.signForm(shrubbery);
    low.executeForm(shrubbery);
    mid.executeForm(shrubbery);
    
    std::cout << "\nRobotomy Request Form Test\n" << std::endl;

    RobotomyRequestForm robotomy("Bender");
    Bureaucrat signer("Signer", 70);
    Bureaucrat executor("Executor", 40);
    std::cout << robotomy << std::endl;
        
    low.signForm(robotomy);
    signer.signForm(robotomy);
    low.executeForm(robotomy);
    for (int i = 0; i < 5; ++i) {
        executor.executeForm(robotomy);
    }
   
    std::cout << "\nPresidential Pardon Form Test\n" << std::endl;

    PresidentialPardonForm presi("Xavi");
    Bureaucrat presiSigner("PresiSigner", 25);
    Bureaucrat presiExecutor("PresiExecutor", 5);
    std::cout << presi << std::endl;

    low.signForm(presi);
    presiSigner.signForm(presi);
    low.executeForm(presi);
    presiExecutor.executeForm(presi);
    
    return 0;
}

