/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:06:14 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/31 20:14:31 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed 
{
	public:
	
	Fixed(void);
	Fixed(Fixed const &src);
	Fixed(int const nb);
	Fixed(float const nb);
	~Fixed(void);

	Fixed & operator=(Fixed const & src);
	bool operator<(Fixed const & other) const;
	bool operator>(Fixed const & other) const;
	bool operator<=(Fixed const & other) const;
	bool operator>=(Fixed const & other) const;
	bool operator==(Fixed const & other) const;
	bool operator!=(Fixed const & other) const;
	Fixed operator+(Fixed const & other) const;
	Fixed operator-(Fixed const & other) const;
	Fixed operator*(Fixed const & other) const;
	Fixed operator/(Fixed const & other) const;
	Fixed & operator++(void);
	Fixed operator++(int value);

	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;
	
	private:
	
	int 				_RawBits;
	static const int	_Fractional_Bits = 8;
};

std::ostream &	operator<<(std::ostream &o, Fixed const & src);

#endif