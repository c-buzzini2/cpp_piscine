/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/11 14:01:31 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
    std::cout << this->type << " created (default)\n";
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const &src)
{
    this->type = src.type;    
    std::cout << this->type << " assigned\n";
    return(*this);
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) : type(src.type)
{
    std::cout << this->type << "'s copy created\n";
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << this->type << " destructed\n";
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WRONG!!!!!\n";
}