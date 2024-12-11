/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:59:57 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/11 01:36:46 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
    std::cout << "Bureaucrat :: Default constructor has been called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    std::cout << "Bureaucrat :: Constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    *this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    this->grade = rhs.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat()   
{
    std::cout << "Bureaucrat :: Default Destructor called" << std::endl;
}

void Bureaucrat::setGrade(int grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() 
{
    return ("Bureaucrat :: Grade too high\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() 
{
    return ("Bureaucrat :: Grade too low\n");
}

int Bureaucrat::getGrade() const
{
    return(this->grade);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

void Bureaucrat::AddGrade()
{
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::MinGrade()
{
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signForm(Form &src)
{
    if (this->getGrade() > src.get_grade_min_sign())
    {
        std::cout << this->getName() << " cannot sign " << src.get_name() << " cause his grade is too low" << std::endl;
    }
    else if (src.get_is_signed() == true)
    {
        std::cout << this->getName() << " cannot sign " << src.get_name() << " cause the form is already signed" << std::endl;
    }
    else
    {
        src.beSigned(*this);
    }
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
    o << rhs.getGrade();
    return o;
}