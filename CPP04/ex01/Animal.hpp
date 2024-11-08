/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:39:20 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/07 23:32:29 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
    
        Animal();
        Animal(std::string name);
        Animal(const Animal &src);
        Animal &operator=(const Animal &src);
        virtual ~Animal();
        
        virtual void makeSound() const;
        virtual std::string getType() const;
        virtual void setType(std::string name);

    protected :
    
        std::string type;
};

#endif