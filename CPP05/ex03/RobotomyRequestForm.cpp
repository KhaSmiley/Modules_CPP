/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 03:29:29 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/12 21:54:04 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RobotomyRequestForm.cpp
// RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized successfully 50% of the time. Otherwise, informs that the robotomy failed.
#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default_target"), _gradeSign(72)
{
    std::cout << "Robotomy :: Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target + "_target"), _gradeSign(72)
{
    std::cout << "Robotomy :: Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
{
    std::cout << "Robotomy :: Copy constructor called" << std::endl;
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) 
{
    std::cout << "Robotomy :: Copy assignment operator called" << std::endl;
    this->_target = other._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Robotomy :: Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->get_is_signed() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeSign)
		throw AForm::GradeTooLowException();
	std::cout << "\n";
	srand(std::time(0));
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " robotomy failed" << std::endl;
}