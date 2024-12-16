/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:21:16 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/11 01:39:17 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), grade_min_sign(150), grade_min_exec(150)
{
    std::cout << "AForm :: Default Constructor has been called" << std::endl;
    if (grade_min_sign < 1 || grade_min_exec < 1)
        throw AForm::GradeTooHighException();
    else if (grade_min_sign > 150 || grade_min_exec > 150)
        throw AForm::GradeTooLowException();
    this->is_signed = false;
}

AForm::AForm(const std::string name, const int grade_min_s, const int grade_min_e) : name(name), grade_min_sign(grade_min_s), grade_min_exec(grade_min_e)
{
    std::cout << "AForm :: Constructor has been called" << std::endl;
    if (grade_min_sign < 1 || grade_min_exec < 1)
        throw AForm::GradeTooHighException();
    else if (grade_min_sign > 150 || grade_min_exec > 150)
        throw AForm::GradeTooLowException();
    this->is_signed = false;
}

AForm::AForm(const AForm &src) : name(src.name), grade_min_sign(src.grade_min_sign), grade_min_exec(src.grade_min_exec)
{
    std::cout << "AForm :: Constructor by copy has been called" << std::endl;
    this->is_signed = false;
}

AForm &AForm::operator=(const AForm &src)
{
    this->is_signed = src.is_signed;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm :: Default Destructor has been called" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw() 
{
    return ("AForm :: Grade too high\n");
}

const char *AForm::GradeTooLowException::what() const throw() 
{
    return ("AForm :: Grade too low\n");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form :: Form not signed");
}

void AForm::beSigned(Bureaucrat &src)
{
    if (src.getGrade() > this->grade_min_sign)
        throw AForm::GradeTooLowException();
    else
    {
        this->is_signed = 1;
        std::cout << src.getName() << " signed " << this->get_name() << std::endl;
    }
}

std::string AForm::get_name() const
{
    return this->name;
}

int AForm::get_grade_min_sign() const
{
    return (this->grade_min_sign);
}

int AForm::get_grade_min_exec() const
{
    return (this->grade_min_exec);
}

bool AForm::get_is_signed() const
{
    return (this->is_signed);
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs)
{
    o << "AForm name : " << rhs.get_name() << " | Grade to sign : " << rhs.get_grade_min_sign() << " | Is signed : " << rhs.get_is_signed() << std::endl;
    return o;
}