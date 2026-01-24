/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:17:34 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/24 11:18:28 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.h"

int main(void)
{	
	int n = 10000;
	Zombie *zb = zombieHorde(n, "Greta");
	if (!zb)
		return (1);
	for(int i = 0; i < n; i++)
		zb[i].announce();
	delete[] zb;
}