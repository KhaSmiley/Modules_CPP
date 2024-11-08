/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:41:57 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/08 01:03:52 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << std::endl << "----------------- Constructor ----------------" << std::endl <<std::endl;

    const Animal* Random = new Animal();
    std::cout << std::endl;
    const Animal* Chatpotte = new Cat();
    std::cout << std::endl;
    const Animal* Clifford = new Dog();
    std::cout << std::endl;
    const WrongAnimal* Alien = new WrongCat();
    
    std::cout << std::endl << "----------------- getType ----------------" << std::endl <<std::endl;
    
    std::cout << "Clifford Type : " << Clifford->getType() << " " << std::endl;
    std::cout << "Chatpotte Type : " << Chatpotte->getType() << " " << std::endl;
    std::cout << "Alien Type : " << Alien->getType() << " " << std::endl;
    std::cout << "Random Type : " << Random->getType() << " " << std::endl;
    std::cout << std::endl;
    std::cout << "Clifford Sound : ";
    Clifford->makeSound();
    std::cout << "Chatpotte Sound : "; 
    Chatpotte->makeSound();
    std::cout << "Alien Sound : ";
    Alien->makeSound();
    std::cout << "Random Sound : ";
    Random->makeSound();

    std::cout << std::endl << "----------------- Delete ----------------" << std::endl <<std::endl;
    delete Alien;
    std::cout << std::endl;
    delete Clifford;
    std::cout << std::endl;
    delete Chatpotte;
    std::cout << std::endl;
    delete Random;
    return 0;
}