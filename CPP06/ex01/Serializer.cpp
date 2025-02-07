/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:26:43 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/03 19:33:35 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}
Serializer::Serializer(Serializer const &src)
{
	*this = src;
}

Serializer &Serializer::operator=(Serializer const &src)
{
	if (this != &src)
		*this = src;
	return *this;
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t value = reinterpret_cast <uintptr_t>(ptr);
	return value;	
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *p = reinterpret_cast <Data *>(raw);
	return p;
}

