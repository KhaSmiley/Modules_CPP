/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 01:43:21 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/06 01:59:17 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"
#include <iostream>

class WrongAnimal : public Animal
{
    public :
    
        WrongAnimal();
        WrongAnimal(const WrongAnimal &src);
        ~WrongAnimal();
        
        WrongAnimal &operator=(const WrongAnimal &src);
        
        void makeSound() const;
        std::string getType() const;
        void setType(std::string name);
};

#endif