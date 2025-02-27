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
    size_t i = 0;
    int stack_size = 0;

    while (i < _input.size())
    {
        while (i < _input.size() && (_input[i] == ' ' || _input[i] == '\t'))
            i++;
        if (i >= _input.size())
            break;
        if (_input[i] >= '0' && _input[i] <= '9')
        {
            if (_input[i + 1] && _input[i + 1] != ' ' && _input[i + 1] != '\t')
                    throw invalidInput();
            while(i < _input.size() && _input[i] == '0')
                i++;
            stack_size++;
            i++;
            continue;
        }
        if (_input[i] == '+' || _input[i] == '-' || _input[i] == '*' || _input[i] == '/')
        {
            if (stack_size < 2)  // Need at least 2 numbers for an operation
                throw invalidInput();
            stack_size--; // An operation consumes 2 numbers and produces 1
            i++;
            continue;
        }

        // If we get here, we found an invalid character
        if (_input[i] != ' ' && _input[i] != '\t')
            throw invalidInput();
        i++;
    }

    // At the end, we should have exactly one number left
    if (stack_size != 1)
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