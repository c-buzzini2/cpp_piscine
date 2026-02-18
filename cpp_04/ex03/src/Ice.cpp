/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/13 21:53:08 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
    std::cout << this->type << " created (default)\n";
}

Ice & Ice::operator=(Ice const &src)
{
    AMateria::operator=(src);
    this->type = src.type;    
    std::cout << this->type << " assigned\n";
    return(*this);
}

Ice::Ice(Ice const &src) : AMateria(src)
{
    std::cout << this->type << "'s copy created\n";
}

Ice::~Ice(void)
{
    std::cout << this->type << " destructed\n";
}

AMateria* Ice::clone() const
{
    Ice* clone = new Ice();
    clone->type = this->type;
    std::cout << this->type << "'s clone created\n";
    return (clone);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
