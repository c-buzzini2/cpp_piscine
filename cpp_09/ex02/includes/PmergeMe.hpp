/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:36:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/11/25 15:51:01 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>
#include <deque>

class PmergeMe
{
    private:
        std::vector<int>    vec_values;
        std::deque<int>     deq_values;

        PmergeMe(void);
        std::vector<int> sortVector(std::vector<int> &idxs_to_order);
    
    public:
        PmergeMe(int argc, char** argv);
        PmergeMe(unsigned int N);
        PmergeMe(const PmergeMe& src);
        ~PmergeMe(void);
        PmergeMe& operator=(const PmergeMe& src);
        
        void run(void);
};
