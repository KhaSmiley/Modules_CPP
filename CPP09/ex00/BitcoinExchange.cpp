




#include "BitcoinExchange.hpp"

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
    int Year;
    int Month;
    int Day;
        
    Year = atoi(line.substr(0, 4).c_str());
    Month = atoi(line.substr(5, 2).c_str());
    Day = atoi(line.substr(8, 2).c_str());

    if (Year > 2025 ||  Year < 2000)
    {
        return (1);
    }    
    if (Month > 12 || Month < 0)
    {
        return (1);
    }
    if (Day > 31 || Day < 1)
    {
        return (1);
    }
    if (Month == 2 || Month == 4 || Month == 6 || Month == 9 || Month == 11)
        if (Day == 31)
        {
                return (1);
        }
    if (Month == 2)
        if(Year % 4 == 0)
            if (Day > 29)
            {
                return (1);
            }
    if (line.length() < 12)
        return 1;
    return (0);
}

int BitcoinExchange::stock_data()
{
    std::string line;
    std::ifstream file;
    std::ifstream test;
    int i = 0;
    
    test.open(_file.c_str());
    
    while(getline(test, line))
    {
        if (line.empty() && i == 0)
        {
            test.close();
            return 1;
        }
        _dataInfile.insert(std::pair<int, std::string>(i, line));
        i++;
    }
    test.close();

    i = 0;
    file.open("data.csv");
    while(getline(file, line))
    {
        _dataBtc.insert(std::pair<std::string, float>(line.substr(0, 10), atof(line.substr(11).c_str())));
        i++;
    }
    if (i == 0)
        return (file.close(), 1);
    return 0;
}

void BitcoinExchange::makeitwork()
{
    std::map<int, std::string>::iterator it = _dataInfile.begin();
    
    while(it != _dataInfile.end())
    {
        if (parse_date(it->second))
            std::cout << "Error: bad input => " << it->second << std::endl;
        else if (atof(it->second.substr(12).c_str()) < 0 || atof(it->second.substr(12).c_str()) > 1000)
        {
            if (atof(it->second.substr(12).c_str()) > 1000)
                std::cout << "Error : too large a number." << std::endl;
            else
                std::cout << "Error : not a positive number." << std::endl;
        }
        else
            find_value(it->second);
        it++;
    }
}
void BitcoinExchange::print_value(float price, std::string line)
{
    float btc;
    (void)price;
    btc = atof(line.substr(12).c_str());
    std::cout << line.substr(0, 10) << " =>" << line.substr(12) << " = " << btc * price << std::endl;
}

void BitcoinExchange::find_value(std::string line)
{
    std::map<std::string, float>::iterator it = _dataBtc.begin();
    while(it != _dataBtc.end())
    {
        if (std::strcmp(it->first.c_str(), line.substr(0, 10).c_str()) == 0)
        {
            print_value(it->second, line);
            break;
        }
        else if (std::strcmp(it->first.c_str(), line.substr(0, 10).c_str()) > 0)
        {
            it--;
            print_value(it->second, line);
            break;
        }
        it++;
    }
}
