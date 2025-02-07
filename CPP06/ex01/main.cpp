/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:26:38 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/04 02:33:57 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data card;
    Data *card_ptr;
    uintptr_t stock;

    card._name = "Khalid";
    card._age = 28;
    std::cout << "Data before Serialize" << std::endl;
    std::cout << "Name = " << card._name << std::endl;
    std::cout << "Age = " << card._age << std::endl;

    stock = Serializer::serialize(&card);
    std::cout << "Seralization done" << std::endl;
    std::cout << "Value of uintptr_t -> " << stock << std::endl;
    std::cout << "Memory of card after seralizer -> " << &card << std::endl;
    std::cout << "Memory of card_ptr before serializer -> " << &card_ptr << std::endl;
    card_ptr = Serializer::deserialize(stock);
    std::cout << "Memory of card_ptr after serializer -> " << &card_ptr << std::endl;
    std::cout << "Data after Deserialize" << std::endl;
    std::cout << "Name = " << card_ptr->_name << std::endl;
    std::cout << "Age = " << card_ptr->_age << std::endl;
    card._name = "Boulkri";
    card._age = 25;
    std::cout << "Data after change" << std::endl;
    std::cout << "Name = " << card_ptr->_name << std::endl;
    std::cout << "Age = " << card_ptr->_age << std::endl;
    
}