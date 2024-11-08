/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:40:00 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/08 01:15:03 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog :: Default constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(std::string name)
{
    this->type = name;
    std::cout << "Dog :: constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src)
{
    this->brain = new Brain();
    *this = src;
    std::cout << "Dog :: Copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog :: Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);
    delete this->brain;
	brain = new Brain(*rhs.brain);
	return (*this);
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog :: Destructor called" << std::endl;
}

void Dog::setType(std::string name)
{
    this->type = name;
}

std::string Dog::getType() const
{
    return(this->type);
}

void Dog::makeSound() const
{
    std::cout << "Wouf Wouf" << std::endl;
}

Brain *Dog::getBrain()
{
    return(this->brain);
}

void Dog::setIdeas(std::string name)
{
    this->brain->setIdeas(name);
}

std::string Dog::getIdeas(int index)
{
    return(this->brain->getIdeas(index));
}
