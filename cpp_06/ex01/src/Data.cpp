/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data_canon.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:18:31 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/26 11:01:14 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void)
{
    nb = 0;
}

Data::Data(int n) : nb(n)
{
}

Data::~Data(void)
{
}

Data::Data(const Data& src)
{
    *this = src;
}

Data& Data::operator=(const Data& src)
{
    this->nb = src.nb;
    return *this;
}
