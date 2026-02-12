/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:26:15 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/12 11:57:21 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
	Brain(void);
    Brain(Brain const &src);
    ~Brain(void);
    Brain & operator=(Brain const &src);
	
	private:
	std::string ideas[100];
};

#endif