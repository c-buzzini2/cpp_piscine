/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:42:51 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/10 10:05:45 by cbuzzini         ###   ########.fr       */
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
    
    private:
      
        std::string _name;
        int         _hit_pts;
        int         _energy_pts;
        int         _attack_dmg;
};

#endif