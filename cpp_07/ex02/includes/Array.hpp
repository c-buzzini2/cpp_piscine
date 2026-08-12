/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:36:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/08/12 11:49:11 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>

class Array
{
    private:
        T       *_arr;
        size_t  _size;
    
    public:
        Array(void);
        Array(unsigned int n);
        Array(Array& src);
        ~Array(void);
        Array& operator=(Array& src);
        const Array& getArray(void) const;
        const size_t& size(void) const;
        T& operator[](int idx);

        class OutOfBounds : public std::exception
        {
            const char* what(void) const throw();
        };
};

#include "Array.tpp"