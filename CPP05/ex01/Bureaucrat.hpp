/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:40:35 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/02 21:29:26 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    public :

    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat &operator=(const Bureaucrat &rhs);
    ~Bureaucrat();

    std::string getName();
    int getGrade() const;
    void setGrade(int grade);

    void AddGrade();
    void MinGrade();
    
    class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
    class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
        
    private :

    const std::string name;
    int grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif