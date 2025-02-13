#ifndef RPN_HPP
#define RPN_HPP


#include <iostream>
#include <stack>


class RPN
{
    public :

        RPN();
        RPN(std::string input);
        RPN(const RPN &src);
        RPN &operator=(const RPN &rhs);
        ~RPN();

        void parse_input();
        void calculate();
        int getResult();

        class invalidInput : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };

    private :

        std::stack<int> _stack;
        std::string     _input;
        int             _result;
        
};


#endif
