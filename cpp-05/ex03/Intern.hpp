/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:22:47 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/05/27 19:34:16 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Intern {
    public:
        Intern();
        Intern(const Intern &intern);
        Intern &operator=(const Intern &intern);
        ~Intern();
        
        AForm *makeForm(const std::string &formName, const std::string &target) const;

        class UnknownFormException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "Unknown form type!";
                }
        };
};

#endif