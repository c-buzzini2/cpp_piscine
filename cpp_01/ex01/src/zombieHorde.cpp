/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:19:02 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/24 12:05:15 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0 || N > 10000)
    {
        std::cerr << "Invalid number\n";
        return (NULL);
    }
    if (name == "")
        name = "[nameless]";
    Zombie  *zb = new (std::nothrow) Zombie[N];
    if (!zb)
    {
        std::cerr << "Allocation error\n";
        return (NULL);
    }
    
    for(int i = 0; i < N; i++)
        zb[i].SetName(name);
    return(zb);
}