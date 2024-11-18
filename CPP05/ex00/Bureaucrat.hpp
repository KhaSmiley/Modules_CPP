/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:40:35 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/11 21:53:57 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    public :

    Bureaucrat();
    Bureaucrat(std::string name);
    ~Bureaucrat();

    std::string getName();
    int getGrade() const;
    void setGrade(int grade);

    void AddGrade();
    void MinGrade();
    
    std::string GradeTooHighException();
    std::string GradeTooLowException();
    
    private :

    const std::string name;
    int grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif