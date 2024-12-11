/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:21:42 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/11 02:45:17 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
    public :

        AForm();
        AForm(const std::string name, const int grade_min_s, const int grade_min_e);
        AForm(const AForm &src);
        AForm &operator=(const AForm &rhs);
        ~AForm();

        void beSigned(Bureaucrat &src);

        std::string get_name() const;
        int get_grade_min_sign() const;
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

std::ostream & operator<<(std::ostream & o, AForm const & rhs);


#endif