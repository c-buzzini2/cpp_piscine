/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:42:39 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/23 11:34:14 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

int main (int argc, char **argv)
{	
	Harl						test_harl;

	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" 
					<< std::endl;
		return (1);
	}
	test_harl.complain(argv[1]);
}
