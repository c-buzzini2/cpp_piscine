/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/18 08:39:56 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

void Character::_free_arr(AMateria **arr)
{
    for (int i = 0; i < 4; i++)
        delete(arr[i]);
}

void Character::_init_arr(AMateria **arr)
{
    for (int i = 0; i < 4; i++)
        arr[i] = NULL;
}

Character::Character(void) : _name("Unnamed"), _mat_total(0)
{
    _init_arr(this->_inventory);
    std::cout << this->_name << " created (default)\n";
}

Character::Character(std::string const & name) : _name(name), _mat_total(0)
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
        this->_inventory[i] = src._inventory[i]; //not allocating yet
    }
    std::cout << this->_name << " assigned\n";
    return(*this);
}

Character::Character(Character const &src) : _name(src._name), _mat_total(src._mat_total)
{
    _init_arr(this->_inventory);
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = src._inventory[i]; //not allocating yet
    std::cout << this->_name << "'s copy created\n";
}

Character::~Character(void)
{
    _free_arr(_inventory);
    std::cout << this->_name << " destructed\n";
}

std::string const & Character::getName() const
{
    return (this->_name);
}

//START HERE!!!! IMPLEMENT FUNCTIONS AND START TESTING, 
//GO BACK TO ICE AND CURE TO IMPLEMENT USE PROPERLY
//THEN CHECK IF/HOW I CAN ALLOCATE ABOVE
//FINALLY, MATERIASOURCE

void Character::use(int idx, ICharacter& target)
{
    
}

void Character::equip(AMateria* m)
{
    
}
void Character::unequip(int idx)
{
    
}
