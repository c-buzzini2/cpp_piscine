/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:43:07 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/11/08 10:27:16 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>
#include <sstream>
#include <limits>

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
    *this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
    if (this != &src)
    {
        this->vec_values = src.vec_values;
        this->deq_values = src.deq_values;
    }
    return *this;
}

PmergeMe::PmergeMe(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string         nb_string = static_cast<std::string>(argv[i]);
        double				nb;
        std::istringstream	ss(nb_string);

        if (!(ss >> nb) || nb > std::numeric_limits<int>::max())
            throw (std::runtime_error("Invalid numeric value: " + nb_string));
        else if (!ss.eof())
            throw (std::runtime_error("Unexpected characters: " + nb_string));
        else if (nb < 0)
            throw (std::runtime_error("Negative number: " + nb_string));
        vec_values.push_back(nb);
        deq_values.push_back(nb);
    }
    // for (std::vector<int>::const_iterator it = vec_values.begin(); it != vec_values.end(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;
    // for (std::deque<int>::const_iterator it = deq_values.begin(); it != deq_values.end(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;
}

std::vector<int> PmergeMe::sortVector(std::vector<int> &idxs_to_order)
{
    int                 vec_size = idxs_to_order.size();
    std::vector<int>    unordered_idxs(idxs_to_order);
    int                 odd_one_out = -1;

    if (vec_size <= 1)
        return (idxs_to_order);
    if (vec_size % 2 != 0)
    {
        odd_one_out = unordered_idxs.back();
        unordered_idxs.pop_back();
        vec_size--;
    }

    std::vector<int>    bigger;
    std::vector<int>    smaller;

    for (int i = 0; i < vec_size; i += 2)
    {
        int idx1 = unordered_idxs[i];
        int idx2 = unordered_idxs[i + 1];
        if (vec_values[idx1] < vec_values[idx2])
        {
            smaller.push_back(idx1);
            bigger.push_back(idx2);
        }
        else // think about repeated numbers later (>=)
        {
            smaller.push_back(idx2);
            bigger.push_back(idx1);
        }
    }
    for (std::vector<int>::const_iterator it = bigger.begin(); it != bigger.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::vector<int>    ordered_bigger = sortVector(bigger);
    std::vector<int>    final_chain;


    return (final_chain);
}


void PmergeMe::run(void)
{
    //track time
    int                 vec_size = vec_values.size();
    std::vector<int>    idxs_to_order(vec_size);
    for (int i = 0; i < vec_size; i++)
        idxs_to_order[i] = i;
    sortVector(idxs_to_order);

}


