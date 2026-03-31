/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer_canon.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:18:31 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/26 11:01:14 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

Base::~Base(void){}

Base* Base::generate(void)
{
	int nb = rand();

	if (nb % 3 == 0)
	{
		std::cout << "generating A\n";
		return (new A);
	}
	else if (nb % 3 == 1)
	{
		std::cout << "generating B\n";
		return (new B);
	}
	else
	{
		std::cout << "generating C\n";
		return (new C);
	}
}

void Base::identify(Base* p)
{
	if (!p)
	{
		std::cerr << "pointer is a null-pointer\n";
		return;
	}
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "object identified as A\n";
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "object identified as B\n";
	}	
	else
	{
		std::cout << "object identified as C\n";
	}
}

void Base::identify(Base& p)
{
	try 
	{
		A& testA = dynamic_cast<A&>(p);
		std::cout << "object identified as A\n";
		(void) testA;
		return;
	}
	catch (std::exception &e)
	{}

	try 
	{
		B& testB =dynamic_cast<B&>(p);
		std::cout << "object identified as B\n";
		(void) testB;
		return;
	}
	catch (std::exception &e)
	{}

	std::cout << "object identified as C\n";
		return;
}

