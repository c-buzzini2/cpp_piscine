/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:42:23 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/11/24 15:44:09 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int PhoneBook::_total_contacts = 0;

int    PhoneBook::ft_add_contact(void)
{
    char        buff[250];
    const char  *prompts[] = 
    {
    "Nickname:",
    "First name:",
    "Last name:",
    "Phone number:",
    "Darkest secret:"
    };
    for (int i = 0; i < 5; i++)
    {
        std::cout << prompts[i]
        << std::endl;
        if (i != 4)
            std::cin.getline(buff, 20);
        else
            std::cin.getline(buff, 250);
        this->_contacts[this->_total_contacts % 8].ft_set_info(i, buff);
    }
    //MAKE SURE THAT THAT RETURN 2 GOES BACK THE ENTIRE CHAIN
    //else (ONLY IF EVERYTHING IS OK)
    PhoneBook::_total_contacts++;
    return (0);
}