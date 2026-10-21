/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:15:22 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/10/21 14:07:25 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack& src) : std::stack<T>(src)
{
}
template <typename T>
MutantStack<T>::~MutantStack(void)
{
}
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& src)
{
    if (this != &src)
        std::stack<T>::operator=(src);
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{ 
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{ 
    return this->c.end();
}
