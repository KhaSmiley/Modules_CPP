/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:41:57 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/06 02:06:23 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* i = new Cat();
    const Animal* j = new Dog();
    const Animal* l = new WrongAnimal();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << l->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    l->makeSound();
    meta->makeSound();

    delete l;
    delete j;
    delete i;
    delete meta;
    return 0;
}