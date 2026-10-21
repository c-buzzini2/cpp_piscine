/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:36:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/10/21 14:07:08 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{   
    public:
        MutantStack(void);
        MutantStack(const MutantStack& src);
        ~MutantStack(void);
        MutantStack& operator=(const MutantStack& src);

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin();
		iterator end();
};

#include "MutantStack.tpp"