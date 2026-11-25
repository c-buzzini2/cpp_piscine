/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:17:59 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/11/25 15:40:59 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char** argv)
{
   if (argc < 2 || argv[1][0] == '\0')
   {
        std::cerr << "You need at least one number as argument\n";
        return (1);
   }
   try
   {
        PmergeMe  program(argc, argv);
        program.run();
   }
   catch(const std::exception& e)
   {
        std::cerr << e.what() << '\n';
   }
   

   
   
}