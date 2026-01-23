/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:44:02 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/23 12:34:39 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

void    Harl::complain(std::string level)
{	
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int         level_nb = -1;	

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			level_nb = i;
	}
    switch (level_nb)
    {
        case 0:
            this->debug();
            //fall through
        case 1:
            this->info();
            //fall through
        case 2:
            this->warning();
            //fall through
        case 3:
            this->error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" 
					<< std::endl;
        }
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
