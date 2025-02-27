/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 05:39:56 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/18 05:43:36 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
    {
        _file = src._file;
        _dataInfile = src._dataInfile;
        _dataBtc = src._dataBtc;
        _date = src._date;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

const char *BitcoinExchange::FileError::what() const throw()
{
    return ("Error with file\n");
}

const char *BitcoinExchange::DateError::what() const throw()
{
    return ("Error with Date\n");
}

void BitcoinExchange::parse_file(char *file)
{
    std::ifstream infile;
    _file = file;
    infile.open(_file.c_str());
    if (!infile.is_open())
        throw FileError();
    data.open("data.csv");
    if (!data.is_open())
        throw FileError();
    infile.close();
    data.close();
}

int BitcoinExchange::parse_date(std::string line)
{
    if (line.empty())
        return (2);
    if (line.length() < 10 || line[4] != '-' || line[7] != '-')
        return (1);

    int Year;
    int Month;
    int Day;

    Year = atoi(line.substr(0, 4).c_str());
    Month = atoi(line.substr(5, 2).c_str());
    Day = atoi(line.substr(8, 2).c_str());

    if (Year > 2025 ||  Year < 2009)
        return (1);
    if (Month > 12 || Month < 0)
        return (1);
    if (Day > 31 || Day < 1)
        return (1);
    if (Month == 2 || Month == 4 || Month == 6 || Month == 9 || Month == 11)
        if (Day == 31)
                return (1);
    if (Month == 2)
    {
        bool isLeapYear = (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
        if ((isLeapYear && Day > 29) || (!isLeapYear && Day > 28)) 
            return 1;
    }
    return (0);
}

int BitcoinExchange::stock_data()
{
    try
    {
        std::string line;
        std::ifstream file;
        std::ifstream test;
        int i = 0;
        
        
        checkDataBase("data.csv");
        test.open(_file.c_str());
        getline(test, line);
        while(getline(test, line))
        {
            if (line.empty() && i == 0)
            {
                test.close();
                throw FileError();
            }
            _dataInfile.insert(std::pair<int, std::string>(i, line));
            i++;
        }
        test.close(); 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

void BitcoinExchange::makeitwork()
{
    std::map<int, std::string>::iterator it = _dataInfile.begin();
    while(it != _dataInfile.end())
    {   
        if (parse_date(it->second) == 1)
        {
            std::cout << "Error: bad input => " << it->second << std::endl;
            it++;
            continue ;
        }
        else if (parse_date(it->second) == 2)
        {
            it++;
            continue ;
        }
        int start = parse_value(it->second);
        if (!start)
        {
            std::cout << "Error: bad input => " << it->second << std::endl;
            it++;
            continue;
        }
        else if (atof(it->second.substr(start).c_str()) < 0 || atof(it->second.substr(start).c_str()) > 1000)
        {
            if (atof(it->second.substr(start).c_str()) > 1000)
                std::cout << "Error : too large a number." << std::endl;
            else
                std::cout << "Error : not a positive number." << std::endl;
        }
        else
            find_value(it->second, start);
        it++;
    }
}
void BitcoinExchange::print_value(float price, std::string line, int start)
{
    float btc;
    (void)price;
    btc = atof(line.substr(start).c_str());
    std::cout << line.substr(0, 10) << " => " << line.substr(start) << " = " << btc * price << std::endl;
}

void BitcoinExchange::find_value(std::string line, int start)
{
    
    if (_dataBtc.empty()) 
    {
        std::cout << "Error: No data available" << std::endl;
        return;
    }
    std::string dateToFind = line.substr(0, 10);
    std::map<std::string, float>::iterator it = _dataBtc.begin();
    if (std::strcmp(dateToFind.c_str(), it->first.c_str()) < 0) 
    {
        std::cout << "Error: No data available" << std::endl;
        return;
    }
    while(it != _dataBtc.end())
    {
        if (std::strcmp(it->first.c_str(), line.substr(0, 10).c_str()) == 0)
        {
            print_value(it->second, line, start);
            break;
        }
        else if (std::strcmp(it->first.c_str(), line.substr(0, 10).c_str()) > 0)
        {
            if (it == _dataBtc.begin())
            {
                std::cout << "Error : No data available " << std::endl;
                break;
            }
            it--;
            print_value(it->second, line, start);
            break;
        }
        it++;
    }
    if (it == _dataBtc.end())
    {
        it = _dataBtc.end();
        it--;
        print_value(it->second, line, start);
    }
}

int BitcoinExchange::parse_value(std::string line)
{
    int start = 0;
    for(unsigned long int i = 0; i < line.size(); i++)
    {
        int nb_dots = 0;
        while(line[i] && line[i] != '|')
        {
            i++;
        }
        while(line[++i] && (line[i] == ' ' || line[i] == '\t'))
        {
        }
        start = i;
        while(line[i] && (isdigit(line[i]) || line[i] == '.'))
        {
            if (line[i] == '.')
                ++nb_dots;
            if(nb_dots > 1)
                return(0);
            i++;
        }
        if(line[i] && !isdigit(line[i]))
            return (0);
    }
    return (start);
}

void BitcoinExchange::checkDataBase(const std::string& filename) 
{
    std::ifstream file(filename.c_str());
 
    if (!file.is_open())
        throw FileError();
    
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) 
    {
        try 
        {
            size_t pos = line.find(',');
            if (pos == std::string::npos) 
            {
                std::cerr << "Error: invalid format => " << line << std::endl;
                continue;
            }
            
            std::string date = line.substr(0, pos);
            std::string rate = line.substr(pos + 1);
            
            if (parse_date(date)) 
            {
                std::cerr << "Error: invalid date => " << date << std::endl;
                continue;
            }
            
            char* endptr;
            float value = strtof(rate.c_str(), &endptr);
            
            if (*endptr != '\0') 
            {
                std::cerr << "Error: invalid rate value => " << rate << std::endl;
                continue;
            }
            if (value < 0)
                std::cerr << "Error: negative value in database" << std::endl;
            _dataBtc.insert(std::pair<std::string, float>(date, value));
        }
        catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }
    }
    if (_dataBtc.empty()) 
        throw FileError();
}
