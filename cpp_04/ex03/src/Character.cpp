/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/18 14:35:51 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

std::string const & Character::getName() const
{
    return (this->_name);
}

void Character::use(int idx, ICharacter& target)
{
    if (_inventory[idx] != NULL)
        _inventory[idx]->use(target);
}

void Character::equip(AMateria* m)
{
    if (this->_mat_total < 4)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i] == NULL)
            {
                _inventory[i] = m;
                _mat_total++;
                std::cout << m->getType() << " equiped at index " 
                            << i << std::endl;
                break;
            }
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 4 && _inventory[idx] != NULL)
    {
        _send_to_floor(_inventory[idx]);
        std::cout << _inventory[idx]->getType() << " unequiped at index " 
                            << idx << std::endl;
        _inventory[idx] = NULL;
        _mat_total--;
    }
}

void Character::_send_to_floor(AMateria *m)
{
    _floor_total++;
    AMateria** new_floor = new AMateria*[_floor_total];
    _copy_arr(new_floor, _floor_mat, _floor_total - 1);
    new_floor[_floor_total - 1] = m;
    delete []_floor_mat;
    _floor_mat = new_floor;
}
