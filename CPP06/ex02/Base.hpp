/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:35:48 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/04 00:47:50 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include <cstdlib>

class Base
{
    public :
        Base() {};
        virtual ~Base() {};
};

class A : public Base
{
    public :
        A();
        ~A();
};

class B : public Base
{
    public :
        B();
        ~B();
};

class C : public Base
{
    public :
        C();
        ~C();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif