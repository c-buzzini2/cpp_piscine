/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:43:07 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/11/04 18:31:01 by cbuzzini         ###   ########.fr       */
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

void RPN::run(int argc, char** argv)
{
    int result = 0;
    
    for (int i = 0; i < argc; i++)
    {
        std::string str = static_cast<std::string>(argv[i]);
        if (str.size() != 1)
            throw(std::runtime_error("Invalid parameter"));
        if (argv[i][0] >= 48 && argv[i][0] <= 57)
        {
            std::istringstream	ss(str);
            int                 value;
            
            ss >> value;
            stk.push(value);
        }
        else if (argv[i][0] == '+' || argv[i][0] == '-' || argv[i][0] == '*' || argv[i][0] == '/')
        {
            if (stk.size() < 2)
                throw(std::runtime_error("Not enough numbers"));
            else
            {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
            
                switch (argv[i][0]) 
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
        std::cout << result << std::endl;
    else
        throw (std::runtime_error("Not enough operators"));

    //DEBUG!!!
    // std::cout << "STACK SIZE: " << stk.size() << std::endl;
    // for (int i = 0; i < argc; i++)
    // {
    //     std::cout << stk.top() << std::endl;
    //     stk.pop();
    // }
    // std::cout << "STACK SIZE: " << stk.size() << std::endl;

}