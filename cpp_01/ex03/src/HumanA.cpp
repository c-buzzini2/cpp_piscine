/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:26:56 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/17 12:05:11 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string src_name, Weapon &src_wp) : wp(src_wp), name(src_name)
{
}

void HumanA::attack(void)
{
    std::cout << this->getName() << " attacks with their " << this->getWeapon()
                << std::endl;
}

const std::string& HumanA::getWeapon(void) const
{
    return (this->wp.getType());
}
const std::string& HumanA::getName(void) const
{
    return (this->name);
}