/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:33:57 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/06 02:25:00 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
    public :
        
        Cat();
        Cat(const Cat &src);
        Cat &operator=(const Cat &src);
        ~Cat();
        
        void makeSound() const;

        std::string getType() const;
        void setType(std::string name);

    private :

        Brain *Brain;
};

#endif