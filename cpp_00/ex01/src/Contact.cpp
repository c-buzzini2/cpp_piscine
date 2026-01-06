/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:15:53 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/06 20:26:07 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	Contact::ft_create_contact(void)
{
	std::string	buff;
    const char  *prompts[] = 
    {
		"First name:",
		"Last name:",
		"Nickname:",
    	"Phone number:",
    	"Darkest secret:"
    };
    for (int i = 0; i < 5; i++)
    {
        std::cout << prompts[i]
        << std::endl;
        if (i != 4)
            std::getline(std::cin, buff);
        else
            std::getline(std::cin, buff);
		if (this->ft_set_info(i, buff) != 0)
			return (2);
    }
	return (0);
}

bool	Contact::ft_input_is_valid(std::string input) const
{
	int i;

	i = 0;
	if (!input.empty())
	{
		while (input[i])
		{
			if (!std::isspace(input[i]))
				return (true);
			i++;
		}
	}
	std::cerr << "Field cannot be left empty"
		<< std::endl;
	return (false);
}

bool	Contact::ft_phone_is_valid(std::string input) const
{
	int i;

	i = 0;
	if (input[i] == '+')
		i++;
	while (input[i])
	{
		if (!std::isdigit(input[i]))
		{
			std::cerr << "Phone must be digits"
					<< std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}

int	Contact::ft_set_info(int info_type, std::string content)
{
	if (!ft_input_is_valid(content))
		return (2);
    if (info_type == 0)
        this->_f_name = content;
    else if (info_type == 1)
        this->_l_name = content;
	else if (info_type == 2)
        this->_nick = content;
    else if (info_type == 3)
	{
		if (!ft_phone_is_valid(content))
			return (2);
		this->_phone_nb = content;
	}
	else if (info_type == 4)
		this->_secret = content;

	return (0);
}

std::string Contact::ft_get_info(int info_type) const
{
    if (info_type == 0)
        return(this->_f_name);
    else if (info_type == 1)
        return(this->_l_name);
	else if (info_type == 2)
        return(this->_nick);
    else if (info_type == 3)
        return(this->_phone_nb);
    else if (info_type == 4)
        return(this->_secret);
    else
		return (NULL);
}