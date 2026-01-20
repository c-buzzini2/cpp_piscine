/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 10:57:58 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/20 21:19:59 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(void) //see argc agv + error checks
{
	std::ifstream	src("test.txt"); //make sure to open the right files
	std::ofstream	dest("test_out.txt");
	std::string		line;
	std::string		line_post;

	while (std::getline(src, line)) //read, search, replace, print (incl newline)
	{
		dest << line;
		dest << std::endl;
	}
}

/*     // search
    std::string::size_type pos = text.find(pattern);

    // check if found
    if (pos != std::string::npos) {
        std::cout << "Found at index " << pos << std::endl;
    } else {
        std::cout << "Not found!" << std::endl;
    } */