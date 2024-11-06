/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:39:58 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/05 00:48:12 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
    public :
        
        Dog();
        Dog(const Dog &src);
        Dog &operator=(const Dog &src);
        ~Dog();
        
        void makeSound() const;

        std::string getType() const;
        void setType(std::string name);
};

#endif