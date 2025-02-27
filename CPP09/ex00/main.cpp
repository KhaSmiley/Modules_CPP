/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 05:40:04 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/18 05:40:09 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        BitcoinExchange Exchanger;
        try
        {
            Exchanger.parse_file(av[1]);
            Exchanger.stock_data();
            Exchanger.makeitwork();
        }
        catch (const std::exception &e)
        {
            std::cout << e.what();
        }
    }
    else
        std::cout << "Error: ./btc [filename]" << std::endl;
}