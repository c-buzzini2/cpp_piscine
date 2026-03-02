/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:34:42 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/02 14:23:16 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation Form", 145, 137), _target ("Unnamed")
{
    std::cout << "Shrubbery Form constructed (default)\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
    std::cout << "Shrubbery Form constructed\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "Shrubbery Form " << this->getName() << " destructed\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src._target)
{
    std::cout << "Shrubbery Form " << this->getName() << " copied\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const & exctr) const
{
    (void) exctr;//WRITE CODE!!!!!!!!!!!!!
}

/* AForm& ShrubberyCreationForm::operator=(const AForm& src) 
{
    (void) src;
    std::cout << "Form " << this->getName() << " assigned\n";
    return *this;
} */