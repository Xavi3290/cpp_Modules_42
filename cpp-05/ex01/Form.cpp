/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:04:52 by xroca-pe          #+#    #+#             */
/*   Updated: 2025/05/22 21:30:46 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &form) : _name(form._name), _isSigned(form._isSigned), _gradeToSign(form._gradeToSign), _gradeToExec(form._gradeToExec) {}

Form &Form::operator=(const Form &form) {
    if (this != &form) {
        _isSigned = form._isSigned;
    }
    return *this;
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    if (_isSigned)
        throw AlreadySignedException();
    _isSigned = true;
}

const std::string &Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _isSigned;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExec() const {
    return _gradeToExec;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form: " << form.getName() << ", Signed: ";
    if (form.isSigned()) 
        os << "Yes";
    else
        os << "No";
    os << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExec();
    return os;
}
