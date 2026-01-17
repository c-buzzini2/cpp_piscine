/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 10:39:46 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/17 12:05:37 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		const std::string&  getWeapon(void) const;
		const std::string&	getName(void) const;
		void				attack(void);

		HumanA(std::string src_name, Weapon &src_wp);
		
	private:
		Weapon		&wp;
		std::string	name;
};

#endif