/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/11 14:01:31 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    type = "Dog";
    brn = new Brain;
    std::cout << this->type << " created (default)\n";
}

Dog & Dog::operator=(Dog const &src)
{
    this->type = src.type;
    delete(this->brn);
    this->brn = new Brain(*src.brn);
    std::cout << this->type << " assigned\n";
    return(*this);
}

Dog::Dog(Dog const &src) : Animal(src)
{
    this->type = src.type;
    this->brn = new Brain(*src.brn);
    std::cout << this->type << "'s copy created\n";
}

Dog::~Dog(void)
{
    delete(brn);
    std::cout << this->type << " destructed\n";
}

void Dog::makeSound(void) const
{
    std::cout << "woof\n";
}
