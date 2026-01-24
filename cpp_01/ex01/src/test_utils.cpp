/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:36:06 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/24 15:24:54 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

long	ft_atol(const char *nptr)
{
	int		i;
	int		neg;
	long	nb;

	i = 0;
	nb = 0;
	neg = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * neg);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

bool	valid_input(char *argmt)
{
	int	i = 0;
	std::string str = static_cast<std::string>(argmt);
	
	if (str.length() > 10 || argmt[i] == '-')
		return (false);
	while (argmt[i] && ft_isdigit(argmt[i]))
		i++;
	if (argmt[i])
		return (false);
	return (true);
}
