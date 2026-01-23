/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:44:02 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/23 12:21:46 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::complain(std::string level)
{
	if (level.empty())
	{
		std::cerr << "Please, enter a level\n";
		return;
	}
    
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
    typedef void (Harl::*Hrl_fcts)(void);
    Hrl_fcts fcts[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*fcts[i])();
			return;
		}
	}
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
