/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:43:07 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/11/08 10:27:16 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <exception>
#include <sstream>

RPN::RPN(void)
{
}

RPN::~RPN(void)
{
}

RPN::RPN(const RPN& src)
{
    *this = src;
}

RPN& RPN::operator=(const RPN& src)
{
    if (this != &src)
        this->stk = src.stk;
    return *this;
}

void RPN::run(std::string expr)
{
    int result = 0;
    std::istringstream ss0(expr);
    std::string token;

    while (ss0 >> token)
    {
        if (token.size() != 1)
            throw(std::runtime_error("Invalid parameter"));
        if (token[0] >= 48 && token[0] <= 57)
        {
            std::istringstream	ss(token);
            int                 value;
            
            ss >> value;
            stk.push(value);
        }
        else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
        {
            if (stk.size() < 2)
                throw(std::runtime_error("Not enough numbers"));
            else
            {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
            
                switch (token[0]) 
                {
                    case '+':
                        result = a + b;
                        break;
                    case '-': 
                        result = a - b;
                        break;
                    case '*':
                        result = a * b;
                        break;
                    case '/':
                        if (b == 0) 
                            throw (std::runtime_error("Division by zero"));
                        result = a / b;
                        break;                    
                    default:
                            throw (std::runtime_error("Invalid operator"));
                }
                stk.push(result);
            }
	    }
    }
    if (stk.size() == 1)
        std::cout << stk.top() << std::endl;
    else
        throw (std::runtime_error("Not enough operators"));
}