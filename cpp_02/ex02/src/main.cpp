/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:24:27 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/31 20:24:46 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); //WHY ARE THESE CALLING INT CONSTRUCTOR also for the multiplication?
    Fixed const c (1.5f);
    Fixed const d (2.5f);

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
   // std::cout << Fixed::max( a, b ) << std::endl;
    //START HERE!!! WHY ARE ALL THE OPERATIONS GOING WRONG
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



    return 0;
}