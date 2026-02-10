/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:42:51 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/09 11:36:13 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
    public:
        
        ClapTrap(void);
        ClapTrap(ClapTrap const &src);
        ClapTrap(std::string name);
        ~ClapTrap(void);

        ClapTrap & operator=(ClapTrap const &src);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    
    protected:
      
        std::string name;
        int         hit_pts;
        int         energy_pts;
        int         attack_dmg;
};

#endif