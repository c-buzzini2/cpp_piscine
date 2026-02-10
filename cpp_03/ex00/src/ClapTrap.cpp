/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/10 10:10:04 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Unnamed"), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
    std::cout << this->_name << " created\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
        std::cout << this->_name << " created\n";
}

ClapTrap & ClapTrap::operator=(ClapTrap const &src)
{
    this->_name = src._name;
    this->_hit_pts = src._hit_pts; 
    this->_energy_pts = src._energy_pts;
    this->_attack_dmg = src._attack_dmg;
    
    std::cout << this->_name << " assigned\n";
    return(*this);
}

ClapTrap::ClapTrap(ClapTrap const &src) : _name(src._name), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
    std::cout << this->_name << "'s copy created\n";
}

ClapTrap::~ClapTrap(void)
{
    std::cout << this->_name << " destructed\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_hit_pts == 0 || this->_energy_pts == 0)
    {
        std::cout << this->_name << " doesn't have enough hit points" 
                    << " or energy points to attack\n";
        return;
    }
    std::cout << this->_name << " attacks " << target 
                << ", causing " << _attack_dmg << " points of damage\n";
    this->_energy_pts--;
    std::cout << this->_name << " now has " << this->_energy_pts << " energy points\n";
    //later, call target's take damage passing _attack_dmg as parameter -> not part of these exercises
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hit_pts -= amount;
    std::cout << this->_name << " takes " << amount << " points of damage\n";
    std::cout << this->_name << " now has " << this->_hit_pts << " hit points\n";
    if (this->_hit_pts <= 0)
        std::cout << this->_name << " is dead\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hit_pts == 0 || this->_energy_pts == 0)
    {
        std::cout << this->_name << " doesn't have enough hit points" 
                    << " or energy points to repair themselves\n";
        return;
    }
    this->_hit_pts += amount;
    this->_energy_pts--;
    std::cout << this->_name << " repairs itself\n";
    std::cout << this->_name << " now has " << this->_energy_pts << " energy points\n";
    std::cout << this->_name << " now has " << this->_hit_pts << " hit points\n";
}
