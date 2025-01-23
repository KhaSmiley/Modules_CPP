/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:14:52 by kboulkri            #+#    #+#           */
/*   Updated: 2025/01/22 16:14:52 by kboulkri           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
        ScalarConverter test(av[1]);
    else
        std::cout << "Error: Invalid number of arguments" << std::endl;
    return 0;
}