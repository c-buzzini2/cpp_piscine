/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:36:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/10/14 15:32:30 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>
#include <vector>

class Span
{
    private:
        std::vector<int> vec;
        unsigned int sizeMax;
    
    public:
        Span(void);
        Span(unsigned int N);
        Span(const Span& src);
        ~Span(void);
        Span& operator=(const Span& src);
        
        const std::vector<int>& getVec(void) const;
        
        void addNumber(int i);
        template<typename Iterator>
        void addNumber(Iterator begin, Iterator end);

        unsigned int shortestSpan(void);
        unsigned int longestSpan(void);

        class NoSpanException : public std::exception
        {
            const char* what(void) const throw();
        };
        class FullVecException : public std::exception
        {
            const char* what(void) const throw();
        };
};

#include "Span.tpp"