/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:26:56 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/17 15:19:30 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string src_name) : wp(NULL), name(src_name)
{
}

void HumanB::attack(void)
{
    if (this->wp != NULL)
        std::cout << this->getName() << " attacks with their " << *this->getWeapon()
                    << std::endl;
    else
        std::cout << this->getName() << " has no weapon"
                    << std::endl;
}

const std::string* HumanB::getWeapon(void) const
{
    if (this->wp == NULL)
        return (NULL);
    const std::string* wpPTR = &this->wp->getType();
    return (wpPTR);
}
const std::string& HumanB::getName(void) const
{
    return (this->name);
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->wp = &weapon;
}
