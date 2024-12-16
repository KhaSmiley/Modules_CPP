/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 03:30:23 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/12 02:14:37 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ShrubberyCreationForm.hpp
#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <iostream>
#include "AForm.hpp"
#include <fstream>

class AForm;

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        virtual void execute (Bureaucrat const & executor ) const;

    private:
        std::string _target;
        int _gradeSign;// Add member variables here
};

#endif // ShrubberyCreationForm_HPP