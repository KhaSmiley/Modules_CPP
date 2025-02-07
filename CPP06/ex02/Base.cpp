/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:35:34 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/04 02:21:39 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void)
{

    std::srand(time(0));
    int i = rand() % 3;
    if (i == 0)
    {
        return new A;
    }
    else if (i == 1)
    {
        return new B;
    }
    else
    {
        return new C;   
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
        return;
    }
    catch(const std::exception& e){}
    try
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;     
        (void)b;
        return;
    }
    catch(const std::exception& e){}
    try
    {
        C &c = dynamic_cast<C&>(p); 
        std::cout << "C" << std::endl;   
        (void)c;
        return;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error type not found" << std::endl;
    }
}