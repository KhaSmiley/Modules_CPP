/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:26:45 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/04 02:33:14 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
    std::string _name;
    int _age;
};

class Serializer
{
    public :
    
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

    private :

        Serializer();
        Serializer(Serializer const &src);
        Serializer &operator=(Serializer const &src);
        ~Serializer();
};

#endif