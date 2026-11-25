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
    for (std::vector<int>::const_iterator it = vec_values.begin(); it != vec_values.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    for (std::deque<int>::const_iterator it = deq_values.begin(); it != deq_values.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

std::vector<int> PmergeMe::sortVector(std::vector<int> &idxs_to_order)
{
    if (idxs_to_order.size() <= 1)
        return (idxs_to_order);
    //how do I deal with an odd number?
    std::vector<int>    temp_cpy_unordered_idxs(idxs_to_order);
    std::vector<int>    ordered_idxs;
    //START HERE!!!     
}


void PmergeMe::run(void)
{
    //track time
    int                 vec_size = vec_values.size();
    std::cout << vec_size << "\n";
    std::vector<int>    idxs_to_order(vec_size);
    for (int i = 0; i < vec_size; i++)
        idxs_to_order[i] = i;
    sortVector(idxs_to_order);

}


