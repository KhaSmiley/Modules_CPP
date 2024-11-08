/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 01:43:21 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/08 00:48:12 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"
#include <iostream>

class WrongAnimal
{
    public:
    
        WrongAnimal();
        WrongAnimal(std::string name);
        WrongAnimal(const WrongAnimal &src);
        WrongAnimal &operator=(const WrongAnimal &src);
        virtual ~WrongAnimal();
        
        virtual void makeSound() const;
        virtual std::string getType() const;
        virtual void setType(std::string name);

    protected :
    
        std::string type;
};

#endif