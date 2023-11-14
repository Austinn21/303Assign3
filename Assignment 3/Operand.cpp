#include <iostream>


using namespace std;

bool isOperand(char ch) 
{   // will return true if the 'ch' is a digit between 0-9
    return (ch >= '0' && ch <= '9');
}

bool isOperator(char ch) 
{   // will return true if the character has those 'ch' in them
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

int precedence(char op) 
{   // if the operator is '+' or '-', will return 1
    if (op == '+' || op == '-')
        return 1;
    // if the operator is '*' or '/' or '%', will return 2
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else
        return 0;
}