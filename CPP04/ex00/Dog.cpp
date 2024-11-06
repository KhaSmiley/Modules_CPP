/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:40:00 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/05 00:50:53 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &src)
{
    *this = src;
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    type = src.type;
    std::cout << "Dog Assignation operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Wouf Wouf" << std::endl;
}

std::string Dog::getType() const
{
    return (this->type);
}

void Dog::setType(std::string name)
{
    this->type = name;   
}