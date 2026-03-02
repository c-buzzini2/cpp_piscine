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

#include "AForm.hpp"

const char* AForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low");
}

AForm::AForm(void) : _name("Nameless"), _grade_to_sign(0), _grade_to_exec(0),
                                    _already_signed(false)
{
    throw (AForm::GradeTooHighException());
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name) ,
                     _grade_to_sign(sign_grade), _grade_to_exec(exec_grade),
                     _already_signed(false)
{
        if (this->getGradeSign() < 1 || this->getGradeExec() < 1)
            throw (GradeTooHighException());
        if (this->getGradeSign() > 150 || this->getGradeExec() > 150)
            throw (GradeTooLowException());
        std::cout << "AForm " << this->getName() << " constructed\n";
}

AForm::~AForm(void)
{
    std::cout << "AForm " << this->getName() << " destructed\n";
}

AForm::AForm(const AForm& src) : _name(src._name), _grade_to_sign(src._grade_to_sign),
                            _grade_to_exec(src._grade_to_exec), _already_signed(src._already_signed)
{
    std::cout << "AForm " << this->getName() << " copied\n";
}

/* AForm& AForm::operator=(const AForm& src) 
{
    if (this != &src)
    this->_already_signed = src._already_signed;
    std::cout << "Form " << this->_name << " assigned\n";
    return *this;
} */

std::ostream& operator<<(std::ostream& os, const AForm & form)
{
    os << "Form " << form.getName() << ", grade to sign " << form.getGradeSign() 
        << ", grade to execute " << form.getGradeExec();
    form.getAlreadySigned() ? os << ", signed\n" : os << ", unsigned\n";
    return (os);
}

std::string AForm::getName() const
{
    return (this->_name);
}

int AForm::getGradeSign() const
{
    return (this->_grade_to_sign);
}

int AForm::getGradeExec() const
{
    return (this->_grade_to_exec);
}

bool AForm::getAlreadySigned() const
{
    return (this->_already_signed);
}

void AForm::beSigned(Bureaucrat& brcrt)
{
    if (brcrt.getGrade() > this->_grade_to_sign)
        throw (AForm::GradeTooLowException());
    else
        this->_already_signed = true;
}
