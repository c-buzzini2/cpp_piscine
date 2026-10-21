/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:17:59 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/10/21 14:52:13 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main (void)
{
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
   it = mstack.begin();
    while (ite != it)
    {
        --ite;
        std::cout << *ite << std::endl;
    }
    std::stack<int> s(mstack);

    std::cout << "LIST\n";
    
    std::list<int> test_list;
    
    test_list.push_back(5);
    test_list.push_back(17);
    std::cout << test_list.back() << std::endl;
    test_list.pop_back();
    std::cout << test_list.size() << std::endl;
    test_list.push_back(3);
    test_list.push_back(5);
    test_list.push_back(737);
    //[...]
    test_list.push_back(0);
    std::list<int>::iterator it2 = test_list.begin();
    std::list<int>::iterator ite2 = test_list.end();
    ++it2;
    --it2;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
   it2 = test_list.begin();
    while (ite2 != it2)
    {
        --ite2;
        std::cout << *ite2 << std::endl;
    }

    std::cout << "CANONICAL\n";

    MutantStack<int> copied(mstack);
	std::cout << "Copied stack size: " << copied.size() << std::endl;
	std::cout << "Copied stack top: " << copied.top() << std::endl;
	MutantStack<int> assigned;
	assigned = mstack;
	std::cout << "Assigned stack size: " << assigned.size() << std::endl;
	std::cout << "Assigned stack top: " << assigned.top() << std::endl;
    mstack.push(11111);
    std::cout << "Original after push: " << mstack.size() << std::endl;
    std::cout << "Original stack yop: " << mstack.top() << std::endl;
	std::cout << "Copied after original push: " << copied.size() << std::endl;
    std::cout << "Assigned after original push: " << assigned.size() << std::endl;

    return 0;
}