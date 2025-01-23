/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:14:52 by kboulkri            #+#    #+#           */
/*   Updated: 2025/01/22 16:14:52 by kboulkri           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <climits>

class ScalarConverter
{
    public :

        ScalarConverter();
        ScalarConverter(const std::string &str);
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator=(const ScalarConverter &src);
        ~ScalarConverter();

        void convert(const std::string &str);

};

std::ostream &operator<<(std::ostream &out, const ScalarConverter &src);

#endif