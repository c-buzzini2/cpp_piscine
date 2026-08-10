/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:36:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/08/07 12:24:08 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void swap(T& valueA, T& valueB) 
{
    T temp = valueA;
    valueA = valueB;
    valueB = temp;
    return;
}

template <typename T>
T& min(T& valueA, T& valueB) 
{
    if (valueA < valueB)
        return (valueA);
    return (valueB);
}

template <typename T>
T& max(T& valueA, T& valueB) 
{
    if (valueA > valueB)
        return (valueA);
    return (valueB);
}
