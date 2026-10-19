/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:15:22 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/10/14 15:20:33 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template<typename Iterator>
void Span::addNumber(Iterator begin, Iterator end)
{
    if (vec.size() + std::distance(begin, end) > sizeMax)
        throw (FullVecException());
    vec.insert(vec.end(), begin, end);
}
