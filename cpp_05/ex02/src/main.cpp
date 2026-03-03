/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:42:52 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/03 13:49:28 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
    srand(time(NULL));
    std::cout << "\n*******SHRUBBERY TESTS********\n";    
    std::cout << "\nTEST SHRUBBERY Default constructor\n";
    {
        AForm* a = new ShrubberyCreationForm();
    
        std::cout << *a;
        std::cout << "Target: " << a->getTarget() << std::endl;

        delete (a);
    }

    std::cout << "\nTEST SHRUBBERY Copy constructor\n";
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
    {
        Bureaucrat John("John", 130);
        John.signForm(*b);
        std::cout << *b;
        John.executeForm(*b);
    }
    delete(b);
    
    std::cout << "\nTEST SHRUBBERY fails to sign\n";
    AForm *f = new ShrubberyCreationForm("office");
    std::cout << *f;
    {
        Bureaucrat Jack("Jack", 146);
        Jack.signForm(*f);
        std::cout << *f;
    }

    std::cout << "\nTEST SHRUBBERY fails to execute\n";
    std::cout << *f;

    {
        Bureaucrat Jack("Jack", 130);
        Jack.executeForm(*f);
    }
    {
        Bureaucrat Jack("Jack", 138);
        Jack.signForm(*f);
        std::cout << *f;
        Jack.executeForm(*f);
    }
    delete (f);

    std::cout << "\n\n*******ROBOTOMY TESTS********\n";    
    std::cout << "\nTEST Robotomy Default constructor\n";
    {
        AForm* a = new RobotomyRequestForm();
    
        std::cout << *a;
        std::cout << "Target: " << a->getTarget() << std::endl;

        delete (a);
    }

    std::cout << "\nTEST ROBOTOMY Copy constructor\n";
    {
        RobotomyRequestForm g;
        RobotomyRequestForm h(g);
    
        std::cout << g;
        std::cout << h;
    }

    std::cout << "\nTEST ROBOTOMY successfully sign and execute\n";
    AForm *g = new RobotomyRequestForm("Wall-e");
    std::cout << *g;
    std::cout << "Target: " << g->getTarget() << std::endl;
    {
        Bureaucrat John("John", 45);
        John.signForm(*g);
        std::cout << *g;
        John.executeForm(*g);
    }
    delete(g);
    
    std::cout << "\nTEST ROBOTOMY fails to sign\n";
    AForm *h = new RobotomyRequestForm("Android");
    std::cout << *h;
    {
        Bureaucrat Jack("Jack", 73);
        Jack.signForm(*h);
        std::cout << *h;
    }

    std::cout << "\nTEST ROBOTOMY fails to execute\n";
    std::cout << *h;

    {
        Bureaucrat Jack("Jack", 45);
        Jack.executeForm(*h);
    }
    {
        Bureaucrat Jack("Jack", 46);
        Jack.signForm(*h);
        std::cout << *h;
        Jack.executeForm(*h);
    }
    delete (h);

        std::cout << "\n\n*******PRESIDENTIAL TESTS********\n";    
    std::cout << "\nTEST PRESIDENTIAL Default constructor\n";
    {
        AForm* a = new PresidentialPardonForm();
    
        std::cout << *a;
        std::cout << "Target: " << a->getTarget() << std::endl;

        delete (a);
    }

    std::cout << "\nTEST PRESIDENTIAL Copy constructor\n";
    {
        PresidentialPardonForm i;
        PresidentialPardonForm j(i);
    
        std::cout << i;
        std::cout << j;
    }

    std::cout << "\nTEST PRESIDENTIAL successfully sign and execute\n";
    AForm *i = new PresidentialPardonForm("Wall-e");
    std::cout << *i;
    std::cout << "Target: " << i->getTarget() << std::endl;
    {
        Bureaucrat John("John", 5);
        John.signForm(*i);
        std::cout << *i;
        John.executeForm(*i);
    }
    delete(i);
    
    std::cout << "\nTEST PRESIDENTIAL fails to sign\n";
    AForm *j = new PresidentialPardonForm("Android");
    std::cout << *j;
    {
        Bureaucrat Jack("Jack", 26);
        Jack.signForm(*j);
        std::cout << *j;
    }

    std::cout << "\nTEST PRESIDENTIAL fails to execute\n";
    std::cout << *j;

    {
        Bureaucrat Jack("Jack", 5);
        Jack.executeForm(*j);
    }
    {
        Bureaucrat Jack("Jack", 6);
        Jack.signForm(*j);
        std::cout << *j;
        Jack.executeForm(*j);
    }
    delete (j);
    
}