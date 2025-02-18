/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 05:40:01 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/18 05:43:24 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <fcntl.h>
#include <stdlib.h>
#include <cstring>
#include <exception>
#include <map>

class BitcoinExchange
{
    public :

        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &src);
        ~BitcoinExchange();
        

        void print_value(float price, std::string line, int start);
        int parse_date(std::string line);
        void parse_file(char *file);
        int parse_value(std::string line);
        int stock_data();
        void makeitwork();
        void find_value(std::string line, int start);

        class FileError : public std::exception
        {
            public :
                virtual const char *what() const throw ();
        };
        class DateError : public std::exception
        {
            public :
                virtual const char *what() const throw ();
        };

    private :

        std::string _file;
        std::map<int, std::string>  _dataInfile;
        std::map<std::string, float>  _dataBtc;
        std::string _date;

        std::ifstream infile;
        std::ifstream data;
};