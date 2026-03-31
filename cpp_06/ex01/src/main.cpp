/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:42:52 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/31 13:27:36 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main (void)
{
    Data a;
    Data *ptr = &a;
    uintptr_t srl;
    
    std::cout << ptr << '\n';
    srl =  Serializer::serialize(ptr);
    std::cout << srl << '\n';
    std::cout << Serializer::deserialize(srl) << '\n';
}