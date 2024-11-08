/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:39:58 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/07 23:13:11 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
    public :
        
        Dog();
        Dog(std::string name);
        Dog(const Dog &src);
        Dog &operator=(const Dog &src);
        ~Dog();
        
        Brain *getBrain();
        void makeSound() const;
        void setIdeas(std::string name);
        std::string getIdeas(int index);

        std::string getType() const;
        void setType(std::string name);
        void printIdeas();

    private :
        
        Brain *brain;
        
};

#endif