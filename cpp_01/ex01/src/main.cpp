/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:17:34 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/16 15:49:32 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.h"

//START HERE!!! CHECK FOR LEAKS with valgrind

int main(void)
{	
	int N = 10;
	Zombie *zb = zombieHorde(N, "Greta");
	for(int i = 0; i < N; i++)
		zb[i].announce();
	delete[] zb;
}