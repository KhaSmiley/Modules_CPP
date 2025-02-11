/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:33:57 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/07 21:28:11 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
    public :
        
        Cat();
        Cat(std::string name);
        Cat(const Cat &src);
        Cat &operator=(const Cat &src);
        ~Cat();
        
        void makeSound() const;

        std::string getType() const;
        void setType(std::string name);
};

#endif