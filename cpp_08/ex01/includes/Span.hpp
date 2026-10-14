/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:36:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/10/14 14:04:47 by cbuzzini         ###   ########.fr       */
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
        
        std::vector<int> getVec(void);
        
        void addNumber(int i);
        void addRange(int size);

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
