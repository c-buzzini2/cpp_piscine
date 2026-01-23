/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:17:25 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/22 18:22:03 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <map>

class Harl
{
	public:
	void complain(std::string level);
	
    private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif