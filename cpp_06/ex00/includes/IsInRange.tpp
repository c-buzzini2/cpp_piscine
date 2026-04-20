/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IsInRange.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:36:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/04/20 11:14:01 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include <typeinfo>

template <typename Target, typename Source>
bool ScalarConverter::IsInRange(Source value) 
{
    if (typeid(Target) == typeid(float))
    {
        if (value >= -std::numeric_limits<Target>::max() &&
           value <= std::numeric_limits<Target>::max())
            return (true);
    }
    else if (value >= std::numeric_limits<Target>::min() &&
           value <= std::numeric_limits<Target>::max())
    {
        if (typeid(Target) == typeid(char))
        {
            char c = static_cast<char>(value);
            if (!std::isprint(c))
                std::cout << "char: non-displayable\n";
            else
                std::cout << "char: " << c << "\n";
        }
        return (true);
    }
    return (false);
}
