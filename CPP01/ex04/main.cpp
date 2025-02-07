/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:55:59 by kboulkri          #+#    #+#             */
/*   Updated: 2024/10/29 19:55:46 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <iostream>

std::string    find_and_replace(std::string line, const std::string &s1, const std::string &s2)
{
    size_t pos;

    pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos)
    {
        line.erase(pos, s1.size());
        line.insert(pos, s2);
        pos += s2.size();
    }
    return (line);
}

int check_args(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "ERROR : wrong number of arguments" << std::endl;
        return (1);
    }
    if (strlen(argv[2]) == 0 || strlen(argv[3]) == 0)
    {
        std::cout << "ERROR : empty string" << std::endl;
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    
    if (check_args(argc, argv))
        return (1);   
    const char 			*infile = argv[1];
    std::string         replace;
	std::string			outfile(infile);
	std::string			line;
	std::ifstream		file(infile);
    std::ofstream		out;
    outfile += ".replace";
    out.open(outfile.c_str(), std::fstream::out);
    if (!out.is_open())
    {
        std::cout << "ERROR : can't open file" << std::endl;
        return (1);
    }
    while(std::getline(file, line))
    {
        replace = find_and_replace(line, argv[2], argv[3]);
        out << replace << std::endl;
    }
    return (0);
}