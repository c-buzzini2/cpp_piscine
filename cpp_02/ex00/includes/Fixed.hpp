/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:06:14 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/29 15:55:16 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed 
{
	public:
	
	Fixed(void);
	Fixed(Fixed const &src);
	~Fixed(void);

	Fixed & operator=(Fixed const & src);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	private:
	
	int 				_RawBits;
	static const int	_Fractional_Bits = 8;
};

#endif