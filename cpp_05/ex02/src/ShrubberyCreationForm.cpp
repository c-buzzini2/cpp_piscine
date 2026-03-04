/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:34:42 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/04 10:01:21 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <cerrno>
#include <cstring>

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

std::string ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);
}

void ShrubberyCreationForm::action(void) const
{
    std::string		outfile_name = this->_target + "_shrubbery";
	std::ofstream	dest(outfile_name.c_str());
	if (!dest.is_open())
	{
    	std::cerr << "Failed to open dest file: " << std::strerror(errno) << '\n';
		return;
	}
    dest << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n"
        << " \\  _-     -_  /\n   ~  \\ //  ~\n_- -   | | _- _\n"
        << "  _ -  | |   -_\n      // \\\\\n";
}

AForm& ShrubberyCreationForm::operator=(const AForm& src) 
{
    std::cerr << "Forms have constants that cannot be assigned\n";
    return *this;
}