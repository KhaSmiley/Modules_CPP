/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:40:33 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/11 21:53:48 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat :: Default constructor has been called" << std::endl;
    this->grade = 149;
}
Bureaucrat::Bureaucrat(std::string name) : name(name)
{
    std::cout << "Bureaucrat :: Constructor has been called" << std::endl;
    this->grade = 149;
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
        throw this->GradeTooHighException();
    else if (grade < 0)
        throw this->GradeTooLowException();
    else
        this->grade = grade;
}

int Bureaucrat::getGrade() const
{
    return(this->grade);
}

std::string Bureaucrat::GradeTooHighException()
{
    std::string High = "Grade too high";
    return(High);
}
std::string Bureaucrat::GradeTooLowException()
{
    std::string Low = "Grade too Low";
    return(Low);
}

void Bureaucrat::AddGrade()
{
    this->grade++;
    if (this->grade > 150)
        throw this->GradeTooHighException();
}

void Bureaucrat::MinGrade()
{
    this->grade--;
    if (this->grade < 0)
        throw this->GradeTooLowException();
}
std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
    o << rhs.getGrade();
    return o;
}