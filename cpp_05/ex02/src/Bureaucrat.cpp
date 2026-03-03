/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:08:38 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/03 13:07:56 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

/* Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    if (this != &src)
        this->_grade = src._grade;
    std::cout << "Bureaucrat " << this->_name << " assigned\n";
    return *this;
} */

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

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << form.getName()
		            << ": " << e.what() << '\n';
        return;
	}
	std::cout << this->_name << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't execute " << form.getName()
		            << ": " << e.what() << '\n';
        return;
	}
    std::cout << this->_name << " executed " << form.getName() << " at " 
                << form.getTarget() << std::endl;
}
