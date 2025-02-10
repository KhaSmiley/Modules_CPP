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

        void parse_date();
        void parse_file(char *file);
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

        std::map<int, std::string>  _dataInfile;
        std::map<std::string, float>  _dataBtc;
        std::string _date;
        float   _price;
        float   _finalValue;

        std::ifstream infile;
        std::ifstream data;
};