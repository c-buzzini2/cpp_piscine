/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/09 12:40:52 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    this->hit_pts = 100;
    this->energy_pts = 50;
    this->attack_dmg = 20;
    std::cout << "ScavTrap " << this->name << " created\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hit_pts = 100;
    this->energy_pts = 50;
    this->attack_dmg = 20;
    std::cout << "ScavTrap " << this->name << " created\n";
}

ScavTrap & ScavTrap::operator=(ScavTrap const &src)
{
    this->name = src.name;
    this->hit_pts = src.hit_pts; 
    this->energy_pts = src.energy_pts;
    this->attack_dmg = src.attack_dmg;
    
    std::cout << "ScavTrap " << this->name << " assigned\n";
    return(*this);
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap()
{
    this->name = src.name;
    this->hit_pts = src.hit_pts; 
    this->energy_pts = src.energy_pts;
    this->attack_dmg = src.attack_dmg;
    std::cout << "ScavTrap " << this->name << "'s copy created\n";
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->name << " destructed\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (this->hit_pts == 0 || this->energy_pts == 0)
    {
        std::cout << "ScavTrap " << this->name << " doesn't have enough hit points" 
                    << " or energy points to attack\n";
        return;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target 
                << ", causing " << attack_dmg << " points of damage\n";
    this->energy_pts--;
    std::cout << "ScavTrap " << this->name << " now has " << this->energy_pts << " energy points\n";
    //later, call target's take damage passing attack_dmg as parameter -> not part of these exercises
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->name << " is now in Gatekeeper Mode\n";
}

