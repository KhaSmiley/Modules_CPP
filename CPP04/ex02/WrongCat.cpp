/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:06:20 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/08 01:09:29 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat :: Default Constructor called" << std::endl;
}

WrongCat::WrongCat(std::string name)
{
    this->type = name;
    std::cout << "WrongCat :: Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src)
{
    *this = src;
    std::cout << "WrongCat :: Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
    type = src.type;
    std::cout << "WrongCat :: Assignation operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat :: Destructor called" << std::endl;
}
void WrongCat::makeSound() const
{
    std::cout << "GRRRPAAAAW" << std::endl;
}

std::string WrongCat::getType() const
{
    return (this->type);
}

void WrongCat::setType(std::string name)
{
    this->type = name;   
}