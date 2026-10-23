/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:17:59 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/10/23 16:13:07 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Program needs one filename as argument";
        return 1;
    }
    try
    {
        BitcoinExchange     exge_rate("data.csv");
        
        //exge_rate.calculate(argv[1]);
        (void) argv;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}