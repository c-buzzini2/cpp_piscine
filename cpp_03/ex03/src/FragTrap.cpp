/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/13 18:30:50 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    this->hit_pts = 100;
    this->energy_pts = 100;
    this->attack_dmg = 30;
    std::cout << "FragTrap " << this->name << " created (default)\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hit_pts = 100;
    this->energy_pts = 100;
    this->attack_dmg = 30;
    std::cout << "FragTrap " << this->name << " created\n";
}

FragTrap & FragTrap::operator=(FragTrap const &src)
{
    this->name = src.name;
    this->hit_pts = src.hit_pts; 
    this->energy_pts = src.energy_pts;
    this->attack_dmg = src.attack_dmg;
    
    std::cout << "FragTrap " << this->name << " assigned\n";
    return(*this);
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
    this->name = src.name;
    this->hit_pts = src.hit_pts; 
    this->energy_pts = src.energy_pts;
    this->attack_dmg = src.attack_dmg;
    std::cout << "FragTrap " << this->name << "'s copy created\n";
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << this->name << " destructed\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " high-fives guys\n";
}

