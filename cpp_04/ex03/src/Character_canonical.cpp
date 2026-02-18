/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character_canonical.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/18 14:28:25 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void) : _name("Unnamed"), _mat_total(0), _floor_total(0), _floor_mat(NULL)
{
    _init_arr(this->_inventory);
    std::cout << this->_name << " created (default)\n";
}

Character::Character(std::string const & name) : _name(name), _mat_total(0), _floor_total(0), _floor_mat(NULL)
{
    _init_arr(this->_inventory);
    std::cout << this->_name << " created (name param)\n";
}

Character & Character::operator=(Character const &src)
{
    this->_name = src._name;
    this->_mat_total = src._mat_total;
    for (int i = 0; i < 4; i++)
    {
        delete (this->_inventory[i]);
        if (src._inventory[i] != NULL)
        {
            AMateria *copy_mat = src._inventory[i]->clone();
            this->_inventory[i] = copy_mat;    
        }
        else
            this->_inventory[i] = NULL;    
    }
    if (this->_floor_total > 0)
    {
        _free_arr(_floor_mat, _floor_total);
    }
    if (src._floor_total > 0)
    {
        this->_floor_total = src._floor_total;
        AMateria** new_floor = new AMateria*[_floor_total];
        for (int i = 0; i < _floor_total; i++)
        {
            new_floor[i] = src._floor_mat[i]->clone();
        }
        _floor_mat = new_floor;
    }
    else
        _floor_mat = NULL;
    std::cout << this->_name << " assigned\n";
    return(*this);
}

Character::Character(Character const &src) : _name(src._name), _mat_total(src._mat_total),
                                            _floor_total(src._floor_total)
{
    _init_arr(this->_inventory);
    for (int i = 0; i < 4; i++)
    {
        if (src._inventory[i] != NULL)
        {
            AMateria *copy_mat = src._inventory[i]->clone();
            this->_inventory[i] = copy_mat;    
        }
        else
            this->_inventory[i] = NULL;    
    }
    if (src._floor_total > 0)
    {
        this->_floor_total = src._floor_total;
        AMateria** new_floor = new AMateria*[_floor_total];
        for (int i = 0; i < _floor_total; i++)
        {
            new_floor[i] = src._floor_mat[i]->clone();
        }
        _floor_mat = new_floor;
    }
    else
        _floor_mat = NULL;
    std::cout << this->_name << "'s copy created\n";
}

Character::~Character(void)
{
    _free_arr(_inventory, 4);
    _free_arr(_floor_mat, _floor_total);
    delete [] _floor_mat;
    std::cout << this->_name << " destructed\n";
}
