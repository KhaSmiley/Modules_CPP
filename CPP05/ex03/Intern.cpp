/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:12:43 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/13 21:13:35 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Intern.cpp
#include "Intern.hpp"

Intern::Intern() 
{
    std::cout << "Default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) 
{
    std::cout << "Copy constructor called" << std::endl;
    // Add copy logic here, e.g., memberVariable = other.memberVariable;
}

Intern& Intern::operator=(const Intern& other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Add assignment logic here, e.g., memberVariable = other.memberVariable;
    }
    return *this;
}

Intern::~Intern() 
{
    std::cout << "Destructor called" << std::endl;
}