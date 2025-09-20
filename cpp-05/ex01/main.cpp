/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:05:16 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/09/20 12:02:49 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Form badFormLowSign("BadFormLow", 0, 50);
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Form badFormHighSign("BadFormHigh", 151, 50);
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Form badFormLowExec("BadFormLow", 50, 0);
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Form badFormHighExec("BadFormHigh", 50, 151);
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    Form formA("FormA", 50, 50);
    std::cout << formA << std::endl;

    Bureaucrat pep("Pep", 50);
    Bureaucrat bob("Bob", 100);

    pep.signForm(formA);
    std::cout << formA << std::endl;
    bob.signForm(formA);
    std::cout << formA << std::endl;
    pep.signForm(formA);
     
    return 0;
}

