/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:42:23 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/11/27 18:20:51 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int PhoneBook::_total_contacts = 0;

int    PhoneBook::ft_add_contact(void)
{
	Contact	new_ctct;

	if (new_ctct.ft_create_contact())
		return (2);
    this->_contacts[this->_total_contacts % 8] = new_ctct;
    PhoneBook::_total_contacts++;
    return (0);
}

void    PhoneBook::ft_print_contact(int i) const
{
	const char  *fields[] = 
    {
		"First name: ",
		"Last name: ",
		"Nickname: ",
    	"Phone number: ",
    	"Darkest secret: "
    };

	for (int j = 0; j < 5; j++)
	{
	    std::cout << fields[j];
		std::cout << this->_contacts[i].ft_get_info(j)
				<< std::endl;
	}
}

std::string PhoneBook::ft_truncate_field(const std::string &field) const
{
    if (field.length() > 10)
        return (field.substr(0, 9) + ".");
    return (field);
}


void    PhoneBook::ft_display_list(void) const
{
	int i;
	int	to_print;
	
	std::cout << std::right;
    std::cout << std::setw(10) << "Index"
			<< std::setw(1) << "|"
			<< std::setw(10) << "First name"
			<< std::setw(1) << "|"
            << std::setw(10) << "Last name"
			<< std::setw(1) << "|"
            << std::setw(10) << "Nickname"
			<< std::endl;
			
	if (_total_contacts > 8)
		to_print = 8;
	else
		to_print = _total_contacts;

	for (i = 0; i < to_print; i++)
	{
		std::cout << std::setw(10) << i
				<< std::setw(1) << "|";

		for (int j = 0; j < 3; j++)
		{
			std::cout << std::setw(10) << ft_truncate_field(this->_contacts[i].ft_get_info(j));
			if (j < 2)
				std::cout << std::setw(1) << "|";
		}
		std::cout << std::endl;
	}
}

int    PhoneBook::ft_search_contact(void) const
{
    std::string			buff;
	int 				n;
	
	this->ft_display_list();
	std::cout << "\nType index number to see contact"
	<< std::endl;
	std::getline(std::cin, buff);
	std::stringstream	ss(buff);
	if (!(ss >> n) || !(ss.eof()) || (n < 0) 
		|| (_total_contacts < 8 && n >= _total_contacts) || n > 7)
	{
		std::cerr << "Invalid input"
		<< std::endl;
	}
	else
		this->ft_print_contact(n);
    return (0);
}
