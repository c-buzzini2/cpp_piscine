/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:34:42 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/03 13:25:41 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <cerrno>
#include <cstring>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon Form", 25, 5), _target ("Unnamed")
{
    std::cout << "Presidential Form constructed (default)\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
    std::cout << "Presidential Form constructed\n";
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "Presidential Form " << this->getName() << " destructed\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), _target(src._target)
{
    std::cout << "Presidential Form " << this->getName() << " copied\n";
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void PresidentialPardonForm::action(void) const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox\n";
}


/* AForm& PresidentialPardonForm::operator=(const AForm& src) 
{
    (void) src;
    std::cout << "Form " << this->getName() << " assigned\n";
    return *this;
} */

//ASSIGNMENT OPERATOR????