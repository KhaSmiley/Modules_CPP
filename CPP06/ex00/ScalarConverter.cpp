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
        // if (input.c_str()[input.size() - 1] == '.' )
        //     return (true);
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
    int i = static_cast<int>(c);
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
    if(checkStr(str))
    {
        std::cout << "Error: Invalid argument" << std::endl;
        return;
    }
    switch (find_type(str))
    {
        case 1:
            std::cout << "int" << std::endl;
            break;
        case 2:
            std::cout << "double" << std::endl;
            break;
        case 3:
            toChar(str);
            break;
        case 4:
            std::cout << "float" << std::endl;
            break;
    }
}