/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:41:57 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/08 01:11:25 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main(void)
{

    // Uncomment the following line to test the abstract class
    // Animal animal;
	Animal*	tab[10];

	std::cout << std::endl << "------------- Constructor of dogs------------" << std::endl << std::endl;
    for(int i = 0; i < 5; i++)
    {
        tab[i] = new Dog();
        std::cout << std::endl;
    }
	std::cout << std::endl << "------------- Sound of dogs------------" << std::endl << std::endl;
    for(int i = 0; i < 5; i++)
    {
        tab[i]->makeSound();
    }
	std::cout << std::endl << "------------- Constructor of cats ------------" << std::endl << std::endl;
	for (int i = 5; i < 10; i++)
    {
        tab[i] = new Cat();
        std::cout << std::endl;
    }
	std::cout << std::endl << "------------- Sound of cats ------------" << std::endl << std::endl;
    for(int i = 5; i < 10; i++)
    {
        tab[i]->makeSound();
    }
    std::cout << std::endl << "------------- Deleting array of Animals ----------" << std::endl << std::endl;
    for (int i = 0; i < 10; i++)
    {
        delete tab[i];
        std::cout << std::endl;
    }
    std::cout << std::endl << "----------------- Check Deep Copy ----------------" << std::endl <<std::endl;
    
    Dog Doggy("Doggy");
    std::cout << std::endl;
    Dog Doggy_test("Doggy_test");
    std::cout << std::endl;
    
    Doggy.getBrain()->setIdeas("I'm a good Dog");
    Doggy_test = Doggy;
    std::cout << std::endl;
    Doggy_test.getBrain()->setIdeas("I'm a bad Dog");
    std::cout << "Doggy idea " << Doggy.getIdeas(0) << std::endl;
    std::cout << "Doggy_test idea " << Doggy_test.getIdeas(0) << std::endl;
    std::cout << std::endl;
    return (0);
}