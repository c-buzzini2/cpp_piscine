/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:53:36 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/11/27 17:50:55 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int ft_parse_command(PhoneBook* p_book, std::string line)
{
	if (line == "EXIT")
		return (1);
	else if (line == "ADD")
		return (p_book->ft_add_contact());
	else if (line == "SEARCH")
		return (p_book->ft_search_contact());
	else
		return (2);
	return (0);
}

int main(void)
{
	PhoneBook	p_book;
	std::string	buff;
	int			ret;

	while (1)
	{
		std::cout << "\nWelcome to the Crappy Awesome Phonebook Software."
		<< std::endl
		<< "Type ADD, SEARCH, or EXIT"
		<< std::endl;
		std::getline(std::cin, buff);
		ret = ft_parse_command(&p_book, buff);
		if (ret == 1)
			break;
		if (ret == 2)
			continue;
	}
    
}
