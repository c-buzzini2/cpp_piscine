/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/11 14:01:31 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain created (default)\n";
}

Brain & Brain::operator=(Brain const &src)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
    std::cout << "Brain assigned\n";
    return(*this);
}

Brain::Brain(Brain const &src)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
    std::cout << "Brain's copy created\n";
}

Brain::~Brain(void)
{
    std::cout << "Brain destructed\n";
}
