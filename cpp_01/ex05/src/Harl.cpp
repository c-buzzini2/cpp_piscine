/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:44:02 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/23 10:13:48 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//START HERE!! IMPLEMENT EACH FUNCION

void    Harl::complain(std::string level)
{
	if (level.empty())
	{
		std::cerr << "Please, enter a level\n";
		return;
	}
	
    std::map<std::string, void(Harl::*)(void)> funcMap;

    funcMap["DEBUG"] = &Harl::debug;
    funcMap["INFO"] = &Harl::info;
    funcMap["WARNING"] = &Harl::warning;
    funcMap["ERROR"] = &Harl::error;

    std::map<std::string, void(Harl::*)(void)>::iterator it = funcMap.find(level);
    if (it != funcMap.end()) 
        (this->*(it->second))();
    else
        std::cerr << "Level does not exist\n";
 
}

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my" 
                << "7XL-double-cheese-triple-pickle-specialketchup burger. "
                << "I really do!"
                << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money." 
				<< "You didn’t put enough bacon in my burger! "
				<< "If you did, I wouldn’t be asking for more!"
                << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. "
				<< "I’ve been coming for years, "
				<< "whereas you started working here just last month."
                << std::endl;
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now."
                << std::endl;
}
