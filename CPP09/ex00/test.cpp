#include <iostream>
#include <string>
#include <fstream>
#include <fcntl.h>
#include <stdlib.h>
#include <cstring>
#include <exception>
#include <map>
#include <stdio.h>
#include <string.h>

int main()
{
    std::ifstream file;
    std::string line;
    std::map<std::string, float>  _dataBtc;

    file.open("test");
    int i = 0;
    while(getline(file, line))
    {
        _dataBtc.insert(std::pair<std::string, float>(line.substr(0, 10), atof(line.substr(11).c_str())));
    }
    file.close();

    std::map<std::string, float>::iterator it = _dataBtc.begin();
    while(it != _dataBtc.end())
    {
        std::cout << it->first << std::endl;
        it++;
    }
    file.close();
}