/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/11 14:01:31 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    type = "Cat";
    std::cout << this->type << " created (default)\n";
}

Cat & Cat::operator=(Cat const &src)
{
    Animal::operator=(src);
    this->type = src.type;    
    std::cout << this->type << " assigned\n";
    return(*this);
}

Cat::Cat(Cat const &src) : Animal(src)
{
    this->type = src.type;
    std::cout << this->type << "'s copy created\n";
}

Cat::~Cat(void)
{
    std::cout << this->type << " destructed\n";
}

void Cat::makeSound(void) const
{
    std::cout << "meow\n";
}
