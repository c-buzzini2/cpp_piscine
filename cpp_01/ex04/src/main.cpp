/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 10:57:58 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/03 20:20:46 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>

void	ft_search_and_replace(char **argv, std::ifstream& src, std::ofstream& dest)
{
	std::string		line;
	std::string		line_post;
	int				len_s1 = std::string(argv[2]).length();

	while (std::getline(src, line))
	{
		while (line.length() > 0)
		{
			std::string::size_type pos = line.find(argv[2]);
			if (pos == std::string::npos)
			{
				line_post.append(line);
				break;
			}
			else
			{
				line_post.append(line, 0, pos);
				line_post.append(argv[3]);
				line = line.substr(pos + len_s1);
			}
		}
		dest << line_post;
		dest << std::endl;
		line_post.clear();
	}
}

int main(int argc, char **argv)
{
	if (argc != 4 || argv[2][0] == '\0')
	{
		std::cerr << "Program needs three parameters in this order: filename, "
					<< "non-empty string to be replaced and replacing string\n";
		return (1);
	}
	
	std::ifstream	src(argv[1]);
	if (!src.is_open())
	{
    	std::cerr << "Failed to open src file: " << std::strerror(errno) << '\n';
		return (1);
	}
	
	std::string		outfile_name = std::string(argv[1]) + ".replace";
	std::ofstream	dest(outfile_name.c_str());
		if (!dest.is_open())
	{
    	std::cerr << "Failed to open dest file: " << std::strerror(errno) << '\n';
		return (1);
	}
	ft_search_and_replace(argv, src, dest);
	return (0);
}
