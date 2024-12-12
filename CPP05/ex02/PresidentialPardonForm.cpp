/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 03:28:52 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/12 04:52:55 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PresidentialPardonForm.cpp
// PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default_target"), _gradeSign(25)
{
    std::cout << "PresidentialPardonForm :: Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target + "_target"), _gradeSign(25)
{
    std::cout << "PresidentialPardonForm :: Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
{
    std::cout << "PresidentialPardonForm :: Copy constructor called" << std::endl;
    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) 
{
    std::cout << "PresidentialPardonForm :: Copy assignment operator called" << std::endl;
    this->_target = other._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
    std::cout << "PresidentialPardonForm :: Destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->get_is_signed() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeSign)
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}