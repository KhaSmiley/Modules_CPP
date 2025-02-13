#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string input)
{
    this->_input = input;
}

RPN::RPN(const RPN &src)
{
    *this = src;
}

RPN &RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
    {
        _stack = rhs._stack;
        _input = rhs._input;
        _result = rhs._result;
    }
    return *this;
}

RPN::~RPN()
{
}

const char *RPN::invalidInput::what() const throw()
{
    return ("Error : Parsing issue\n");
}

int RPN::getResult()
{
    return(_result);
}

void RPN::parse_input()
{
    int flag_nb = 0;
    int operand = 0;

    int j = 0;
    while((_input[j] && (_input[j] >= '0' && _input[j] <= '9')) || (_input[j] == ' ' || _input[j] == '\t'))
    {
        if (_input[j] >= '0' && _input[j] <= '9')
        {
            if (flag_nb > 2)
                throw invalidInput();
            flag_nb++;
        }
        j++;
    }
    for(long unsigned int i = j; i < _input.size(); ++i)
    {
        if (_input[i] >= '0' && _input[i] <= '9')
        {
            if (flag_nb > 2)
                throw invalidInput();
            flag_nb++;
            operand = 0;
        }
        else if (_input[i] == '+' || _input[i] == '-' || _input[i] == '*' || _input[i] == '/')
        {
            if (operand > 3 || flag_nb > 2)
                throw invalidInput();
            operand++;
            flag_nb = 0;
        }
        else if (_input[i] == ' ' || _input[i] == '\t')
            continue ;
    }
    if (operand != flag_nb  - 1)
        throw invalidInput();
}

void RPN::calculate()
{
    for (long unsigned int i = 0; i < _input.size(); ++i)
    {
        if (_input[i] == ' ' || _input[i] == '\t')
            continue ;
        if (std::isdigit(_input[i]))
        {
            int res = 0;
            res = res * 10 + (_input[i] - '0');
            _stack.push(res);
        }
        else
        {
            int second = _stack.top();
            _stack.pop();
            int first = _stack.top();
            _stack.pop();

            if (_input[i] == '+')
                _stack.push(first + second);
            else if (_input[i] == '-')
                _stack.push(first - second);
            else if (_input[i] == '*')
                _stack.push(first * second);
            else if (_input[i] == '/')
            {
                if (second == 0)
                    throw invalidInput();
                _stack.push(first / second);
            }
        }
    }
    _result = _stack.top();
}