/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:21:42 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/11 04:56:24 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
    public :

        Form();
        Form(const std::string name, const int grade_min_s, const int grade_min_e);
        Form(const Form &src);
        Form &operator=(const Form &rhs);
        ~Form();
        
        void beSigned(Bureaucrat &src);
        virtual void		execute(Bureaucrat const &executor) const = 0;

        std::string get_name() const;
        int get_grade_min_sign() const;
        int get_grade_min_exec() const;
        bool get_is_signed() const;

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
        bool  is_signed;
        const int grade_min_sign;
        const int grade_min_exec;
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);


#endif