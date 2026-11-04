/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:36:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/11/04 16:48:33 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>

class RPN
{
    private:
        std::stack<int> stk;
    
    public:
        RPN(void);
        RPN(unsigned int N);
        RPN(const RPN& src);
        ~RPN(void);
        RPN& operator=(const RPN& src);
        
        void run(int argc, char** args);
};
