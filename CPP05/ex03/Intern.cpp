/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:12:43 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/18 22:47:43 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Intern.cpp
#include "Intern.hpp"

Intern::Intern() 
{
    std::cout << "Intern :: Default constructor called" << std::endl;
    strings[0] = "shrubbery creation";
    strings[1] = "robotomy request";
    strings[2] = "presidential pardon";
    forms[0] = &Intern::createShrubberyCreationForm;
    forms[1] = &Intern::createRobotomyRequestForm;
    forms[2] = &Intern::createPresidentialPardonForm;
}

Intern::Intern(const Intern& other) 
{
    std::cout << "Intern :: Copy constructor called" << std::endl;
    *this = other;
}

Intern& Intern::operator=(const Intern& other) 
{
    std::cout << "Intern :: Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    return *this;
}

Intern::~Intern() 
{
    std::cout << "Destructor called" << std::endl;
}

AForm* Intern::createShrubberyCreationForm(std::string const &target)
{
    return new ShrubberyCreationForm(target);  
}

AForm* Intern::createPresidentialPardonForm(std::string const &target)
{
    return new PresidentialPardonForm(target);   
}

AForm* Intern::createRobotomyRequestForm(std::string const &target)
{
    return (new RobotomyRequestForm(target));
}

const char *Intern::FormNotFoundException::what() const throw() 
{
    return ("Intern :: Form doesn't exist\n");
}

AForm* Intern::MakeForm(std::string const &formName, std::string const &target)
{
    for (int i = 0; i < 3; i++)
    {
        if (formName == strings[i])
        {
            return (this->*forms[i])(target);
        }
    }
    throw FormNotFoundException();
    return NULL;
}