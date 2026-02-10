/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:42:51 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/10 11:28:25 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        
        DiamondTrap(void);
        DiamondTrap(DiamondTrap const &src);
        DiamondTrap(std::string name);
        ~DiamondTrap(void);

        DiamondTrap & operator=(DiamondTrap const &src);

        using ScavTrap::attack;
        void whoAmI();
    
    protected:
      
        std::string name;
        using FragTrap::hit_pts;
        using ScavTrap::energy_pts;
        using FragTrap::attack_dmg;
};

#endif