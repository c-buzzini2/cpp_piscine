/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/13 21:53:08 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
    std::cout << this->type << " created (default)\n";
}

Cure & Cure::operator=(Cure const &src)
{
    AMateria::operator=(src);
    this->type = src.type;    
    std::cout << this->type << " assigned\n";
    return(*this);
}

Cure::Cure(Cure const &src) : AMateria(src)
{
    std::cout << this->type << "'s copy created\n";
}

Cure::~Cure(void)
{
    std::cout << this->type << " destructed\n";
}

AMateria* Cure::clone() const
{
    Cure* clone = new Cure();
    clone->type = this->type;
    std::cout << this->type << "'s clone created\n";
    return (clone);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << " *\n";
}
