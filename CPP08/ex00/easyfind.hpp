/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 04:40:05 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/10 22:51:16 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

class NothingIn
{
    public :

    virtual const char *what () const
    {
        return ("No occurrence\n");
    }
};

template <typename T>

int easyfind(T container, int to_find)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), to_find);
    if (it == container.end())
    {
        throw NothingIn();
    }
    else
        return (*it);
}


#endif