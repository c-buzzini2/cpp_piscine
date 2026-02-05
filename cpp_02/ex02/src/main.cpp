/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:24:27 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/05 12:06:32 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const c (1.5f);
    Fixed const d (2.5f);
    Fixed e;

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << (d + c) << std::endl;
    std::cout << (d - c) << std::endl;
    std::cout << (d * c) << std::endl;
    std::cout << (c / d) << std::endl;
    std::cout << (a < c) << std::endl;
    std::cout << (a > c) << std::endl;
    std::cout << (a <= c) << std::endl;
    std::cout << (a >= c) << std::endl;
    std::cout << (a == c) << std::endl;
    std::cout << (a != c) << std::endl;

    e.setRawBits(100);
    std::cout << Fixed::min(a, e) << std::endl;
    std::cout << Fixed::max(a, e) << std::endl;
    std::cout << Fixed::min(c, d) << std::endl;
    std::cout << Fixed::max(c, d) << std::endl;

    return 0;
}