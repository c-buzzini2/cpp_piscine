/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:08:38 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/04 09:56:51 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low");
}

Bureaucrat::Bureaucrat(void) : _name("Nameless"), _grade(0)
{
    throw (Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
        if (_grade < 1)
            throw (GradeTooHighException());
        if (_grade > 150)
            throw (GradeTooLowException());
        std::cout << "Bureaucrat " << this->_name << " constructed\n";
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat " << this->_name << " destructed\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade)
{
    std::cout << "Bureaucrat " << this->_name << " copied\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    std::cerr << "Bureaucrats have constants that cannot be assigned\n";
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat & brcrt)
{
    os << brcrt.getName() << ", bureaucrat grade " << brcrt.getGrade() << ".\n";
    return (os);
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
    this->_grade--;
    if (_grade < 1)
        throw (GradeTooHighException());
}

void Bureaucrat::decrementGrade(void)
{
    this->_grade++;
    if (_grade > 150)
        throw (GradeTooLowException());
}
