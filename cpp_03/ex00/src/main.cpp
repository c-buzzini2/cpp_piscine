/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:13:42 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/08 13:26:36 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
    ClapTrap a;
    ClapTrap b("John");
    ClapTrap c (b);
    ClapTrap d;
    
    d = b;

    ClapTrap e("James");

    e.attack("Peter");//dummy
    e.takeDamage(9);
    e.beRepaired(9);
    for (int i = 0; i < 10; i++)
    {
        e.attack("Peter");
    }
    e.takeDamage(10);
}