/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:34:42 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/03 10:40:12 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <cstring>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 72, 45), _target ("Unnamed")
{
    std::cout << "Robotomy Form constructed (default)\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
    std::cout << "Robotomy Form constructed\n";
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "Robotomy Form " << this->getName() << " destructed\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target)
{
    std::cout << "Robotomy Form " << this->getName() << " copied\n";
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

void RobotomyRequestForm::action(void) const
{
    std::cout << "BRRRRRRRRRR\n";
    if (rand() % 2)
        std::cout << this->_target << " has been successfully robotomized\n";
    else
        std::cout << this->_target << "'s robotomy failed\n";
}


AForm& RobotomyRequestForm::operator=(const AForm& src) 
{
    std::cerr << "Forms have constants that cannot be assigned\n";
    return *this;
}