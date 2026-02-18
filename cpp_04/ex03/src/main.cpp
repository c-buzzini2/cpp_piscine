/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:13:42 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/18 15:07:26 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() //original
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
    return 0;
}

/* int main (void) //tests character
{ 
    {
        ICharacter* me = new Character("me");
        AMateria* tmp = new Ice;
        me->equip(tmp);
        AMateria* tmp2 = new Cure;
        me->equip(tmp2);

        AMateria* tmp3 = new Ice;
        me->equip(tmp3);

        AMateria* tmp4 = new Cure;
        me->equip(tmp4);

        AMateria* tmp5 = new Ice;
        me->equip(tmp5);

        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        me->use(3, *bob);
        me->unequip(3);
        me->use(3, *bob);
        me->equip(tmp5);
        me->use(3, *bob);
        me->unequip(2);
        me->unequip(2);
        me->unequip(3);
        delete bob;
        delete me;
    }

    Character me("me");
    AMateria* tmp = new Ice;
    me.equip(tmp);
    AMateria* tmp2 = new Cure;
    me.equip(tmp2);

    AMateria* tmp3 = new Ice;
    me.equip(tmp3);

    AMateria* tmp4 = new Cure;
    me.equip(tmp4);

    AMateria* tmp5 = new Ice;
    me.equip(tmp5);

    Character bob;
  
    me.unequip(3);
    me.use(3, bob);
    me.equip(tmp5);
    me.use(3, bob);
    me.unequip(2);
    me.unequip(2);
    me.unequip(3);

    bob = me;
    bob.use(3, bob);
    bob.use(0, bob);

    Character dan(me);
    bob.use(3, bob);
    bob.use(0, bob);

    return (0);
} */

/* 
int main (void) // tests constructors and destructors of materia, ice, cure
{
    {
        AMateria* temp1 = new Ice();
        AMateria* temp2 = temp1->clone();
        AMateria* temp3;
        ICharacter* chtr = new Character("Bob");

        temp3 = temp1;//copies address only
        std::cout << temp3->getType() << std::endl;
        temp3->use(*chtr);
        delete (temp1);
        delete (temp2);
        delete (chtr);
    }
    {
        Ice temp4;
        Ice temp5(temp4);
        Ice temp6;
        ICharacter* chtr = new Character("Bob");

        temp6 = temp4;
        std::cout << temp6.getType() << std::endl;
        temp6.use(*chtr);

        delete(chtr);
    }
    {
        AMateria* temp1 = new Cure();
        AMateria* temp2 = temp1->clone();
        AMateria* temp3;
        ICharacter* chtr = new Character("Bob");

        temp3 = temp1;//copies address only
        std::cout << temp3->getType() << std::endl;
        temp3->use(*chtr);
        delete (temp1);
        delete (temp2);
        delete (chtr);

    }
    {
        Cure temp4;
        Cure temp5(temp4);
        Cure temp6;
        ICharacter* chtr = new Character("Bob");

        temp6 = temp4;

        std::cout << temp6.getType() << std::endl;
        temp6.use(*chtr);

        delete(chtr);
    }

    return (0);
}
 */