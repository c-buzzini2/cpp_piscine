/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/08 13:33:37 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Unnamed"), hit_pts(10), energy_pts(10), attack_dmg(0)
{
    std::cout << this->name << " created\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_pts(10), energy_pts(10), attack_dmg(0)
{
        std::cout << this->name << " created\n";
}

ClapTrap & ClapTrap::operator=(ClapTrap const &src)
{
    this->name = src.name;
    this->hit_pts = src.hit_pts; 
    this->energy_pts = src.energy_pts;
    this->attack_dmg = src.attack_dmg;
    
    std::cout << this->name << " assigned\n";
    return(*this);
}

ClapTrap::ClapTrap(ClapTrap const &src) : name(src.name), hit_pts(10), energy_pts(10), attack_dmg(0)
{
    std::cout << this->name << "'s copy created\n";
}

ClapTrap::~ClapTrap(void)
{
    std::cout << this->name << " destructed\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hit_pts == 0 || this->energy_pts == 0)
    {
        std::cout << this->name << " doesn't have enough hit points" 
                    << " or energy points to attack\n";
        return;
    }
    std::cout << this->name << " attacks " << target 
                << ", causing " << attack_dmg << " points of damage\n";
    this->energy_pts--;
    std::cout << this->name << " now has " << this->energy_pts << " energy points\n";
    //later, call target's take damage passing attack_dmg as parameter -> not part of these exercises
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->hit_pts -= amount;
    std::cout << this->name << " takes " << amount << " points of damage\n";
    std::cout << this->name << " now has " << this->hit_pts << " hit points\n";
    if (this->hit_pts <= 0)
        std::cout << this->name << " is dead\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_pts == 0 || this->energy_pts == 0)
    {
        std::cout << this->name << " doesn't have enough hit points" 
                    << " or energy points to repair themselves\n";
        return;
    }
    this->hit_pts += amount;
    this->energy_pts--;
    std::cout << this->name << " repairs itself\n";
    std::cout << this->name << " now has " << this->energy_pts << " energy points\n";
    std::cout << this->name << " now has " << this->hit_pts << " hit points\n";
}
