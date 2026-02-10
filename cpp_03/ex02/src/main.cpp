/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:13:42 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/10 10:24:58 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main (void)
{
    FragTrap a;
    FragTrap b("John");
    FragTrap c (b);
    FragTrap d;
    
    d = b;

    FragTrap e("James");
    e.highFivesGuys();
    e.attack("Peter");//dummy
    e.takeDamage(9);
    e.beRepaired(9);
    for (int i = 0; i < 100; i++)
    {
        e.attack("Peter");
    }
    e.takeDamage(100);
}