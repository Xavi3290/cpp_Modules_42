/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:04:56 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/05/22 21:30:40 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExec;
    
    public:
        Form();
        Form(const std::string &name, int gradeToSign, int gradeToExec);
        Form(const Form &form);
        Form &operator=(const Form &form);
        ~Form();

        const std::string &getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;

        void beSigned(const Bureaucrat &bureacurat);

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

        class AlreadySignedException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Already signed!";
                }
        };         
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
