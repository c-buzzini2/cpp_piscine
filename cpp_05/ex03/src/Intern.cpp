/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:08:14 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/04 14:11:03 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
    std::cout << "Intern created\n";
}

Intern::~Intern(void)
{
    std::cout << "Intern destructed\n";
}

Intern::Intern(const Intern& src)
{
    *this = src;
    std::cout << "Intern copied\n";
}

Intern& Intern::operator=(const Intern& src)
{
    (void)src;
    std::cout << "Intern assigned\n";
    return *this;
}

AForm *Intern::makeShrub(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobot(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresid(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    AForm *(*fcts[3])(std::string) = 
    {
		makePresid,
		makeRobot,
		makeShrub,
	};
    std::string form_names[3] = 
    {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };
    for(int i = 0; i < 3; i++)
    {
        if (name == form_names[i])
        {
            std::cout << "Intern creates " << form_names[i] << std::endl;
            return(fcts[i](target));
        }
    }
    std::cerr << "Form name does not exist\n";
    return (NULL);
}