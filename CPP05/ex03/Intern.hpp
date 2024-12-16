/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:12:30 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/14 01:11:45 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Intern.hpp
#ifndef Intern_HPP
#define Intern_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern 
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
                                                                                          
        AForm MakeForm(std::string formName, std::string target);

    private:
        // Add member variables here
};

#endif // Intern_HPP