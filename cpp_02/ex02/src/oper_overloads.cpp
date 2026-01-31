/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_overloads.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:27:47 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/31 20:21:01 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed & Fixed::operator=(Fixed const & src)
{
	std::cout << "Copy assignment operator called\n";
	this->_RawBits = src._RawBits;
	return (*this);
}

std::ostream &	operator<<(std::ostream &o, Fixed const & src)
{
	o << src.toFloat();
	return (o);
}

bool Fixed::operator<(Fixed const & other) const
{
	return (this->_RawBits < other._RawBits);
}

bool Fixed::operator>(Fixed const & other) const
{
	return (this->_RawBits > other._RawBits);
}

bool Fixed::operator<=(Fixed const & other) const
{
	return (this->_RawBits <= other._RawBits);
}

bool Fixed::operator>=(Fixed const & other) const
{
	return (this->_RawBits >= other._RawBits);
}

bool Fixed::operator==(Fixed const & other) const
{
	return (this->_RawBits == other._RawBits);
}

bool Fixed::operator!=(Fixed const & other) const
{
	return (this->_RawBits != other._RawBits);
}

Fixed Fixed::operator+(Fixed const & other) const
{
	Fixed	temp(this->_RawBits + other._RawBits);
	
	return (temp);
}

Fixed Fixed::operator-(Fixed const & other) const
{
	Fixed	temp(this->_RawBits - other._RawBits);
	
	return (temp);
}

Fixed Fixed::operator*(Fixed const & other) const
{
	Fixed	temp(this->_RawBits * other._RawBits);
	
	return (temp);
}

Fixed Fixed::operator/(Fixed const & other) const
{
	Fixed	temp(this->_RawBits / other._RawBits);
	
	return (temp);
}

Fixed Fixed::operator++(int value)
{
	(void)value;
	Fixed	temp(*this);
	
	this->_RawBits += 1; 
	
	return (temp);
}

Fixed & Fixed::operator++(void)
{
	this->_RawBits += 1; 
	
	return (*this);
}