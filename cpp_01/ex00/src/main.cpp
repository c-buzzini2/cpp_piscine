/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:17:34 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/24 11:51:43 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.h"

int main(void)
{
	randomChump("Ana");
	
	Zombie *zb = newZombie("Maria");
	zb->announce();
	delete(zb);
}