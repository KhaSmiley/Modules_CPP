/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:21:42 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/02 21:19:10 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form
{
    public :

        Form();
        Form(const std::string name, bool is_signed, const int grade_min_s, const int grade_min_e);
        Form(const Form &src);
        Form &operator=(const Form &rhs);
        ~Form();

    private :
    
        const std::string name;
        bool  is_signed;
        const int grade_min_sign;
        const int grade_min_exec;
};

#endif