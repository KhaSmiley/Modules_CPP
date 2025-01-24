/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:14:52 by kboulkri            #+#    #+#           */
/*   Updated: 2025/01/22 16:14:52 by kboulkri           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const std::string &str)
{
    convert(str);
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    if (this != &src)
        *this = src;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void	print_special(const std::string& str)
{
	if (str == "nanf" || str == "nan")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : nanf" << std::endl;
		std::cout << "double : nan" << std::endl;
	}
	else if (str == "inff" || str == "inf")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : inff" << std::endl;
		std::cout << "double : inf" << std::endl;
	}
	else if (str == "+inff" || str == "+inf")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : +inff" << std::endl;
		std::cout << "double : +inf" << std::endl;
	}
	else if (str == "-inff" || str == "-inf")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : -inff" << std::endl;
		std::cout << "double : -inf" << std::endl;
	}
}

bool	checkStr(const std::string &input)
{
    int i = 0;
    int nbDots = 0;

	if (input.size() > 1)
	{
		if ((input.c_str()[0] < '0' || input.c_str()[0] > '9')
				&& input.c_str()[0] != '-' && input.c_str()[0] != '+')
			return (true);
		if ((input.c_str()[0] == '-' || input.c_str()[0] == '+') && (input.c_str()[1] < '0' || input.c_str()[1] > '9'))
			return (true);
		i++;
		while (input.c_str()[i])
		{
			if (input.c_str()[i] == '.')
				nbDots++;
			if (nbDots > 1)
				return (true);
			if (input.c_str()[i] == 'f' && input.c_str()[i + 1])
				return (true);
			if (input.c_str()[i] != 'f' && (input.c_str()[i] < '0' || input.c_str()[i] > '9') && input.c_str()[i] != '.')
				return (true);
			i++;
		}
		
	}
	return (false);
}
bool isChar(const std::string &str)
{
    if (str.length() == 1)
        return true;
    return false;
}

bool isInt(const std::string &str)
{
    char *end;

    std::strtol(str.c_str(), &end, 10);
    if (*end == '\0')
        return true;
    return false;
}

bool isDouble(const std::string &input)
{
	char	*end;
	size_t	dot = input.find('.');
	
	std::strtod(input.c_str(), &end);
	if (end[0] == '\0' && dot != std::string::npos)
		return (true);
	return (false);
}

bool isFloat(const std::string &input)
{
	if (input[input.size() - 1] == 'f')
		return (true);
	return (false);
}

int find_type(const std::string &str)
{
    if(isInt(str))
        return 1;
    else if(isDouble(str))
        return 2;
    else if(isChar(str))
        return 3;
    else if(isFloat(str))
        return 4;
    return 0;
}

void toChar(const std::string &str)
{
    char c = str[0];
    
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void toInt(const std::string &str)
{
    long i = std::atol(str.c_str());
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    
    if (std::isprint(c))
		std::cout << "char : '" << c << "'" << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;
	if (i < INT_MIN || i > INT_MAX)
		std::cout << "int : out of range" << std::endl;
	else
		std::cout << "int : " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void toDouble(const std::string &str)
{
    double d = std::atof(str.c_str());
    char c = static_cast<char>(d);
    long i = static_cast<long>(d);
    float f = static_cast<float>(d);

    
    if (std::isprint(c))
        std::cout << "char : '" << c << "'" << std::endl;
    else
        std::cout << "char : Non displayable" << std::endl;
    if (i < INT_MIN || i > INT_MAX)
        std::cout << "int : out of range" << std::endl;
    else
        std::cout << "int : " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void toFloat(const std::string &str)
{
    float	f = std::atof(str.c_str());
	char	c = static_cast<char>(f);
	double	d = static_cast<double>(f);
	long	i = static_cast<long>(f);
    
    if (std::isprint(c))
        std::cout << "char : '" << c << "'" << std::endl;
    else
        std::cout << "char : Non displayable" << std::endl;
    if (i < INT_MIN || i > INT_MAX)
        std::cout << "int : out of range" << std::endl;
    else
        std::cout << "int : " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
    if (str == "nan" || str == "nanf" || str == "inf" || str == "inff" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
    {
        print_special(str);
        return;
    }
    if(checkStr(str))
    {
        std::cout << "Error: Invalid argument" << std::endl;
        return;
    }
    switch (find_type(str))
    {
        case 1:
            toInt(str);
            break;
        case 2:
            toDouble(str);
            break;
        case 3:
            toChar(str);
            break;
        case 4:
            toFloat(str);
            break;
    }
}