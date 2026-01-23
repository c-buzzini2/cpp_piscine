/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:44:02 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/23 11:37:20 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

void    Harl::complain(std::string level)
{	
    std::map<std::string, int> level_nb;

    level_nb["DEBUG"] = 1;
    level_nb["INFO"] = 2;
    level_nb["WARNING"] = 3;
    level_nb["ERROR"] = 4;

	std::map<std::string, int>::iterator it = level_nb.find(level);
    if (it != level_nb.end())
	{
        int nb = it->second;
        switch (nb)
        {
            case 1:
                this->debug();
                //fall through
            case 2:
                this->info();
                //fall through
            case 3:
                this->warning();
                //fall through
            case 4:
                this->error();
                //fall through
        }
    }
    else
		std::cout << "[ Probably complaining about insignificant problems ]" 
					<< std::endl; 
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
