/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:08:38 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/27 13:58:49 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low");
}

Form::Form(void) : _name("Nameless"), _grade_to_sign(0), _grade_to_exec(0),
                                    _already_signed(false)
{
    throw (Form::GradeTooHighException());
}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name) ,
                     _grade_to_sign(sign_grade), _grade_to_exec(exec_grade),
                     _already_signed(false)
{
        if (_grade_to_sign < 1 || _grade_to_exec < 1)
            throw (GradeTooHighException());
        if (_grade_to_sign > 150 || _grade_to_exec > 150)
            throw (GradeTooLowException());
        std::cout << "Form " << this->_name << " constructed\n";
}

Form::~Form(void)
{
    std::cout << "Form " << this->_name << " destructed\n";
}

Form::Form(const Form& src) : _name(src._name), _grade_to_sign(src._grade_to_sign),
                            _grade_to_exec(src._grade_to_exec), _already_signed(src._already_signed)
{
    std::cout << "Form " << this->_name << " copied\n";
}

/* Form& Form::operator=(const Form& src) 
{
    if (this != &src)
    this->_already_signed = src._already_signed;
    std::cout << "Form " << this->_name << " assigned\n";
    return *this;
} */

std::ostream& operator<<(std::ostream& os, const Form & form)
{
    os << "Form " << form.getName() << ", grade to sign " << form.getGradeSign() 
        << ", grade to execute " << form.getGradeExec();
    form.getAlreadySigned() ? os << ", signed\n" : os << ", unsigned\n";
    return (os);
}

std::string Form::getName() const
{
    return (this->_name);
}

int Form::getGradeSign() const
{
    return (this->_grade_to_sign);
}

int Form::getGradeExec() const
{
    return (this->_grade_to_exec);
}

bool Form::getAlreadySigned() const
{
    return (this->_already_signed);
}

void Form::beSigned(Bureaucrat& brcrt)
{
    if (brcrt.getGrade() > this->_grade_to_sign)
        throw (Form::GradeTooLowException());
    else
        this->_already_signed = true;
}
