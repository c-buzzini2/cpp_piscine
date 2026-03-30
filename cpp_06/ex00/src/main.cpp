/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:42:52 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/30 15:30:01 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "program needs one argument\n";
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}