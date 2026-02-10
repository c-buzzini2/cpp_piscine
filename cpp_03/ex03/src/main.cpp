/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:13:42 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/10 11:49:57 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main (void)
{
    DiamondTrap a;
    DiamondTrap b("John");
    DiamondTrap c (b);
    DiamondTrap d;
    
    d = b;

    DiamondTrap e("James");
    e.guardGate();
    e.attack("Peter");//dummy
    e.takeDamage(9);
    e.beRepaired(9);
    for (int i = 0; i < 5; i++)
    {
        e.attack("Peter");
    }
    e.takeDamage(100);
}