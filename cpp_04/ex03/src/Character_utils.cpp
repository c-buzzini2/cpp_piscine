/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/18 14:35:59 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

void Character::_copy_arr(AMateria **dest, AMateria **src, int size)
{
    int i = 0;
    
    while (i < size)
    {
        dest[i] = src[i];
        i++;
    }
}

void Character::_free_arr(AMateria **arr, int size)
{
    for (int i = 0; i < size; i++)
        delete(arr[i]);
}

void Character::_init_arr(AMateria **arr)
{
    for (int i = 0; i < 4; i++)
        arr[i] = NULL;
}
