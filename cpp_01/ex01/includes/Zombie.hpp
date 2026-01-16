/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:53:36 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/15 15:41:36 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
		void	announce(void);
		void	SetName(std::string name);
		~Zombie(void);
		
	private:
		std::string	name;
};

#endif
