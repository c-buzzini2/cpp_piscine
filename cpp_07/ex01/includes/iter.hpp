/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:36:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/08/12 09:48:42 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename A, typename F>
void iter(A *arr, size_t len, F fctn) 
{
    for (size_t i = 0; i < len; i++)
        fctn(arr[i]);
    return;
}

template <typename T>
void print(const T &value)
{
    std::cout << value << std::endl;
}

template <typename T>
void add_A(T &value)
{
    value += 'A';
}

