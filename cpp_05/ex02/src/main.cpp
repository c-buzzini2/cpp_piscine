/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:42:52 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/03 10:55:13 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
    std::cout << "\nTEST SHRUBBERY Default constructor\n";
    {
        AForm* a = new ShrubberyCreationForm();
    
        std::cout << *a;
        std::cout << "Target: " << a->getTarget() << std::endl;

        delete (a);
    }

    std::cout << "\nnTEST SHRUBBERY Copy constructor\n";
    {
        ShrubberyCreationForm b;
        ShrubberyCreationForm d(b);
    
        std::cout << b;
        std::cout << d;
    }

    std::cout << "\nTEST SHRUBBERY successfully sign and execute\n";
    AForm *b = new ShrubberyCreationForm("home");
    std::cout << *b;
    std::cout << "Target: " << b->getTarget() << std::endl;
    try
    {
        {
            Bureaucrat John("John", 130);
            John.signForm(*b);
            std::cout << *b;
            b->execute(John);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete(b);
    
    std::cout << "\nTEST SHRUBBERY fails to sign\n";
    AForm *f = new ShrubberyCreationForm("office");
    std::cout << *f;
    try
    {
        {
            Bureaucrat Jack("Jack", 146);
            Jack.signForm(*f);
            std::cout << *f;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nTEST SHRUBBERY fails to execute\n";
    std::cout << *f;
    try
    {
        {
            Bureaucrat Jack("Jack", 130);
            f->execute(Jack);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        {
            Bureaucrat Jack("Jack", 138);
            Jack.signForm(*f);
            std::cout << *f;
            f->execute(Jack);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete (f);

    
}