/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:13:42 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/17 13:03:25 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
//#include "Character.hpp"
//#include "MateriaSource.hpp"

/* int main (void)
{ 
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return (0);
} */

//!!!! Go back in the module and correct operator= of derived class

int main (void)
{
    {
        AMateria* temp1 = new Ice();
        AMateria* temp2 = temp1->clone(); //this test cannot use Werror
        AMateria* temp3;

        temp3 = temp1;//copies address only
        delete (temp1);
        delete (temp2);
    }
    {
        Ice temp4;
        Ice temp5(temp4);
        Ice temp6;

        temp6 = temp4;
    }
    {
        AMateria* temp1 = new Cure();
        AMateria* temp2 = temp1->clone(); //this test cannot use Werror
        AMateria* temp3;

        temp3 = temp1;//copies address only
        delete (temp1);
        delete (temp2);
    }
    {
        Cure temp4;
        Cure temp5(temp4);
        Cure temp6;

        temp6 = temp4;
    }

    return (0);
}
