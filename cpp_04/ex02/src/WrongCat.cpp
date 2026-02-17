/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:52:13 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/17 14:02:37 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    type = "WrongCat";
    std::cout << this->type << " created (default)\n";
}

WrongCat & WrongCat::operator=(WrongCat const &src)
{
    WrongAnimal::operator=(src);
    this->type = src.type;    
    std::cout << this->type << " assigned\n";
    return(*this);
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
    this->type = src.type;
    std::cout << this->type << "'s copy created\n";
}

WrongCat::~WrongCat(void)
{
    std::cout << this->type << " destructed\n";
}

void WrongCat::makeSound(void) const
{
    std::cout << "meow\n";
}
