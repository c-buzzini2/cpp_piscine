/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:17:59 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/11/04 18:21:57 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char** argv)
{
   if (argc < 4)
   {
        std::cerr << "Not enough arguments\n";
        return (1);
   }
   try
   {
        RPN  program;
        program.run(argc - 1, argv + 1);
   }
   catch(const std::exception& e)
   {
        std::cerr << e.what() << '\n';
   }
   

   
   
}