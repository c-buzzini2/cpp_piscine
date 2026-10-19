/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:17:59 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/10/19 14:37:18 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <algorithm>

int main (void)
{
    std::cout << "ADD TOO MANY NUMBERS\n";
    Span test(3);

    try
    {
        test.addNumber(4);
        test.addNumber(11);
        test.addNumber(6);
        test.addNumber(3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < 3; i++)
        std::cout << (test.getVec())[i] << std::endl;
    std::cout << "longest: " << test.longestSpan() << "\n";
    std::cout << "shortest: " << test.shortestSpan() << "\n";


    std::cout << "ADD TOO MANY NUMBERS AT ONCE\n";

    try
    {
        Span test_big(5);
        test_big.addNumber(100);
        test_big.addNumber(110);
        test_big.addNumber(600);
        test_big.addNumber(300);
        test_big.addNumber((test.getVec()).begin(), (test.getVec()).end());
        for (int i = 0; i < 7; i++)
            std::cout << (test_big.getVec())[i] << std::endl;
        std::cout << "longest: " << test_big.longestSpan() << "\n";
        std::cout << "shortest: " << test_big.shortestSpan() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    std::cout << "SUCCESSFULLY ADD MANY NUMBERS AT ONCE\n";
    try
    {
        Span test_big(15);
        test_big.addNumber(100);
        test_big.addNumber(110);
        test_big.addNumber(600);
        test_big.addNumber(300);
        test_big.addNumber((test.getVec()).begin(), (test.getVec()).end());
        for (int i = 0; i < 7; i++)
            std::cout << (test_big.getVec())[i] << std::endl;
        std::cout << "longest: " << test_big.longestSpan() << "\n";
        std::cout << "shortest: " << test_big.shortestSpan() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "SUBJECT TEST\n";
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "longest: " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "SINGLE NUMBER\n";
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        std::cout << "shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "longest: " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "EMPTY SPAN\n";
    try
    {
        Span sp = Span(5);
        std::cout << "longest: " << sp.longestSpan() << std::endl;
        std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "NEGATIVE NUMBERS\n";
    try
    {
        Span sp(5);
        sp.addNumber(-50);
        sp.addNumber(-10);
        sp.addNumber(0);
        sp.addNumber(-20);
        sp.addNumber(100);

        std::cout << "shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest:  " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "10,000+ Numbers\n";
    try
    {
        std::vector<int> numbers;

        for (int i = 0; i < 10000; ++i)
            numbers.push_back(i * 3);

        std::random_shuffle(numbers.begin(), numbers.end());

        Span sp(10001);
        sp.addNumber(numbers.begin(), numbers.end());
        sp.addNumber(1);

        std::cout << "Elements: " << sp.getVec().size() << std::endl;
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest:  " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}