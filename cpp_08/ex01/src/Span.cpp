/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:43:07 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/10/14 14:39:38 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <numeric>

Span::Span(void) : sizeMax(0)
{
}

Span::Span(unsigned int N) : sizeMax(N)
{
}

Span::~Span(void)
{
}

Span::Span(const Span& src)
{
    *this = src;
}

Span& Span::operator=(const Span& src)
{
    if (this != &src)
    {
        this->vec = src.vec;
        this->sizeMax = src.sizeMax;
    }
    return *this;
}

const char* Span::NoSpanException::what(void) const throw()
{
    return ("No span for less than two ints");
}

const char* Span::FullVecException::what(void) const throw()
{
    return ("Span object is full");
}

std::vector<int> Span::getVec(void)
{
    return (vec);
}

void Span::addNumber(int i)
{
    if (vec.size() == sizeMax)
        throw (FullVecException());
    vec.push_back(i);
}

unsigned int Span::shortestSpan(void)
{
    if (vec.size() < 2)
        throw (NoSpanException());
        
    std::vector<int>    sorted(vec);
    std::sort(sorted.begin(), sorted.end());
    
    std::vector<int>    diffs(vec.size());
    std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());
    return (*std::min_element(diffs.begin(), diffs.end()));
}

unsigned int Span::longestSpan(void)
{
    if (vec.size() < 2)
        throw (NoSpanException());
        
    std::vector<int>    sorted(vec);
    std::sort(sorted.begin(), sorted.end());
    
    std::vector<int>    diffs(vec.size());
    std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());
    return (*std::max_element(diffs.begin(), diffs.end()));
}