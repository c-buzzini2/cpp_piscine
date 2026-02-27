/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:42:52 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/27 14:09:20 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
    std::cout << "Default constructor (no grade / too high)\n";
    try
    {
        {
            Bureaucrat a;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nGrade too low\n";
    try
    {
        {
            Bureaucrat b("Jay", 500);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\nGrade ok\n";
    try
    {
        {
            Bureaucrat b("Jay", 5);
            Bureaucrat d(b);
            
            std::cout << b;

            d = b;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\nIncrement\n";
    try
    {
        {
            Bureaucrat b("John", 2);         
            std::cout << b;
            b.incrementGrade();
            std::cout << b;
            b.incrementGrade();
            std::cout << b;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nDecrement\n";
    try
    {
        {
            Bureaucrat b("Jack", 149);         
            std::cout << b;
            b.decrementGrade();
            std::cout << b;
            b.decrementGrade();
            std::cout << b;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}