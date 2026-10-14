/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:17:59 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/10/14 11:17:12 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.tpp"

int main (void)
{
    std::cout << "VECTOR\n";
    std::vector<int> vec;
    
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found: " << *it << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    for (int i = 0; i < 5; i++)
        vec.push_back(i);
        
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found: " << *it << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 6);
        std::cout << "Found: " << *it << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    std::cout << "DEQUE\n";
    std::deque<int> deq;
    
    for (int i = 0; i < 5; i++)
        deq.push_back(i);
        
    try
    {
        std::deque<int>::iterator it = easyfind(deq, 3);
        std::cout << "Found: " << *it << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::deque<int>::iterator it = easyfind(deq, 6);
        std::cout << "Found: " << *it << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    std::cout << "LIST\n";
    std::list<int> lst;
    
    for (int i = 0; i < 5; i++)
        lst.push_back(i);
        
    try
    {
        std::list<int>::iterator it = easyfind(lst, 3);
        std::cout << "Found: " << *it << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::list<int>::iterator it = easyfind(lst, 6);
        std::cout << "Found: " << *it << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}