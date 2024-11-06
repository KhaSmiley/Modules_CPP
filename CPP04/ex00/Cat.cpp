/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:38:29 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/04 22:43:40 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &src)
{
    *this = src;
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    type = src.type;
    std::cout << "Cat Assignation operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
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