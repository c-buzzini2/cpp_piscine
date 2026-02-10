/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/10 10:23:29 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//START WITH THESE TWO FUNCTIONS. WHY ARE ALL VALUES TAKEN OVER FROM FRAGTRAP?
DiamondTrap::DiamondTrap(void)
{
    std::cout << "DiamondTrap " << this->name << " created:\n"
                << "hit_pts: " << this->hit_pts << std::endl
                 << "en_pts: " << this->energy_pts << std::endl
                  << "attack_dmg: " << this->attack_dmg << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
    // this->hit_pts = 100;
    // this->energy_pts = 100;
    // this->attack_dmg = 30;
    std::cout << "DiamondTrap " << this->name << " created:\n"
                << "hit_pts: " << this->hit_pts << std::endl
                 << "en_pts: " << this->energy_pts << std::endl
                  << "attack_dmg: " << this->attack_dmg << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const &src)
{
    this->name = src.name;
    this->hit_pts = src.hit_pts; 
    this->energy_pts = src.energy_pts;
    this->attack_dmg = src.attack_dmg;
    
    std::cout << "DiamondTrap " << this->name << " assigned\n";
    return(*this);
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap()
{
    this->name = src.name;
    this->hit_pts = src.hit_pts; 
    this->energy_pts = src.energy_pts;
    this->attack_dmg = src.attack_dmg;
    std::cout << "DiamondTrap " << this->name << "'s copy created\n";
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << this->name << " destructed\n";
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap: my name is " << this->name << " high-fives guys\n";
}

