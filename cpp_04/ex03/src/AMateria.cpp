/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/13 21:53:08 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type("AMateria")
{
    std::cout << this->type << " created (default)\n";
}

AMateria::AMateria(std::string const & type) : type(type)
{
    std::cout << this->type << " created (default)\n";
}

AMateria & AMateria::operator=(AMateria const &src)
{
    this->type = src.type;    
    std::cout << this->type << " assigned\n";
    return(*this);
}

AMateria::AMateria(AMateria const &src) : type(src.type)
{
    std::cout << this->type << "'s copy created\n";
}

AMateria::~AMateria(void)
{
    std::cout << this->type << " destructed\n";
}

std::string const & AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    
}
