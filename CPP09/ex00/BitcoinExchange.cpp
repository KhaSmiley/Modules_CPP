




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

    if (line.empty())
        return (2);
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
            if (Day >= 29)
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
        if (line.empty() && i == 0)
        {
            file.close();
            return 1;
        }
        if (isdigit(line[0]))
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
        if (parse_date(it->second) == 1)
            std::cout << "Error: bad input => " << it->second << std::endl;
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
    std::map<std::string, float>::iterator it = _dataBtc.begin();
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