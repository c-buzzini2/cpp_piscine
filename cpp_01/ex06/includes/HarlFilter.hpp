/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:17:25 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/23 11:04:13 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARLFILTER_HPP
#define HARLFILTER_HPP

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