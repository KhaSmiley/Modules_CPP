/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:21:16 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/02 21:25:47 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), is_signed(0), grade_min_sign(150), grade_min_exec(150)
{
    std::cout << "Form :: Default constructor has been called" << std::endl;
}

Form::Form(const std::string name, bool is_s, const int grade_min_s, const int grade_min_e) : name(name), is_signed(is_s), grade_min_sign(grade_min_s), grade_min_exec(grade_min_e)
{
    std::cout << "Form :: Constructor has been called" << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
    this->name = 
}

// Form::Form(const Form &src)
// {
//     *this = src;
// }