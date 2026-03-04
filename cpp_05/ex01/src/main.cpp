/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:42:52 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/04 10:06:31 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

    std::cout << "\n***NEW TESTS***\n";
    std::cout << "FORM Default constructor (no grade / too high)\n";
    try
    {
        {
            Form a;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nSign Grade too high\n";
    try
    {
        {
            Form b("Finance", 0, 5);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nExec Grade too low\n";
    try
    {
        {
            Form b("Health", 5, 151);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\nGrades ok, sign form\n";
    try
    {
        {
            Form b("Security", 5, 40);
            Form d(b);
            std::cout << b;
                      
            Bureaucrat John("John", 5);
            John.signForm(b);
            std::cout << b;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nCannot sign form\n";
    try
    {
        {
            Form b("NATO", 5, 40);
            Form d(b);
            std::cout << b;
                        
            Bureaucrat Mark("Mark", 6);
            Mark.signForm(b);
            std::cout << b;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}