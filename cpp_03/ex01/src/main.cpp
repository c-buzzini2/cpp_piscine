/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:13:42 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/09 12:41:50 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (void)
{
    ScavTrap a;
    ScavTrap b("John");
    ScavTrap c (b);
    ScavTrap d;
    
    d = b;

    ScavTrap e("James");
    e.guardGate();
    e.attack("Peter");//dummy
    e.takeDamage(9);
    e.beRepaired(9);
    for (int i = 0; i < 10; i++)
    {
        e.attack("Peter");
    }
    e.takeDamage(100);
}