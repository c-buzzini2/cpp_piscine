/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:53:36 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/11/20 15:15:14 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc < 2)
	{	
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
		<< std::endl;
		return (0);
	}
	x = 1;
	while (x < argc)
	{
		y = 0;
		while (argv[x][y])
			std::cout << static_cast<char>(std::toupper(argv[x][y++]));
		x++;
	}
	std::cout << std::endl;
	return (0);
}
