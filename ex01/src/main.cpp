/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:53:36 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/11/21 15:21:50 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int ft_parse_command(std::string line)
{
	if (line == "EXIT")
		return (1);
	//else if (line == "ADD")
	return (0);
}

int main(void)
{
	PhoneBook	p_book;
	char		buff[7];

	while (1)
	{
		std::cout << "Welcome to the Crappy Awesome Phonebook Software."
		<< std::endl
		<< "Type ADD, SEARCH, or EXIT"
		<< std::endl;
		std::cin.getline(buff, 7);
		if (ft_parse_command(buff) == 1)
			break;
		
	}
    
}
