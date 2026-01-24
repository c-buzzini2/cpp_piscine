/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:17:34 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/24 15:25:11 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.h"

int main(int argc, char **argv)
{	
	long n;
	
	if (argc != 3 || !valid_input(argv[1]) || (n = ft_atol(argv[1])) > 2147483647)
	{
		std::cerr << "Include horde size (int > 0) and Zombie name\n";
		return (1);
	}
	int nb = static_cast<int>(n);
	Zombie *zb = zombieHorde(nb, argv[2]);
	if (!zb)
		return (1);
	for(int i = 0; i < n; i++)
		zb[i].announce();
	delete[] zb;
}