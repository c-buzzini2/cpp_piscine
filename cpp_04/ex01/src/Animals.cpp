/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/11 14:01:31 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

Animal::Animal(void) : type("Animal")
{
    std::cout << this->type << " created (default)\n";
}

Animal & Animal::operator=(Animal const &src)
{
    this->type = src.type;    
    std::cout << this->type << " assigned\n";
    return(*this);
}

Animal::Animal(Animal const &src) : type(src.type)
{
    std::cout << this->type << "'s copy created\n";
}

Animal::~Animal(void)
{
    std::cout << this->type << " destructed\n";
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound(void) const
{
    std::cout << "WTF\n";
}