/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/16 13:14:15 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void MateriaSource::_free_arr(AMateria **arr)
{
    for (int i = 0; i < 4; i++)
        delete(arr[i]);
}

void MateriaSource::_init_arr(AMateria **arr)
{
    for (int i = 0; i < 4; i++)
        arr[i] = NULL;
}

MateriaSource::MateriaSource(void) : _mat_total(0)
{
    _init_arr(this->_learned);
    std::cout << "MateriaSource created (default)\n";
}

MateriaSource::MateriaSource(std::string const & name) : _mat_total(0)
{
    _init_arr(this->_learned);
    std::cout << "MateriaSource created (name param)\n";
}

MateriaSource & MateriaSource::operator=(MateriaSource const &src)
{
    this->_mat_total = src._mat_total;
    for (int i = 0; i < 4; i++)
    {
        delete (this->_learned[i]);
        this->_learned[i] = src._learned[i]; //not allocating yet
    }
    std::cout << "MateriaSource assigned\n";
    return(*this);
}

MateriaSource::MateriaSource(MateriaSource const &src) : _mat_total(src._mat_total)
{
    _init_arr(this->_learned);
    for (int i = 0; i < 4; i++)
        this->_learned[i] = src._learned[i]; //not allocating yet
    std::cout << "MateriaSource's copy created\n";
}

MateriaSource::~MateriaSource(void)
{
    _free_arr(_learned);
    std::cout << "MateriaSource destructed\n";
}

void MateriaSource::learnMateria(AMateria*)
{
    
}
