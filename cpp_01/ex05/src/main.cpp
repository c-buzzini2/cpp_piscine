/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:42:39 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/23 10:19:08 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (void)
{	
	Harl	test_harl;
	
	test_harl.complain("DEBUG");
	test_harl.complain("INFO");
	test_harl.complain("WARNING");
	test_harl.complain("ERROR");
	test_harl.complain("info");
	test_harl.complain("");
}
