/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:40:33 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/02 20:29:41 by kboulkri         ###   ########.fr       */
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
    std::cout << "Bureaucrat :: Destructor called" << std::endl;
}
std::string Bureaucrat::getName()
{
    return(this->name);
}

void Bureaucrat::setGrade(int grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 0)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade = grade;
}
int Bureaucrat::getGrade() const
{
    return(this->grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() 
{
    return ("Bureaucrat :: Grade too high\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() 
{
    return ("Bureaucrat :: Grade too low\n");
}

void Bureaucrat::AddGrade()
{
    if (this->grade - 1 < 0)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::MinGrade()
{
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
    o << rhs.getGrade();
    return o;
}