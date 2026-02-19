/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:13:42 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/19 08:25:29 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main (void)
{
    {
        Dog A;
        Dog B;
        A = B;
        Dog D(B);
    }
    std::cout << "\n\n";
    {
        Cat A;
        Cat B;
        A = B;
        Cat D(B);
    }
    std::cout << "\n\n";
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;//should not create a leak
        delete i;
    }
    std::cout << "\n\n";
    {
        int N = 20;
        Animal **animals_arr = new Animal*[N];
        for (int i = 0; i < N; i++)
        {
            if (i % 2 == 0)
                animals_arr[i] = new Dog;
            else
                animals_arr[i] = new Cat;  
        }
        for (int i = 0; i < N; i++)
        {
            delete(animals_arr[i]);
        }
        delete[] animals_arr;
    }
    std::cout << "\n\n";
    {
        const Animal* j = new Dog(); //polymorphism
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        delete(i);
        delete(j);
    }
    std::cout << "\n\n";
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* j = new WrongCat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << meta->getType() << " " << std::endl;
        j->makeSound(); //will output the animal sound!
        meta->makeSound();
        delete(j);
        delete(meta);
    }
    std::cout << "\n\n";
    {
        const WrongCat* meta_cat = new WrongCat();
        std::cout << meta_cat->getType() << " " << std::endl;
        meta_cat->makeSound();
        delete(meta_cat);
    }
    return 0;
}
