/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 10:39:46 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/17 15:16:34 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		void				setWeapon(Weapon &weapon);
		const std::string*  getWeapon(void) const;
		const std::string&	getName(void) const;
		void				attack(void);

		HumanB(std::string src_name);
		
	private:
		Weapon		*wp;
		std::string	name;
};

#endif