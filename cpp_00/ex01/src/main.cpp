/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:53:36 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/11/24 14:57:04 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int ft_parse_command(PhoneBook* p_book, std::string line)
{
	if (line == "EXIT")
		return (1);
	else if (line == "ADD")
		return (p_book->ft_add_contact());
	return (0);
}

int main(void)
{
	PhoneBook	p_book;
	char		buff[7];
	int			ret;

	while (1)
	{
		std::cout << "Welcome to the Crappy Awesome Phonebook Software."
		<< std::endl
		<< "Type ADD, SEARCH, or EXIT"
		<< std::endl;
		std::cin.getline(buff, 7);
		ret = ft_parse_command(&p_book, buff);
		if (ret == 1)
			break;
		if (ret == 2)
			continue;
	}
    
}
