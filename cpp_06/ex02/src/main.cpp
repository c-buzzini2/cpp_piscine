/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:42:52 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/04/20 11:51:59 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <ctime>

int main (void)
{
    srand(time(NULL));
    Base *gen;

    gen = Base::generate();
    Base::identify(gen);

    if (!gen)
        return (1);
    
    Base::identify(*gen);
    delete (gen);
}
