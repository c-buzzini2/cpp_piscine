/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:42:52 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/04 14:15:42 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main ()
{
    Intern Josh;
    AForm *form;
    
    form = Josh.makeForm("robotomy request", "Wall-e");
    delete (form);
    form = Josh.makeForm("shrubbery creation", "42 Berlin");
    delete (form);
    form = Josh.makeForm("presidential pardon", "Frida");
    delete (form);
    form = Josh.makeForm("robotomy", "android");
}