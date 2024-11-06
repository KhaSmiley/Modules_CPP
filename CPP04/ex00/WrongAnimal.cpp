/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 01:43:23 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/06 02:01:23 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    *this = src;
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
    type = src.type;
    std::cout << "WrongAnimal Assignation operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "GRRRPAAAAW" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}

void WrongAnimal::setType(std::string name)
{
    this->type = name;   
}