/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:42:52 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/02 15:05:13 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
    std::cout << "\nSHRUBBERY Default constructor\n";
    {
        AForm* a = new ShrubberyCreationForm();
    
        std::cout << *a;

        delete (a);
    }

    std::cout << "\nSHRUBBERY Copy constructor\n";
    {
        ShrubberyCreationForm b;
        ShrubberyCreationForm d(b);
    
        std::cout << b;
        std::cout << d;
    }

    std::cout << "\nSHRUBBERY successfully sign\n";
    AForm *b = new ShrubberyCreationForm("TargetBob");
    std::cout << *b;
    try
    {
        {
            Bureaucrat John("John", 145);
            John.signForm(*b);
            std::cout << *b;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete(b);
    
    std::cout << "\nSHRUBBERY fails to sign\n";
    AForm *f = new ShrubberyCreationForm("TargetBob");
    std::cout << *f;
    try
    {
        {
            Bureaucrat John("Jack", 146);
            John.signForm(*f);
            std::cout << *f;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete (f);
    //START HERE!!! IMPLEMENT TEST EXECUTE

/*     std::cout << "\nCannot sign form\n";
    try
    {
        {
            Form b("NATO", 5, 40);
            Form d(b);
            std::cout << b;
            
            //d = b;
            
            Bureaucrat Mark("Mark", 6);
            Mark.signForm(b);
            std::cout << b;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } */
}