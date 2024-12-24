/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:12:30 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/18 22:46:12 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Intern.hpp
#ifndef Intern_HPP
#define Intern_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
    public:
        Intern();
        Intern(Intern const &other);
        Intern& operator=(Intern const &other);
        ~Intern();
        
        AForm *MakeForm(std::string const &formName, std::string const &target);
        AForm* createPresidentialPardonForm(std::string const &target);
        AForm* createRobotomyRequestForm(std::string const &target);
        AForm* createShrubberyCreationForm(std::string const &target);

        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    private:

        std::string strings[3];
		AForm *(Intern::*forms[3])(std::string const &target);
        // Add member variables here
};

#endif // Intern_HPP