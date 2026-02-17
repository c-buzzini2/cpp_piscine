/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/17 12:50:32 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type("AMateria")
{
    std::cout << "AMateria of type " << this->type << " created (default)\n";
}

AMateria::AMateria(std::string const & type) : type(type)
{
    std::cout << "AMateria of type " << this->type << " created (type string)\n";
}

AMateria & AMateria::operator=(AMateria const &src)
{
    this->type = src.type;    
    std::cout << "AMateria of type " << this->type << " assigned\n";
    return(*this);
}

AMateria::AMateria(AMateria const &src) : type(src.type)
{
    std::cout << "AMateria of type " << this->type << "'s copy created\n";
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria of type " << this->type << " destructed\n";
}

std::string const & AMateria::getType() const
{
    return (this->type);
}

