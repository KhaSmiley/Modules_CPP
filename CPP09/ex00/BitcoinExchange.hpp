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

        void print_value(float price, std::string line);
        int parse_date(std::string line);
        void parse_file(char *file);
        int stock_data();
        void makeitwork();
        void find_value(std::string line);

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
        // float   _price;
        // float   _finalValue;

        std::ifstream infile;
        std::ifstream data;
};