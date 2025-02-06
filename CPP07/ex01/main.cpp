/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:41:54 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/06 20:56:20 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void print_char(int a)
{
    std::cout << a << std::endl;
}

void print_str(std::string a)
{
    std::cout << a << std::endl;
}

int main()
{
    int int_array[5] = {1, 2, 3, 4, 5};
    std::string s[5] = {"un", "deux", "trois", "quatre", "cinq"};
    
    iter(int_array, 5, print_char);
    iter(s, 5, print_str);
    return 0;
}