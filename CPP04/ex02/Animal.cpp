/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:39:01 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/08 01:09:29 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal()
{
    std::cout << "Animal :: Default Constructor called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(std::string name)
{
    this->type = name;
    std::cout << "Animal :: Constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
    *this = src;
    std::cout << "Animal :: Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
    type = src.type;
    std::cout << "Animal :: Assignation operator called" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal :: Destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::setType(std::string name)
{
    this->type = name;
}