/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:04:56 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/05/26 19:09:04 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExec;

    protected:
        void checkExecutable(Bureaucrat const &executor) const;
    
    public:
        AForm();
        AForm(const std::string &name, int gradeToSign, int gradeToExec);
        AForm(const AForm &form);
        AForm &operator=(const AForm &form);
        virtual ~AForm();

        const std::string &getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;

        void beSigned(const Bureaucrat &bureacurat);

        virtual void execute(const Bureaucrat &executor) const = 0;

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

        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Form is not signed!";
                }
        };      
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
