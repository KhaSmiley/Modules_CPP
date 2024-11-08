/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:38:29 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/08 01:09:29 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat :: Default constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(std::string name)
{
    this->type = name;
    std::cout << "Cat :: constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src)
{
    this->brain = new Brain();
    *this = src;
    std::cout << "Cat :: Copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat :: Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);
    delete this->brain;
	brain = new Brain(*rhs.brain);
	return (*this);
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat :: Destructor called" << std::endl;
}

void Cat::setType(std::string name)
{
    this->type = name;
}

std::string Cat::getType() const
{
    return(this->type);
}

void Cat::makeSound() const
{
    std::cout << "Miaou Miaou" << std::endl;
}

Brain *Cat::getBrain()
{
    return(this->brain);
}

void Cat::setIdeas(std::string name)
{
    this->brain->setIdeas(name);
}

std::string Cat::getIdeas(int index)
{
    return(this->brain->getIdeas(index));
}