/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:21:16 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/11 01:39:17 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), grade_min_sign(150), grade_min_exec(150)
{
    std::cout << "Form :: Default Constructor has been called" << std::endl;
    if (grade_min_sign < 1 || grade_min_exec < 1)
        throw Form::GradeTooHighException();
    else if (grade_min_sign > 150 || grade_min_exec > 150)
        throw Form::GradeTooLowException();
    this->is_signed = false;
}

Form::Form(const std::string name, const int grade_min_s, const int grade_min_e) : name(name), grade_min_sign(grade_min_s), grade_min_exec(grade_min_e)
{
    std::cout << "Form :: Constructor has been called" << std::endl;
    if (grade_min_sign < 1 || grade_min_exec < 1)
        throw Form::GradeTooHighException();
    else if (grade_min_sign > 150 || grade_min_exec > 150)
        throw Form::GradeTooLowException();
    this->is_signed = false;
}

Form::Form(const Form &src) : name(src.name), grade_min_sign(src.grade_min_sign), grade_min_exec(src.grade_min_exec)
{
    std::cout << "Form :: Constructor by copy has been called" << std::endl;
    this->is_signed = false;
}

Form &Form::operator=(const Form &src)
{
    this->is_signed = src.is_signed;
    return *this;
}

Form::~Form()
{
    std::cout << "Form :: Default Destructor has been called" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw() 
{
    return ("Form :: Grade too high\n");
}

const char *Form::GradeTooLowException::what() const throw() 
{
    return ("Form :: Grade too low\n");
}

void Form::beSigned(Bureaucrat &src)
{
    if (src.getGrade() > this->grade_min_sign)
        throw Form::GradeTooLowException();
    else
    {
        this->is_signed = 1;
        std::cout << src.getName() << " signed " << this->get_name() << std::endl;
    }
}

std::string Form::get_name() const
{
    return this->name;
}

int Form::get_grade_min_sign() const
{
    return (this->grade_min_sign);
}

bool Form::get_is_signed() const
{
    return (this->is_signed);
}

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
    o << "Form name : " << rhs.get_name() << " | Grade to sign : " << rhs.get_grade_min_sign() << " | Is signed : " << rhs.get_is_signed() << std::endl;
    return o;
}