/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:30:31 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/31 18:28:22 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _RawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const nb)
{
	std::cout << "Int constructor called\n";
	_RawBits = nb << _Fractional_Bits;
}

Fixed::Fixed(float const nb)
{
	std::cout << "Float constructor called\n";
	_RawBits = static_cast<int>(roundf(nb * (1 << _Fractional_Bits)));
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called\n";
	this->_RawBits = src._RawBits;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_RawBits);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->_RawBits = raw;
}

int Fixed::toInt(void) const
{
	return (this->_RawBits >> this->_Fractional_Bits);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_RawBits) / (1 << this->_Fractional_Bits));
}
