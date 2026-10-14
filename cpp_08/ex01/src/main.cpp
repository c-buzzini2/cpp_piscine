/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:17:59 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/10/14 14:40:46 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main (void)
{
    Span test(3);

    try
    {
        test.addNumber(4);
        test.addNumber(11);
        test.addNumber(6);
        test.addNumber(3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < 3; i++)
        std::cout << (test.getVec())[i] << std::endl;
    std::cout << test.longestSpan() << "\n";
    std::cout << test.shortestSpan() << "\n";


    

}