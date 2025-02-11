




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
    if (!infile.is_open())
        throw FileError();
    infile.close();
    data.close();
}

void BitcoinExchange::parse_date()
{
    std::string line;
    infile.open(_file.c_str());
    while(getline(this->infile, line))
    {
        int Year;
        int Month;
        int Day;
            
        Year = atoi(line.substr(0, 4).c_str());
        Month = atoi(line.substr(5, 2).c_str());
        Day = atoi(line.substr(8, 2).c_str());
    
        if (Year > 2025 ||  Year < 2000)
        {
            this->infile.close();
            throw DateError();
        }    
        if (Month > 12 || Month < 0)
        {
            this->infile.close();
            throw DateError();
        }
        if (Day > 31 || Day < 1)
        {
            this->infile.close();
            throw DateError();
        }
        if (Month == 2 || Month == 4 || Month == 6 || Month == 9 || Month == 11)
            if (Day == 31)
            {
                    this->infile.close();
                    throw DateError();
            }
        if (Month == 2)
            if(Year % 4 == 0)
                if (Day > 29)
                {
                    this->infile.close();
                    throw DateError();
                }
        infile.close();
    }
}

void BitcoinExchange::stock_data()
{
    std::string line;
    std::ifstream file;
    int i = 0;
    
    this->infile.open(_file.c_str());
    while(getline(file, line))
    {
        _dataInfile.insert(std::pair<int, std::string>(i, line));
        i++;
    }
    this->infile.close();
    file.open("data.csv");
    while(getline(file, line))
    {
        _dataBtc.insert(std::pair<std::string, float>(line.substr(0, 10), atof(line.substr(11).c_str())));
    }
    file.close();
}