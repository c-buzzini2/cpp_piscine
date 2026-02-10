/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:15:05 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/09 12:02:36 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
        public:
        
        ScavTrap(void);
        ScavTrap(ScavTrap const &src);
        ScavTrap(std::string name);
        ~ScavTrap(void);

        ScavTrap & operator=(ScavTrap const &src);
        
        void guardGate();
        void attack(const std::string& target);
};

#endif