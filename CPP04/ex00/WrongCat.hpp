/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:06:39 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/07 23:29:34 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
		WrongCat (void);
		WrongCat (std::string name);
		WrongCat (WrongCat const &src);
		~WrongCat (void);
		WrongCat	&operator= (WrongCat const &rhs);

		void	makeSound (void) const;

        void setType(std::string name);
		std::string	getType (void) const;	
};

#endif