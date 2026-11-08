/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:17:59 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/11/08 10:21:39 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char** argv)
{
   if (argc != 2 || argv[1][0] == '\0')
   {
        std::cerr << "You need a single non-empty expression as parameter\n";
        return (1);
   }
   try
   {
        RPN  program;
        program.run(static_cast<std::string>(argv[1]));
   }
   catch(const std::exception& e)
   {
        std::cerr << e.what() << '\n';
   }
   

   
   
}