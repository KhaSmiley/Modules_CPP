/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 04:45:45 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/10 22:51:12 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::list<int> lst;
    lst.push_back(20);
    lst.push_back(50);
    lst.push_back(30);
    try
    {
        std::cout << easyfind(lst, 30) << std::endl;
        std::cout << easyfind(lst, 60) << std::endl;
    }
    catch (NothingIn &e)
    {
        std::cout << e.what();
    }
    
    std::vector<int> vec;
    vec.push_back(20);
    vec.push_back(50);
    vec.push_back(30);
    try
    {
        std::cout << easyfind(vec, 30) << std::endl;
        std::cout << easyfind(vec, 60) << std::endl;
    }
    catch (NothingIn &e)
    {
        std::cout << e.what();
    }
    return (0);    
}