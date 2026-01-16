/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:19:02 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/16 15:21:40 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie  *zb = new Zombie[N];
    
    for(int i = 0; i < N; i++)
        zb[i].SetName(name);
    return(zb);
}