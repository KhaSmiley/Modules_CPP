




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

    infile.open(file);
    if (!infile.is_open())
        throw FileError();
    data.open("data.csv");
    if (!infile.is_open())
        throw FileError();
}

void BitcoinExchange::parse_date()
{
    std::string line;
    while(getline(this->infile, line))
    {
        int Year;
        int Month;
        int Day;
            
        Year = atoi(line.substr(0, 4).c_str());
        Month = atoi(line.substr(5, 2).c_str());
        Day = atoi(line.substr(8, 2).c_str());
    
        if (Year > 2025 ||  Year < 2000)
            throw DateError();
        if (Month > 12 || Month < 0)
            throw DateError();
        if (Day > 31 || Day < 1)
            throw DateError();
        if (Month == 2 || Month == 4 || Month == 6 || Month == 9 || Month == 11)
            if (Day == 31)
                throw DateError();
        if (Month == 2)
            if(Year % 4 == 0)
                if (Day > 29)
                    throw DateError();
        
    }
}

void BitcoinExchange::stock_data()
{

}