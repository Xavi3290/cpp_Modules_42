/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:35:05 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/05/22 20:51:04 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &bureaucrat);
        Bureaucrat &operator=(const Bureaucrat &bureaucrat);
        ~Bureaucrat();
        
        const std::string &getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &form);
        
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "Grade too high!";
                } 
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "Grade too low!";
                }
        };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureucrat);

#endif
